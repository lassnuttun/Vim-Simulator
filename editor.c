#include <stdio.h>
#include "globalVarible.h"
#include "acllib.h"
#include "paint.h"
#include "ctrl.h"

char str[81] = {'\0'};
char _mode[20] = {'\0'};
int id1 = 0;
int mode = UNCHOOSEN;
CARET _caret = {0, 0};
CARET *caret = &_caret;

int Setup()
{
    initWindow("Vim Editor", DEFAULT, DEFAULT, WIDTH, HEIGHT);
    initConsole();
    startMenu();
    registerCharEvent(charListener);
    registerKeyboardEvent(keyListener);
}