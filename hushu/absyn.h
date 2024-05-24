#ifndef __ABSYN_H
#define __ABSYN_H
#include "symbol.h" /* symbol table data structures */

#include <stdio.h>

typedef int A_pos;

typedef struct A_yly_exp_ *A_yly_exp;
typedef struct A_yly_var_ *A_yly_var;

typedef struct A_yly_expList_ *A_yly_expList;
typedef struct A_yly_varList_ *A_yly_varList;

typedef enum {
  A_yly_plusOp,
  A_yly_minusOp,
  A_yly_timesOp,
  A_yly_divideOp,
} A_yly_oper;

struct A_yly_var_ {
  enum { A_yly_simpleVar, A_yly_seqVar } kind;
  A_pos pos;
  union {
    S_symbol simple;
    struct {
      A_yly_var var;
      S_symbol sym;
    } field;
    A_yly_varList seq;
  } u;
};

struct A_yly_exp_ {
  A_pos pos;
  enum { A_yly_varExp, A_yly_opExp, A_yly_printExp,A_yly_fieldVarExp, A_yly_intExp, A_yly_seqExp, A_yly_assignExp } kind;
  union {
    A_yly_var var; // 类型为varExp 需要
    int intt;
    struct {
      A_yly_var var;
      A_yly_exp exp;
    } assign;
    struct {
      A_yly_oper oper;
      A_yly_exp left;
      A_yly_exp right;
    } op;
    struct {
      A_yly_exp exp;
    } print;
    A_yly_expList seq;
  } u;
};

struct A_yly_expList_ {
  A_yly_exp head;
  A_yly_expList tail;
};
struct A_yly_varList_{
  A_yly_var data;
  A_yly_varList next;
};
A_yly_var A_yly_SimpleVar(A_pos pos, S_symbol sym);
A_yly_var A_yly_SeqVar(A_pos pos, A_yly_varList var);
A_yly_varList A_yly_SimpleVar_List(A_pos pos, A_yly_var data, A_yly_varList next);
A_yly_exp A_yly_VarExp(A_pos pos, A_yly_var var);
A_yly_exp A_yly_SeqExp(A_pos pos, A_yly_expList exp);
A_yly_exp A_yly_AssignExp(A_pos pos, A_yly_var var, A_yly_exp exp);
A_yly_exp A_yly_IntExp(A_pos pos, int i);
A_yly_exp A_yly_OpExp(A_pos pos, A_yly_oper oper, A_yly_exp left, A_yly_exp right);
A_yly_exp A_yly_OpExp2(A_pos pos, A_yly_oper oper);
A_yly_exp A_yly_PrintExp(A_pos pos, A_yly_exp exp);
A_yly_expList A_yly_ExpList(A_yly_exp head, A_yly_expList tail);

#endif // !__ABSYN_H
