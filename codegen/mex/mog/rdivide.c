/*
 * rdivide.c
 *
 * Code generation for function 'rdivide'
 *
 * C source code generated on: Sat Dec 28 10:10:59 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "rdivide.h"
#include "mog_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = { 1, 14, "rdivide",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/ops/rdivide.m" };

/* Function Definitions */
void rdivide(const emxArray_real_T *x, real_T y, emxArray_real_T *z)
{
  int32_T i5;
  int32_T loop_ub;
  i5 = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)z, i5, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  loop_ub = x->size[0];
  for (i5 = 0; i5 < loop_ub; i5++) {
    z->data[i5] = x->data[i5] / y;
  }
}

/* End of code generation (rdivide.c) */
