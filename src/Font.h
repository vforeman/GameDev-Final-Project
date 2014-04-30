//folowed: nehe.gamedev.net/tutorial/freetype_fonts_in_opengl/24001


#ifndef FONT_H
#define FONT_H


#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>


#include <GL/gl.h>
#include <GL/glu.h>

#include <vector>
#include <string>

#include <stdexcept>

namespace freetype
{
    using std::vector;
    using std::string;   
    
    struct font_data
    {
        float h;                            //Holds the height of the font
        GLuint * textures;                  //Holds the texture id's 
        GLuint list_base;                   //Holds the first display list id

        //The init function will create a font with
        //The height h from the file fname
        void init(const char* fname, unsigned int h);
        
        //Free all the resources associated with the font
        void clean();
    };
    
   
    void print(const font_data &ft_font, float x, float y, const char *fmt, ...);

};

#endif
