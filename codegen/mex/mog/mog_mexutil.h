/*
 * mog_mexutil.h
 *
 * Code generation for function 'mog_mexutil'
 *
 * C source code generated on: Wed Dec 25 11:02:59 2013
 *
 */

#ifndef __MOG_MEXUTIL_H__
#define __MOG_MEXUTIL_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "omp.h"
#include "mog_types.h"

/* Function Declarations */
extern void error(emlrtCTX aTLS, const mxArray *b, emlrtMCInfo *location);
extern const mxArray *message(emlrtCTX aTLS, const mxArray *b, emlrtMCInfo *location);
#endif
/* End of code generation (mog_mexutil.h) */
