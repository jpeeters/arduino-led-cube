#ifndef LEDCUBE_INCLUDED
#define LEDCUBE_INCLUDED

//=====================================================================================
//	Branchement du Cube a l'Arduino Uno
//=====================================================================================
/*
	#define PLAN0  13
	#define PLAN1  12
	#define PLAN2  11

	#define LED_0  2
	#define LED_1  3
	#define LED_2  4
	#define LED_3  5
	#define LED_4  6
	#define LED_5  7
	#define LED_6  8
	#define LED_7  9
	#define LED_8  10
*/
	
class LedCube
{
	public:

		void setupIO ();

		void setLed ( int led, bool ledState, int plane);

		void setPlane ( int plane[3], int ledState[9] );

		void setAll ();

		void resetAll ();

		void shadowOn(long tempo);

		void shadowOff(long tempo);

		void resetTop();

		void setTop();

		void resetMidle();

		void setMidle();

		void resetBottom();

		void setBottom();
		
		void setFace1();

		void setFace2();

		void setFace3();

		void setFace4();

		void setAllFace();

		void blink(long tempo, char blinkNbr);

		void circularDemo(long tempo);

		void test(long tempo);

		void rotation(long tempo);

		void effect(long tempo, char nbr);
};

#endif
