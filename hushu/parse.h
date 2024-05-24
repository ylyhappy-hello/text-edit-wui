#ifndef __PARSE_H
#define __PARSE_H


#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "absyn.h"
#include "errormsg.h"

/* function prototype from parse.c */
A_yly_exp parse(char* fname);
A_yly_expList parseExpList(char* fname);

#endif // !__PARSE_H
