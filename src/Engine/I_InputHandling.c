#include "I_InputHandling.h"
#include "A_Application.h"
#include "R_Rendering.h"
#include "U_Utilities.h"
#include "G_GUIButtons.h"


// -------------------------------
// Handles SDL Events and input
// -------------------------------
void I_HandleInput(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
                DrawingApp.quit = true;
				exit(0);
            break;

            // Get Mouse Pos
            case SDL_MOUSEBUTTONDOWN:
                
                if(event.button.button == SDL_BUTTON_LEFT)
                    drawing = true;
                else
                    altdrawing = true;

                    // Get latest mouse
                    omx = mx;
                    omy = my;

                    SDL_GetMouseState(&mx,&my);
            break;

            case SDL_MOUSEBUTTONUP:
                if(event.button.button == SDL_BUTTON_LEFT)
                    drawing = false;
                else
                    altdrawing = false;
            break;

            case SDL_KEYDOWN:
                switch( event .key.keysym.sym )
                {
                    case SDLK_c:
                    R_ClearCanvas();
                    break;

                    case SDLK_1:
                        bushSize = 1;
                        printf("Bush Size: 1\n");
                    break;

                    case SDLK_2:
                        bushSize = 2;
                        printf("Bush Size: 2\n");
                    break;

                    case SDLK_3:
                        bushSize = 3;
                        printf("Bush Size: 3\n");
                    break;

                    case SDLK_4:
                        bushSize = 4;
                        printf("Bush Size: 4\n");
                    break;

                    case SDLK_5:
                        bushSize = 5;
                        printf("Bush Size: 5\n");
                    break;

                    case SDLK_6:
                        bushSize = 6;
                        printf("Bush Size: 6\n");
                    break;

                    case SDLK_7:
                        bushSize = 7;
                        printf("Bush Size: 7\n");
                    break;

                    case SDLK_8:
                        bushSize = 8;
                        printf("Bush Size: 8\n");
                    break;

                    case SDLK_9:
                        bushSize = 9;
                        printf("Bush Size: 9\n");
                    break;

                    case SDLK_0:
                        bushSize = 10;
                        printf("Bush Size: 10\n");
                    break;

                    case SDLK_e:
                        G_SaveButtonOnClick(NULL);
                    break;

                    case SDLK_f:
                        floodFillCalled = true;
                    break;
                }
            break;

			default:
				break;
		}

        // Handle 
        I_HandleGUI(event);
	}

    // Save old mouse pos
    omx = mx;
    omy = my;

    // Get new pos and clamp values
    SDL_GetMouseState(&mx,&my);

    // Clamp coordinates to screen
    mx = CLAMP(mx, 0, SCREEN_WIDTH + PALETTE_WIDTH);
    my = CLAMP(my, 0, SCREEN_HEIGHT-1);

    omx = CLAMP(omx, 0, SCREEN_WIDTH + PALETTE_WIDTH);
    omy = CLAMP(omy, 0, SCREEN_HEIGHT-1);

}

// -------------------------------
// Callbacks for GUIButtons
// -------------------------------
void I_HandleGUI(SDL_Event event)
{
    if(mouseOnPalette == false)
        return;

    // Offset mouse pos
    static int x = 0;
    static int y = 0;

    // For each buttons
    for(int i = 0; i < PALETTE_BUTTONS_COUNT; i++)
    {
        // If there's a click
        if( event.type == SDL_MOUSEBUTTONDOWN )
        {
            //If the left mouse button was pressed
            if( event.button.button == SDL_BUTTON_LEFT )
            {
                //Get the mouse offsets
                x = event.button.x;
                y = event.button.y;

                //If the mouse is over the button
                if( ( x > paletteButtons[i].box.x ) && ( x < paletteButtons[i].box.x + paletteButtons[i].box.w ) && 
                    ( y > paletteButtons[i].box.y ) && ( y < paletteButtons[i].box.y + paletteButtons[i].box.h ) )                
                {
                    // Callback
                    paletteButtons[i].OnClick(&paletteButtons[i]);
                }
            }
        }
    }
}