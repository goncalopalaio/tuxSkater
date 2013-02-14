#include <GL/glut.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <GL/glut.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include <unistd.h>

#include "RgbImage.h"
	
//--------------------------------- Definir cores
#define AZUL     0.0, 0.0, 1.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define AMARELO  1.0, 1.0, 0.0, 1.0
#define VERDE    0.0, 1.0, 0.0, 1.0
#define LARANJA  1.0, 0.5, 0.1, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY     0.9, 0.92, 0.29, 1.0
#define PI		 3.1415

//================================================================================
//===========================================================Variaveis e constantes
GLfloat   tam=2.5;
GLint 	  zIO=1;		//ZOOM
GLfloat ambiente[]		= { 0.5f, 0.5f,  0.0f, 0.5f};	//luz ambiente
GLfloat difusa[]		= { 0.0f, 0.0f,  1.0f, 1.0f};	//luz difusa (azul)

time_t 	lastpressed=-1;	//timer para a tecla UP
time_t	introstart=-1;	//timer para a intro

//------------------------------------------------------------ Sistema Coordenadas + objectos
GLint     wScreen=800, hScreen=600;		//.. janela
GLfloat   xC=10.0, yC=10.0, zC=10.0;	//.. Mundo

//------------------------------------------------------------ Observador
GLfloat  aVisao=0;
GLfloat  obsP[] ={0.0, 1.0, 0.0};
GLfloat	 ang_obsP[] = {0.0, obsP[1], 0.0};
GLfloat  introP[] ={1.0, 1.0, 1.0};

//------------------------------------------------------------ Tux
GLfloat tuxX=0,tuxY=0,tuxZ=0,tuxAng=0,tuxRotacaoMax=0.08;
GLfloat tuxRotacao=0.08,tuxSpeed=0,tuxMaxSpeed=0.7,tuxLastKey=-1;

//------------------------------------------------------------
GLfloat diaRotate=0;

GLfloat density = 0.07; //density 0.3 -> thick
GLfloat fogColor[4] = {0.5, 0.5, 0.5, 0.0}; //set fog color to grey

RgbImage  imag;
GLuint    tex;
GLfloat   angRot  = 0;
GLint     msec    = 50;	//timer	
GLboolean start = false; //ainda nao encontrou o Tux no array
GLint	  level = 1;
GLboolean intro	= true;
GLboolean press	= false;
GLboolean howto = false;
GLboolean vitory = false;
GLint	  score = 0;	//numero de cervejas bebidas
GLint	  maxscore = 0;	//numero maximo de cervejas no map

pthread_t id;
char *MUSICFILENAME;
GLuint    texture[17];


int MAXPARTICLES=50;
typedef struct
{
	bool	active;					// Active (Yes/No)
	float	life;					// Particle Life
	float	fade;					// Fade Speed
	float	r;						// Red Value
	float	g;						// Green Value
	float	b;						// Blue Value
	float	x;						// X Position
	float	y;						// Y Position
	float	z;						// Z Position
	float	xi;						// X Direction
	float	yi;						// Y Direction
	float	zi;						// Z Direction
	float	xg;						// X Gravity
	float	yg;						// Y Gravity
	float	zg;						// Z Gravity
}
particles;							// Particles Structure

particles particle[50];	// Particle Array

static GLfloat colors[12][3]=		// Rainbow Of Colors
{
	{1.0f,0.5f,0.5f},{1.0f,0.75f,0.5f},{1.0f,1.0f,0.5f},{0.75f,1.0f,0.5f},
	{0.5f,1.0f,0.5f},{0.5f,1.0f,0.75f},{0.5f,1.0f,1.0f},{0.5f,0.75f,1.0f},
	{0.5f,0.5f,1.0f},{0.75f,0.5f,1.0f},{1.0f,0.5f,1.0f},{1.0f,0.5f,0.75f}
};
GLuint	col;						// Current Color Selection
float	slowdown=4.0f;				// Slow Down Particles
int loop;



void criaDefineTexturas();
void defineLuzes();
void init(void);
void initParticles(int posX, int posZ);
void *playme(void *ss);
void resizeWindow(GLsizei w, GLsizei h);
void drawmapa();
void drawScene();
void drawPoints();
void drawParticles();
void nevoeiro();
void drawIntro(int type);
void renderBitmapString(float x, float y, float z, void *font, char *string);
void display(void);
int collision(GLfloat posX, GLfloat posZ);
void defineNewAngles(int type, int countx, int countz);
void Timer(int value);
void keyboard(unsigned char key, int x, int y);
void teclasNotAscii(int key, int x, int y);
