#include <stdio.h>
#include <math.h>

#include "include/SDL2/SDL.h"

#include "Engine/A_Application.h"
#include "Engine/U_DataTypes.h"
#include "Engine/U_Utilities.h"
#include "Engine/R_Rendering.h"
#include "Engine/I_InputHandling.h"

// ------------------------------------------------
//  Source Code 
// ------------------------------------------------
//  A_ [ Application/Implementation Specific]
//  G_ [GUI]
//  I_ [Input/Implementation Specific]
//  R_ [Rendering]
//  U_ [Utilities]
// ------------------------------------------------

int main(int argc, char* argv[])
{
    // Init Application
    A_InitTomentPainter();    

    // Draw Paltte
    R_DrawPalette();

    // GameLoop
    while(DrawingApp.quit == false)
    {
        I_HandleInput();

        A_GameLoop();
        
        // Update Screen
        SDL_UpdateWindowSurface(DrawingApp.window);
    }
}