/*
 * update.h
 *
 * Code generation for function 'update'
 *
 * C source code generated on: Sat Dec 28 17:42:20 2013
 *
 */

#ifndef __UPDATE_H__
#define __UPDATE_H__
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
#include "mog_types.h"

/* Function Declarations */
extern void update(const emxArray_real_T *X, real_T weight[3], emxArray_real_T *mu, real_T sigma[3], real_T alpha);
#endif
/* End of code generation (update.h) */
