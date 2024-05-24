#ifndef __ERRORMSG_H
#define __ERRORMSG_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "util.h"

extern char EM_anyErrors;

void EM_newline(void);

extern int EM_tokPos;

void EM_error(int, string,...);
void EM_impossible(string,...);
void EM_reset(string filename);

#endif // !__ERRORMSG_H
