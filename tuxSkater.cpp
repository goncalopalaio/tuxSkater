#include "tuxSkater.h"
#include "drawObjects.c"
#include "maps.h"

GLint *mapasize;
GLint *mapa;
//================================================================================
//=========================================================================== INIT
void criaDefineTexturas()
{   
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	imag.LoadBmpFile("images/building2.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);	//modulate=pa tb ser afectado pela luz ambiente
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
	glGenTextures(1, &texture[1]);
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	imag.LoadBmpFile("images/building3.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[2]);
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	imag.LoadBmpFile("images/building4.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());	
	
	glGenTextures(1, &texture[3]);
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	imag.LoadBmpFile("images/building5.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
	glGenTextures(1, &texture[4]);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	imag.LoadBmpFile("images/building6.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
		
	glGenTextures(1, &texture[5]);
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	imag.LoadBmpFile("images/building7.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[6]);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	imag.LoadBmpFile("images/bricks.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[7]);
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	imag.LoadBmpFile("images/road.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[8]);
	glBindTexture(GL_TEXTURE_2D, texture[8]);
	imag.LoadBmpFile("images/world.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[9]);
	glBindTexture(GL_TEXTURE_2D, texture[9]);
	imag.LoadBmpFile("images/tux.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[10]);
	glBindTexture(GL_TEXTURE_2D, texture[10]);
	imag.LoadBmpFile("images/skate.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[11]);
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	imag.LoadBmpFile("images/superbock.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[12]);
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	imag.LoadBmpFile("images/grass.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[13]);
	glBindTexture(GL_TEXTURE_2D, texture[13]);
	imag.LoadBmpFile("images/crowd.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[14]);
	glBindTexture(GL_TEXTURE_2D, texture[14]);
	imag.LoadBmpFile("images/akgraphics.bmp");
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); /* or GL_REPLACE */
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[15]);
	glBindTexture(GL_TEXTURE_2D, texture[15]);
	imag.LoadBmpFile("images/presskey.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); /* or GL_REPLACE */
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
	
	glGenTextures(1, &texture[16]);
	glBindTexture(GL_TEXTURE_2D, texture[16]);
	imag.LoadBmpFile("images/howto.bmp");
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); /* or GL_REPLACE */
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		imag.GetNumCols(),
		imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
		imag.ImageData());
}

void defineLuzes()
{
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);			// Set The Ambient Lighting For Light0
	glLightfv(GL_LIGHT0, GL_DIFFUSE, difusa);			// Set The Ambient Lighting For Light0
	glEnable(GL_LIGHTING);
}

void init(void)
{
	//……………………………………………………………………………………………………………………………Apagar
	glClearColor(BLACK);
	//……………………………………………………………………………………………………………………………Profundidade
	glEnable(GL_DEPTH_TEST);
	//……………………………………………………………………………………………………………………………Interpolacao de cores
	glShadeModel(GL_FLAT);
	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);	// Really Nice Perspective Calculations
	glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);				// Really Nice Point Smoothing

	glShadeModel(GL_SMOOTH);
	glColorMaterial(GL_FRONT_AND_BACK,GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	   
	//……………………………………………………………………………………………………………………………Texturas
	criaDefineTexturas( );
	glEnable(GL_TEXTURE_2D);
	
	mapasize = &mapa1size;
	mapa = &mapa1[0];
	
	/*HOW MANY BOTTLES TO CATCH*/
	int i;
	for(i=0;i<(*mapasize)*(*mapasize);i++){
		if(mapa[i] == 3)
			maxscore++;
	}
	
	srand(getpid());	//para particulas
	if(introstart==-1)		//timer inicial 
		introstart=time(NULL);
	
	/*OPEN AUDIO DEVICE*/
	int audio_rate = 22050;			//Frequency of audio playback
	Uint16 audio_format = AUDIO_S16SYS; 	//Format of the audio we're playing
	int audio_channels = 2;			//2 channels = stereo
	int audio_buffers = 4096;		//Size of the audio buffers in memory
		
	//Initialize SDL_mixer with our chosen audio settings
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		printf("Unable to initialize audio: %s\n", Mix_GetError());
		exit(1);
	}
	/*---------*/
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	/* COR AMBIENTE BRANCA <-> PRETA */
	ambiente[2]=ambiente[1];
	defineLuzes();
	glEnable(GL_LIGHT0);	//ligar a luz 
}
//=========================================================================== FIM INIT

void initParticles(int posX, int posZ){
	for (loop=0;loop<MAXPARTICLES;loop++){
		particle[loop].active=true;								// Make All The Particles Active
		particle[loop].life=1.0f;								// Give All The Particles Full Life
		particle[loop].fade=float(rand()%100)/1000.0f+0.003f;	// Random Fade Speed
		particle[loop].r=colors[rand()%12][0];	// Select Red Rainbow Color
		particle[loop].g=colors[rand()%12][1];	// Select Red Rainbow Color
		particle[loop].b=colors[rand()%12][2];	// Select Red Rainbow Color
		particle[loop].x=posX+tam;
		particle[loop].y=obsP[1]+(0.1*tam);
		particle[loop].z=posZ+tam;
		particle[loop].xi=float((rand()%50)-26.0f)*10.0f;		// Random Speed On X Axis
		particle[loop].yi=float((rand()%50)-25.0f)*10.0f;		// Random Speed On Y Axis
		particle[loop].zi=float((rand()%50)-25.0f)*10.0f;		// Random Speed On Z Axis
		particle[loop].xg=0.0f;									// Set Horizontal Pull To Zero
		particle[loop].yg=-0.8f;								// Set Vertical Pull Downward
		particle[loop].zg=0.0f;									// Set Pull On Z Axis To Zero
	}
}

void *playme(void *ss){
	Mix_Chunk *sound = NULL;		//Pointer to our sound, in memory
	int channel;					//Channel on which our sound is played
	
	char mysound[256];
	strcpy(mysound,MUSICFILENAME);
	//Load our WAV file from disk
	sound = Mix_LoadWAV(mysound);
	if(sound == NULL) {
		printf("Unable to load WAV file: %s\n", Mix_GetError());
	}
	
	if(strcmp("data/background.wav",mysound)==0){
		//Play our sound file, and capture the channel on which it is played
		channel = Mix_PlayChannel(-1, sound, -1 //-1 para loop infinito
													);
	}else{
		//Play our sound file, and capture the channel on which it is played
		channel = Mix_PlayChannel(-1, sound, 1 //-1 para loop infinito
													);
	}
	
	if(channel == -1) {
		printf("Unable to play WAV file: %s\n", Mix_GetError());
	}
	
	//Wait until the sound has stopped playing
	while(Mix_Playing(channel) != 0)
		SDL_Delay(100);
	
	//Release the memory allocated to our sound
	Mix_FreeChunk(sound);
	//Need to make sure that SDL_mixer and SDL have a chance to clean up
	//Mix_CloseAudio();
	//SDL_Quit();
}

void resizeWindow(GLsizei w, GLsizei h)
{
 	wScreen=w;
	hScreen=h;
	glViewport( 0, 0, wScreen,hScreen );	
	glutPostRedisplay();
}

//CRIA O MAPA segundo o array mapa
void drawmapa(){
	int desenhaX = tam*2;		//foi definido que o tamanho dos objectos e do dobro de tam
    int desenhaZ = tam*2;
	int i, j=0, k=0;
		
		for(i=0;i<( (*mapasize)*(*mapasize) );i++){
			if(i>0 && i%(*mapasize)==0){	
				j++;	//verifica linha 
				k=0;	//verifica coluna
			}
			
			//Tux - Acabou de iniciar o jogo -> obtem as direccoes e posicoes do tux e da camara
			if(mapa[i]==2 && start==false){	//start e pa dizer k ainda n encontrou o tux e qud encontra e faz as coisas passa a true
				tuxX = k*desenhaX+tam;	//k*desenha pa andar de 5 em 5 + tam para centrar
				tuxZ = j*desenhaZ+tam;
					
				/*Descobrir a orientacao do Tux*/
					//nao existe obstaculo a ESTE
					if(mapa[i+1]!=1 && mapa[i+1]!=4){
						tuxAng=-90;
						aVisao=0;	//dirrecao do observador
						
						obsP[0] = (tuxX-1)+(tam/5);	//posicao do observador//foi a testar 
						obsP[2] = (tuxZ+1)-(tam/3);
						
					//nao existe obstaculo a SUL
					}else if(mapa[i+(*mapasize)]!=1 && mapa[i+(*mapasize)]!=4){
						tuxAng=-180;
						aVisao=PI/2;
						
						obsP[0] = tuxX+(tam/5);
						obsP[2] = tuxZ-(tam/2);
						
					//nao existe obstaculo a OESTE
					}else if(mapa[i-1]!=1 && mapa[i-1]!=4){
						tuxAng=-270;
						aVisao=-(PI/2)*2;
						
						obsP[0] = (tuxX-1)+tam;
						obsP[2] = (tuxZ+1)-(tam/2.8);
						
					//nao existe obstaculo a NORTE
					}else if(mapa[i-(*mapasize)]!=1 && mapa[i-(*mapasize)]!=4){
						tuxAng=-360;
						aVisao=-(PI/2);
						
						obsP[0] = (tuxX-1)+(tam/1.8);
						obsP[2] = (tuxZ+1);
					}
				
				tuxX = obsP[0] + cos(aVisao);	//desnecessario
				tuxZ = obsP[2] + sin(aVisao);
				
				ang_obsP[0] = obsP[0] + cos(aVisao);
				ang_obsP[1] = obsP[1];
				ang_obsP[2] = obsP[2] + sin(aVisao);
				
				start = true;
				glutPostRedisplay();	//redesenhar o tux com as coordenadas certas
			//desenha obstaculo
			}else if(mapa[i]==3){
				glPushMatrix();
					glTranslatef(k*desenhaX+tam,0.0,j*desenhaZ+tam);
					bottle();
				glPopMatrix();
			}
			
			//estrada | tux | obstaculo
			//->desenha estrada //-1 sitios onde havia cerveja e ja nao ha
			if(mapa[i]==0 || mapa[i]==2 || mapa[i]==3 || mapa[i]==-1){
				glPushMatrix();
					glTranslatef(k*desenhaX,0.0,j*desenhaZ);	//meter no sitio certo
					glScalef(1.0,1.0,1.25);
					glTranslatef(-1, 0.0, tam);
					surface();
				glPopMatrix();
			//->desenha espectadores
			}else if(mapa[i]==5){
				glPushMatrix();
					glTranslatef(k*desenhaX,0.0,j*desenhaZ);
					
					//TOP
					if(i>0 && i<(*mapasize))
						glRotatef(-90,0.0,1.0,0.0);
					//RIGHT
					else if((i+1)%(*mapasize)==0){
						glTranslatef(tam*2,0.0,0.0); //verificacoes para rodar 4x
						glRotatef(-180,0.0,1.0,0.0);
					//BOTTOM
					}else if(i>=((*mapasize)*(*mapasize)-(*mapasize))){
						glTranslatef(0.0,0.0,tam*2);
						glRotatef(-270,0.0,1.0,0.0);
					}
					
					//LEFT
					glTranslatef(tam,tam*(tam/1.8),0.0);
					glRotatef(-45,0.0,0.0,1.0);	//inclinacao
					glScalef(1.0,1.0,1.25);
					glTranslatef(-1, 0.0, tam);
					crowd();
				glPopMatrix();
			//->desenha vegetacao
			}else if(mapa[i]==4){
				glPushMatrix();
					glTranslatef(k*desenhaX,0.0,j*desenhaZ);
					glScalef(1.0,1.0,1.25);
					glTranslatef(-1, 0.0, tam);
					vegetation();
				glPopMatrix();
			//->desenha predio menino andre
			}else if(mapa[i]==1){
				glPushMatrix();
					glTranslatef(k*desenhaX,0.0,j*desenhaZ);
					glTranslatef(tam, tam+1, tam);
					glScalef(1.0,2.0,1.0);
					myglutSolidCube(tam+1);
				glPopMatrix();
			}
			
			k++;
		}
}

void drawScene(){
	glDisable(GL_LIGHTING);
	
	/* COR AMBIENTE BRANCA <-> PRETA */
	ambiente[2]=ambiente[1];
	defineLuzes();
	
	/* CEU */
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); /* or GL_REPLACE */
	glBindTexture(GL_TEXTURE_2D,texture[8]);
    
	GLUquadricObj* y = gluNewQuadric ( );
    gluQuadricDrawStyle ( y, GLU_FILL    );
    gluQuadricNormals    ( y, GLU_SMOOTH );
    gluQuadricTexture    ( y, GL_TRUE    );
    gluSphere ( y, (*mapasize)*(*mapasize), 50, 50);
    gluDeleteQuadric ( y );
	
	glDisable(GL_TEXTURE_2D);
	
	glDisable(GL_LIGHTING);
	/* COR AMBIENTE AMARELA pk esta de dia*/
	if(diaRotate>-180){
		ambiente[2]=0.0;
	}else
		ambiente[2]=ambiente[1];
	
	defineLuzes();
	
	/*SOL E LUA*/
	glPushMatrix();
		glRotatef(diaRotate,0.0,0.0,1.0);
		glPushMatrix();
			glColor4f(WHITE);
			glTranslatef((*mapasize)*((*mapasize)/1.15),0.0,((*mapasize)*tam));
			glutSolidSphere((*mapasize)*tam,50,50);
		glPopMatrix();
		glPushMatrix();
			glColor4f(AMARELO);
			glTranslatef(-((*mapasize)*((*mapasize)/1.15)),0.0,((*mapasize)*tam));
			glutSolidSphere((*mapasize)*tam,50,50);
		glPopMatrix();
	glPopMatrix();
	
	
	glDisable(GL_LIGHTING);
	
	/* COR AMBIENTE BRANCA <-> PRETA */
	ambiente[2]=ambiente[1];
	defineLuzes();
	
	/*MUNDO*/
	glPushMatrix();
		drawmapa();
	glPopMatrix();
	
	/*TUX*/
	glPushMatrix();
		glTranslatef(obsP[0],tuxY,obsP[2]);
		glTranslatef(0.0,0.5,0.0);
		glRotatef(tuxAng,0.0,1.0,0.0);
		drawtux();
	glPopMatrix();
}

void drawPoints(){
	glDisable(GL_LIGHTING);
	//andre
	/* DESENHA PONTO (mini mapa) PARA O TUX */
	glColor4f(BLACK);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(5.0);
	glBegin(GL_POINTS);
		glVertex3f(obsP[0],obsP[1],obsP[2]);
		glColor4f(VERMELHO);
		glVertex3f(ang_obsP[0],obsP[1],ang_obsP[2]);
	glEnd();
	
	/* DESENHA PONTO (mini mapa) PARA A CERVEJA */
	int desenhaX = tam*2;
    int desenhaZ = tam*2;
	int i, j=0, k=0;
		
	for(i=0;i<((*mapasize)*(*mapasize));i++){
		if(i>0 && i%(*mapasize)==0){
			j++;
			k=0;
		}
		
		//desenha obstaculo
		if(mapa[i]==3){
			glColor4f(AMARELO);
			glEnable(GL_POINT_SMOOTH);
			glPointSize(5.0);
			glBegin(GL_POINTS);
				glVertex3f(k*desenhaX+tam,obsP[1],j*desenhaZ+tam);
			glEnd();
		}
		k++;
	}
}

void nevoeiro(){
	glEnable (GL_FOG); //enable the fog
	glFogi (GL_FOG_MODE, GL_EXP2); //set the fog mode to GL_EXP2          
	glFogfv (GL_FOG_COLOR, fogColor); //set the fog color to our color chosen above
	glFogf (GL_FOG_DENSITY, density); //set the density to the value above
	glHint (GL_FOG_HINT, GL_NICEST); // set the fog to look the nicest, may slow down on older cards
}

void drawIntro(int type){
	glDisable(GL_LIGHTING);
	
	glEnable(GL_TEXTURE_2D);
	//INTRO
	if(type==1)
		glBindTexture(GL_TEXTURE_2D,texture[14]);
	//PRESS KEY
	else if(type==2)
		glBindTexture(GL_TEXTURE_2D,texture[15]);
	//HOWTOPLAY
	else if(type==3)
		glBindTexture(GL_TEXTURE_2D,texture[16]);
	
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	
    glBegin(GL_QUADS);
		glTexCoord2f(0.0f,0.0f); glVertex3f(introP[0],-1*introP[1],-2*introP[2]);
		glTexCoord2f(1.0f,0.0f); glVertex3f(introP[0],-1*introP[1],2*introP[2]);
		glTexCoord2f(1.0f,1.0f); glVertex3f(introP[0],3*introP[1],2*introP[2]);
		glTexCoord2f(0.0f,1.0f); glVertex3f(introP[0],3*introP[1],-2*introP[2]);
    glEnd();
	glDisable(GL_TEXTURE_2D);
	
	/* CEU */
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D,texture[8]);
    
	GLUquadricObj* y = gluNewQuadric ( );
    gluQuadricDrawStyle ( y, GLU_FILL    );
    gluQuadricNormals    ( y, GLU_SMOOTH );
    gluQuadricTexture    ( y, GL_TRUE    );
    gluSphere ( y, (*mapasize)*(*mapasize), 50, 50);
    gluDeleteQuadric ( y );

}

void drawParticles(){
	/*DESENHA AS PARTICULAS APOS A CAPTURA DE UMA CERVEJA - (festejo)*/
	for (loop=0;loop<MAXPARTICLES;loop++)					// Loop Through All The Particles
	{
		if (particle[loop].active)							// If The Particle Is Active
		{
			float x=particle[loop].x;						// Grab Our Particle X Position
			float y=particle[loop].y;						// Grab Our Particle Y Position
			float z=particle[loop].z;						// Particle Z Pos

			// Draw The Particle Using Our RGB Values, Fade The Particle Based On It's Life
			glColor4f(particle[loop].r,particle[loop].g,particle[loop].b,particle[loop].life);
			glBegin(GL_TRIANGLE_STRIP);						// Build Quad From A Triangle Strip
				glTexCoord2d(1,1); glVertex3f(x+0.05f,y+0.05f,z); // Top Right
				glTexCoord2d(0,1); glVertex3f(x-0.05f,y+0.05f,z); // Top Left
				glTexCoord2d(1,0); glVertex3f(x+0.05f,y-0.05f,z); // Bottom Right
				glTexCoord2d(0,0); glVertex3f(x-0.05f,y-0.05f,z); // Bottom Left
			glEnd();										// Done Building Triangle Strip
			particle[loop].x+=particle[loop].xi/(slowdown*1000);// Move On The X Axis By X Speed
			particle[loop].y+=particle[loop].yi/(slowdown*1000);// Move On The Y Axis By Y Speed
			particle[loop].z+=particle[loop].zi/(slowdown*1000);// Move On The Z Axis By Z Speed
			particle[loop].xi+=particle[loop].xg;			// Take Pull On X Axis Into Account
			particle[loop].yi+=particle[loop].yg;			// Take Pull On Y Axis Into Account
			particle[loop].zi+=particle[loop].zg;			// Take Pull On Z Axis Into Account
			particle[loop].life-=particle[loop].fade;		// Reduce Particles Life By 'Fade'

			if (particle[loop].life<0.0f)					// If Particle Is Burned Out
			{
				particle[loop].active=false;
			}
		}
	}
}

void renderBitmapString(
		float x, 
		float y, 
		float z, 
		void *font, 
		char *string) {  
  char *c;
  glColor4f(WHITE);
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

void display(void){
	//andre
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Screen, Depth Buffer
	
	/*MOSTRAR A IMAGEM INICIAL*/
	if(intro==true){
		glViewport (0, 0, wScreen, hScreen);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90+zIO, wScreen/hScreen, 0.1, 30*zC);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(obsP[0]-cos(aVisao), obsP[1], obsP[2]-sin(aVisao), ang_obsP[0], ang_obsP[1], ang_obsP[2], 0, 1, 0);
		
		drawIntro(1);
	/*MOSTRAR A IMAGEM PARA INICIAR O JOGO*/
	}else if(press==true){
		glViewport (0, 0, wScreen, hScreen);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90+zIO, wScreen/hScreen, 0.1, 30*zC);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(obsP[0]-cos(aVisao), obsP[1], obsP[2]-sin(aVisao), ang_obsP[0], ang_obsP[1], ang_obsP[2], 0, 1, 0);
		
		drawIntro(2);
	/*MOSTRAR COMO JOGAR*/
	}else if(howto==true){
		glViewport (0, 0, wScreen, hScreen);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90+zIO, wScreen/hScreen, 0.1, 30*zC);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(obsP[0]-cos(aVisao), obsP[1], obsP[2]-sin(aVisao), ang_obsP[0], ang_obsP[1], ang_obsP[2], 0, 1, 0);
		
		drawIntro(3);
	/*MOSTRAR O MUNDO DO TUX*/
	}else{
		//================================================================= Viewport2
		//canto superior esquerdo
		//--------------------------------------- MINI-MAPA: com posição do observador e cervejas
		glViewport(0, 0.45*hScreen, 0.3*wScreen, hScreen);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-(*mapasize)*(tam*2), (*mapasize), -(*mapasize)*(tam*2), (*mapasize)*(tam*2), -(*mapasize), (*mapasize)*(tam*2));
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(((*mapasize)*(tam*2))/5, (*mapasize), ((*mapasize)*(tam*2)), ((*mapasize)*(tam*2))/5, 0, ((*mapasize)*(tam*2)), 0, -1, 1);
		
		glDisable(GL_LIGHTING);
		
		/*MOSTRA O SCORE*/
		char info[256];
		sprintf(info,"Beer: %d/%d\n",score,maxscore);
		renderBitmapString((*mapasize)*(tam*2),(*mapasize),(*mapasize)*(tam*2),GLUT_BITMAP_HELVETICA_18,info);
		
		/*DESENHA O MUNDO*/
		drawScene();
		/*DESENHA OS PONTOS DO OBSERVADOR E CERVEJAS*/
		drawPoints();
		
		//================================================================= Viewport1
		glViewport (0, 0, wScreen, hScreen);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(90+zIO, wScreen/hScreen, 0.1, 30*zC); //zIO - zoom
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(obsP[0]-cos(aVisao), obsP[1], obsP[2]-sin(aVisao), ang_obsP[0], ang_obsP[1], ang_obsP[2], 0, 1, 0);
		
		/*GANHOU - APANHOU TODAS AS CERVEJAS*/
		if(vitory==true){
			char msg[] = "Tux Emerges Victorious";
			char msg2[] = "Press ENTER for the next level.";
			renderBitmapString(obsP[0],obsP[1],obsP[2],GLUT_BITMAP_TIMES_ROMAN_24,msg);
			renderBitmapString(obsP[0],obsP[1]-(0.04*tam),obsP[2],GLUT_BITMAP_TIMES_ROMAN_24,msg2);
		}
		
		/*ACTUALIZA A POSICAO DAS PARTICULAS*/
		drawParticles();
		
		/*DESENHA O MUNDO*/
		drawScene();
		nevoeiro();
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Actualizacao
	glutSwapBuffers();
}

/*Verifica com qual das faces colidiu
 * Retorna o identificador da face
					 * 1-TOP
					 * 2-RIGHT
					 * 3-DOWN
					 * 4-LEFT
					 * 
					 * 5-OUT OF BOUNDS
					 */
int collision(GLfloat posX, GLfloat posZ){
	GLfloat CORNERUpLeftX = posX,
			CORNERUpLeftZ = posZ,
			CORNERUpRightX = posX+(tam*2),
			CORNERUpRightZ = posZ,
			CORNERDownLeftX = posX,
			CORNERDownLeftZ = posZ+(tam+2),
			CORNERDownRightX = posX+(tam*2),
			CORNERDownRightZ = posZ+(tam*2),
			
			centerX = posX+tam,
			centerZ = posZ+tam;
	
	/*DISTANCIA EUCLIDIANA - TUX ao CENTRO*/
	int dC=sqrt( pow((obsP[0]-centerX),2)+ pow((obsP[2]-centerZ),2) );
	
	/*ENCONTRA-SE PERTO DO CENTRO*/
	if ( dC < (tam-(0.2*tam)) )
		return 5;
	
	/*DISTANCIA EUCLIDIANA - TUX ao CANTO SUPERIOR ESQUERDO*/
	int dUL=sqrt( pow((obsP[0]-CORNERUpLeftX),2)+ pow((obsP[2]-CORNERUpLeftZ),2) );
	/*DISTANCIA EUCLIDIANA - TUX ao CANTO SUPERIOR DIREITO*/
	int dUR=sqrt( pow((obsP[0]-CORNERUpRightX),2)+ pow((obsP[2]-CORNERUpRightZ),2) );
	/*DISTANCIA EUCLIDIANA - TUX ao CANTO INFERIOR ESQUERDO*/
	int dDL=sqrt( pow((obsP[0]-CORNERDownLeftX),2)+ pow((obsP[2]-CORNERDownLeftZ),2) );
	/*DISTANCIA EUCLIDIANA - TUX ao CANTO INFERIOR DIREITO*/
	int dDR=sqrt( pow((obsP[0]-CORNERDownRightX),2)+ pow((obsP[2]-CORNERDownRightZ),2) );
	
	int top=dUL+dUR;
	int right=dUR+dDR;
	int left=dUL+dDL;
	int down=dDL+dDR;
	if(top<right && top<left && top<down)
		return 1;
	if(right<top && right<left && right<down)
		return 2;
	if(down<top && down<right && down<left)
		return 3;	
	if(left<top && left<right && left<down)
		return 4;
}

/*Verifica qual o angulo de colisao e define um angulo
 * para obter um movimento paralelo a face que colide
 */
void defineNewAngles(int type, int countx, int countz){
	/*COLISAO DOS LADOS*/
	if(type==1){
		if( (aVisao<0 && aVisao>-(PI/2)) ||
			(aVisao<2*PI && aVisao>PI+(PI/2))
			){
			aVisao=-(PI/2);//-(0.1*PI);
			tuxAng=0;//+(0.1*180);
		}else if( (aVisao<-(PI/2) && aVisao>-PI) ||
					(aVisao<PI+(PI/2) && aVisao>PI)
				){
			aVisao=-(PI/2);//+(0.1*PI);
			tuxAng=0;//-(0.1*180);;
		}else if( (aVisao<-PI && aVisao>-PI-(PI/2)) ||
					(aVisao<PI && aVisao>(PI/2))
				){
			aVisao=-(PI+(PI/2));//-(0.05*PI);
			tuxAng=180;//+(0.1*180);;
		}else{
			aVisao=PI/2;//+(0.1*PI);
			tuxAng=180;//-(0.1*180);;
			}
	/*COLISAO TRAS/FRENTE*/
	}else if(type==2){
		if( (aVisao<0 && aVisao>-(PI/2)) ||
			(aVisao<2*PI && aVisao>PI+(PI/2))
			){
			aVisao=0;//+(0.1*PI);
			tuxAng=-90;//-(0.1*180);
		}else if( (aVisao<-(PI/2) && aVisao>-PI) ||
			(aVisao<PI+(PI/2) && aVisao>PI)
			){
			aVisao=-PI;//-(0.1*PI);
			tuxAng=-270;//+(0.1*180);
		}else if( (aVisao<-PI && aVisao>-PI-(PI/2)) ||
			(aVisao<PI && aVisao>(PI/2))
			){
			aVisao=-PI;//+(0.1*PI);
			tuxAng=-270;//-(0.1*180);
		}else{
			aVisao=0;//-(0.1*PI);
			tuxAng=-90;//+(0.1*180);
		}
	
	/*ENCONTRA-SE PRESO NO OBJECTO*/
	}else if(type==3){
		int i=0;
		
		if( mapa[countz*(*mapasize)+(countx+1)] == -1 ||
			mapa[countz*(*mapasize)+(countx+1)] == 0 ||
			mapa[countz*(*mapasize)+(countx+1)] == 3 ||
			mapa[countz*(*mapasize)+(countx+1)] == 2
			){
			obsP[0]=((countx+1)*(tam*2));
			obsP[2]=obsP[2];
			tuxSpeed=0;
			tuxRotacao=tuxRotacaoMax;
			i = (countx+1);
		}else if( mapa[countz*(*mapasize)+(countx-1)] == -1 ||
			mapa[countz*(*mapasize)+(countx-1)] == 0 ||
			mapa[countz*(*mapasize)+(countx-1)] == 3 ||
			mapa[countz*(*mapasize)+(countx-1)] == 2
			){
			obsP[0]=((countx-1)*(tam*2));
			obsP[2]=obsP[2];
			tuxSpeed=0;
			tuxRotacao=tuxRotacaoMax;
			i = (countx-1);
		}else if( mapa[(countz+1)*(*mapasize)+countx] == -1 ||
			mapa[(countz+1)*(*mapasize)+countx] == 0 ||
			mapa[(countz+1)*(*mapasize)+countx] == 3 ||
			mapa[(countz+1)*(*mapasize)+countx] == 2
			){
			obsP[2]=((countz+1)*(tam*2));
			obsP[0]=obsP[0];
			tuxSpeed=0;
			tuxRotacao=tuxRotacaoMax;
			i = (countz+1)*(*mapasize)+countx;
		}else if( mapa[(countz-1)*(*mapasize)+countx] == -1 ||
			mapa[(countz-1)*(*mapasize)+countx] == 0 ||
			mapa[(countz-1)*(*mapasize)+countx] == 3 ||
			mapa[(countz-1)*(*mapasize)+countx] == 2
			){
			obsP[2]=((countz-1)*(tam*2));
			obsP[0]=obsP[0];
			tuxSpeed=0;
			tuxRotacao=tuxRotacaoMax;
			i = (countz-1)*(*mapasize)+countx;
		}
		
		//RIGHT
		if((i+1)%((*mapasize)-2)==0){
			obsP[0]=obsP[0]+(tam*2);
		//BOTTOM
		}else if(i>=( ((*mapasize)-2)*((*mapasize)-2)-(*mapasize))){
			obsP[2]=obsP[2]+(tam*2);
		}
	}
}

void Timer(int value) 
{
	/*ENCONTRA-SE NA INTRO*/
	if(intro==true){
		/*MOSTRA A INTRO DURANTE 5segundos*/
		if( (time(NULL)-introstart)>5){
			intro=false;
			press=true;
			glutPostRedisplay();
		}
	/*ESTA ACTUALMENTE A JOGAR*/
	}else if(intro==false && press==false && vitory==false && howto==false){
		
		int myx=0,myy=0;
		
		diaRotate-=0.15;
		
		//controlar a densidade do nevoeiro
		if(diaRotate>-270 && density>0){
			density-=0.0005;
		}else if(density<0.1){
			density+=0.0005;
		}
		
		/*CONTROLAR LUZ AMBIENTE*/
		//nascer do sol -> dia
		if(diaRotate>-180){
			if(ambiente[0]<4.0){
				ambiente[0]+=0.05;
				ambiente[1]+=0.05;
				//ambiente[2]+=0.03;
				ambiente[3]+=0.05;
			}
		//por do sol -> noite
		}else if(diaRotate<-180){
			if(ambiente[0]>0.5){
				ambiente[0]-=0.05;
				ambiente[1]-=0.05;
				//ambiente[2]-=0.03;
				ambiente[3]-=0.05;
			}
		}
		
		if(diaRotate<=-360)
			diaRotate=0;
			
		//esta parte andre
		//ainda nao apanhou todas as latas de cerveja e o Tux está a mover-se
		if(score<maxscore && tuxSpeed>0){
			//esta dentro dos limites do mapa
			if( ((obsP[0]+tuxSpeed*cos(aVisao))<(( (*mapasize)*tam*2)-((tam*2)*2)) && (obsP[2]+tuxSpeed*sin(aVisao))<( (*mapasize)*tam*2)-((tam*2)*2))
				&& ((obsP[0]+tuxSpeed*cos(aVisao))>((tam*2)*2) && (obsP[2]+tuxSpeed*sin(aVisao))>((tam*2)*2))
				){
				
				//actualiza posicao do Tux
				obsP[0] = obsP[0]+tuxSpeed*cos(aVisao);
				obsP[2] = obsP[2]+tuxSpeed*sin(aVisao);
				
				tuxX = obsP[0]+cos(aVisao);
				tuxZ = obsP[2]+sin(aVisao);
				
				//Obtem o indice do segmento no array mapa em que se encontra actualmente
				int countx=0;
				while(myx<obsP[0]){
					myx+=5;
					countx++;
				}
				int countz=0;
				while(myy<obsP[2]){
					myy+=5;
					countz++;
				}
				countz--;
				countx--;
				
				/*EXISTE UM OBSTACULO*/
				if((mapa[countz*(*mapasize)+countx]==1 || mapa[countz*(*mapasize)+countx]==4)){
					/*PONTO SUPERIOR ESQUERDO DO OBJECTO*/
					GLfloat posX = countx*(tam*2);
					GLfloat posZ = countz*(tam*2);
					
					/*ESTA DENTRO DA AREA DO OBJECTO - COLISAO*/
					if(
						(posX<obsP[0] && obsP[0]<posX+(tam*2)) && 
						(posZ<obsP[2] && obsP[2]<posZ+(tam*2))
							){
						
						/*VERIFICAR FACE DA COLISAO*/
						int colisionFace=collision(posX,posZ);
						/* Retorna:
						 * 1-TOP
						 * 2-RIGHT
						 * 3-DOWN
						 * 4-LEFT
						 * 
						 * 5-OUT OF BOUNDS
						 */
						
						/*if(mapa[countz*(*mapasize)+countx]==4){
							tuxSpeed=0;
							tuxRotacao=tuxRotacaoMax;
						}else */
						if(colisionFace==5)
							defineNewAngles(3,countx,countz);
						/*COLISAO DOS LADOS*/
						else if(colisionFace==2 || colisionFace==4){
							defineNewAngles(1,0,0);
							tuxSpeed=0.1;
							tuxRotacao=tuxRotacaoMax;
						/*COLISAO FRENTE/TRAS*/
						}else if(colisionFace==1 || colisionFace==3){
							defineNewAngles(2,0,0);
							tuxSpeed=0.1;
							tuxRotacao=tuxRotacaoMax;
						}
						
					}
					
				/*O OBSTACULO E UMA LATA DE CERVEJA*/
				}else if(mapa[countz*(*mapasize)+countx]==3){
					GLfloat posX = countx*(tam*2);
					GLfloat posZ = countz*(tam*2);
					
					/*TUX ENCONTRA-SE PERTO DA LATA*/
					if(
						(posX+(0.5*tam)<obsP[0] && obsP[0]<posX+(tam*2)-(0.5*tam)) && 
						(posZ+(0.5*tam)<obsP[2] && obsP[2]<posZ+(tam*2)-(0.5*tam))
							){
						
						/*INICIALIZA AS PARTICULAS (na posicao da lata de cerveja)*/
						initParticles(posX,posZ);
						
						/*ELIMINA A LATA*/
						mapa[countz*(*mapasize)+countx] = -1;
						score++;
						/*APANHOU TODAS AS LATAS*/
						if(score==maxscore){
							vitory=true;
						}
					}
				}
			//esta nos limites do mapa
			}else{
				//actualiza posicao do Tux
				obsP[0] = obsP[0]+tuxSpeed*cos(aVisao);
				obsP[2] = obsP[2]+tuxSpeed*sin(aVisao);
				
				//Obtem o indice do segmento no array mapa em que se encontra actualmente
				int countx=0;
				while(myx<obsP[0]){
					myx+=5;
					countx++;
				}
				int countz=0;
				while(myy<obsP[2]){
					myy+=5;
					countz++;
				}
				countz--;
				countx--;
				
				defineNewAngles(3,countx,countz);
			}
				
			ang_obsP[0] = obsP[0] + cos(aVisao);
			ang_obsP[1] = obsP[1];
			ang_obsP[2] = obsP[2] + sin(aVisao);
		}
		
		glutPostRedisplay();
	}
	
	glutTimerFunc(msec,Timer, 1);
}

//======================================================= EVENTOS
void keyboard(unsigned char key, int x, int y){
	/*CASO ESTEJA NA INTRO/MENU/AJUDA/FIM DE MAPA - espera pelo ENTER*/
	if(intro==true || press==true || vitory==true || howto==true){
		switch (key) {
			case 13:	//enter
				if(intro==true){
					intro=false;
					press=true;
				}else if(press==true){
					press=false;
					howto=true;	
				}else if(howto==true){
					howto=false;
				/*TERMINOU O NIVEL*/
				}else if(vitory==true){
					int i;
					start=false;
					
					/*NIVEL SEGUINTE*/
					level+=1;
					if(level==2){
						/*RECONSTRUIR O NIVEL ANTERIOR*/
						for(i=0;i<( (*mapasize)*(*mapasize) );i++){
							if(mapa[i]==-1)
								mapa[i]=3;
						}
						/*PASSAR PARA O NIVEL SEGUINTE*/
						mapasize=&mapa2size;
						mapa=&mapa2[0];
					}else if(level==3){
						/*RECONSTRUIR O NIVEL ANTERIOR*/
						for(i=0;i<( (*mapasize)*(*mapasize) );i++){
							if(mapa[i]==-1)
								mapa[i]=3;
						}
						/*PASSAR PARA O NIVEL SEGUINTE*/
						mapasize=&mapa3size;
						mapa=&mapa3[0];
					/*VOLTA AO MENU*/
					}else{
						/*RECONSTRUIR O NIVEL ANTERIOR*/
						for(i=0;i<( (*mapasize)*(*mapasize) );i++){
							if(mapa[i]==-1)
								mapa[i]=3;
						}
						/*PASSAR PARA O NIVEL SEGUINTE*/
						press=true;
						mapasize=&mapa1size;
						mapa=&mapa1[0];
						
						/*ACTUALIZA AS VARIAVEIS PARA OS VALORES POR DEFEITO*/
						level=1;
						obsP[0]=0.0;
						obsP[1]=1.0;
						obsP[2]=0.0;
						ang_obsP[0]=0.0;
						ang_obsP[1]=obsP[1];
						ang_obsP[2]=0.0;
						aVisao=0;
					}
					
					/*HOW MANY BOTTLES TO CATCH*/
					maxscore=0;
					for(i=0;i<(*mapasize)*(*mapasize);i++){
						if(mapa[i] == 3)
							maxscore++;
					}
					
					/*ACTUALIZA AS VARIAVEIS PARA OS VALORES POR DEFEITO*/
					tuxSpeed=0;
					tuxRotacao=0.08;
					diaRotate=0;
					density = 0.07;
					fogColor[0] = 0.5;
					fogColor[1] = 0.5;
					fogColor[2] = 0.5;
					fogColor[3] = 0.0;
					ambiente[0] = 0.5f;
					ambiente[1] = 0.5f;
					ambiente[2] = 0.5f;
					ambiente[3] = 0.5f;
					zIO=1;
					score=0;
					vitory=false;
				}
				
				glutPostRedisplay();
				break;
			//EXIT
			case 27:
				exit(0);
				break;
		}
	}else{
		switch (key) {
			//ZOOM out
			case 'z':
				if(zIO<20)
					zIO+=5;
				glutPostRedisplay();
				break;
			//ZOOM in
			case 'x':
				if(zIO>-20)
					zIO-=5;
				glutPostRedisplay();
				break;
			//EXIT
			case 27:
				exit(0);
				break;
		}
	}

}

//andre
void teclasNotAscii(int key, int x, int y){
	int myx=0,myy=0;
	
	/*ESTA ACTUALMENTE A JOGAR*/
	if(intro==false && press==false && vitory==false && howto==false){
		/*PERMITE AUMENTOS DE VELOCIDADE APENAS DE 0.5 a 0.5 SEGUNDOS*/
		if(key == GLUT_KEY_UP && ((time(NULL)-lastpressed)>0.5 || lastpressed==-1) ) {
			lastpressed=time(NULL);
			
			tuxLastKey=key;
			
			if(tuxSpeed+0.1<tuxMaxSpeed)
				tuxSpeed+=0.1;
			
			if(tuxRotacao>0.01)
				tuxRotacao-=0.001;
		}
		if(key == GLUT_KEY_DOWN) {
			lastpressed=-1;
			
			tuxLastKey=key;
			
			if(tuxSpeed-0.1>-1*tuxMaxSpeed)
				tuxSpeed-=0.1;
			
			if(tuxRotacao<tuxRotacaoMax)
				tuxRotacao+=0.001;
			
			if(score<maxscore && tuxSpeed<=0){
				tuxSpeed=0.1;
				//esta dentro dos limites do mapa
				if( ((obsP[0]-tuxSpeed*cos(aVisao))<(( (*mapasize)*tam*2)-((tam*2)*2)) && (obsP[2]-tuxSpeed*sin(aVisao))<( (*mapasize)*tam*2)-((tam*2)*2))
					&& ((obsP[0]-tuxSpeed*cos(aVisao))>((tam*2)*2) && (obsP[2]-tuxSpeed*sin(aVisao))>((tam*2)*2))
					){
					
					//actualiza posicao do Tux
					obsP[0] = obsP[0]-tuxSpeed*cos(aVisao);
					obsP[2] = obsP[2]-tuxSpeed*sin(aVisao);
					
					tuxX = obsP[0]-cos(aVisao);
					tuxZ = obsP[2]-sin(aVisao);
					
					//Obtem o indice do segmento no array mapa em que se encontra actualmente
					int countx=0;
					while(myx<obsP[0]){
						myx+=5;
						countx++;
					}
					int countz=0;
					while(myy<obsP[2]){
						myy+=5;
						countz++;
					}
					countz--;
					countx--;
					
					/*EXISTE UM OBSTACULO*/
					if((mapa[countz*(*mapasize)+countx]==1 || mapa[countz*(*mapasize)+countx]==4)){
						/*PONTO SUPERIOR ESQUERDO DO OBJECTO*/
						GLfloat posX = countx*(tam*2);
						GLfloat posZ = countz*(tam*2);
						
						/*ESTA DENTRO DA AREA DO OBJECTO - COLISAO*/
						if(
							(posX<obsP[0] && obsP[0]<posX+(tam*2)) && 
							(posZ<obsP[2] && obsP[2]<posZ+(tam*2))
								){
							
							/*VERIFICAR FACE DA COLISAO*/
							int colisionFace=collision(posX,posZ);
							/* Retorna:
							 * 1-TOP
							 * 2-RIGHT
							 * 3-DOWN
							 * 4-LEFT
							 * 
							 * 5-OUT OF BOUNDS
							 */
							
							/*if(mapa[countz*(*mapasize)+countx]==4){
								tuxSpeed=0;
								tuxRotacao=tuxRotacaoMax;
							}else */
							if(colisionFace==5)
								defineNewAngles(3,countx,countz);
							/*COLISAO DOS LADOS*/
							else if(colisionFace==2 || colisionFace==4){
								defineNewAngles(1,0,0);
								tuxSpeed=0.1;
								tuxRotacao=tuxRotacaoMax;
							/*COLISAO FRENTE/TRAS*/
							}else if(colisionFace==1 || colisionFace==3){
								defineNewAngles(2,0,0);
								tuxSpeed=0.1;
								tuxRotacao=tuxRotacaoMax;
							}
							
						}
						
					/*O OBSTACULO E UMA LATA DE CERVEJA*/
					}else if(mapa[countz*(*mapasize)+countx]==3){
						GLfloat posX = countx*(tam*2);
						GLfloat posZ = countz*(tam*2);
						
						/*TUX ENCONTRA-SE PERTO DA LATA*/
						if(
							(posX+(0.5*tam)<obsP[0] && obsP[0]<posX+(tam*2)-(0.5*tam)) && 
							(posZ+(0.5*tam)<obsP[2] && obsP[2]<posZ+(tam*2)-(0.5*tam))
								){
							
							/*INICIALIZA AS PARTICULAS (na posicao da lata de cerveja)*/
							initParticles(posX,posZ);
							
							/*ELIMINA A LATA*/
							mapa[countz*(*mapasize)+countx] = -1;
							score++;
							/*APANHOU TODAS AS LATAS*/
							if(score==maxscore){
								vitory=true;
							}
						}
					}
				}else{
					//actualiza posicao do Tux
					obsP[0] = obsP[0]-tuxSpeed*cos(aVisao);
					obsP[2] = obsP[2]-tuxSpeed*sin(aVisao);
					
					//Obtem o indice do segmento no array mapa em que se encontra actualmente
					int countx=0;
					while(myx<obsP[0]){
						myx+=5;
						countx++;
					}
					int countz=0;
					while(myy<obsP[2]){
						myy+=5;
						countz++;
					}
					countz--;
					countx--;
					
					defineNewAngles(3,countx,countz);
				}
				tuxSpeed=0;
			}
			
		}
		

		if(key == GLUT_KEY_LEFT){
			if(score<maxscore){
				if( (aVisao - tuxRotacao)==-(PI*2)){
					aVisao=0;
					tuxAng=-90;
				}else
					aVisao = (aVisao - tuxRotacao);
				
				if((tuxAng + (tuxRotacao*90/(PI/2)) )==-360){
					tuxAng=0;
					aVisao=-(PI/2);
				}else
					tuxAng = (tuxAng + (tuxRotacao*90/(PI/2)) );
			}
		}
		if(key == GLUT_KEY_RIGHT){
			if(score<maxscore){
				if( (aVisao + tuxRotacao)==(PI*2)){
					aVisao=0;
					tuxAng=-90;
				}else
					aVisao = (aVisao + tuxRotacao);
				
				if((tuxAng - (tuxRotacao*90/(PI/2)) )==360){
					tuxAng=0;
					aVisao=-(PI/2);
				}else
					tuxAng = (tuxAng - (tuxRotacao*90/(PI/2)) );
			}
		}
		
		ang_obsP[0] = obsP[0] + cos(aVisao);
		ang_obsP[1] = obsP[1];
		ang_obsP[2] = obsP[2] + sin(aVisao);
	}
	
	glutPostRedisplay();	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize (wScreen, hScreen); 
	glutInitWindowPosition (300, 100); 
	glutCreateWindow ("TuxSkater  ~~~~~~  Movimento: SETAS | Zoom: Z (out) X (in)");
  
	init();
	
	/*EXECUTA O SOM DE BACKGROUND*/
	MUSICFILENAME=(char *)malloc(sizeof(char)*256);
	sprintf(MUSICFILENAME,"data/background.wav");
	//pthread_create(&id,NULL,(*playme),MUSICFILENAME);
	/*---------*/
	
	glutSpecialFunc(teclasNotAscii); 
	glutDisplayFunc(display); 
	glutReshapeFunc(resizeWindow);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(msec, Timer, 1);

	glutMainLoop();

	return 0;
}
