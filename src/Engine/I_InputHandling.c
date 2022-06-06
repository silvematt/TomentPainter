#include "I_InputHandling.h"
#include "A_Application.h"
#include "R_Rendering.h"
#include "U_Utilities.h"

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

                    SDL_GetMouseState(&mx,&my);
                    omx = mx;
                    omy = my;
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
                }
            break;

			default:
				break;
		}

        I_HandleGUI(event);
	}

    // Save old mouse pos
    omx = mx;
    omy = my;

    // Get new pos and clamp values
    SDL_GetMouseState(&mx,&my);

    mx = CLAMP(mx, 0, SCREEN_WIDTH + PALETTE_WIDTH);
    my = CLAMP(my, 0, SCREEN_HEIGHT-1);

    omx = CLAMP(omx, 0, SCREEN_WIDTH + PALETTE_WIDTH);
    omy = CLAMP(omy, 0, SCREEN_HEIGHT-1);

}

void I_HandleGUI(SDL_Event event)
{
    // Offset mouse pos
    static int x = 0;
    static int y = 0;

    for(int i = 0; i < PALETTE_BUTTONS_COUNT; i++)
    {
        if( event.type == SDL_MOUSEBUTTONDOWN )
        {
            //If the left mouse button was pressed
            if( event.button.button == SDL_BUTTON_LEFT )
            {
                //Get the mouse offsets
                x = event.button.x;
                y = event.button.y;
                printf("hardskool %d | %d \n", paletteButtons[i].box.x, paletteButtons[i].box.y);
                printf("hardskool %d | %d \n", paletteButtons[i].box.w, paletteButtons[i].box.h);

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