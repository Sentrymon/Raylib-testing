#include "raylib.h"
#include <unistd.h>
#include <chrono>
#include <float.h>
#include "raymath.h"

#define FLT_DECIMAL_DIG __FLT_DECIMAL_DIG__
#define FLT_STRING_SIZE (1+1+1+(FLT_DECIMAL_DIG-1)+1+1+ 4   +1)






/*
const char * textifyFloat(float input)
{
    char charBuffer[FLT_STRING_SIZE];
    sprintf(charBuffer, "%.*g", FLT_DECIMAL_DIG-1, input);
    return charBuffer;
}
*/