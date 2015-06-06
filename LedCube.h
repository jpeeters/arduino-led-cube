#ifndef LEDCUBE_INCLUDED
#define LEDCUBE_INCLUDED

//=====================================================================================
//	Branchement du Cube a l'Arduino Uno
//=====================================================================================
	#define PLAN0  13
	#define PLAN1  12
	#define PLAN2  11

	#define LINE_0  2
	#define LINE_1  3
	#define LINE_2  4
	#define LINE_3  5
	#define LINE_4  6
	#define LINE_5  7
	#define LINE_6  8
	#define LINE_7  9
	#define LINE_8  10

class LedCube
{
public:

    void setupIO ();

    void setLed ( int led, bool state );

    void setPlane ( int plane, int state[9] );

    void setAll ();
    void resetAll ();
	
// Fonctions rajoutees par theo
	void setOn(void);
	void setOff(void);
	void shadowOn(long tempo);
	void shadowOff(long tempo);
	void lineWrite( int lineState[9]);
	void layerWrite(int layerState[3]);
	void setTopOff(void);
	void setTopOn(void);
	void setMidleOff(void);
	void setMidleOn(void);
	void setBottomOff(void);
	void setBottomOn(void);
	void blink(long tempo, char blinkNbr);
	void circularDemo(long tempo);
	void setFace1On(void);
	void setFace2On(void);
	void setFace3On(void);
	void setFace4On(void);
	void setAllFaceOn(void);
	void test(long tempo);
	void rotation(long tempo);
	void effect(long tempo, char nbr);
};

#endif
