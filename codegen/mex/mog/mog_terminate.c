/*
 * mog_terminate.c
 *
 * Code generation for function 'mog_terminate'
 *
 * C source code generated on: Wed Dec 25 11:02:59 2013
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
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     emlrtLockerFunction, omp_get_num_procs());
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
