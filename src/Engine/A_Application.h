#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

#include <stdio.h>
#include "../include/SDL2/SDL.h"
#include "U_DataTypes.h"

// Drawing + Palette
#define PALETTE_WIDTH 158
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct app_s
{
    SDL_Window* window;
    boolean_t quit;
} app_t;

SDL_Surface* window_surface;
unsigned int * pixels;
int width;
app_t DrawingApp;

boolean_t drawing;
boolean_t altdrawing;
int mx,my; // mouse x,y
int omx, omy; // old mouse x,y
int paletteBrightness;

int bushSize;
int currentMainColor;
int currentAltColor;

SDL_Surface* exportSurface;
SDL_Rect exportRect;

// Palette Buttons
#define PALETTE_BUTTONS_COUNT 14

// 0 = brighthnessSelector;
button_t paletteButtons[PALETTE_BUTTONS_COUNT];


void A_InitTomentPainter(void);
static void A_InitPalette(void);
void A_GameLoop(void);

#endif