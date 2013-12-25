/*
 * mog_data.c
 *
 * Code generation for function 'mog_data'
 *
 * C source code generated on: Wed Dec 25 11:02:59 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "mog_data.h"

/* Variable Definitions */
const volatile char_T *emlrtBreakCheckR2012bFlagVar;
emxArray_struct_T *models;
boolean_T models_not_empty;
emlrtRSInfo s_emlrtRSI = { 55, "mtimes",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/ops/mtimes.m" };

emlrtRSInfo t_emlrtRSI = { 21, "mtimes",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/ops/mtimes.m" };

emlrtRSInfo u_emlrtRSI = { 89, "mtimes",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/ops/mtimes.m" };

emlrtRSInfo v_emlrtRSI = { 54, "eml_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m" };

emlrtRSInfo w_emlrtRSI = { 20, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo x_emlrtRSI = { 32, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo y_emlrtRSI = { 63, "eml_refblas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"
};

emlrtRSInfo ab_emlrtRSI = { 85, "eml_refblas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"
};

emlrtRSInfo bb_emlrtRSI = { 89, "eml_refblas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"
};

emlrtRSInfo cb_emlrtRSI = { 110, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo db_emlrtRSI = { 111, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo eb_emlrtRSI = { 112, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo fb_emlrtRSI = { 113, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo gb_emlrtRSI = { 114, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo hb_emlrtRSI = { 115, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo ib_emlrtRSI = { 119, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo jb_emlrtRSI = { 122, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo kb_emlrtRSI = { 125, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo lb_emlrtRSI = { 128, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo mb_emlrtRSI = { 131, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo nb_emlrtRSI = { 134, "eml_blas_xgemm",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"
};

emlrtRSInfo ob_emlrtRSI = { 14, "eml_c_cast",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/blas/external/eml_c_cast.m"
};

emlrtRTEInfo d_emlrtRTEI = { 90, 13, "mtimes",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/ops/mtimes.m" };

emlrtMCInfo g_emlrtMCI = { 90, 13, "mtimes",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/ops/mtimes.m" };

emlrtMCInfo h_emlrtMCI = { 89, 23, "mtimes",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/ops/mtimes.m" };

emlrtRTEInfo h_emlrtRTEI = { 127, 5, "find",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/find.m" };

/* End of code generation (mog_data.c) */
