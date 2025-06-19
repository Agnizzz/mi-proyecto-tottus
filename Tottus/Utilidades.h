#pragma once
#include <windows.h>
#include <iostream>

enum ConsoleColor {
    Black = 0,
    Blue = FOREGROUND_BLUE,
    Green = FOREGROUND_GREEN,
    Cyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
    Red = FOREGROUND_RED,
    Magenta = FOREGROUND_RED | FOREGROUND_BLUE,
    Yellow = FOREGROUND_RED | FOREGROUND_GREEN,
    White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

    Gray = FOREGROUND_INTENSITY,
    LightBlue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LightGreen = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LightCyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LightRed = FOREGROUND_RED | FOREGROUND_INTENSITY,
    LightMagenta = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LightYellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    BrightWhite = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
};

void SetTextColor(ConsoleColor color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        static_cast<WORD>(color));
}

void SetForegroundColor(ConsoleColor color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(h, &csbi);
    WORD bgBits = csbi.wAttributes & (BACKGROUND_BLUE |
        BACKGROUND_GREEN |
        BACKGROUND_RED |
        BACKGROUND_INTENSITY);
    WORD attr = static_cast<WORD>(color) | bgBits;
    SetConsoleTextAttribute(h, attr);
}

void SetBackgroundColor(ConsoleColor color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(h, &csbi);
    WORD attr = csbi.wAttributes;
    WORD fgBits = attr & (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    WORD bgBits = static_cast<WORD>(color) << 4;
    SetConsoleTextAttribute(h, fgBits | bgBits);
}

int GetConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int GetConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void SetCursorVisible(bool visible) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(h, &cursorInfo);
    cursorInfo.bVisible = visible ? TRUE : FALSE;
    SetConsoleCursorInfo(h, &cursorInfo);
}

void SetCursorPosition(int x, int y) {
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetConsoleSize(int cols, int rows) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize;
    bufferSize.X = static_cast<SHORT>(cols);
    bufferSize.Y = static_cast<SHORT>(rows);
    SetConsoleScreenBufferSize(h, bufferSize);
    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = static_cast<SHORT>(cols - 1);
    windowSize.Bottom = static_cast<SHORT>(rows - 1);
    SetConsoleWindowInfo(h, TRUE, &windowSize);
}

void SetConsoleOutputUtf8(bool enable) {
    static UINT originalCP = 0;
    if (enable) {
        if (originalCP == 0) {
            originalCP = GetConsoleOutputCP();
        }
        SetConsoleOutputCP(CP_UTF8);
    }
    else {
        SetConsoleOutputCP(originalCP != 0 ? originalCP : GetACP());
    }
}