#ifndef MYREADKEY_H
#define MYREADKEY_H
#include "bigChars.h"
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// F5     F6     UP   DOWN LEFT RIGHT
// \E[15~ \E[17~ \E[A \E[B \E[D \E[C

enum keys
{
    F5 = 10,
    F6,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    OTHER,
    MINUS,
    PLUS
};

int rk_readKey(enum keys *key);
int rk_mytermsave();
int rk_mytermrestore();
int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);

#endif