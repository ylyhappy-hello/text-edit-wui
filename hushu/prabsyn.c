/*
 * prabsyn.c - Print Abstract Syntax data structures. Most functions
 *           handle an instance of an abstract syntax rule.
 */
#include "prabsyn.h"
#include "absyn.h"
#include <assert.h>
#include <stdio.h>

/* local function prototypes */
static void pr_yly_var(FILE *out, A_yly_var v, int d);

static void indent(FILE *out, int d) {
  int i;
  for (i = 0; i <= d; i++)
    fprintf(out, " ");
}

static char str_oper[][10] = {"PLUS",  "MINUS",    "TIMES",    "DIVIDE"};

static void pr_yly_oper(FILE *out, A_yly_oper d) { fprintf(out, "%s", str_oper[d]); }

/* Print A_var types. Indent d spaces. */
static void pr_yly_var(FILE *out, A_yly_var v, int d) {
  indent(out, d);
  switch (v->kind) {
  case A_yly_simpleVar:
    fprintf(out, "simpleVar(%s)", S_name(v->u.simple));
    break;
  case A_yly_seqVar: 
    fprintf(out, "%s", "seqVar(");
    for (A_yly_varList i = v->u.seq; i; i = i->next){
        pr_yly_var(out, i->data, 0);
        fprintf(out, ",");
    }
    fprintf(out,")");
    break;
  default:
    assert(0);
  }
}

void pr_yly_exp(FILE *out, A_yly_exp v, int d) {
  indent(out, d);
  switch (v->kind) {
  case A_yly_assignExp:
    fprintf(out, "assignExp(\n");
    pr_yly_var(out, v->u.assign.var, d + 1);
    fprintf(out, ",\n");
    pr_yly_exp(out, v->u.assign.exp, d + 1);
    fprintf(out, ")");
    break;
  case A_yly_intExp:
    fprintf(out, "intExp(%d)", v->u.intt);
    break;
  case A_yly_opExp:
   fprintf(out, "opExp(\n");
   indent(out, d+1); pr_yly_oper(out, v->u.op.oper); fprintf(out, ",\n"); 
   pr_yly_exp(out, v->u.op.left, d+1); fprintf(out, ",\n"); 
   pr_yly_exp(out, v->u.op.right, d+1); fprintf(out, ")");
   break;
   case A_yly_varExp:
   fprintf(out, "varExp(\n"); pr_yly_var(out, v->u.var, d+1); 
   fprintf(out, "%s", ")");
   break;
  case A_yly_printExp:
   fprintf(out, "printExp(\n"); pr_yly_exp(out, v->u.print.exp, d+1); 
   fprintf(out, "%s", ")");
    break;
  case A_yly_seqExp:
    assert(0);
    break;
  default:
    break;
  }
}

