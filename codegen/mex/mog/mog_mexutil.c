/*
 * mog_mexutil.c
 *
 * Code generation for function 'mog_mexutil'
 *
 * C source code generated on: Wed Dec 25 11:02:59 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "mog_mexutil.h"

/* Function Definitions */
void error(emlrtCTX aTLS, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(aTLS, 0, NULL, 1, &pArray, "error", TRUE, location);
}

const mxArray *message(emlrtCTX aTLS, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m5;
  pArray = b;
  return emlrtCallMATLABR2012b(aTLS, 1, &m5, 1, &pArray, "message", TRUE,
    location);
}

/* End of code generation (mog_mexutil.c) */
