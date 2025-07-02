#include <windows.h>

#include "cursor.h"

void setCursor(Cursor *cursor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = cursor->visible;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    if (cursor->x > 0 && cursor->y > 0)
    {
        COORD pos;
        pos.X = cursor->x - 1;
        pos.Y = cursor->y - 1;
        SetConsoleCursorPosition(hConsole, pos);
    }
}

void getCursor(Cursor *cursor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hConsole, &csbi))
    {
        cursor->x = csbi.dwCursorPosition.X + 1;
        cursor->y = csbi.dwCursorPosition.Y + 1;
    }
    else
    {
        cursor->x = -1;
        cursor->y = -1;
    }
}