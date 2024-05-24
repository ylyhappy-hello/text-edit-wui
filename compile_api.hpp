#ifndef COMPILE_API_HPP
#define COMPILE_API_HPP

#include <string>
#include <stdio.h>
extern "C" {
#include "hushu/errormsg.h"
#include "hushu/prabsyn.h"
#include "hushu/symbol.h"
#include "hushu/parseAST.h"
#include "hushu/parse.h"
}

void A_yly_compile();

#endif // !COMPILE_API_HPP
