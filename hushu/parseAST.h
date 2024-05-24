#ifndef PARSEAST
#define PARSEAST
#include "globalVarTable.h"
#include "absyn.h"
#include "parse.h"
#include <assert.h>
#include <stdio.h>

void parseAST(FILE *out,A_yly_expList expListRoot);

#endif // !PARSEAST
