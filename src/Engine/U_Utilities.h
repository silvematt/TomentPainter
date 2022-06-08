#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "../include/SDL2/SDL.h"

#define CLAMP(v, min, max)  (v < min) ? min : (v > max) ? max : v

// ----------------------------------------------------
// Sets an SDL Rect
// ----------------------------------------------------
void SDL_Rect_Set(SDL_Rect* r, int x, int y, int w, int h);

// ----------------------------------------------------
// Flood Fill Stack Operations
// ----------------------------------------------------
void FF_StackPush(transform2d_t* stack, int x, int y, int* top);
transform2d_t FF_StackPop(transform2d_t* stack, int* top);

#endif