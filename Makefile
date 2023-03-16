SRC_CORRE=	Contacto.cpp  \
			testi.cpp

OBJ_CORRE=	Contacto.o \
			testi.o

SRC=Contacto.cpp \
	Agenda.cpp \

OBJ=Contacto.o \
	Agenda.o

all:
	g++ -g -c ${SRC}
	g++ ${OBJ} main.cpp -g -o main
corre:
	g++ -c -g ${SRC_CORRE}
	g++ -g ${OBJ_CORRE} Agenda.cpp -g -o corrector

