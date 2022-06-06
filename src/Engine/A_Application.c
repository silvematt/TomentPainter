#include "A_Application.h"
#include "U_Utilities.h"
#include "R_Rendering.h"
#include "G_GUIButtons.h"

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

    A_InitPalette();
}

static void A_InitPalette(void)
{
    paletteBrightness = 128;
    bushSize = 5;

    paletteButtons[0].name = "BrightnessSelector";
    paletteButtons[0].box.x = 775;
    paletteButtons[0].box.y = 10;
    paletteButtons[0].box.w = 16;
    paletteButtons[0].box.h = 64;
    paletteButtons[0].OnClick = G_BrightnessButtonOnClick;

    paletteButtons[1].name = "ColorPicker";
    paletteButtons[1].box.x = 647;
    paletteButtons[1].box.y = 10;
    paletteButtons[1].box.w = 128;
    paletteButtons[1].box.h = 64;
    paletteButtons[1].OnClick = G_ColorPickerOnClick;
}

void A_GameLoop(void)
{
    //printf("%d\n", my);

    // In canvas
    if(mx <= SCREEN_WIDTH) 
    {
        if(drawing || altdrawing)
        {
            R_DrawFixed(omx, omy, mx, my);
        }
    }
    else // In toolbar
    {
        //printf("TOOLBAR ");
    }
}