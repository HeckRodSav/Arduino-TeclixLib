/*
 Name:		Teclix.h
 Created:	04/01/2016 07:04:47
 Author:	HeckRodSav
 Editor:	http://www.visualmicro.com
*/

#ifndef _Teclix_h
#define _Teclix_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Teclix
{
private:
	bool in_Linha = 0;
	bool in_Coluna = 0;
	bool In = 0;
	byte *T_Linha;
	byte *T_Coluna;
	char **M;
	char _Read;
	int _linha;
	int _coluna;
	String S_Linha;
	String S_Coluna;
	byte led;

public:
	Teclix(byte *_pin, char *tecIn, int L, int C, byte LED);
	Teclix(byte *_pin, char *tecIn, int L, int C);
	Teclix(byte *_pin, char *tecIn);
	~Teclix();
	byte L();
	byte C();
	char read();
	bool in(bool I);
	bool in();
	char getRead();
};

#endif

