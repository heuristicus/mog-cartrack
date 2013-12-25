/*
 * modelInit.c
 *
 * Code generation for function 'modelInit'
 *
 * C source code generated on: Wed Dec 25 11:02:59 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "modelInit.h"
#include "mog_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo l_emlrtRTEI = { 1, 30, "modelInit",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/modelInit.m" };

/* Function Definitions */
void modelInit(emlrtCTX aTLS, const emxArray_real_T *X, emxArray_real_T *mu)
{
  int32_T loop_ub;
  int32_T i5;
  int32_T i6;

  /* MODELINIT Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  Inputs */
  /*          X:                  Cx1 */
  /*          K:                  1x1 */
  /*           */
  /*  Outputs */
  /*          weight:             Kx1 */
  /*          mu:                 CxK */
  /*          sigma:              Kx1 */
  /* Uniform weights */
  loop_ub = X->size[0];
  i5 = mu->size[0] * mu->size[1];
  mu->size[0] = loop_ub;
  mu->size[1] = 3;
  emxEnsureCapacity(aTLS, (emxArray__common *)mu, i5, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  for (i5 = 0; i5 < 3; i5++) {
    for (i6 = 0; i6 < loop_ub; i6++) {
      mu->data[i6 + mu->size[0] * i5] = X->data[i6];
    }
  }

  /* nxK    %Current pixel value */
  /* Large sigma */
}

/* End of code generation (modelInit.c) */
