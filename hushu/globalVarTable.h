#ifndef GLOBALVARTABLE_H
#define GLOBALVARTABLE_H
#include <stdio.h>
#include "symbol.h"


void A_yly_reset_gbTable();
void A_yly_gb_setVar(FILE* out,char* sym, int value);
int A_yly_gb_getVar(FILE* out,S_symbol sym);

#endif // !GLOBALVARTABLE_H
