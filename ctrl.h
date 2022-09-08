#ifndef _CTRL_H_
#define _CTRL_H_

void charListener(char key);

void keyListener(int key, int event);

void triKeyListener(int key, int event);

void triCharListener(int key);

void vimNormalCharListener(int key);

void vimInsertCharListener(int key);

void vimInsertKeyListener(int key, int event);

void left(int event);

void right(int event);

void insert(char key);

void backspace(int event);

void del(int event);

void esc(int event);

void overtype(char key);

void switchMode(int event);

void finish(int event);

#endif