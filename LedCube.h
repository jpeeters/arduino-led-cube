#ifndef LEDCUBE_INCLUDED
#define LEDCUBE_INCLUDED

class LedCube
{
public:

    void setupIO ();

    void setLed ( int led, bool state );

    void setPlane ( int plane, int state[9] );

    void setAll ();
    void resetAll ();
};

#endif
