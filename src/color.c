#include <windows.h>

#define GREEN_BG  "\033[42m"

void colored_window(void){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD topLeft = {0, 0};
    DWORD charsWritten;

    WORD color = BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    FillConsoleOutputAttribute(hConsole, color, consoleSize, topLeft, &charsWritten);
    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &charsWritten);
    SetConsoleTextAttribute(hConsole, color);
}