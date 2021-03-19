/*
 Name:		Teclix.ino
 Created:	04/01/2016 07:04:47
 Author:	HeckRodSav
 Editor:	http://www.visualmicro.com
*/

#include <Teclix.h>

char Matrix[4 * 4] =
{
	'1', '2', '3', 'A',
	'4', '5', '6', 'B',
	'7', '8', '9', 'C',
	'*', '0', '#', 'D'
};

byte pin[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

Teclix teclado(pin, Matrix, 4, 4, 13);

// the setup function runs once when you press reset or power the board
void setup()
{
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop()
{
	teclado.read();
	if (teclado.in())
	{
		Serial.println(teclado.getRead());
	}
}
