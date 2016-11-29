#ifndef CONSOLECOLOR_H_INCLUDED
#define CONSOLECOLOR_H_INCLUDED

#include <windows.h>

/// ====
/// Defines
/// ====
#define FG_BLUE FOREGROUND_BLUE
#define FG_GREEN FOREGROUND_GREEN
#define FG_RED FOREGROUND_RED
#define FG_INTENSE FOREGROUND_INTENSITY

#define BG_BLUE BACKGROUND_BLUE
#define BG_GREEN BACKGROUND_GREEN
#define BG_RED BACKGROUND_RED
#define BG_INTENSE BACKGROUND_INTENSITY


/// ====
/// Functions
/// ====
void consoleColors_Init();
void consoleColors_RestoreDefault();
void consoleColors_SetColor(int color);


#endif // CONSOLECOLOR_H_INCLUDED