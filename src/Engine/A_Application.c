#include "A_Application.h"
#include "U_Utilities.h"
#include "R_Rendering.h"
#include "G_GUIButtons.h"

// --------------------------------------------
// Definition of Globals
// --------------------------------------------
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

button_t paletteButtons[PALETTE_BUTTONS_COUNT];

// --------------------------------------------
// Initializes the program
// --------------------------------------------
void A_InitTomentPainter(void)
{
    DrawingApp.quit = false;
    
    SDL_Init(SDL_INIT_EVERYTHING);

    printf("Booting up...\n");
    printf("Resolution: %dx%d\n\n", SCREEN_WIDTH, SCREEN_HEIGHT);

    DrawingApp.window = SDL_CreateWindow("Toment Painter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH + PALETTE_WIDTH, SCREEN_HEIGHT, 0);

    window_surface = SDL_GetWindowSurface(DrawingApp.window);

    pixels = window_surface->pixels;
    width = window_surface->w;

    for(int y = 0; y < 480; y++)
        for(int x = 0; x < 680; x++)
            pixels[x + y * width] = SDL_MapRGBA(window_surface->format, 0,0,0, 255);

    A_InitPalette();
}


// --------------------------------------------
// Initializes the palette
// --------------------------------------------
static void A_InitPalette(void)
{
    // Set defaults
    currentMainColor = SDL_MapRGBA(window_surface->format, 255, 255, 255, 255);
    currentAltColor = SDL_MapRGBA(window_surface->format, 0,0,0, 255);

    paletteBrightness = 256;
    bushSize = 1;
    printf("Bush Size: 1\n");


    // Create and configure buttons
    paletteButtons[0].name = "BrightnessSelector";
    paletteButtons[0].box.x = 775;
    paletteButtons[0].box.y = 10;
    paletteButtons[0].box.w = 16;
    paletteButtons[0].box.h = 64;
    paletteButtons[0].OnClick = G_BrightnessButtonOnClick;
    paletteButtons[0].render = false;

    paletteButtons[1].name = "ColorPicker";
    paletteButtons[1].box.x = 647;
    paletteButtons[1].box.y = 10;
    paletteButtons[1].box.w = 128;
    paletteButtons[1].box.h = 64;
    paletteButtons[1].OnClick = G_ColorPickerOnClick;
    paletteButtons[1].render = false;

    paletteButtons[2].name = "SaveButton";
    paletteButtons[2].box.x = SCREEN_WIDTH + (PALETTE_WIDTH / 2) - 25;
    paletteButtons[2].box.y = 400;
    paletteButtons[2].box.w = 50;
    paletteButtons[2].box.h = 50;
    paletteButtons[2].OnClick = G_SaveButtonOnClick;
    paletteButtons[2].render = true;
    paletteButtons[2].fileName = "Data/floppy.bmp";

    // Bush Sizes 1
    paletteButtons[3].name = "BushSize1";
    paletteButtons[3].box.x = SCREEN_WIDTH + 5;
    paletteButtons[3].box.y = 250;
    paletteButtons[3].box.w = 25;
    paletteButtons[3].box.h = 25;
    paletteButtons[3].OnClick = G_SetBushSize;
    paletteButtons[3].data1 = 1;
    paletteButtons[3].render = true;
    paletteButtons[3].fileName = "Data/bs1.bmp";

    // Bush Sizes 2
    paletteButtons[4].name = "BushSize2";
    paletteButtons[4].box.x = SCREEN_WIDTH + 35;
    paletteButtons[4].box.y = 250;
    paletteButtons[4].box.w = 25;
    paletteButtons[4].box.h = 25;
    paletteButtons[4].OnClick = G_SetBushSize;
    paletteButtons[4].data1 = 2;
    paletteButtons[4].render = true;
    paletteButtons[4].fileName = "Data/bs2.bmp";

    // Bush Sizes 3
    paletteButtons[5].name = "BushSize3";
    paletteButtons[5].box.x = SCREEN_WIDTH + 65;
    paletteButtons[5].box.y = 250;
    paletteButtons[5].box.w = 25;
    paletteButtons[5].box.h = 25;
    paletteButtons[5].OnClick = G_SetBushSize;
    paletteButtons[5].data1 = 3;
    paletteButtons[5].render = true;
    paletteButtons[5].fileName = "Data/bs3.bmp";

    // Bush Sizes 4
    paletteButtons[6].name = "BushSize4";
    paletteButtons[6].box.x = SCREEN_WIDTH + 95;
    paletteButtons[6].box.y = 250;
    paletteButtons[6].box.w = 25;
    paletteButtons[6].box.h = 25;
    paletteButtons[6].OnClick = G_SetBushSize;
    paletteButtons[6].data1 = 4;
    paletteButtons[6].render = true;
    paletteButtons[6].fileName = "Data/bs4.bmp";

    // Bush Sizes 5
    paletteButtons[7].name = "BushSize5";
    paletteButtons[7].box.x = SCREEN_WIDTH + 125;
    paletteButtons[7].box.y = 250;
    paletteButtons[7].box.w = 25;
    paletteButtons[7].box.h = 25;
    paletteButtons[7].OnClick = G_SetBushSize;
    paletteButtons[7].data1 = 5;
    paletteButtons[7].render = true;
    paletteButtons[7].fileName = "Data/bs5.bmp";

    // Bush Sizes 6
    paletteButtons[8].name = "BushSize6";
    paletteButtons[8].box.x = SCREEN_WIDTH + 5;
    paletteButtons[8].box.y = 295;
    paletteButtons[8].box.w = 25;
    paletteButtons[8].box.h = 25;
    paletteButtons[8].OnClick = G_SetBushSize;
    paletteButtons[8].data1 = 6;
    paletteButtons[8].render = true;
    paletteButtons[8].fileName = "Data/bs6.bmp";

    // Bush Sizes 7
    paletteButtons[9].name = "BushSize7";
    paletteButtons[9].box.x = SCREEN_WIDTH + 35;
    paletteButtons[9].box.y = 295;
    paletteButtons[9].box.w = 25;
    paletteButtons[9].box.h = 25;
    paletteButtons[9].OnClick = G_SetBushSize;
    paletteButtons[9].data1 = 7;
    paletteButtons[9].render = true;
    paletteButtons[9].fileName = "Data/bs7.bmp";

    // Bush Sizes 8
    paletteButtons[10].name = "BushSize8";
    paletteButtons[10].box.x = SCREEN_WIDTH + 65;
    paletteButtons[10].box.y = 295;
    paletteButtons[10].box.w = 25;
    paletteButtons[10].box.h = 25;
    paletteButtons[10].OnClick = G_SetBushSize;
    paletteButtons[10].data1 = 8;
    paletteButtons[10].render = true;
    paletteButtons[10].fileName = "Data/bs7.bmp";
    
    // Bush Sizes 9
    paletteButtons[11].name = "BushSize9";
    paletteButtons[11].box.x = SCREEN_WIDTH + 95;
    paletteButtons[11].box.y = 295;
    paletteButtons[11].box.w = 25;
    paletteButtons[11].box.h = 25;
    paletteButtons[11].OnClick = G_SetBushSize;
    paletteButtons[11].data1 = 9;
    paletteButtons[11].render = true;
    paletteButtons[11].fileName = "Data/bs8.bmp";

    // Bush Sizes 8
    paletteButtons[12].name = "BushSize10";
    paletteButtons[12].box.x = SCREEN_WIDTH + 125;
    paletteButtons[12].box.y = 295;
    paletteButtons[12].box.w = 25;
    paletteButtons[12].box.h = 25;
    paletteButtons[12].OnClick = G_SetBushSize;
    paletteButtons[12].data1 = 10;
    paletteButtons[12].render = true;
    paletteButtons[12].fileName = "Data/bs8.bmp";

    // Clear Screen
    paletteButtons[13].name = "Cls";
    paletteButtons[13].box.x = SCREEN_WIDTH + 52;
    paletteButtons[13].box.y = 190;
    paletteButtons[13].box.w = 50;
    paletteButtons[13].box.h = 25;
    paletteButtons[13].OnClick = G_ClearScreen;
    paletteButtons[13].render = true;
    paletteButtons[13].fileName = "Data/cls.bmp";

}


// --------------------------------------------
// Update
// --------------------------------------------
void A_GameLoop(void)
{
    // In canvas
    if(mx <= SCREEN_WIDTH) 
    {
        mouseOnPalette = false;

        if(drawing || altdrawing)
        {
            R_Paint(omx, omy, mx, my);
        }
    }
    else // In toolbar
    {
        mouseOnPalette = true;
    }
}