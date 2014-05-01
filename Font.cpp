#include "src/Font.h"


namespace freetype
{
    
    //This function gets teh first power of 2 >= the int that we pass it
    inline int nextPowerOf2 (int a)
    {
        int rval = 1;
        while(rval<a)
        {
            rval <<= 1;
        }
        return rval;
    }

    void make_dlist (FT_Face face, char ch, GLuint list_base, GLuint * tex_base )
    {
        //Lod the glyph for our characeter
        if(FT_Load_Glyph( face, FT_Get_Char_Index( face, ch ), FT_LOAD_DEFAULT ))
            throw std::runtime_error("FT LOAD GLYPH failed\n");

        //Move the face's glyph into a glyph object
        FT_Glyph glyph;
        if(FT_Get_Glyph( face->glyph, &glyph ))
            throw std::runtime_error("FT GET GLYPH FAILED\n");

        //Convert the glyph to a bitmap
        FT_Glyph_To_Bitmap( &glyph, ft_render_mode_normal, 0, 1 );
        FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph) glyph;

        //This referece will make accessing the bitmap easier
        FT_Bitmap& bitmap = bitmap_glyph->bitmap;

        int width = nextPowerOf2(bitmap.width);
        int height = nextPowerOf2(bitmap.rows);

        //Allocate memory for the texture Data
        GLubyte* expandedData = new GLubyte[2 * width * height];


        //Here we fill in the data Data for the Expanded Bitmap.
        //Notice that we are using a two channel bitmap (one for
        //Channel luminosity and one for alpha), but we assign
        //Both luminosity and Alpha to the value that we 
        //Find in the Freetype bitmap
        //We use the ?: operator to say that the value which we use
        //will be 0 if we are in the Padding Zone, and whatever
        //Is the FreetypeBitmap otherwise
        for(int j = 0; j < height; ++j)
        {
            for(int i = 0; i < width; ++i)
            {
                expandedData[2*(i+j*width)] = 255;
                expandedData[2*(i+j*width) + 1] =
                    (i >= bitmap.width || j >= bitmap.rows) ? 0 : bitmap.buffer[i+bitmap.width*j];
            }
        }

        glBindTexture(GL_TEXTURE_2D, tex_base[ch]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        //Here we actually create the texture itself, notice that we are using GL_LUMINANCE_ALPHA to 
        //indcate that we are using 2 channel data
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_LUMINANCE_ALPHA,
                      GL_UNSIGNED_BYTE, expandedData);

        delete [] expandedData;

        glNewList(list_base+ch, GL_COMPILE);

        glBindTexture(GL_TEXTURE_2D, tex_base[ch]);

        glPushMatrix();
            glTranslatef(bitmap_glyph->left, 0, 0);
            glTranslatef(0, bitmap_glyph->top-bitmap.rows, 0);

            float x = (float)bitmap.width/(float)width;
            float y = (float)bitmap.rows /(float)height;

            glBegin(GL_QUADS);
                glTexCoord2d(0, 0); glVertex2f(0, bitmap.rows);
                glTexCoord2d(0, y); glVertex2f(0, 0);
                glTexCoord2d(x, y); glVertex2f(bitmap.width, 0);
                glTexCoord2d(x, 0); glVertex2f(bitmap.width, bitmap.rows);
            glEnd();
        glPopMatrix();
        glTranslatef(face->glyph->advance.x >> 6, 0, 0);

        glEndList();
        //FT_Done_Glyph(glyph);
    }

    
    void font_data::init(const char* fname, unsigned int h)
    {
        textures = new GLuint[128];
        this->h = h;

        FT_Library library;
        if(FT_Init_FreeType( &library ))
            throw std::runtime_error("FT_Init_FreeType failed");

        FT_Face face;

        if(FT_New_Face( library, fname, 0, &face ))
            throw std::runtime_error("FT_New_Face failed (there is probably a problem with your font file)\n");

        FT_Set_Char_Size( face, h << 6, h << 6, 96, 96);

        list_base = glGenLists(128);
        glGenTextures( 128, textures);
        
        for(unsigned char i = 0; i < 128; ++i)
        {
            make_dlist(face, i, list_base, textures);
        }

        FT_Done_Face(face);

        FT_Done_FreeType(library);
    }

    void font_data::clean()
    {
        glDeleteLists(list_base, 128);
        glDeleteTextures(128, textures);
        delete [] textures;
    }

    inline void pushScreenCoordinateMatrix()
    {
        glPushAttrib(GL_TRANSFORM_BIT);
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(viewport[0], viewport[2], viewport[1], viewport[3]);
        glPopAttrib();
    }


    inline void popProjectionMatrix()
    {
        glPushAttrib(GL_TRANSFORM_BIT);
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glPopAttrib();
    }

    void print(const font_data &ft_font, float x, float y, const char* fmt, ...)
    {
        pushScreenCoordinateMatrix();

        GLuint font = ft_font.list_base;

        float h = ft_font.h/0.63f;

        char text[256];

        va_list ap;                     //Pointer to list of arguments

        if(fmt == NULL)
        {
            *text = 0;
        }
        else
        {
            va_start(ap, fmt);
            vsprintf(text, fmt, ap);
            va_end(ap);
        }

        const char* start_line = text;
        vector<string> lines;

        const char * c = text;

        for(; * c; ++c)
        {
            if(*c == '\n')
            {
                string line;
                for(const char *n = start_line; n < c; ++n)
                {
                    line.append(1, *n);
                }

                lines.push_back(line);
                start_line=c+1;
            }
            
            
        }
        if(start_line)
        {
            string line;
            for(const char* n = start_line; n < c; ++n) 
            {
                line.append(1, *n);
            }
            lines.push_back(line);
        }

        glPushAttrib(GL_LIST_BIT | GL_CURRENT_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT);
        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glListBase(font);


        float modelview_matrix[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);

        for(int i = 0; i < lines.size(); ++i)
        {
            glPushMatrix();
            glLoadIdentity();
            glTranslatef(x, y-h*i, 0);
            glMultMatrixf(modelview_matrix);


            glCallLists(lines[i].length(), GL_UNSIGNED_BYTE, lines[i].c_str());

            glPopMatrix();
        }

        glPopAttrib();

        popProjectionMatrix();
    }

   
};
