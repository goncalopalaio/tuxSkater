#include "drawObjects.h"

/* BUILDINGS AND SIDEWALKS */
static void
drawBox(GLfloat size, GLenum type)
{
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {2, 3, 0, 1},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {1, 0, 4, 5},
    {6, 2, 1, 5},
    {3, 7, 4, 0}
  };
  GLfloat v[8][3];
  GLint i;

  v[0][0] = v[1][0] = v[2][0] = v[3][0] = size / 2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = -size / 2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = size / 2;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = -size / 2;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = size / 2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = -size / 2;
  	
  for (i = 5; i >= 0; i--) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[ (level-1)%5 ]);	//para termos texturas diferentes em cada nivel
    glBegin(type);
		glNormal3fv(&n[i][0]);
		glTexCoord2f(0.0f,0.0f); glVertex3fv(&v[faces[i][0]][0]);
		glTexCoord2f(1.0f,0.0f); glVertex3fv(&v[faces[i][1]][0]);
		glTexCoord2f(1.0f,1.0f); glVertex3fv(&v[faces[i][2]][0]);
		glTexCoord2f(0.0f,1.0f); glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
	glDisable(GL_TEXTURE_2D);
  }
  
  //--------------------------------SIDEWALK
  size = size+1.5;
  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2.8;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = -size / 2.9;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;
  	
  for (i = 5; i >= 0; i--) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture[6]);
    glBegin(type);
		glNormal3fv(&n[i][0]);
		glTexCoord2f(0.0f,0.0f); glVertex3fv(&v[faces[i][0]][0]);
		glTexCoord2f(1.0f,0.0f); glVertex3fv(&v[faces[i][1]][0]);
		glTexCoord2f(1.0f,1.0f); glVertex3fv(&v[faces[i][2]][0]);
		glTexCoord2f(0.0f,1.0f); glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
	glDisable(GL_TEXTURE_2D);
  }
}

void myglutSolidCube(GLdouble size)
{
  drawBox(size, GL_QUADS);
}
//------------------------------------------------------------

//LATA DE CERVEJA
void bottle(){
	glPushMatrix();
		glTranslatef(0.0,0.2,0.0);
		glRotatef(-90,1.0,0.0,0.0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,texture[11]);
		
		GLUquadricObj* cyl;
		cyl = gluNewQuadric();
		gluQuadricDrawStyle(cyl, GLU_FILL);
		gluQuadricNormals    ( cyl, GLU_SMOOTH );
		gluQuadricTexture    ( cyl, GL_TRUE    );
		gluCylinder(cyl, 0.3, 0.3, 1.9, 40, 40);
		
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

//ESTRADA
void surface(){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,texture[7]);
		//glTexParameteri(GL_TEXTURE_2D, GL_REPEAT, GL_REPEAT);
		glPushMatrix();
			glTranslatef(0.0,-0.001,0.0);
			glBegin(GL_QUADS);
				glTexCoord2f (0.0f,0.0f); /* lower left corner of image */
				glVertex3f(2*tam+1,0,tam-1);
				glTexCoord2f (1.0f, 0.0f); /* lower right corner of image */
				glVertex3f(2*tam+1,0,tam-5);
				glTexCoord2f (1.0f, 1.0f); /* upper right corner of image */
				glVertex3f(tam-1.5,0,tam-5);
				glTexCoord2f (0.0f, 1.0f); /* upper left corner of image */
				glVertex3f(tam-1.5,0,tam-1);	//ta mal podia ser nas coordenadas 0 , 5
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

//RELVA
void vegetation(){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,texture[12]);
		//glTexParameteri(GL_TEXTURE_2D, GL_REPEAT, GL_REPEAT);
		glPushMatrix();
			glTranslatef(0.0,-0.001,0.0);
			glBegin(GL_QUADS);
				glTexCoord2f (0.0f,0.0f); /* lower left corner of image */
				glVertex3f(2*tam+1,0,tam-1);
				glTexCoord2f (1.0f, 0.0f); /* lower right corner of image */
				glVertex3f(2*tam+1,0,tam-5);
				glTexCoord2f (1.0f, 1.0f); /* upper right corner of image */
				glVertex3f(tam-1.5,0,tam-5);
				glTexCoord2f (0.0f, 1.0f); /* upper left corner of image */
				glVertex3f(tam-1.5,0,tam-1);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

//ESPECTADORES
void crowd(){
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,texture[13]);
		//glTexParameteri(GL_TEXTURE_2D, GL_REPEAT, GL_REPEAT);
		glPushMatrix();
			glTranslatef(0.0,-0.001,0.0);
			glBegin(GL_QUADS);
				glTexCoord2f (0.0f,0.0f); /* lower left corner of image */
				glVertex3f(2*tam+1,0,tam-1);
				glTexCoord2f (1.0f, 0.0f); /* lower right corner of image */
				glVertex3f(2*tam+1,0,tam-5);
				glTexCoord2f (1.0f, 1.0f); /* upper right corner of image */
				glVertex3f(tam-1.5,0,tam-5);
				glTexCoord2f (0.0f, 1.0f); /* upper left corner of image */
				glVertex3f(tam-1.5,0,tam-1); //continua estupido
			glEnd();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

//----------------------------------------------DESENHAR SKATE
	void drawbodyskate(GLdouble size){
		static GLfloat n[6][3] =
		{
			{-1.0, 0.0, 0.0},
			{0.0, 1.0, 0.0},
			{1.0, 0.0, 0.0},
			{0.0, -1.0, 0.0},
			{0.0, 0.0, 1.0},
			{0.0, 0.0, -1.0}
		};
		static GLint faces[6][4] =
		{
			{2, 3, 0, 1},
			{3, 2, 6, 7},
			{7, 6, 5, 4},
			{1, 0, 4, 5},
			{6, 2, 1, 5},
			{3, 7, 4, 0}
		};
		GLfloat v[8][3];
		GLint i;
		
		v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
		v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
		v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
		v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
		v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
		v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;
		
		for (i = 5; i >= 0; i--) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture[10]);
			glBegin(GL_QUADS);
				glNormal3fv(&n[i][0]);
				glTexCoord2f(0.0f,0.0f); glVertex3fv(&v[faces[i][0]][0]);
				glTexCoord2f(1.0f,0.0f); glVertex3fv(&v[faces[i][1]][0]);
				glTexCoord2f(1.0f,1.0f); glVertex3fv(&v[faces[i][2]][0]);
				glTexCoord2f(0.0f,1.0f); glVertex3fv(&v[faces[i][3]][0]);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
	}
	
	void drawskate(){
		glPushMatrix();
			glTranslatef(0.05,-(tam/8.5),-0.03);
			
			glScalef(0.4,0.05,1.0);
			drawbodyskate(tam/5);
		glPopMatrix();
	}
//================================================================================FIM de SKATE

//----------------------------------------------DESENHAR TUX
	void draweye1(){
		glPushMatrix();
			glColor4f(WHITE);
			glTranslatef(-0.03,0.3,-0.08);
			glutSolidSphere(0.02, 10, 10);
		glPopMatrix();
	}

	void draweye2(){
		glPushMatrix();
			glColor4f(WHITE);
			glTranslatef(0.03,0.3,-0.08);
			glutSolidSphere(0.02, 10, 10);
		glPopMatrix();
	}

	void drawpeak(){
		glPushMatrix();
			glColor4f(LARANJA);
			glTranslatef(0.0,0.28,-0.08);
			glRotatef(-45,1.0,0.0,0.0);
			glScalef(0.5,0.2,1.2);
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture[9]);
			
			GLUquadricObj* y = gluNewQuadric ( );
			gluQuadricDrawStyle ( y, GLU_FILL    );
			gluQuadricNormals    ( y, GLU_SMOOTH );
			gluQuadricTexture    ( y, GL_TRUE    );
			gluSphere ( y, 0.1, 50, 50);
			gluDeleteQuadric ( y );
			
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void drawhead(){
		glPushMatrix();
			glColor4f(BLACK);
			glTranslatef(0.0,0.3,0.0);
			glRotatef(90,1.0,0.0,0.0);
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture[9]);
			
			GLUquadricObj* y = gluNewQuadric ( );
			gluQuadricDrawStyle ( y, GLU_FILL    );
			gluQuadricNormals    ( y, GLU_SMOOTH );
			gluQuadricTexture    ( y, GL_TRUE    );
			gluSphere ( y, 0.1, 50, 50);
			gluDeleteQuadric ( y );
			
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void drawarmright(){
		glPushMatrix();
			glColor4f(WHITE);
			glTranslatef(-0.2,0.1,0.0);
			glRotatef(45,0.0,0.0,1.0);
			glRotatef(90,0.0,1.0,0.0);
			glScalef(0.5,0.2,1.2);
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture[9]);
			
			GLUquadricObj* y = gluNewQuadric ( );
			gluQuadricDrawStyle ( y, GLU_FILL    );
			gluQuadricNormals    ( y, GLU_SMOOTH );
			gluQuadricTexture    ( y, GL_TRUE    );
			gluSphere ( y, 0.1, 50, 50);
			gluDeleteQuadric ( y );
			
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void drawarmleft(){
		glPushMatrix();
			glColor4f(WHITE);
			glTranslatef(0.2,0.1,0.0);
			glRotatef(-45,0.0,0.0,1.0);
			glRotatef(-90,0.0,1.0,0.0);
			glScalef(0.5,0.2,1.2);
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture[9]);
			
			GLUquadricObj* y = gluNewQuadric ( );
			gluQuadricDrawStyle ( y, GLU_FILL    );
			gluQuadricNormals    ( y, GLU_SMOOTH );
			gluQuadricTexture    ( y, GL_TRUE    );
			gluSphere ( y, 0.1, 50, 50);
			gluDeleteQuadric ( y );
			
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void drawlegright(){
		glPushMatrix();
			glColor4f(BLACK);
			glTranslatef(-0.05,-0.25,-0.12);
			glRotatef(-60,0.0,1.0,0.0);
			glScalef(0.5,0.2,1.2);
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture[9]);
			
			GLUquadricObj* y = gluNewQuadric ( );
			gluQuadricDrawStyle ( y, GLU_FILL    );
			gluQuadricNormals    ( y, GLU_SMOOTH );
			gluQuadricTexture    ( y, GL_TRUE    );
			gluSphere ( y, 0.1, 50, 50);
			gluDeleteQuadric ( y );
			
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void drawlegleft(){
		glPushMatrix();
			glColor4f(BLACK);
			glTranslatef(0.10,-0.25,0.02);
			glRotatef(-60,0.0,1.0,0.0);
			glScalef(0.5,0.2,1.2);
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture[9]);
			
			GLUquadricObj* y = gluNewQuadric ( );
			gluQuadricDrawStyle ( y, GLU_FILL    );
			gluQuadricNormals    ( y, GLU_SMOOTH );
			gluQuadricTexture    ( y, GL_TRUE    );
			gluSphere ( y, 0.1, 50, 50);
			gluDeleteQuadric ( y );
			
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void drawbody(){
		//draw body
		glPushMatrix();
			glScalef(0.4,0.5,0.3);
			glRotatef(90, 1.0, 0.0, 0.0);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture[9]);
			
			GLUquadricObj* y = gluNewQuadric ( );
			gluQuadricDrawStyle ( y, GLU_FILL    );
			gluQuadricNormals    ( y, GLU_SMOOTH );
			gluQuadricTexture    ( y, GL_TRUE    );
			gluSphere ( y, 0.5, 50, 50);
			gluDeleteQuadric ( y );
			
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void drawtux(){
		drawskate();
		
		draweye1();
		draweye2();
		drawpeak();
		drawhead();
		
		glPushMatrix();
			glRotatef(-35,0.0,1.0,0.0);
			
			drawbody();
			drawarmleft();
			drawarmright();
			drawlegright();
			drawlegleft();
		glPopMatrix();
	}
//================================================================================FIM de TUX
