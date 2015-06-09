#include "Arduino.h"
#include "LedCube.h"

void LedCube::setupIO ()
{
    int io;
    for ( io = 2; io <= 13; ++io )
    {
        pinMode ( io, OUTPUT );
        digitalWrite ( io, LOW );
    }
}

void LedCube::setLed ( int led, bool ledState, int plane)
{
    if ( led < 0 || led > 8 )
        return;

    digitalWrite ( led + 2, ledState ? HIGH : LOW );
    digitalWrite ( plane + 11, HIGH );
}

void LedCube::setPlane ( int plane[3], int ledState[9] )
{
	int io;
	
	for(io = 0; io<3; io++)
	{
		if ( plane[io] < 0 || plane[io] > 2 )
		return;
	}
	
	for ( io = 2; io <= 10; ++io )
		digitalWrite ( io, ledState[io-2] ? HIGH : LOW );
		
	for ( io = 0; io <= 2; ++io )
		digitalWrite ( io + 11, plane[io] ? HIGH : LOW );
}

void LedCube::setAll ()
{
    int io;
    for ( io = 2; io <= 13; ++io )
        digitalWrite ( io, HIGH );
}

void LedCube::resetAll ()
{
    int io;
    for ( io = 2; io <= 13; ++io )
        digitalWrite ( io, LOW );
}

void LedCube::shadowOn(long tempo)
{
	for(int cubePin = 2; cubePin < 14; cubePin++)
	{
		digitalWrite(cubePin, HIGH);
		delay(tempo);
	}
}

void LedCube::shadowOff(long tempo)
{
	for(int cubePin = 2; cubePin < 14; cubePin++)
	{
		digitalWrite(cubePin, LOW);
		delay(tempo);
	}
}

void LedCube::resetTop()
{
	digitalWrite(11, LOW);
}

void LedCube::setTop()
{
	int plan[3] = {1,0,0}; // top , midle, Bottom
	int ledState[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	setPlane(plan, ledState);
}

void LedCube::resetMidle()
{
	digitalWrite(12, LOW);
}

void LedCube::setMidle()
{
	int plan[3] = {0,1,0}; // top , midle, Bottom
	int ledState[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
	setPlane(plan, ledState);
}

void LedCube::resetBottom()
{
	digitalWrite(13, LOW);
}

void LedCube::setBottom()
{
	int plan[3] = {0,0,1}; // top , midle, Bottom
	int ledState[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; 
	setPlane(plan, ledState);
}

void LedCube::setFace1()
{
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int ledState[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0}; 
	setPlane(plan, ledState);
}

void LedCube::setFace2()
{
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int ledState[9] = {1, 0, 0, 1, 0, 0, 1, 0, 0}; 
	setPlane(plan,ledState);
}

void LedCube::setFace3()
{
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int ledState[9] = {0, 0, 0, 0, 0, 0, 1, 1, 1}; 
	setPlane(plan, ledState);
}

void LedCube::setFace4()
{
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int ledState[9] = {0, 0, 1, 0, 0, 1, 0, 0, 1}; 
	setPlane(plan, ledState);
}

void LedCube::setAllFace()
{
	setFace1();
	setFace2();
	setFace3();
	setFace4();
}

void LedCube::blink(long tempo, char blinkNbr)
{
	for(int i = 0; i < blinkNbr; i++)
	{
		setAll();
		delay(tempo);
		resetAll();
		delay(tempo);
	}	
}

void LedCube::circularDemo(long tempo)
{
	int ledState1[8][9] =  {{1, 0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 0, 0, 0, 1, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0, 0}};

	int plane[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

	for(int planeIndex = 0; planeIndex <= 2; planeIndex++)
	{
		for(int ledIndex = 0; ledIndex <= 7; ledIndex++)
		{
			setPlane(plane[planeIndex], ledState1[ledIndex]); delay(tempo);
		}
	}
}

void LedCube::test(long tempo)
{
	setFace1();delay(tempo);
	setFace2();delay(tempo);
	setFace3();delay(tempo);
	setFace4();delay(tempo);
}

void LedCube::rotation(long tempo)
{

	int plane[3] = {1,1,1}; // Bottom, midle, top
	int ledState[4][9] =  {{1, 0, 0, 0, 1, 0, 0, 0, 1},
				{0, 0, 0, 1, 1, 1, 0, 0, 0},
				{0, 0, 1, 0, 1, 0, 1, 0, 0},
				{0, 1, 0, 0, 1, 0, 0, 1, 0}};
	for(int face = 0; face <= 3; face++)
	{
		setPlane(plane, ledState[face]);delay(tempo);
	}
}

void LedCube::effect(long tempo, char nbr)
{
	for(int i =0; i<nbr; i++)
	{
		setTop();delay(tempo);
		setMidle();delay(tempo);
		setBottom();delay(tempo);
		setMidle();delay(tempo);
	}
}