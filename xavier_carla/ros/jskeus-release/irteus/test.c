#include "eus.h"
#undef defun
pointer TEST();
void test(void) {register context *ctx; pointer mod; defun(ctx,"TEST",mod,TEST,NULL);}
