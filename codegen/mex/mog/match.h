/*
 * match.h
 *
 * Code generation for function 'match'
 *
 * C source code generated on: Wed Dec 25 11:02:59 2013
 *
 */

#ifndef __MATCH_H__
#define __MATCH_H__
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
extern void match(emlrtCTX aTLS, const emxArray_real_T *X, const emxArray_real_T *mu, const real_T sigma[3], real_T D[3]);
#endif
/* End of code generation (match.h) */
