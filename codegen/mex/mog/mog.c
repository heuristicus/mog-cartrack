/*
 * mog.c
 *
 * Code generation for function 'mog'
 *
 * C source code generated on: Wed Dec 25 12:08:53 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "mog_emxutil.h"
#include "match.h"
#include "update.h"
#include "mog_mexutil.h"
#include "mog_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 72, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRSInfo b_emlrtRSI = { 68, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRSInfo c_emlrtRSI = { 46, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRSInfo d_emlrtRSI = { 28, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRSInfo e_emlrtRSI = { 20, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRSInfo f_emlrtRSI = { 11, "repmat",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m" };

static emlrtRSInfo g_emlrtRSI = { 19, "repmat",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/repmat.m" };

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

static emlrtRSInfo o_emlrtRSI = { 12, "eml_int_forloop_overflow_check",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo tb_emlrtRSI = { 41, "find",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo ub_emlrtRSI = { 230, "find",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/find.m" };

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

static emlrtRTEInfo b_emlrtRTEI = { 1, 36, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRTEInfo c_emlrtRTEI = { 65, 1, "reshape",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/elmat/reshape.m" };

static emlrtRTEInfo e_emlrtRTEI = { 28, 9, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRTEInfo f_emlrtRTEI = { 31, 9, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtRTEInfo g_emlrtRTEI = { 1, 22, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtECInfo emlrtECI = { -1, 65, 9, "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 65, 22, "background", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 65, 20, "background", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 34, 27, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 34, 25, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 28, 29, "image", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 28, 27, "image", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 48, 16, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 48, 18, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 49, 16, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 49, 18, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 50, 16, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 50, 18, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 52, 16, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 52, 18, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 53, 16, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 53, 18, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 54, 16, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 54, 18, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 75, 24, "foreground", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 75, 26, "foreground", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 65, 36, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 65, 38, "models", "mog",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m", 0 };

/* Function Declarations */
static const mxArray *b_message(const mxArray *b, const mxArray *c, emlrtMCInfo *
  location);
static void check_forloop_overflow_error(void);
static void eml_error(void);
static void eml_sort(const real_T x[3], real_T y[3], int32_T idx[3]);

/* Function Definitions */
static const mxArray *b_message(const mxArray *b, const mxArray *c, emlrtMCInfo *
  location)
{
  const mxArray *pArrays[2];
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m7, 2, pArrays, "message",
    TRUE, location);
}

static void check_forloop_overflow_error(void)
{
  const mxArray *y;
  static const int32_T iv3[2] = { 1, 34 };

  const mxArray *m1;
  char_T cv2[34];
  int32_T i;
  static const char_T cv3[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o',
    'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *b_y;
  static const int32_T iv4[2] = { 1, 23 };

  char_T cv4[23];
  static const char_T cv5[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't',
    'e', 'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  emlrtPushRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
  y = NULL;
  m1 = mxCreateCharArray(2, iv3);
  for (i = 0; i < 34; i++) {
    cv2[i] = cv3[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 34, m1, cv2);
  emlrtAssign(&y, m1);
  b_y = NULL;
  m1 = mxCreateCharArray(2, iv4);
  for (i = 0; i < 23; i++) {
    cv4[i] = cv5[i];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 23, m1, cv4);
  emlrtAssign(&b_y, m1);
  error(b_message(y, b_y, &e_emlrtMCI), &f_emlrtMCI);
  emlrtPopRtStackR2012b(&m_emlrtRSI, emlrtRootTLSGlobal);
}

static void eml_error(void)
{
  emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &n_emlrtRTEI,
    "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
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

void mog(const emxArray_real_T *image, real_T count, emxArray_real_T *foreground,
         emxArray_uint8_T *background)
{
  struct_T a;
  int32_T i;
  int32_T i0;
  int32_T b_image[2];
  int32_T outsize[2];
  emxArray_real_T *b_background;
  int32_T m;
  emxArray_real_T *X;
  emxArray_real_T *prevMu;
  emxArray_real_T *r0;
  emxArray_int32_T *r1;
  emxArray_real_T *c_image;
  struct_T r2;
  struct_T r3;
  struct_T r4;
  struct_T r5;
  emxArray_real_T *r6;
  emxArray_real_T *r7;
  int32_T n;
  int32_T ix;
  int32_T sz_idx_0;
  uint32_T varargin_1[3];
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 40 };

  const mxArray *m0;
  char_T cv0[40];
  static const char_T cv1[40] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'g', 'e', 't', 'R', 'e', 's', 'h', 'a', 'p', 'e', 'D',
    'i', 'm', 's', '_', 'n', 'o', 't', 'S', 'a', 'm', 'e', 'N', 'u', 'm', 'e',
    'l' };

  boolean_T overflow;
  int32_T exitg3;
  real_T prevWeight[3];
  real_T prevSigma[3];
  real_T b_prevWeight[3];
  int32_T iidx[3];
  real_T xlast;
  boolean_T b_varargin_1[3];
  int32_T itmp;
  int32_T bgIndexes_data[3];
  int32_T iv1[3];
  int32_T iv2[1];
  int8_T ii_data[3];
  boolean_T exitg2;
  boolean_T guard1 = FALSE;
  int8_T b_ii_data[3];
  boolean_T x_data[3];
  boolean_T exitg1;
  uint8_T u0;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /* MOG Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  Inputs: */
  /*          image:              MxNxC */
  /*           */
  /*  Outputs */
  /*          foreground:         MxN */
  /*          background:         MxNxC */
  /* Number of Gaussians */
  /* Background Threshold */
  if (!models_not_empty) {
    emxInitStruct_struct_T(&a, &b_emlrtRTEI, TRUE);
    for (i = 0; i < 3; i++) {
      a.weight[i] = 0.0;
    }

    i = image->size[2];
    i0 = a.mu->size[0] * a.mu->size[1];
    a.mu->size[0] = i;
    a.mu->size[1] = 3;
    emxEnsureCapacity((emxArray__common *)a.mu, i0, (int32_T)sizeof(real_T),
                      &b_emlrtRTEI);
    i = image->size[2] * 3;
    for (i0 = 0; i0 < i; i0++) {
      a.mu->data[i0] = 0.0;
    }

    for (i = 0; i < 3; i++) {
      a.sigma[i] = 0.0;
    }

    emlrtPushRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
    b_image[0] = image->size[0];
    b_image[1] = image->size[1];
    for (i0 = 0; i0 < 2; i0++) {
      outsize[i0] = b_image[i0];
    }

    i0 = models->size[0] * models->size[1];
    models->size[0] = outsize[0];
    emxEnsureCapacity_struct_T(models, i0, &b_emlrtRTEI);
    i0 = models->size[0] * models->size[1];
    models->size[1] = outsize[1];
    emxEnsureCapacity_struct_T(models, i0, &b_emlrtRTEI);
    i = outsize[0] * outsize[1];
    for (i0 = 0; i0 < i; i0++) {
      emxCopyStruct_struct_T(&models->data[i0], &a, &b_emlrtRTEI);
    }

    emxFreeStruct_struct_T(&a);
    emlrtPopRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
    models_not_empty = !((models->size[0] == 0) || (models->size[1] == 0));
  }

  i = image->size[0];
  i0 = foreground->size[0] * foreground->size[1];
  foreground->size[0] = i;
  emxEnsureCapacity((emxArray__common *)foreground, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  i = image->size[1];
  i0 = foreground->size[0] * foreground->size[1];
  foreground->size[1] = i;
  emxEnsureCapacity((emxArray__common *)foreground, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  i = image->size[0] * image->size[1];
  for (i0 = 0; i0 < i; i0++) {
    foreground->data[i0] = 0.0;
  }

  c_emxInit_real_T(&b_background, 3, &g_emlrtRTEI, TRUE);
  i = image->size[0];
  i0 = b_background->size[0] * b_background->size[1] * b_background->size[2];
  b_background->size[0] = i;
  emxEnsureCapacity((emxArray__common *)b_background, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  i = image->size[1];
  i0 = b_background->size[0] * b_background->size[1] * b_background->size[2];
  b_background->size[1] = i;
  emxEnsureCapacity((emxArray__common *)b_background, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  i = image->size[2];
  i0 = b_background->size[0] * b_background->size[1] * b_background->size[2];
  b_background->size[2] = i;
  emxEnsureCapacity((emxArray__common *)b_background, i0, (int32_T)sizeof(real_T),
                    &b_emlrtRTEI);
  i = image->size[0] * image->size[1] * image->size[2];
  for (i0 = 0; i0 < i; i0++) {
    b_background->data[i0] = 0.0;
  }

  m = 1;
  b_emxInit_real_T(&X, 1, &e_emlrtRTEI, TRUE);
  emxInit_real_T(&prevMu, 2, &f_emlrtRTEI, TRUE);
  emxInit_real_T(&r0, 2, &b_emlrtRTEI, TRUE);
  emxInit_int32_T(&r1, 1, &b_emlrtRTEI, TRUE);
  c_emxInit_real_T(&c_image, 3, &b_emlrtRTEI, TRUE);
  emxInitStruct_struct_T(&r2, &b_emlrtRTEI, TRUE);
  emxInitStruct_struct_T(&r3, &b_emlrtRTEI, TRUE);
  emxInitStruct_struct_T(&r4, &b_emlrtRTEI, TRUE);
  emxInitStruct_struct_T(&r5, &b_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r6, 1, &b_emlrtRTEI, TRUE);
  b_emxInit_real_T(&r7, 1, &b_emlrtRTEI, TRUE);
  while (m - 1 <= image->size[0] - 1) {
    n = 1;
    while (n - 1 <= image->size[1] - 1) {
      emlrtPushRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
      i0 = image->size[0];
      ix = (int32_T)(1.0 + (real_T)(m - 1));
      emlrtDynamicBoundsCheckFastR2012b(ix, 1, i0, &f_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = image->size[1];
      ix = (int32_T)(1.0 + (real_T)(n - 1));
      emlrtDynamicBoundsCheckFastR2012b(ix, 1, i0, &e_emlrtBCI,
        emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
      sz_idx_0 = image->size[2];
      i = image->size[2];
      i0 = c_image->size[0] * c_image->size[1] * c_image->size[2];
      c_image->size[0] = 1;
      c_image->size[1] = 1;
      c_image->size[2] = i;
      emxEnsureCapacity((emxArray__common *)c_image, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i0 = 0; i0 < i; i0++) {
        c_image->data[c_image->size[0] * c_image->size[1] * i0] = image->data
          [((m + image->size[0] * (n - 1)) + image->size[0] * image->size[1] *
            i0) - 1];
      }

      for (i0 = 0; i0 < 3; i0++) {
        varargin_1[i0] = (uint32_T)c_image->size[i0];
      }

      i = 1;
      for (ix = 0; ix < 2; ix++) {
        if ((int32_T)varargin_1[ix + 1] > i) {
          i = (int32_T)varargin_1[ix + 1];
        }
      }

      i0 = image->size[2];
      if (i0 < i) {
      } else {
        i = image->size[2];
      }

      if (sz_idx_0 > i) {
        emlrtPushRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
        eml_error();
        emlrtPopRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
      }

      if (1 > i) {
        emlrtPushRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
        eml_error();
        emlrtPopRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
      }

      i0 = X->size[0];
      X->size[0] = image->size[2];
      emxEnsureCapacity((emxArray__common *)X, i0, (int32_T)sizeof(real_T),
                        &c_emlrtRTEI);
      i0 = image->size[2];
      i = image->size[2];
      if (i0 == i) {
      } else {
        emlrtPushRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
        y = NULL;
        m0 = mxCreateCharArray(2, iv0);
        for (i = 0; i < 40; i++) {
          cv0[i] = cv1[i];
        }

        emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 40, m0, cv0);
        emlrtAssign(&y, m0);
        error(message(y, &c_emlrtMCI), &d_emlrtMCI);
        emlrtPopRtStackR2012b(&k_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPushRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
      i0 = image->size[2];
      if (1 > i0) {
        overflow = FALSE;
      } else {
        i0 = image->size[2];
        overflow = (i0 > 2147483646);
      }

      if (overflow) {
        emlrtPushRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
        check_forloop_overflow_error();
        emlrtPopRtStackR2012b(&o_emlrtRSI, emlrtRootTLSGlobal);
      }

      emlrtPopRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
      i = 1;
      do {
        exitg3 = 0;
        i0 = image->size[2];
        if (i <= i0) {
          X->data[i - 1] = image->data[((m + image->size[0] * (n - 1)) +
            image->size[0] * image->size[1] * (i - 1)) - 1];
          i++;
        } else {
          exitg3 = 1;
        }
      } while (exitg3 == 0);

      emlrtPopRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);

      /* Preallocate */
      i0 = models->size[0];
      ix = (int32_T)(1.0 + (real_T)(m - 1));
      emlrtDynamicBoundsCheckFastR2012b(ix, 1, i0, &d_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = models->size[1];
      ix = (int32_T)(1.0 + (real_T)(n - 1));
      emlrtDynamicBoundsCheckFastR2012b(ix, 1, i0, &c_emlrtBCI,
        emlrtRootTLSGlobal);
      for (i0 = 0; i0 < 3; i0++) {
        prevWeight[i0] = models->data[(m + models->size[0] * (n - 1)) - 1].
          weight[i0];
      }

      i0 = prevMu->size[0] * prevMu->size[1];
      prevMu->size[0] = models->data[(m + models->size[0] * (n - 1)) - 1]
        .mu->size[0];
      prevMu->size[1] = 3;
      emxEnsureCapacity((emxArray__common *)prevMu, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      i = models->data[(m + models->size[0] * (n - 1)) - 1].mu->size[0] *
        models->data[(m + models->size[0] * (n - 1)) - 1].mu->size[1];
      for (i0 = 0; i0 < i; i0++) {
        prevMu->data[i0] = models->data[(m + models->size[0] * (n - 1)) - 1].
          mu->data[i0];
      }

      for (i0 = 0; i0 < 3; i0++) {
        prevSigma[i0] = models->data[(m + models->size[0] * (n - 1)) - 1]
          .sigma[i0];
      }

      /* Initialization (first frame) */
      if (count == 1.0) {
        /*          if(isempty(prevWeight) || isempty(prevMu) || isempty(prevSigma)) */
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
        /* nxK    %Current pixel value */
        /* Large sigma */
        for (i = 0; i < 3; i++) {
          prevWeight[i] = 0.33333333333333331;
        }

        i = X->size[0];
        i0 = prevMu->size[0] * prevMu->size[1];
        prevMu->size[0] = i;
        prevMu->size[1] = 3;
        emxEnsureCapacity((emxArray__common *)prevMu, i0, (int32_T)sizeof(real_T),
                          &b_emlrtRTEI);
        for (i0 = 0; i0 < 3; i0++) {
          for (ix = 0; ix < i; ix++) {
            prevMu->data[ix + prevMu->size[0] * i0] = X->data[ix];
          }
        }

        for (i = 0; i < 3; i++) {
          prevSigma[i] = 100.0;
        }
      }

      /* Update model */
      emlrtPushRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
      update(X, prevWeight, prevMu, prevSigma);
      emlrtPopRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
      i0 = models->size[0];
      ix = models->size[1];
      for (sz_idx_0 = 0; sz_idx_0 < 3; sz_idx_0++) {
        models->data[(emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &g_emlrtBCI,
          emlrtRootTLSGlobal) + models->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(n, 1, ix, &h_emlrtBCI,
          emlrtRootTLSGlobal) - 1)) - 1].weight[sz_idx_0] = 0.0;
      }

      i = image->size[2];
      i0 = models->size[0];
      ix = models->size[1];
      i0 = (emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &i_emlrtBCI,
             emlrtRootTLSGlobal) + models->size[0] *
            (emlrtDynamicBoundsCheckFastR2012b(n, 1, ix, &j_emlrtBCI,
              emlrtRootTLSGlobal) - 1)) - 1;
      ix = models->data[i0].mu->size[0] * models->data[i0].mu->size[1];
      models->data[i0].mu->size[0] = i;
      i0 = models->size[0];
      sz_idx_0 = models->size[1];
      i0 = (emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &i_emlrtBCI,
             emlrtRootTLSGlobal) + models->size[0] *
            (emlrtDynamicBoundsCheckFastR2012b(n, 1, sz_idx_0, &j_emlrtBCI,
              emlrtRootTLSGlobal) - 1)) - 1;
      models->data[i0].mu->size[1] = 3;
      emxEnsureCapacity((emxArray__common *)models->data[i0].mu, ix, (int32_T)
                        sizeof(real_T), &b_emlrtRTEI);
      i0 = models->size[0];
      ix = models->size[1];
      sz_idx_0 = models->size[0];
      i = models->size[1];
      emxCopyStruct_struct_T(&r2, &models->data
        [(emlrtDynamicBoundsCheckFastR2012b(m, 1, sz_idx_0, &i_emlrtBCI,
        emlrtRootTLSGlobal) + models->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(n, 1, i, &j_emlrtBCI,
        emlrtRootTLSGlobal) - 1)) - 1], &b_emlrtRTEI);
      sz_idx_0 = models->size[0];
      i = models->size[1];
      emxCopyStruct_struct_T(&r3, &models->data
        [(emlrtDynamicBoundsCheckFastR2012b(m, 1, sz_idx_0, &i_emlrtBCI,
        emlrtRootTLSGlobal) + models->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(n, 1, i, &j_emlrtBCI,
        emlrtRootTLSGlobal) - 1)) - 1], &b_emlrtRTEI);
      i = image->size[2] * 3;
      for (sz_idx_0 = 0; sz_idx_0 < i; sz_idx_0++) {
        models->data[(emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &i_emlrtBCI,
          emlrtRootTLSGlobal) + models->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(n, 1, ix, &j_emlrtBCI,
          emlrtRootTLSGlobal) - 1)) - 1].mu->data[sz_idx_0] = 0.0;
      }

      i0 = models->size[0];
      ix = models->size[1];
      for (sz_idx_0 = 0; sz_idx_0 < 3; sz_idx_0++) {
        models->data[(emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &k_emlrtBCI,
          emlrtRootTLSGlobal) + models->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(n, 1, ix, &l_emlrtBCI,
          emlrtRootTLSGlobal) - 1)) - 1].sigma[sz_idx_0] = 0.0;
      }

      i0 = models->size[0];
      ix = models->size[1];
      for (sz_idx_0 = 0; sz_idx_0 < 3; sz_idx_0++) {
        models->data[(emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &m_emlrtBCI,
          emlrtRootTLSGlobal) + models->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(n, 1, ix, &n_emlrtBCI,
          emlrtRootTLSGlobal) - 1)) - 1].weight[sz_idx_0] = prevWeight[sz_idx_0];
      }

      i0 = models->size[0];
      ix = models->size[1];
      i0 = (emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &o_emlrtBCI,
             emlrtRootTLSGlobal) + models->size[0] *
            (emlrtDynamicBoundsCheckFastR2012b(n, 1, ix, &p_emlrtBCI,
              emlrtRootTLSGlobal) - 1)) - 1;
      ix = models->data[i0].mu->size[0] * models->data[i0].mu->size[1];
      models->data[i0].mu->size[0] = prevMu->size[0];
      i0 = models->size[0];
      sz_idx_0 = models->size[1];
      i0 = (emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &o_emlrtBCI,
             emlrtRootTLSGlobal) + models->size[0] *
            (emlrtDynamicBoundsCheckFastR2012b(n, 1, sz_idx_0, &p_emlrtBCI,
              emlrtRootTLSGlobal) - 1)) - 1;
      models->data[i0].mu->size[1] = 3;
      emxEnsureCapacity((emxArray__common *)models->data[i0].mu, ix, (int32_T)
                        sizeof(real_T), &b_emlrtRTEI);
      i0 = models->size[0];
      ix = models->size[1];
      sz_idx_0 = models->size[0];
      i = models->size[1];
      emxCopyStruct_struct_T(&r4, &models->data
        [(emlrtDynamicBoundsCheckFastR2012b(m, 1, sz_idx_0, &o_emlrtBCI,
        emlrtRootTLSGlobal) + models->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(n, 1, i, &p_emlrtBCI,
        emlrtRootTLSGlobal) - 1)) - 1], &b_emlrtRTEI);
      sz_idx_0 = models->size[0];
      i = models->size[1];
      emxCopyStruct_struct_T(&r5, &models->data
        [(emlrtDynamicBoundsCheckFastR2012b(m, 1, sz_idx_0, &o_emlrtBCI,
        emlrtRootTLSGlobal) + models->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(n, 1, i, &p_emlrtBCI,
        emlrtRootTLSGlobal) - 1)) - 1], &b_emlrtRTEI);
      i = prevMu->size[0] * prevMu->size[1];
      for (sz_idx_0 = 0; sz_idx_0 < i; sz_idx_0++) {
        models->data[(emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &o_emlrtBCI,
          emlrtRootTLSGlobal) + models->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(n, 1, ix, &p_emlrtBCI,
          emlrtRootTLSGlobal) - 1)) - 1].mu->data[sz_idx_0] = prevMu->
          data[sz_idx_0];
      }

      i0 = models->size[0];
      ix = models->size[1];
      for (sz_idx_0 = 0; sz_idx_0 < 3; sz_idx_0++) {
        models->data[(emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &q_emlrtBCI,
          emlrtRootTLSGlobal) + models->size[0] *
                      (emlrtDynamicBoundsCheckFastR2012b(n, 1, ix, &r_emlrtBCI,
          emlrtRootTLSGlobal) - 1)) - 1].sigma[sz_idx_0] = prevSigma[sz_idx_0];
      }

      /* Sort weights/sigma */
      for (i = 0; i < 3; i++) {
        b_prevWeight[i] = prevWeight[i] / prevSigma[i];
      }

      eml_sort(b_prevWeight, prevWeight, iidx);

      /* Calculate B = number of background gaussians */
      ix = 0;
      xlast = prevWeight[0];
      for (i = 0; i < 2; i++) {
        ix++;
        xlast += prevWeight[ix];
        prevWeight[ix] = xlast;
      }

      for (i = 0; i < 3; i++) {
        b_varargin_1[i] = (prevWeight[i] > 0.7);
      }

      overflow = b_varargin_1[0];
      itmp = 0;
      for (ix = 0; ix < 2; ix++) {
        if (b_varargin_1[ix + 1] < overflow) {
          overflow = b_varargin_1[ix + 1];
          itmp = ix + 1;
        }
      }

      for (i0 = 0; i0 <= itmp; i0++) {
        bgIndexes_data[i0] = iidx[i0];
      }

      /* Set the background to the most likely gaussian */
      i0 = r0->size[0] * r0->size[1];
      ix = models->size[0];
      sz_idx_0 = models->size[1];
      r0->size[0] = models->data[(emlrtDynamicBoundsCheckFastR2012b(m, 1, ix,
        &u_emlrtBCI, emlrtRootTLSGlobal) + models->size[0] *
        (emlrtDynamicBoundsCheckFastR2012b(n, 1, sz_idx_0, &v_emlrtBCI,
        emlrtRootTLSGlobal) - 1)) - 1].mu->size[0];
      r0->size[1] = 3;
      emxEnsureCapacity((emxArray__common *)r0, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      i0 = models->size[0];
      ix = models->size[1];
      sz_idx_0 = models->size[0];
      i = models->size[1];
      i = models->data[(emlrtDynamicBoundsCheckFastR2012b(m, 1, i0, &u_emlrtBCI,
        emlrtRootTLSGlobal) + models->size[0] *
                        (emlrtDynamicBoundsCheckFastR2012b(n, 1, ix, &v_emlrtBCI,
        emlrtRootTLSGlobal) - 1)) - 1].mu->size[0] * models->data
        [(emlrtDynamicBoundsCheckFastR2012b(m, 1, sz_idx_0, &u_emlrtBCI,
           emlrtRootTLSGlobal) + models->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(n, 1, i, &v_emlrtBCI,
            emlrtRootTLSGlobal) - 1)) - 1].mu->size[1];
      for (i0 = 0; i0 < i; i0++) {
        ix = models->size[0];
        sz_idx_0 = models->size[1];
        r0->data[i0] = models->data[(emlrtDynamicBoundsCheckFastR2012b(m, 1, ix,
          &u_emlrtBCI, emlrtRootTLSGlobal) + models->size[0] *
          (emlrtDynamicBoundsCheckFastR2012b(n, 1, sz_idx_0, &v_emlrtBCI,
          emlrtRootTLSGlobal) - 1)) - 1].mu->data[i0];
      }

      i0 = b_background->size[0];
      ix = (int32_T)(1.0 + (real_T)(m - 1));
      emlrtDynamicBoundsCheckFastR2012b(ix, 1, i0, &b_emlrtBCI,
        emlrtRootTLSGlobal);
      i0 = b_background->size[1];
      ix = (int32_T)(1.0 + (real_T)(n - 1));
      emlrtDynamicBoundsCheckFastR2012b(ix, 1, i0, &emlrtBCI, emlrtRootTLSGlobal);
      i = b_background->size[2];
      i0 = r1->size[0];
      r1->size[0] = i;
      emxEnsureCapacity((emxArray__common *)r1, i0, (int32_T)sizeof(int32_T),
                        &b_emlrtRTEI);
      for (i0 = 0; i0 < i; i0++) {
        r1->data[i0] = i0;
      }

      iv1[0] = 1;
      iv1[1] = 1;
      iv1[2] = r1->size[0];
      i = models->data[(m + models->size[0] * (n - 1)) - 1].mu->size[0];
      i0 = r6->size[0];
      r6->size[0] = i;
      emxEnsureCapacity((emxArray__common *)r6, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i0 = 0; i0 < i; i0++) {
        r6->data[i0] = models->data[(m + models->size[0] * (n - 1)) - 1]
          .mu->data[i0 + models->data[(m + models->size[0] * (n - 1)) - 1]
          .mu->size[0] * (bgIndexes_data[0] - 1)];
      }

      iv2[0] = r6->size[0];
      emlrtSubAssignSizeCheckR2012b(iv1, 3, iv2, 1, &emlrtECI,
        emlrtRootTLSGlobal);
      i = r0->size[0];
      i0 = r7->size[0];
      r7->size[0] = i;
      emxEnsureCapacity((emxArray__common *)r7, i0, (int32_T)sizeof(real_T),
                        &b_emlrtRTEI);
      for (i0 = 0; i0 < i; i0++) {
        r7->data[i0] = r0->data[i0 + r0->size[0] * (bgIndexes_data[0] - 1)];
      }

      i = r1->size[0];
      for (i0 = 0; i0 < i; i0++) {
        ix = 0;
        while (ix <= 0) {
          ix = 0;
          while (ix <= 0) {
            b_background->data[((m + b_background->size[0] * (n - 1)) +
                                b_background->size[0] * b_background->size[1] *
                                r1->data[i0]) - 1] = r7->data[i0];
            ix = 1;
          }

          ix = 1;
        }
      }

      /* See if the pixel matches a background gaussian */
      emlrtPushRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
      match(X, prevMu, prevSigma, prevWeight);
      i = 0;
      sz_idx_0 = 1;
      exitg2 = FALSE;
      while ((exitg2 == FALSE) && (sz_idx_0 < 4)) {
        guard1 = FALSE;
        if (prevWeight[sz_idx_0 - 1] != 0.0) {
          i++;
          ii_data[i - 1] = (int8_T)sz_idx_0;
          if (i >= 3) {
            exitg2 = TRUE;
          } else {
            guard1 = TRUE;
          }
        } else {
          guard1 = TRUE;
        }

        if (guard1 == TRUE) {
          sz_idx_0++;
        }
      }

      if (1 > i) {
        i = 0;
      }

      for (i0 = 0; i0 < i; i0++) {
        b_ii_data[i0] = ii_data[i0];
      }

      for (i0 = 0; i0 < i; i0++) {
        ii_data[i0] = b_ii_data[i0];
      }

      for (i0 = 0; i0 < i; i0++) {
        bgIndexes_data[i0] = ii_data[i0];
      }

      emlrtPopRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
      if (i == 0) {
        bgIndexes_data[0] = -1;
      }

      emlrtPushRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);
      for (i0 = 0; i0 <= itmp; i0++) {
        x_data[i0] = (iidx[i0] == bgIndexes_data[0]);
      }

      emlrtPushRtStackR2012b(&tb_emlrtRSI, emlrtRootTLSGlobal);
      i = 0;
      ix = 1;
      emlrtPushRtStackR2012b(&ub_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ub_emlrtRSI, emlrtRootTLSGlobal);
      sz_idx_0 = 1;
      exitg1 = FALSE;
      while ((exitg1 == FALSE) && (sz_idx_0 <= itmp + 1)) {
        if (x_data[sz_idx_0 - 1]) {
          i = 1;
          exitg1 = TRUE;
        } else {
          sz_idx_0++;
        }
      }

      if (i == 0) {
        ix = 0;
      }

      emlrtPopRtStackR2012b(&tb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);

      /* No match => foreground */
      if (ix == 0) {
        i0 = foreground->size[0];
        ix = foreground->size[1];
        foreground->data[(emlrtDynamicBoundsCheckFastR2012b(m, 1, i0,
          &s_emlrtBCI, emlrtRootTLSGlobal) + foreground->size[0] *
                          (emlrtDynamicBoundsCheckFastR2012b(n, 1, ix,
          &t_emlrtBCI, emlrtRootTLSGlobal) - 1)) - 1] = 1.0;
      }

      n++;
      emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
    }

    m++;
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&r7);
  emxFree_real_T(&r6);
  emxFreeStruct_struct_T(&r5);
  emxFreeStruct_struct_T(&r4);
  emxFreeStruct_struct_T(&r3);
  emxFreeStruct_struct_T(&r2);
  emxFree_real_T(&c_image);
  emxFree_int32_T(&r1);
  emxFree_real_T(&r0);
  emxFree_real_T(&prevMu);
  emxFree_real_T(&X);
  i0 = background->size[0] * background->size[1] * background->size[2];
  background->size[0] = b_background->size[0];
  background->size[1] = b_background->size[1];
  background->size[2] = b_background->size[2];
  emxEnsureCapacity((emxArray__common *)background, i0, (int32_T)sizeof(uint8_T),
                    &b_emlrtRTEI);
  i = b_background->size[0] * b_background->size[1] * b_background->size[2];
  for (i0 = 0; i0 < i; i0++) {
    xlast = muDoubleScalarRound(b_background->data[i0]);
    if (xlast < 256.0) {
      if (xlast >= 0.0) {
        u0 = (uint8_T)xlast;
      } else {
        u0 = 0;
      }
    } else if (xlast >= 256.0) {
      u0 = MAX_uint8_T;
    } else {
      u0 = 0;
    }

    background->data[i0] = u0;
  }

  emxFree_real_T(&b_background);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (mog.c) */
