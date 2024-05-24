#include "compile_api.hpp"
#include "hushu/globalVarTable.h"
void A_yly_compile(){
  char* inputFileName = "tmp";
  A_yly_expList p = parseExpList(inputFileName);
  // assert(p);
  FILE *fp;
  fp = fopen("exp_result","w"); 
  int hang = 1;
  for (A_yly_expList i = p; i; i=i->tail) {
    fprintf(fp, "===================%d===============\n", hang);
    pr_yly_exp(fp, i->head, 0);
    fprintf(fp, "\n===================%d===============\n", hang++);
  }
  fclose(fp);
  A_yly_reset_gbTable();
  FILE *fp2;
  fp2 = fopen("run_ouput","w"); 
  parseAST(fp2, p);
  fclose(fp2);
}
