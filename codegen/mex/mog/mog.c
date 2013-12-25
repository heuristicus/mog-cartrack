/*
 * mog.c
 *
 * Code generation for function 'mog'
 *
 * C source code generated on: Wed Dec 25 11:02:59 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "match.h"
#include "mog_emxutil.h"
#include "update.h"
#include "modelInit.h"
#include "mog_mexutil.h"
#include "mog_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 68, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRSInfo b_emlrtRSI = { 64, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRSInfo c_emlrtRSI = { 45, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRSInfo d_emlrtRSI = { 27, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRSInfo e_emlrtRSI = { 20, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRSInfo f_emlrtRSI = { 11, "repmat",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtRSInfo g_emlrtRSI = { 19, "repmat",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtRSInfo h_emlrtRSI = { 48, "eml_assert_valid_size_arg",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtRSInfo i_emlrtRSI = { 41, "reshape",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m" };

static emlrtRSInfo j_emlrtRSI = { 61, "reshape",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m" };

static emlrtRSInfo k_emlrtRSI = { 66, "reshape",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m" };

static emlrtRSInfo l_emlrtRSI = { 68, "reshape",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m" };

static emlrtRSInfo m_emlrtRSI = { 51, "eml_int_forloop_overflow_check",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo n_emlrtRSI = { 20, "eml_error",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_error.m" };

static emlrtRSInfo o_emlrtRSI = { 12, "eml_int_forloop_overflow_check",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo pb_emlrtRSI = { 41, "find",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo qb_emlrtRSI = { 230, "find",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo emlrtRTEI = { 67, 5, "reshape",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m" };

static emlrtRTEInfo b_emlrtRTEI = { 49, 13, "eml_assert_valid_size_arg",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 52, 9, "eml_int_forloop_overflow_check",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo emlrtMCI = { 49, 13, "eml_assert_valid_size_arg",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtMCInfo b_emlrtMCI = { 48, 23, "eml_assert_valid_size_arg",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"
};

static emlrtMCInfo c_emlrtMCI = { 67, 5, "reshape",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m" };

static emlrtMCInfo d_emlrtMCI = { 66, 15, "reshape",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m" };

static emlrtMCInfo e_emlrtMCI = { 52, 9, "eml_int_forloop_overflow_check",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo f_emlrtMCI = { 51, 15, "eml_int_forloop_overflow_check",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 1, 25, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRTEInfo g_emlrtRTEI = { 65, 1, "reshape",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m" };

static emlrtRTEInfo i_emlrtRTEI = { 30, 9, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRTEInfo j_emlrtRTEI = { 33, 9, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRTEInfo k_emlrtRTEI = { 27, 9, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 33, 27, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 33, 25, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 27, 29, "image", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 27, 27, "image", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 71, 24, "foreground", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 71, 26, "foreground", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtRTEInfo s_emlrtRTEI = { 20, 5, "eml_error",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_error.m" };

/* Function Declarations */
static const mxArray *b_message(emlrtCTX aTLS, const mxArray *b, const mxArray
  *c, emlrtMCInfo *location);
static void check_forloop_overflow_error(emlrtCTX aTLS);
static void eml_error(emlrtCTX aTLS);
static void eml_sort(const real_T x[3], real_T y[3], int32_T idx[3]);

/* Function Definitions */
static const mxArray *b_message(emlrtCTX aTLS, const mxArray *b, const mxArray
  *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m6;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(aTLS, 1, &m6, 2, pArrays, "message", TRUE,
    location);
}

static void check_forloop_overflow_error(emlrtCTX aTLS)
{
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 34 };

  const mxArray *m1;
  char_T cv4[34];
  int32_T i;
  static const char_T cv5[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o',
    'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 23 };

  char_T cv6[23];
  static const char_T cv7[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't',
    'e', 'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  emlrtAssertMATLABThread(aTLS, &c_emlrtRTEI);
  emlrtPushRtStackR2012b(&m_emlrtRSI, aTLS);
  y = NULL;
  m1 = mxCreateCharArray(2, iv2);
  for (i = 0; i < 34; i++) {
    cv4[i] = cv5[i];
  }

  emlrtInitCharArrayR2013a(aTLS, 34, m1, cv4);
  emlrtAssign(&y, m1);
  b_y = NULL;
  m1 = mxCreateCharArray(2, iv3);
  for (i = 0; i < 23; i++) {
    cv6[i] = cv7[i];
  }

  emlrtInitCharArrayR2013a(aTLS, 23, m1, cv6);
  emlrtAssign(&b_y, m1);
  error(aTLS, b_message(aTLS, y, b_y, &e_emlrtMCI), &f_emlrtMCI);
  emlrtPopRtStackR2012b(&m_emlrtRSI, aTLS);
}

static void eml_error(emlrtCTX aTLS)
{
  emlrtPushRtStackR2012b(&n_emlrtRSI, aTLS);
  emlrtErrorWithMessageIdR2012b(aTLS, &s_emlrtRTEI,
    "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  emlrtPopRtStackR2012b(&n_emlrtRSI, aTLS);
}

static void eml_sort(const real_T x[3], real_T y[3], int32_T idx[3])
{
  boolean_T p;
  if ((x[0] >= x[1]) || muDoubleScalarIsNaN(x[0])) {
    p = TRUE;
  } else {
    p = FALSE;
  }

  if (p) {
    if ((x[1] >= x[2]) || muDoubleScalarIsNaN(x[1])) {
      p = TRUE;
    } else {
      p = FALSE;
    }

    if (p) {
      idx[0] = 1;
      idx[1] = 2;
      idx[2] = 3;
      y[0] = x[0];
      y[1] = x[1];
      y[2] = x[2];
    } else {
      if ((x[0] >= x[2]) || muDoubleScalarIsNaN(x[0])) {
        p = TRUE;
      } else {
        p = FALSE;
      }

      if (p) {
        idx[0] = 1;
        idx[1] = 3;
        idx[2] = 2;
        y[0] = x[0];
        y[1] = x[2];
        y[2] = x[1];
      } else {
        idx[0] = 3;
        idx[1] = 1;
        idx[2] = 2;
        y[0] = x[2];
        y[1] = x[0];
        y[2] = x[1];
      }
    }
  } else {
    if ((x[0] >= x[2]) || muDoubleScalarIsNaN(x[0])) {
      p = TRUE;
    } else {
      p = FALSE;
    }

    if (p) {
      idx[0] = 2;
      idx[1] = 1;
      idx[2] = 3;
      y[0] = x[1];
      y[1] = x[0];
      y[2] = x[2];
    } else {
      if ((x[1] >= x[2]) || muDoubleScalarIsNaN(x[1])) {
        p = TRUE;
      } else {
        p = FALSE;
      }

      if (p) {
        idx[0] = 2;
        idx[1] = 3;
        idx[2] = 1;
        y[0] = x[1];
        y[1] = x[2];
        y[2] = x[0];
      } else {
        idx[0] = 3;
        idx[1] = 2;
        idx[2] = 1;
        y[0] = x[2];
        y[1] = x[1];
        y[2] = x[0];
      }
    }
  }
}

void mog(emlrtCTX aTLS, const emxArray_real_T *image, real_T count,
         emxArray_real_T *foreground)
{
  real_T N;
  real_T C;
  struct_T a;
  int32_T i;
  int32_T i0;
  int32_T b_image[2];
  int32_T outsize[2];
  int32_T m;
  emxArray_real_T *c_image;
  emxArray_real_T *X;
  struct_T modelX;
  emxArray_real_T *prevMu;
  real_T b_m;
  real_T matching_data[1];
  int32_T matching_size[1];
  real_T matchingIndex_data[3];
  int32_T matchingIndex_size[1];
  real_T B;
  boolean_T overflow;
  real_T w[3];
  real_T b_index[3];
  real_T prevSigma[3];
  int32_T n;
  int32_T exitg1;
  int32_T i1;
  int32_T i2;
  boolean_T b_C;
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 28 };

  const mxArray *m0;
  char_T cv0[28];
  int32_T b_i;
  static const char_T cv1[28] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'N', 'o', 'n', 'I', 'n', 't', 'e', 'g', 'e', 'r', 'I',
    'n', 'p', 'u', 't' };

  int32_T loop_ub;
  uint32_T varargin_1[3];
  int32_T maxdimlen;
  int32_T ix;
  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 40 };

  char_T cv2[40];
  static const char_T cv3[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D',
    'i', 'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e',
    'l' };

  int32_T k;
  int32_T exitg4;
  int32_T iidx[3];
  boolean_T b_varargin_1[3];
  int32_T itmp;
  int32_T idx;
  int8_T ii_data[3];
  int32_T ii;
  boolean_T exitg3;
  boolean_T guard1 = FALSE;
  int8_T b_ii_data[3];
  boolean_T x_data[3];
  int8_T c_ii_data[1];
  int32_T ii_size_idx_0;
  boolean_T exitg2;
  int32_T i3;
  int32_T i4;
  boolean_T emlrtHadParallelError = FALSE;
  jmp_buf emlrtJBEnviron;
  jmp_buf * volatile emlrtJBStack;
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);

  /* MOG Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  Inputs: */
  /*          image:              MxNxC */
  /*           */
  /*  Outputs */
  /*          foreground:         MxN */
  N = image->size[1];
  C = image->size[2];

  /* Number of Gaussians */
  /* Background Threshold */
  if (!models_not_empty) {
    emxInitStruct_struct_T(aTLS, &a, &f_emlrtRTEI, TRUE);
    for (i = 0; i < 3; i++) {
      a.weight[i] = 0.0;
    }

    i = image->size[2];
    i0 = a.mu->size[0] * a.mu->size[1];
    a.mu->size[0] = i;
    a.mu->size[1] = 3;
    emxEnsureCapacity(aTLS, (emxArray__common *)a.mu, i0, (int32_T)sizeof(real_T),
                      &f_emlrtRTEI);
    i = image->size[2] * 3;
    for (i0 = 0; i0 < i; i0++) {
      a.mu->data[i0] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      a.sigma[i] = 0.0;
    }

    emlrtPushRtStackR2012b(&e_emlrtRSI, aTLS);
    emlrtPushRtStackR2012b(&f_emlrtRSI, aTLS);
    emlrtPopRtStackR2012b(&f_emlrtRSI, aTLS);
    emlrtPushRtStackR2012b(&g_emlrtRSI, aTLS);
    emlrtPopRtStackR2012b(&g_emlrtRSI, aTLS);
    b_image[0] = image->size[0];
    b_image[1] = image->size[1];
    for (i0 = 0; i0 < 2; i0++) {
      outsize[i0] = b_image[i0];
    }

    i0 = models->size[0] * models->size[1];
    models->size[0] = outsize[0];
    emxEnsureCapacity_struct_T(models, i0, &f_emlrtRTEI);
    i0 = models->size[0] * models->size[1];
    models->size[1] = outsize[1];
    emxEnsureCapacity_struct_T(models, i0, &f_emlrtRTEI);
    i = outsize[0] * outsize[1];
    for (i0 = 0; i0 < i; i0++) {
      emxCopyStruct_struct_T(&models->data[i0], &a, &f_emlrtRTEI);
    }

    emxFreeStruct_struct_T(&a);
    emlrtPopRtStackR2012b(&e_emlrtRSI, aTLS);
    models_not_empty = !((models->size[0] == 0) || (models->size[1] == 0));
  }

  i = image->size[0];
  i0 = foreground->size[0] * foreground->size[1];
  foreground->size[0] = i;
  emxEnsureCapacity(aTLS, (emxArray__common *)foreground, i0, (int32_T)sizeof
                    (real_T), &f_emlrtRTEI);
  i = image->size[1];
  i0 = foreground->size[0] * foreground->size[1];
  foreground->size[1] = i;
  emxEnsureCapacity(aTLS, (emxArray__common *)foreground, i0, (int32_T)sizeof
                    (real_T), &f_emlrtRTEI);
  i = image->size[0] * image->size[1];
  for (i0 = 0; i0 < i; i0++) {
    foreground->data[i0] = 0.0;
  }

  i0 = image->size[0];
  i = i0 - 1;
  emlrtEnterParallelRegion(aTLS, omp_in_parallel());
  emlrtPushJmpBuf(aTLS, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(aTLS, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(c_image,X,modelX,prevMu,matching_data,matching_size,matchingIndex_data,matchingIndex_size,B,overflow,w,b_index,prevSigma,b_m,n,exitg1,i1,i2,b_C,loop_ub,maxdimlen,ix,k,exitg4,b_i,itmp,idx,ii,exitg3,guard1,ii_size_idx_0,exitg2,i3,i4,m0,emlrtJBEnviron) \
 firstprivate(aTLS,varargin_1,iidx,b_varargin_1,ii_data,b_ii_data,x_data,c_ii_data,b_y,emlrtHadParallelError,cv2,y,cv0)

  {
    aTLS = emlrtAllocTLS(aTLS, omp_get_thread_num());
    emlrtSetJmpBuf(aTLS, &emlrtJBEnviron);
    if (setjmp(emlrtJBEnviron) == 0) {
      c_emxInit_real_T(aTLS, &c_image, 3, &f_emlrtRTEI, TRUE);
      b_emxInit_real_T(aTLS, &X, 1, &k_emlrtRTEI, TRUE);
      emxInitStruct_struct_T(aTLS, &modelX, &j_emlrtRTEI, TRUE);
      emxInit_real_T(aTLS, &prevMu, 2, &i_emlrtRTEI, TRUE);
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (m = 0; m <= i; m++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(emlrtJBEnviron) == 0) {
        b_m = 1.0 + (real_T)m;
        B = 1.0;
        n = 0;
        do {
          exitg1 = 0;
          emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, aTLS);
          if (n <= (int32_T)N - 1) {
            emlrtPushRtStackR2012b(&d_emlrtRSI, aTLS);
            i1 = image->size[0];
            i2 = (int32_T)b_m;
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &d_emlrtBCI, aTLS);
            i1 = image->size[1];
            i2 = (int32_T)(1.0 + (real_T)n);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &c_emlrtBCI, aTLS);
            emlrtPushRtStackR2012b(&i_emlrtRSI, aTLS);
            if (C != C) {
              b_C = FALSE;
            } else {
              b_C = TRUE;
            }

            if (b_C) {
            } else {
              emlrtAssertMATLABThread(aTLS, &b_emlrtRTEI);
              emlrtPushRtStackR2012b(&h_emlrtRSI, aTLS);
              y = NULL;
              m0 = mxCreateCharArray(2, iv0);
              for (b_i = 0; b_i < 28; b_i++) {
                cv0[b_i] = cv1[b_i];
              }

              emlrtInitCharArrayR2013a(aTLS, 28, m0, cv0);
              emlrtAssign(&y, m0);
              error(aTLS, message(aTLS, y, &emlrtMCI), &b_emlrtMCI);
              emlrtPopRtStackR2012b(&h_emlrtRSI, aTLS);
            }

            emlrtPopRtStackR2012b(&i_emlrtRSI, aTLS);
            loop_ub = image->size[2];
            i1 = c_image->size[0] * c_image->size[1] * c_image->size[2];
            c_image->size[0] = 1;
            c_image->size[1] = 1;
            c_image->size[2] = loop_ub;
            emxEnsureCapacity(aTLS, (emxArray__common *)c_image, i1, (int32_T)
                              sizeof(real_T), &f_emlrtRTEI);
            for (i1 = 0; i1 < loop_ub; i1++) {
              c_image->data[c_image->size[0] * c_image->size[1] * i1] =
                image->data[(((int32_T)b_m + image->size[0] * n) + image->size[0]
                             * image->size[1] * i1) - 1];
            }

            for (i1 = 0; i1 < 3; i1++) {
              varargin_1[i1] = (uint32_T)c_image->size[i1];
            }

            maxdimlen = 1;
            for (ix = 0; ix < 2; ix++) {
              if ((int32_T)varargin_1[ix + 1] > maxdimlen) {
                maxdimlen = (int32_T)varargin_1[ix + 1];
              }
            }

            i1 = image->size[2];
            if (i1 < maxdimlen) {
            } else {
              maxdimlen = image->size[2];
            }

            if ((int32_T)C > maxdimlen) {
              emlrtPushRtStackR2012b(&j_emlrtRSI, aTLS);
              eml_error(aTLS);
              emlrtPopRtStackR2012b(&j_emlrtRSI, aTLS);
            }

            if (1 > maxdimlen) {
              emlrtPushRtStackR2012b(&j_emlrtRSI, aTLS);
              eml_error(aTLS);
              emlrtPopRtStackR2012b(&j_emlrtRSI, aTLS);
            }

            i1 = X->size[0];
            X->size[0] = (int32_T)C;
            emxEnsureCapacity(aTLS, (emxArray__common *)X, i1, (int32_T)sizeof
                              (real_T), &g_emlrtRTEI);
            i1 = image->size[2];
            if (i1 == (int32_T)C) {
            } else {
              emlrtAssertMATLABThread(aTLS, &emlrtRTEI);
              emlrtPushRtStackR2012b(&k_emlrtRSI, aTLS);
              b_y = NULL;
              m0 = mxCreateCharArray(2, iv1);
              for (b_i = 0; b_i < 40; b_i++) {
                cv2[b_i] = cv3[b_i];
              }

              emlrtInitCharArrayR2013a(aTLS, 40, m0, cv2);
              emlrtAssign(&b_y, m0);
              error(aTLS, message(aTLS, b_y, &c_emlrtMCI), &d_emlrtMCI);
              emlrtPopRtStackR2012b(&k_emlrtRSI, aTLS);
            }

            emlrtPushRtStackR2012b(&l_emlrtRSI, aTLS);
            i1 = image->size[2];
            if (1 > i1) {
              overflow = FALSE;
            } else {
              i1 = image->size[2];
              overflow = (i1 > 2147483646);
            }

            if (overflow) {
              emlrtPushRtStackR2012b(&o_emlrtRSI, aTLS);
              check_forloop_overflow_error(aTLS);
              emlrtPopRtStackR2012b(&o_emlrtRSI, aTLS);
            }

            emlrtPopRtStackR2012b(&l_emlrtRSI, aTLS);
            k = 1;
            do {
              exitg4 = 0;
              i1 = image->size[2];
              if (k <= i1) {
                X->data[k - 1] = image->data[(((int32_T)b_m + image->size[0] * n)
                  + image->size[0] * image->size[1] * (k - 1)) - 1];
                k++;
              } else {
                exitg4 = 1;
              }
            } while (exitg4 == 0);

            emlrtPopRtStackR2012b(&d_emlrtRSI, aTLS);

            /* Preallocate */
            i1 = models->size[0];
            i2 = (int32_T)b_m;
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &b_emlrtBCI, aTLS);
            i1 = models->size[1];
            i2 = (int32_T)(1.0 + (real_T)n);
            emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1, &emlrtBCI, aTLS);
            for (i1 = 0; i1 < 3; i1++) {
              w[i1] = models->data[((int32_T)b_m + models->size[0] * n) - 1].
                weight[i1];
            }

            i1 = prevMu->size[0] * prevMu->size[1];
            prevMu->size[0] = models->data[((int32_T)b_m + models->size[0] * n)
              - 1].mu->size[0];
            prevMu->size[1] = 3;
            emxEnsureCapacity(aTLS, (emxArray__common *)prevMu, i1, (int32_T)
                              sizeof(real_T), &f_emlrtRTEI);
            loop_ub = models->data[((int32_T)b_m + models->size[0] * n) - 1].
              mu->size[0] * models->data[((int32_T)b_m + models->size[0] * n) -
              1].mu->size[1];
            for (i1 = 0; i1 < loop_ub; i1++) {
              prevMu->data[i1] = models->data[((int32_T)b_m + models->size[0] *
                n) - 1].mu->data[i1];
            }

            for (i1 = 0; i1 < 3; i1++) {
              prevSigma[i1] = models->data[((int32_T)b_m + models->size[0] * n)
                - 1].sigma[i1];
            }

            /* Initialization (first frame) */
            if (count == 1.0) {
              /*          if(isempty(prevWeight) || isempty(prevMu) || isempty(prevSigma)) */
              modelInit(aTLS, X, prevMu);
              for (b_i = 0; b_i < 3; b_i++) {
                w[b_i] = 0.33333333333333331;
              }

              for (b_i = 0; b_i < 3; b_i++) {
                prevSigma[b_i] = 100.0;
              }
            }

            /* Update model */
            emlrtPushRtStackR2012b(&c_emlrtRSI, aTLS);
            update(aTLS, X, w, prevMu, prevSigma);
            emlrtPopRtStackR2012b(&c_emlrtRSI, aTLS);
            for (b_i = 0; b_i < 3; b_i++) {
              modelX.weight[b_i] = w[b_i];
            }

            i1 = modelX.mu->size[0] * modelX.mu->size[1];
            modelX.mu->size[0] = prevMu->size[0];
            modelX.mu->size[1] = 3;
            emxEnsureCapacity(aTLS, (emxArray__common *)modelX.mu, i1, (int32_T)
                              sizeof(real_T), &f_emlrtRTEI);
            loop_ub = prevMu->size[0] * prevMu->size[1];
            for (i1 = 0; i1 < loop_ub; i1++) {
              modelX.mu->data[i1] = prevMu->data[i1];
            }

            for (b_i = 0; b_i < 3; b_i++) {
              modelX.sigma[b_i] = prevSigma[b_i];
            }

            /* Sort weights/sigma */
            for (i1 = 0; i1 < 3; i1++) {
              w[i1] /= prevSigma[i1];
            }

            for (b_i = 0; b_i < 3; b_i++) {
              b_index[b_i] = w[b_i];
            }

            eml_sort(b_index, w, iidx);
            for (b_i = 0; b_i < 3; b_i++) {
              b_index[b_i] = iidx[b_i];
            }

            /* Calculate B = number of background gaussians */
            ix = 0;
            B = w[0];
            for (k = 0; k < 2; k++) {
              ix++;
              B += w[ix];
              w[ix] = B;
            }

            for (b_i = 0; b_i < 3; b_i++) {
              b_varargin_1[b_i] = (w[b_i] > 0.5);
            }

            overflow = b_varargin_1[0];
            itmp = 1;
            for (ix = 0; ix < 2; ix++) {
              if (b_varargin_1[ix + 1] < overflow) {
                overflow = b_varargin_1[ix + 1];
                itmp = ix + 2;
              }
            }

            B = 0.0;

            /* See if the pixel matches a background gaussian */
            emlrtPushRtStackR2012b(&b_emlrtRSI, aTLS);
            match(aTLS, X, prevMu, prevSigma, w);
            idx = 0;
            ii = 1;
            exitg3 = FALSE;
            while ((exitg3 == FALSE) && (ii < 4)) {
              guard1 = FALSE;
              if (w[ii - 1] != 0.0) {
                idx++;
                ii_data[idx - 1] = (int8_T)ii;
                if (idx >= 3) {
                  exitg3 = TRUE;
                } else {
                  guard1 = TRUE;
                }
              } else {
                guard1 = TRUE;
              }

              if (guard1 == TRUE) {
                ii++;
              }
            }

            if (1 > idx) {
              loop_ub = 0;
            } else {
              loop_ub = idx;
            }

            for (i1 = 0; i1 < loop_ub; i1++) {
              b_ii_data[i1] = ii_data[i1];
            }

            for (i1 = 0; i1 < loop_ub; i1++) {
              ii_data[i1] = b_ii_data[i1];
            }

            matchingIndex_size[0] = loop_ub;
            for (i1 = 0; i1 < loop_ub; i1++) {
              matchingIndex_data[i1] = ii_data[i1];
            }

            emlrtPopRtStackR2012b(&b_emlrtRSI, aTLS);
            if (loop_ub == 0) {
              matchingIndex_size[0] = 1;
              matchingIndex_data[0] = -1.0;
            }

            emlrtPushRtStackR2012b(&emlrtRSI, aTLS);
            for (i1 = 0; i1 < itmp; i1++) {
              x_data[i1] = (b_index[i1] == matchingIndex_data[0]);
            }

            emlrtPushRtStackR2012b(&pb_emlrtRSI, aTLS);
            idx = 0;
            ii_size_idx_0 = 1;
            emlrtPushRtStackR2012b(&qb_emlrtRSI, aTLS);
            emlrtPopRtStackR2012b(&qb_emlrtRSI, aTLS);
            ii = 1;
            exitg2 = FALSE;
            while ((exitg2 == FALSE) && (ii <= itmp)) {
              if (x_data[ii - 1]) {
                idx = 1;
                c_ii_data[0] = (int8_T)ii;
                exitg2 = TRUE;
              } else {
                ii++;
              }
            }

            if (idx == 0) {
              ii_size_idx_0 = 0;
            }

            emlrtPopRtStackR2012b(&pb_emlrtRSI, aTLS);
            matching_size[0] = ii_size_idx_0;
            i1 = 0;
            while (i1 <= ii_size_idx_0 - 1) {
              matching_data[0] = c_ii_data[0];
              i1 = 1;
            }

            emlrtPopRtStackR2012b(&emlrtRSI, aTLS);

            /* No match => foreground */
            if (ii_size_idx_0 == 0) {
              i1 = foreground->size[0];
              i2 = (int32_T)b_m;
              i3 = foreground->size[1];
              i4 = 1 + n;
              foreground->data[(emlrtDynamicBoundsCheckFastR2012b(i2, 1, i1,
                &e_emlrtBCI, aTLS) + foreground->size[0] *
                                (emlrtDynamicBoundsCheckFastR2012b(i4, 1, i3,
                &f_emlrtBCI, aTLS) - 1)) - 1] = 1.0;
            }

            n++;
            emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, aTLS);
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        emlrtHadParallelError = true;
      }
    }

    if (!emlrtHadParallelError) {
      emlrtHeapReferenceStackLeaveScope(aTLS, 4);
      emxFree_real_T(&prevMu);
      emxFreeStruct_struct_T(&modelX);
      emxFree_real_T(&X);
      emxFree_real_T(&c_image);
    }
  }

  emlrtPopJmpBuf(aTLS, &emlrtJBStack);
  emlrtExitParallelRegion(aTLS, omp_in_parallel());
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

/* End of code generation (mog.c) */
