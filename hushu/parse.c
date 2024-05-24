#include "parse.h"

extern int yyparse(void);
extern A_yly_expList y_absyn_root_list;
A_yly_expList parseExpList(char* fname){
  EM_reset(fname);
  if (yyparse() == 0)
    return y_absyn_root_list;
  else return NULL;
}

