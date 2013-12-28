/*
 * sum.c
 *
 * Code generation for function 'sum'
 *
 * C source code generated on: Sat Dec 28 17:42:20 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "sum.h"

/* Function Definitions */
real_T sum(const real_T x_data[3], const int32_T x_size[1])
{
  real_T y;
  int32_T k;
  y = x_data[0];
  for (k = 2; k <= x_size[0]; k++) {
    y += x_data[k - 1];
  }

  return y;
}

/* End of code generation (sum.c) */
