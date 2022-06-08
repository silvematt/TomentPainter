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

extern app_t DrawingApp;

extern SDL_Surface* window_surface;    // Surface of the Window
extern unsigned int * pixels;          // Pixels of the surface
extern int width;                      // Surface width

extern boolean_t drawing;              // Are we drawing with the left mouse button?
extern boolean_t altdrawing;           // Are we drawing with the right mouse button?
extern boolean_t floodFillCalled;      // True if user is trying to flood fiil
extern int mx,my;                      // Mouse X and Y
extern int omx, omy;                   // Old MouseX and Old MouseY (pos at previous update)
extern boolean_t mouseOnPalette;       // True if the mouse is on the palette and not the canvas

extern int paletteBrightness;          // The brightness of the color picker
extern int bushSize;                   // Size of the brush
extern int currentMainColor;           // The selected color for LMB
extern int currentAltColor;            // Color for RMB (eraser)

extern SDL_Surface* exportSurface;     // Surface to for exporting only the canvas
extern SDL_Rect exportRect;

//  Flood Fill stack
#define FLOOD_FILL_STACK_SIZE SCREEN_WIDTH*SCREEN_HEIGHT

// Palette Buttons
#define PALETTE_BUTTONS_COUNT 14

// All the buttons
extern button_t paletteButtons[PALETTE_BUTTONS_COUNT];


// -------------------------------
// Initializes the program
// -------------------------------
void A_InitTomentPainter(void);

// -------------------------------
// Initializes the palette (right toolbar)
// -------------------------------
void A_InitPalette(void);

// -------------------------------
// Update
// -------------------------------
void A_GameLoop(void);

#endif