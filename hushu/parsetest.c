#include "parse.h"
#include "errormsg.h"
#include <stdio.h>
#include "prabsyn.h"
#include "symbol.h"
#include "parseAST.h"

extern int yyparse(void);

// void parse(string fname)
//{EM_reset(fname);
//  if (yyparse() == 0) /* parsing worked */
//    fprintf(stderr,"Parsing successful!\n");
//  else fprintf(stderr,"Parsing failed\n");
// }

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: a.out filename\n");
    exit(1);
  }
  char* inputFileName = "";
  A_yly_expList p = parseExpList(argv[1]);
  assert(p);
  FILE *fp;
  fp = fopen("exp_result","w"); 
  int hang = 1;
  for (A_yly_expList i = p; i; i=i->tail) {
    fprintf(fp, "===================%d===============\n", hang);
    pr_yly_exp(fp, i->head, 0);
    fprintf(fp, "\n===================%d===============\n", hang++);
  }
  fclose(fp);
  FILE *fp2;
  fp2 = fopen("out_result","w"); 
  parseAST(fp2,p);
  return 0;
}
