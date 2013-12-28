/*
 * mog_terminate.c
 *
 * Code generation for function 'mog_terminate'
 *
 * C source code generated on: Sat Dec 28 17:42:20 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "mog_terminate.h"
#include "mog_emxutil.h"
#include "mog_data.h"

/* Function Definitions */
void mog_atexit(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emxFree_struct_T(&models);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void mog_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (mog_terminate.c) */
