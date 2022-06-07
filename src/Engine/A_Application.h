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

app_t DrawingApp;

SDL_Surface* window_surface;    // Surface of the Window
unsigned int * pixels;          // Pixels of the surface
int width;                      // Surface width

boolean_t drawing;              // Are we drawing with the left mouse button?
boolean_t altdrawing;           // Are we drawing with the right mouse button?
int mx,my;                      // Mouse X and Y
int omx, omy;                   // Old MouseX and Old MouseY (pos at previous update)
boolean_t mouseOnPalette;       // True if the mouse is on the palette and not the canvas

int paletteBrightness;          // The brightness of the color picker
int bushSize;                   // Size of the brush
int currentMainColor;           // The selected color for LMB
int currentAltColor;            // Color for RMB (eraser)

SDL_Surface* exportSurface;     // Surface to for exporting only the canvas
SDL_Rect exportRect;

// Palette Buttons
#define PALETTE_BUTTONS_COUNT 14

// All the buttons
button_t paletteButtons[PALETTE_BUTTONS_COUNT];


// -------------------------------
// Initializes the program
// -------------------------------
void A_InitTomentPainter(void);

// -------------------------------
// Initializes the palette (right toolbar)
// -------------------------------
static void A_InitPalette(void);

// -------------------------------
// Update
// -------------------------------
void A_GameLoop(void);

#endif