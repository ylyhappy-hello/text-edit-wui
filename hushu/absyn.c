#include "absyn.h"  /* abstract syntax data structures */
A_yly_var A_yly_SimpleVar(A_pos pos, S_symbol sym) {
  A_yly_var p = checked_malloc(sizeof(*p));
  p->kind = A_yly_simpleVar;
  p->pos = pos;
  p->u.simple = sym;
  return p;
}

A_yly_varList A_yly_SimpleVar_List(A_pos pos, A_yly_var data, A_yly_varList next) {
  A_yly_varList p = checked_malloc(sizeof(*p));
  p->data = data;
  p->next = next;
  return p;
}

A_yly_exp A_yly_PrintExp(A_pos pos, A_yly_exp exp){
  A_yly_exp p = checked_malloc(sizeof(*p));
  p->kind = A_yly_printExp;
  p->pos = pos;
  p->u.print.exp = exp;
  return p;
}

A_yly_var A_yly_SeqVar(A_pos pos, A_yly_varList seq) {
  A_yly_var p = checked_malloc(sizeof(*p));
  p->kind = A_yly_seqVar;
  p->pos = pos;
  p->u.seq = seq;
  return p;
}

A_yly_expList A_yly_ExpList(A_yly_exp head, A_yly_expList tail) {
  A_yly_expList p = checked_malloc(sizeof(*p));
  p->head = head;
  p->tail = tail;
  return p;
}

A_yly_exp A_yly_SeqExp(A_pos pos, A_yly_expList seq) {
  A_yly_exp p = checked_malloc(sizeof(*p));
  p->kind = A_yly_seqExp;
  p->pos = pos;
  p->u.seq = seq;
  return p;
}

A_yly_exp A_yly_VarExp(A_pos pos, A_yly_var var) {
  A_yly_exp p = checked_malloc(sizeof(*p));
  p->kind = A_yly_varExp;
  p->pos = pos;
  p->u.var = var;
  return p;
}

A_yly_exp A_yly_IntExp(A_pos pos, int i) {
  A_yly_exp p = checked_malloc(sizeof(*p));
  p->kind = A_yly_intExp;
  p->pos = pos;
  p->u.intt = i;
  return p;
}

A_yly_exp A_yly_AssignExp(A_pos pos, A_yly_var var, A_yly_exp exp) {
  A_yly_exp p = checked_malloc(sizeof(*p));
  p->kind = A_yly_assignExp;
  p->pos = pos;
  p->u.assign.var = var;
  p->u.assign.exp = exp;
  return p;
}

A_yly_exp A_yly_OpExp(A_pos pos, A_yly_oper oper, A_yly_exp left, A_yly_exp right) {
  A_yly_exp p = checked_malloc(sizeof(*p));
  p->kind = A_yly_opExp;
  p->pos = pos;
  p->u.op.oper = oper;
  p->u.op.left = left;
  p->u.op.right = right;
  return p;
}
