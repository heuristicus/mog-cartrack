/*
 * mog_initialize.c
 *
 * Code generation for function 'mog_initialize'
 *
 * C source code generated on: Wed Dec 25 11:02:59 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "mog_initialize.h"
#include "mog_emxutil.h"
#include "mog_data.h"

/* Variable Definitions */
static emlrtRTEInfo e_emlrtRTEI = { 9, 12, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

/* Function Declarations */
static void mog_once(void);

/* Function Definitions */
static void mog_once(void)
{
  emxInit_struct_T(&models, 2, &e_emlrtRTEI, FALSE);
  models_not_empty = FALSE;
}

void mog_initialize(emlrtContext *aContext)
{
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, emlrtLockerFunction,
                     omp_get_num_procs());
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, FALSE, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    mog_once();
  }
}

/* End of code generation (mog_initialize.c) */
