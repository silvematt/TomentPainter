#ifndef DATA_TYPES_H_INCLUDED
#define DATA_TYPES_H_INCLUDED

#include "../include/SDL2/SDL.h"

typedef enum boolean_e
{
    false = 0,
    true = 1
} boolean_t;

typedef struct ColorHSV_s
{
    int h, s, v;
} ColorHSV_t;

typedef struct ColorRGB_s
{
    int r,g,b,a;
} ColorRGB_t;

typedef struct button_s
{
    char* name;
    SDL_Rect box;
    int (*OnClick)(struct button_s* btn);
    int data1;

    boolean_t render;
    char* fileName;
} button_t;

#endif