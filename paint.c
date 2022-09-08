#include <stdio.h>
#include <acllib.h>
#include <string.h>
#include "globalVarible.h"
#include "paint.h"

void paint()
{
    beginPaint();
    clearDevice();
    setTextFont("Consolas");
    setTextSize(CARET_HGHT);
    paintText(0, 0, str);
    paintText(WIDTH - strlen(_mode) * CARET_WID2, HEIGHT - CARET_HGHT, _mode);
    endPaint();
}

void startMenu()
{
    beginPaint();
    setTextFont("Consolas");
    setTextSize(CARET_HGHT);
    paintText(0, 0, "Would you like to edit with Vim? Enter [Y/n]");
    endPaint();
}

void setCaret()
{
    caret->x = id1 * CARET_WID2;
    setCaretPos(caret->x, caret->y);
    setCaretSize(CARET_WID, CARET_HGHT);
    showCaret();
}

void paintFinish()
{
    beginPaint();
    clearDevice();
    hideCaret();
    paintText(0, 0, "Editing finished! Check your outputs!");
    endPaint();
}