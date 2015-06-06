
/*
*
* @file		led-cube.ino
* @brief	Demonstration program on how to enjoy the cube 3*3*3
* @author	Beta-Members :-)
* @date		04 / 06 / 2015
*
*/

// Betat-Machine Library
#include <LedCube.h>

// Instanciate the class LedCube to make an objet cube.
LedCube cube;

/**
* @fn		void setup(void)
* @brief	Init function
*/
void setup(void)
{
	cube.setupIO(); // Init of the Pin connected to the Cube	
}

/**
* @fn		void loop(void)
* @brief	Main function
*/
void loop(void)
{
	while(1)
	{
		for(int i = 0; i<10; i++)
		{
			cube.test(200);
		}
			
		for(int i = 0; i < 10; i++)
		{
			cube.shadowOff(80);
			cube.shadowOn(80);
		}
			
		for(int i = 0; i < 10; i++)
		{
			cube.circularDemo(50);
		}
		for(int i = 0; i < 10; i++)
		{
			cube.rotation(200);
		}
			
		cube.effect(300, 10);
	}
}
