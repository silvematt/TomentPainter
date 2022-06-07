#ifndef INPUT_HANDLING_H_INCLUDED
#define INPUT_HANDLING_H_INCLUDED

#include "../include/SDL2/SDL.h"

// -------------------------------
// Handles SDL Events and input
// -------------------------------
void I_HandleInput(void);

// -------------------------------
// Checks for GUIButtons
// -------------------------------
void I_HandleGUI(SDL_Event event);
#endif