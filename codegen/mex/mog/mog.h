/*
 * mog.h
 *
 * Code generation for function 'mog'
 *
 * C source code generated on: Sat Dec 28 10:10:59 2013
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
#include "mog_types.h"

/* Function Declarations */
extern void mog(const emxArray_real_T *image, real_T count, real_T alpha, emxArray_real_T *foreground, emxArray_uint8_T *background);
#endif
/* End of code generation (mog.h) */
