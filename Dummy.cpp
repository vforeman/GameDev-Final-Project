#include "src/Dummy.h"

Dummy::Dummy()
{

}
Dummy::~Dummy()
{

}
void Dummy::drawSphere()
{
	float angle1, angle2;
	float xx,yy,zz,xxp,yyp,zzp;


	glPushMatrix();

	for(angle2 = -T_PI/2 ; angle2<=T_PI/2; angle2+= RESL)
	{
		glBegin(GL_QUAD_STRIP);
		for(angle1 =0.0 ; angle1 <=T_PI*2.0 + RESL ; angle1 += RESL)
		{
			yy = sin(angle2);
			xx = cos(angle1) * cos(angle2);
			zz = sin(angle1) * cos(angle2);

			yyp = sin(angle2 + RESL);
			xxp = cos(angle1) * cos(angle2 + RESL);
			zzp = sin(angle1) * cos(angle2 + RESL);

			glColor3f(0.0,1.0,0.0);
			glVertex3f(xx,yy,zz);
			glColor3f(0.0,0.0,1.0);
			glVertex3f(xxp,yyp,zzp);
		}
		glEnd();
	}
	glPopMatrix();
};

void Dummy::drawEnvironment()
{
	glPushMatrix();
	glColor3f(0.09f, 0.9f,0.9f);
	glBegin(GL_QUADS);
			glVertex3f(-100.0f,-1.0f,-100.0f);
			glVertex3f(-100.0f,-1.0f,100.0f);
			glVertex3f(100.0f,-1.0f,100.0f);
			glVertex3f(100.0f,-1.0f,-100.0f);
		glEnd();
	glPopMatrix();


};


