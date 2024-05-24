#ifndef __UTIL_H
#define __UTIL_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *string;

#define TRUE 1
#define FALSE 0

void *checked_malloc(int);
string String(char *);

typedef struct U_boolList_ *U_boolList;
struct U_boolList_ {char head; U_boolList tail;};
U_boolList U_BoolList(char head, U_boolList tail);


#endif
