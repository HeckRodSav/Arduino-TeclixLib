/*
 Name:		Teclix.cpp
 Created:	04/01/2016 07:04:47
 Author:	HeckRodSav
 Editor:	http://www.visualmicro.com
*/

#include "Teclix.h"

Teclix::Teclix(byte *_pin, char *tecIn, int L, int C, byte LED)
{
	led = LED;
	_linha = L;
	_coluna = C;
	T_Linha = new byte[_linha];
	T_Coluna = new byte[_coluna];
	M = new char*[_linha];
	for (int i = 0; i < _linha; ++i)
	{
		M[i] = new char[_coluna];
	}
	for (int l = 0, k = 0; l < _linha; l++)
	{
		for (int c = 0; c < _coluna; c++, k++)
		{
			M[l][c] = tecIn[k];
		}
	}
	for (byte i = 0; i < _linha; i++)
	{
		T_Linha[i] = _pin[i];
	}
	for (byte i = 0; i < _coluna; i++)
	{
		T_Coluna[i] = _pin[i + _linha];
	}
	if (led != '\0')pinMode(led, OUTPUT);
}

Teclix::Teclix(byte *_pin, char *tecIn, int L, int C)
{
	led = '\0';
	_linha = L;
	_coluna = C;
	T_Linha = new byte[_linha];
	T_Coluna = new byte[_coluna];
	M = new char*[_linha];
	for (int i = 0; i < _linha; ++i)
	{
		M[i] = new char[_coluna];
	}
	for (int l = 0, k = 0; l < _linha; l++)
	{
		for (int c = 0; c < _coluna; c++, k++)
		{
			M[l][c] = tecIn[k];
		}
	}
	for (byte i = 0; i < _linha; i++)
	{
		T_Linha[i] = _pin[i];
	}
	for (byte i = 0; i < _coluna; i++)
	{
		T_Coluna[i] = _pin[i + _linha];
	}
	if (led != '\0')pinMode(led, OUTPUT);
}

Teclix::Teclix(byte *_pin, char *tecIn)
{
	led = '\0';
	_linha = 4;
	_coluna = 4;
	T_Linha = new byte[_linha];
	T_Coluna = new byte[_coluna];
	M = new char*[_linha];
	for (int i = 0; i < _linha; ++i)
	{
		M[i] = new char[_coluna];
	}
	for (int l = 0, k = 0; l < _linha; l++)
	{
		for (int c = 0; c < _coluna; c++, k++)
		{
			M[l][c] = tecIn[k];
		}
	}
	for (byte i = 0; i < _linha; i++)
	{
		T_Linha[i] = _pin[i];
	}
	for (byte i = 0; i < _coluna; i++)
	{
		T_Coluna[i] = _pin[i + _linha];
	}
	if (led != '\0')pinMode(led, OUTPUT);
}

Teclix::~Teclix()
{
	if (led != '\0') digitalWrite(led, HIGH);
	delete[]T_Linha;
	delete[]T_Coluna;
	for (int i = 0; i < _linha; ++i)
	{
		delete[]M[i];
	}
	delete[]M;
	if (led != '\0') digitalWrite(led, LOW);
}

byte Teclix::L()
{
	byte l = 0;
	S_Linha = "";
	for (byte i = 0; i < _linha; i++)
	{
		pinMode(T_Linha[i], INPUT_PULLUP);
		pinMode(T_Coluna[i], OUTPUT);
		digitalWrite(T_Coluna[i], LOW);
	}
	for (byte i = 0; i < _linha; i++)
	{
		bool t = digitalRead(T_Linha[i]);
		S_Linha.concat(t);
		if (!t)
		{
			l = i;
			in_Linha = 1;
		}
	}
	return l;
}

byte Teclix::C()
{
	byte c = 0;
	S_Coluna = "";
	for (byte i = 0; i < _coluna; i++)
	{
		pinMode(T_Coluna[i], INPUT_PULLUP);
		pinMode(T_Linha[i], OUTPUT);
		digitalWrite(T_Linha[i], LOW);
	}
	for (byte i = 0; i < _coluna; i++)
	{
		bool t = digitalRead(T_Coluna[i]);
		S_Coluna.concat(t);
		if (!t)
		{
			c = i;
			in_Coluna = 1;
		}
	}
	return c;
}

char Teclix::read()
{
	_Read = M[L()][C()];
	return _Read;
}

bool Teclix::in(bool I)
{
	bool t = in_Linha && in_Coluna;
	in_Linha = 0;
	in_Coluna = 0;
	if (I) return t;
	else
	{
		if (t)
		{
			if (!In)
			{
				In = 1;
				if (led != '\0') digitalWrite(led, HIGH);
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			In = 0;
			if (led != '\0') digitalWrite(led, LOW);
			return 0;
		}
	}
}

bool Teclix::in()
{
	bool t = in_Linha && in_Coluna;
	in_Linha = 0;
	in_Coluna = 0;
	if (t)
	{
		if (!In)
		{
			In = 1;
			if (led != '\0') digitalWrite(led, HIGH);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		In = 0;
		if (led != '\0') digitalWrite(led, LOW);
		return 0;
	}
}

char Teclix::getRead()
{
	return _Read;
}
