
FLAGS  = -Wall -g -lglut -lSDL_mixer -lm
CC     = g++
PROG   = tuxSkater
OBJS   = tuxSkater.o RgbImage.o

all:	${PROG}

clean:
	rm ${OBJS} ${PROG}
  
${PROG}:	${OBJS}
	${CC} ${FLAGS} ${OBJS} -o $@

.c.o:
	${CC} ${FLAGS} $< -c

##########################

RgbImage.o: RgbImage.cpp RgbImage.h

tuxSkater.o: tuxSkater.cpp drawObjects.h maps.h

tuxSkater: tuxSkater.o RgbImage.o

