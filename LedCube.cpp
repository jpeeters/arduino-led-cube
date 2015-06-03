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
