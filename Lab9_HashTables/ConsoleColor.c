//#define NDEBUG
#include <windows.h>
#include <stdio.h>
#include "ConsoleColor.h"


/// ====
/// Defines
/// ====


/// ====
/// Prototypes
/// ====


/// ====
/// Locals
///
HANDLE hConsole;
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;

int isInited = 0;

/// ====
/// Functions
/// ====

void consoleColors_Init()
{
    if (isInited != 0)
    {
        return;
    }
    
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    isInited++;
}

void consoleColors_RestoreDefault()
{
    if (isInited == 0)
    {
        consoleColors_Init();
    }
    
    SetConsoleTextAttribute(hConsole, saved_attributes);
}

void consoleColors_SetColor(int color)
{
    if (isInited == 0)
    {
        consoleColors_Init();
    }
    
    // set color
    SetConsoleTextAttribute(hConsole, color);
}

