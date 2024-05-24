#include "parseAST.h"
#include "symbol.h"
#include <assert.h>
#include <stdio.h>

void parseAssignExp(FILE *out,A_yly_exp exp) {
  A_yly_var var = exp->u.assign.var;
  A_yly_exp valueExp = exp->u.assign.exp;
  char *varNames[1024];
  int varNamePoint = 0;
  switch (var->kind) {
  case A_yly_simpleVar: {
    varNames[varNamePoint++] = S_name(var->u.simple);
    break;
  }
  case A_yly_seqVar: {
    for (A_yly_varList v = var->u.seq; v; v = v->next) {
      varNames[varNamePoint++] = S_name(v->data->u.simple);
    }
    break;
  }
  default:
    assert(0);
  }
  switch (valueExp->kind) {
  case A_yly_intExp: {
    for (int i = 0; i < varNamePoint; i++) {
      A_yly_gb_setVar(out,varNames[i], valueExp->u.intt);
    }
    break;
  }
  default:
    fprintf(out,"赋值语句后边需要值\n");
    break;
  }
}

int parseOpExp(FILE *out, A_yly_exp exp) {
  switch (exp->kind) {
  case A_yly_opExp: {
    A_yly_oper o = exp->u.op.oper;
    A_yly_exp left = exp->u.op.left;
    A_yly_exp right = exp->u.op.right;
    int leftOpNum = -1;
    int rightOpNum = -1;
      switch (left->kind) {
        case A_yly_opExp: { leftOpNum = parseOpExp(out,left); break;}
        case A_yly_varExp: { 
              leftOpNum = A_yly_gb_getVar(out,left->u.var->u.simple); break;}
        case A_yly_intExp: { leftOpNum = left->u.intt;break; }
        default: fprintf(out ,"xxxx 和 xxxx 不能相加"); return 9999; break;
      }
      switch (right->kind) {
        case A_yly_opExp: { rightOpNum = parseOpExp(out,right); break; }
        case A_yly_varExp: { rightOpNum = A_yly_gb_getVar(out,right->u.var->u.simple); break;}
        case A_yly_intExp: { rightOpNum = right->u.intt; break;}
        default: fprintf(out, "xxxx 和 xxxx 不能相加"); return 9999; break; 
      }
    if (rightOpNum != -1 && leftOpNum != -1) {
      switch (exp->u.op.oper) {
        case A_yly_plusOp: return leftOpNum + rightOpNum; break;
        case A_yly_minusOp: return leftOpNum - rightOpNum; break;
        case A_yly_timesOp: return leftOpNum * rightOpNum; break;
        case A_yly_divideOp: return leftOpNum / rightOpNum; break;
      }
    }
  }
  case A_yly_varExp: { 
      return A_yly_gb_getVar(out,exp->u.var->u.simple); }

  case A_yly_intExp: { return exp->u.intt; }
  default: fprintf(out ,"解析OpExp错误"); break; }
  return -1;
}

void parsePrintExp(FILE *out, A_yly_exp exp){
  A_yly_exp v_exp = exp->u.print.exp;
  switch (v_exp->kind) {
    case A_yly_varExp: {
      S_symbol sym = v_exp->u.var->u.simple;
      char* vname = S_name(sym);
      fprintf(out,"variable %s is %d \n",vname, A_yly_gb_getVar(out,sym)); 
      break;
    }
    case A_yly_opExp: {
      fprintf(out,"calc result is %d \n",parseOpExp(out, v_exp)); 
      break;
    }
    default:{
      fprintf(out,"only print variable and calc express"); 
      break;
    }
  }
}

void parseExp(FILE *out,A_yly_exp exp) {
  switch (exp->kind) {
  case A_yly_assignExp: {
    parseAssignExp(out, exp);
    break;
  }
  case A_yly_opExp: {
    int t = parseOpExp(out, exp);
    //printf("total result is %d", t);
    break;
  }
  case A_yly_printExp: {
      parsePrintExp(out, exp);
      break;
  }
  default:
    assert(0);
  }
}

void parseAST(FILE *out ,A_yly_expList expListRoot) {
  for (A_yly_expList e = expListRoot; e; e = e->tail) {
    parseExp(out, e->head);
  }
}
