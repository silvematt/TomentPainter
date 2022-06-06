#include <stdio.h>
#include <math.h>

#include "include/SDL2/SDL.h"

#include "Engine/A_Application.h"
#include "Engine/U_DataTypes.h"
#include "Engine/U_Utilities.h"
#include "Engine/R_Rendering.h"
#include "Engine/I_InputHandling.h"

int main(int argc, char* argv[])
{
    A_InitTomentPainter();    

    // Draw Paltte
    R_DrawPalette();

    // Run
    while(DrawingApp.quit == false)
    {
        I_HandleInput();

        A_GameLoop();
        
        SDL_UpdateWindowSurface(DrawingApp.window);
    }
}