#ifndef _GLOBAL_VARIBLE_
#define _GLOBAL_VARIBLE_

#define WIDTH 1200
#define HEIGHT 200

#define CARET_HGHT 30
#define CARET_WID1 1
#define CARET_WID2 14
#define CARET_WID (mode == TRI_INSERT || mode == VIM_NORMAL || mode == VIM_INSERT || mode == VIM_VISUAL ? CARET_WID1 : CARET_WID2)

#define UNCHOOSEN -1
#define TRI_INSERT 0
#define TRI_OVERTYPE 1
#define VIM_NORMAL 2
#define VIM_INSERT 3
#define VIM_VISUAL 4

#define BACKSPACE_KEY 8
#define ENTER_KEY 13
#define ESC_KEY 27
#define LEFT_KEY 37
#define RIGHT_KEY 39
#define INSERT_KEY 45
#define DELETE_KEY 46

extern char str[81];
extern char _mode[20];

extern int id1;

typedef struct _Caret
{
    int x;
    int y;
} CARET;

extern CARET *caret;

extern int mode;

#endif