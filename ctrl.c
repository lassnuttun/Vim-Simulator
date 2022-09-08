#include <stdio.h>
#include <string.h>
#include "globalVarible.h"
#include "acllib.h"
#include "ctrl.h"
#include "paint.h"

#define lenSTR strlen(str)

void charListener(char key)
{
    if (mode == UNCHOOSEN)
    {
        if (key == 'y' || key == 'Y')
        {
            mode = VIM_NORMAL;
            strcpy(_mode, "Vim Normal");
            paint();
        }
        else if (key == 'n' || key == 'N')
        {
            mode = TRI_INSERT;
            strcpy(_mode, "Tridition Insert");
            paint();
        }
    }
    else if (mode == TRI_INSERT || mode == TRI_OVERTYPE)
    {
        triCharListener(key);
        setCaret();
        paint();
    }
    else if (mode == VIM_NORMAL)
    {
        vimNormalCharListener(key);
        setCaret();
        paint();
    }
    else if (mode == VIM_INSERT)
    {
        vimInsertCharListener(key);
        setCaret();
        paint();
    }
}

void keyListener(int key, int event)
{
    // printf("%d %d\n", key, event);
    if (mode == TRI_INSERT || mode == TRI_OVERTYPE)
    {
        triKeyListener(key, event);
        setCaret();
        paint();
    }
    else if (mode == VIM_INSERT)
    {
        vimInsertKeyListener(key, event);
        setCaret();
        paint();
    }
}

void triKeyListener(int key, int event)
{
    switch (key)
    {
    case BACKSPACE_KEY:
        backspace(event);
        break;
    case ENTER_KEY:
        finish(event);
        break;
    case LEFT_KEY:
        left(event);
        break;
    case RIGHT_KEY:
        right(event);
        break;
    case INSERT_KEY:
        switchMode(event);
        break;
    case DELETE_KEY:
        del(event);
        break;
    default:
        break;
    }
}

void triCharListener(int key)
{
    if (lenSTR <= 80 && key >= 32 && key <= 127)
    {
        if (mode == TRI_INSERT)
        {
            insert(key);
        }
        else if (mode == TRI_OVERTYPE)
        {
            overtype(key);
        }
    }
}

void vimNormalCharListener(int key)
{
    switch (key)
    {
    case 'h':
        left(0);
        break;
    case 'l':
        right(0);
        break;
    case '0':
        id1 = 0;
        break;
    case '$':
        id1 = lenSTR;
        break;
    case 'i':
        mode = VIM_INSERT;
        strcpy(_mode, "Vim Insert");
        break;
    case 'I':
        id1 = 0;
        mode = VIM_INSERT;
        strcpy(_mode, "Vim Insert");
        break;
    case 'a':
        right(0);
        mode = VIM_INSERT;
        strcpy(_mode, "Vim Insert");
        break;
    case 'A':
        id1 = lenSTR;
        mode = VIM_INSERT;
        strcpy(_mode, "Vim Insert");
        break;
    case 's':
        backspace(0);
        mode = VIM_INSERT;
        strcpy(_mode, "Vim Insert");
        break;
    case 'S':
        for (int i = 0; i < 81; i++)
        {
            str[i] = '\0';
        }
        id1 = 0;
        mode = VIM_INSERT;
        strcpy(_mode, "Vim Insert");
        break;
    case 'x':
        del(0);
        break;
    case 'd':
        for (int i = 0; i < lenSTR; i++)
        {
            str[i] = '\0';
        }
        id1 = 0;
        break;
    case 'q':
        finish(0);
        paintFinish();
        break;
    default:
        break;
    }
}

void vimInsertCharListener(int key)
{
    if (lenSTR <= 80 && key >= 32 && key <= 127)
    {
        insert(key);
    }
}

void vimInsertKeyListener(int key, int event)
{
    switch (key)
    {
    case BACKSPACE_KEY:
        backspace(event);
        break;
    case ENTER_KEY:
        finish(event);
        break;
    case LEFT_KEY:
        left(event);
        break;
    case RIGHT_KEY:
        right(event);
        break;
    case DELETE_KEY:
        del(event);
        break;
    case ESC_KEY:
        esc(event);
        break;
    default:
        break;
    }
}

void insert(char key)
{
    int i;
    for (i = lenSTR; i >= id1; i--)
    {
        str[i + 1] = str[i];
    }
    str[id1++] = key;
}

void left(int event)
{
    if (!event)
    {
        if (id1 >= 1)
        {
            id1--;
        }
    }
}

void right(int event)
{
    if (!event)
    {
        if (id1 < lenSTR)
        {
            id1++;
        }
    }
}

void backspace(int event)
{
    if (!event)
    {
        if (id1 > 0)
        {
            int i;
            for (i = id1 - 1; i < lenSTR; i++)
            {
                str[i] = str[i + 1];
            }
            id1--;
        }
    }
}

void overtype(char key)
{
    str[id1++] = key;
}

void del(int event)
{
    if (!event)
    {
        if (!event && id1 < lenSTR)
        {
            int i;
            for (i = id1; i < lenSTR; i++)
            {
                str[i] = str[i + 1];
            }
        }
    }
}

void esc(int event)
{
    if (!event)
    {
        left(0);
        mode = VIM_NORMAL;
        strcpy(_mode, "Vim Normal");
        paint();
    }
}

void switchMode(int event)
{
    if (!event)
    {
        if (mode == TRI_INSERT)
        {
            mode = TRI_OVERTYPE;
            strcpy(_mode, "Tridition Overtype");
        }
        else if (mode == TRI_OVERTYPE)
        {
            mode = TRI_INSERT;
            strcpy(_mode, "Tridition Insert");
        }
    }
}

void finish(int event)
{
    if (!event)
    {
        printf("%s\n", str);
    }
}