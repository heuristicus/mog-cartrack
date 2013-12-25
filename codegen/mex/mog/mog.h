/*
 * mog.h
 *
 * Code generation for function 'mog'
 *
 * C source code generated on: Wed Dec 25 11:02:59 2013
 *
 */

#ifndef __MOG_H__
#define __MOG_H__
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
extern void mog(emlrtCTX aTLS, const emxArray_real_T *image, real_T count, emxArray_real_T *foreground);
#endif
/* End of code generation (mog.h) */
