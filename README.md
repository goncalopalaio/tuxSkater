tuxSkater
=========

Video Game written using OpenGL for the purpose of a School Project. This config where made in 2009, so they probably have changed a bit since

=====================================
Tux Skater
AK Productions
Developers : Andre Santos && Nuno Khan
Version 0.7
2009
=====================================

	Este é um readme que mostra como intalar e correr o TuxSkater na plataforma Linux (Debian/Ubuntu).
A maneira mais fácil é ter os repositórios activos, caso contrário terá que instalar a partir dos ficheiros .deb disponibilizados na pasta juntamente com o código fonte. De notar que o GlUT tem algumas incompatibilidades com o Compiz por isso aconselhamos a desliga-lo antes de jogar.

Packages necessárias : 

1.OpenGL : 
	#Normalmente vem nos repositórios oficiais do Ubuntu/Debian
	#Introduzir os seguintes comandos na consola/terminal
	sudo apt-get update
	sudo apt-get install libglu1-mesa-dev mesa-common-dev
2.Free Glut: 
	#Normalmente vem nos repositórios oficiais do Ubuntu/Debian
	#Introduzir os seguintes comandos na consola/terminal
	sudo apt-get install freeglut3
	sudo apt-get install freeglut3-dev 
3.SDL_Mixer:
	Disponibilizamos ficheiros .deb (ficheiros executáveis) visto que estas packages não se encontram nos 		repositórios oficiais.

	Depois de instaladas as livrarias (Packages) necessárias, ja podemos compilar o código fonte. Foi criado para auxilio, um ficheiro makefile que podera ser usado da seguinte maneira:
	#Entramos na directória onde esta o codigo fonte a partir do terminal e 
		sudo make
	Se a compilação correr sem erros(problemas de livrarias que não estão instaladas) poderemos correr o jogo com o seguinte comando : 
		./tuxSkater

	Happy Gaming 

====================================================
Apoio Técnico : nunok7@gmail.com , t100n@hotmail.com
====================================================

