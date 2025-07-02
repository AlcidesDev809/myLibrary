#ifndef CURSOR_H
#define CURSOR_H

typedef struct {
    int x;
    int y;
    _Bool visible;
} Cursor;

void setCursor(Cursor *cursor);
void getCursor(Cursor *cursor);

#endif