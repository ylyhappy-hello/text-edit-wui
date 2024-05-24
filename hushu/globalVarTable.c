#include "globalVarTable.h"
#include <stdio.h>
#define SIZE 1024
typedef struct { char* key; int value; } gloablBinding_; 
typedef gloablBinding_ *gloablBinding; 
static gloablBinding gbTable[SIZE];

void A_yly_reset_gbTable(){
  for (int i = 0; i < SIZE; i++){
     gbTable[i] = NULL;
  }
}

static unsigned int hash(char *s0){
  unsigned int h = 0; char *s;
  for (s = s0; *s; s++)
    h = h * 65599 + *s;
  return h;
}

void A_yly_gb_setVar(FILE *out ,char* sym, int value){
  char* vname = sym;
  int idx = hash(vname) % SIZE;
  if (gbTable[idx] != NULL){
    fprintf(out,"变量%s重复定义\n", vname);
    return;
  }
  gbTable[idx] = checked_malloc(sizeof(*gbTable[idx]));
  gbTable[idx]->key = vname; gbTable[idx]->value = value; 
} 

int A_yly_gb_getVar(FILE *out ,S_symbol sym){
  char* vname = S_name(sym);
  int idx = hash(vname) % SIZE;
  gloablBinding gbs = gbTable[idx];
  if (gbs == NULL){
    fprintf(out,"使用了未定义的变量%s\n", vname);
    return 0;
  }
  return gbs->value;
}


