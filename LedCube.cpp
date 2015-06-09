#include "Arduino.h"
#include "LedCube.h"

void
LedCube::
setupIO ()
{
    int io;
    for ( io = 2; io <= 13; ++io )
    {
        pinMode ( io, OUTPUT );
        digitalWrite ( io, LOW );
    }
}

void
LedCube::
setLed ( int led, bool state )
{
    if ( led < 0 || led > 8 )
        return;

    digitalWrite ( led + 2, state ? HIGH : LOW );
}

void
LedCube::
setPlane ( int plane, int state[9] )
{
    int io;

    if ( plane < 0 || plane > 2 )
        return;

    for ( io = 2; io <= 10; ++io )
        digitalWrite ( io, state[io-2] ? HIGH : LOW );

    for ( io = 11; io <= 13; ++io )
        digitalWrite ( io, plane + 11 == io ? HIGH : LOW );
}

void
LedCube::
setAll ()
{
    int io;
    for ( io = 2; io <= 13; ++io )
        digitalWrite ( io, HIGH );
}

void
LedCube::
resetAll ()
{
    int io;
    for ( io = 2; io <= 13; ++io )
        digitalWrite ( io, LOW );
}

void 
LedCube::
setOn(void)
{
	for(int cubePin = 2; cubePin < 14; cubePin++)
	{
		digitalWrite(cubePin, HIGH);
	}
}
	
void
LedCube::
setOff(void)
{
	for(int cubePin = 2; cubePin < 14; cubePin++)
	{
		digitalWrite(cubePin, LOW);
	}
}

void
LedCube::
shadowOn(long tempo)
{
	for(int cubePin = 2; cubePin < 14; cubePin++)
	{
		digitalWrite(cubePin, HIGH);
		delay(tempo);
	}
}
	
void
LedCube::
shadowOff(long tempo)
{
	for(int cubePin = 2; cubePin < 14; cubePin++)
	{
		digitalWrite(cubePin, LOW);
		delay(tempo);
	}
}

void
LedCube::
lineWrite( int lineState[9])
{
	for(int line = 0; line <= 8; line++)
	{
		digitalWrite(line + 2, lineState[line]);
	}
}

void
LedCube::
layerWrite(int layerState[3])
{
	for(int layer = 0; layer <= 2; layer++)
	{
		digitalWrite(layer+11, layerState[layer]);
	}
}


void
LedCube::
setTopOff(void)
{
	digitalWrite(PLAN2, LOW);
}
	

void
LedCube::
setTopOn(void)
{
	int plan[3] = {1,0,0}; // top , midle, Bottom
	int lineState[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; 
	layerWrite(plan);
	lineWrite(lineState);
}
	
void
LedCube::
setMidleOff(void)
{
	digitalWrite(PLAN1, LOW);
}

void
LedCube::
setMidleOn(void)
{
	int plan[3] = {0,1,0}; // top , midle, Bottom
	int lineState[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; 
	layerWrite(plan);
	lineWrite(lineState);
}

void
LedCube::
setBottomOff(void)
{
	digitalWrite(PLAN0, LOW);
}
	
void
LedCube::
setBottomOn(void)
{
	int plan[3] = {0,0,1}; // top , midle, Bottom
	int lineState[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1}; 
	layerWrite(plan);
	lineWrite(lineState);
}
	
void
LedCube::
blink(long tempo, char blinkNbr)
{
	for(int i = 0; i < blinkNbr; i++)
	{
		setOn();
		delay(tempo);
		setOff();
		delay(tempo);
	}	
}

void
LedCube::
circularDemo(long tempo)
{
	int lineState1[9] = {1, 0, 0, 0, 0, 0, 0, 0, 0};
	int lineState2[9] = {0, 1, 0, 0, 0, 0, 0, 0, 0};
	int lineState3[9] = {0, 0, 1, 0, 0, 0, 0, 0, 0};
	int lineState4[9] = {0, 0, 0, 0, 0, 1, 0, 0, 0};
	int lineState5[9] = {0, 0, 0, 0, 0, 0, 0, 0, 1};
	int lineState6[9] = {0, 0, 0, 0, 0, 0, 0, 1, 0};
	int lineState7[9] = {0, 0, 0, 0, 0, 0, 1, 0, 0};
	int lineState8[9] = {0, 0, 0, 1, 0, 0, 0, 0, 0};
		
	for(int i=0; i<3; i++)
	{
		if(i == 0)
		{
			int plan[3] = {1,0,0};
			layerWrite(plan);
		}
		
		if(i == 1)
		{
			int plan[3] = {0,1,0};
			layerWrite(plan);
		}
			
		if(i == 2)
		{
			int plan[3] = {0,0,1};
			layerWrite(plan);
		}
			
		lineWrite(lineState1);delay(tempo);
		lineWrite(lineState2);delay(tempo);
		lineWrite(lineState3);delay(tempo);
		lineWrite(lineState4);delay(tempo);
		lineWrite(lineState5);delay(tempo);
		lineWrite(lineState6);delay(tempo);
		lineWrite(lineState7);delay(tempo);
		lineWrite(lineState8);delay(tempo);
	}
}

void
LedCube::
setFace1On(void)
{
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int lineState[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0}; 
	layerWrite(plan);
	lineWrite(lineState);
}

void
LedCube::
setFace2On(void)
{
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int lineState[9] = {1, 0, 0, 1, 0, 0, 1, 0, 0}; 
	layerWrite(plan);
	lineWrite(lineState);
}

void
LedCube::
setFace3On(void)
{
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int lineState[9] = {0, 0, 0, 0, 0, 0, 1, 1, 1}; 
	layerWrite(plan);
	lineWrite(lineState);
}

void
LedCube::
setFace4On(void)
{
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int lineState[9] = {0, 0, 1, 0, 0, 1, 0, 0, 1}; 
	layerWrite(plan);
	lineWrite(lineState);
}
	
void 
LedCube::
setAllFaceOn(void)
{
	setFace1On();
	setFace2On();
	setFace3On();
	setFace4On();
}

void
LedCube::
test(long tempo)
{
	setFace1On();delay(tempo);
	setFace2On();delay(tempo);
	setFace3On();delay(tempo);
	setFace4On();delay(tempo);
}

void 
LedCube::
rotation(long tempo)
{
	int plan[3] = {1,1,1}; // Bottom, midle, top
	int lineState1[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	int lineState2[9] = {0, 0, 0, 1, 1, 1, 0, 0, 0};
	int lineState3[9] = {0, 0, 1, 0, 1, 0, 1, 0, 0};
	int lineState4[9] = {0, 1, 0, 0, 1, 0, 0, 1, 0};
		
	layerWrite(plan);
	lineWrite(lineState1);delay(tempo);
	lineWrite(lineState2);delay(tempo);
	lineWrite(lineState3);delay(tempo);
	lineWrite(lineState4);delay(tempo);
}

void 
LedCube::
effect(long tempo, char nbr)
{
	for(int i =0; i<nbr; i++)
	{
		setTopOn();delay(tempo);
		setMidleOn();delay(tempo);
		setBottomOn();delay(tempo);
		setMidleOn();delay(tempo);
	}
}
