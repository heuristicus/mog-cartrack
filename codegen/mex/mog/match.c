/*
 * match.c
 *
 * Code generation for function 'match'
 *
 * C source code generated on: Sat Dec 28 17:42:20 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "match.h"
#include "mog_emxutil.h"
#include "mog_mexutil.h"
#include "mog_data.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = { 16, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

static emlrtRTEInfo j_emlrtRTEI = { 1, 16, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

static emlrtRTEInfo k_emlrtRTEI = { 15, 1, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

static emlrtECInfo b_emlrtECI = { 2, 15, 9, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

/* Function Definitions */
void match(const emxArray_real_T *X, const emxArray_real_T *mu, const real_T
           sigma[3], boolean_T D[3])
{
  emxArray_real_T *b_X;
  int32_T i;
  int32_T i2;
  int32_T i3;
  int32_T c_X[2];
  int32_T b_mu[2];
  emxArray_real_T *delta;
  emxArray_real_T *a;
  const mxArray *y;
  static const int32_T iv4[2] = { 1, 21 };

  const mxArray *m2;
  char_T cv6[21];
  static const char_T cv7[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  real_T b_y[9];
  int32_T i4;
  real_T alpha1;
  real_T beta1;
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  double * alpha1_t;
  double * Aia0_t;
  double * Bib0_t;
  double * beta1_t;
  double * Cic0_t;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&b_X, 2, &j_emlrtRTEI, TRUE);

  /* MATCH Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  Inputs: */
  /*              X:          Cx1 */
  /*              mu:         CxK */
  /*              sigma:      Kx1 */
  /*  Outputs: */
  /*              match:      Kx1 */
  /* Compute Mahalanobis distance */
  /* 2.5^2; */
  i = X->size[0];
  i2 = b_X->size[0] * b_X->size[1];
  b_X->size[0] = i;
  b_X->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)b_X, i2, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  for (i2 = 0; i2 < 3; i2++) {
    for (i3 = 0; i3 < i; i3++) {
      b_X->data[i3 + b_X->size[0] * i2] = X->data[i3];
    }
  }

  for (i2 = 0; i2 < 2; i2++) {
    c_X[i2] = b_X->size[i2];
  }

  emxFree_real_T(&b_X);
  for (i2 = 0; i2 < 2; i2++) {
    b_mu[i2] = mu->size[i2];
  }

  emxInit_real_T(&delta, 2, &k_emlrtRTEI, TRUE);
  emlrtSizeEqCheck2DFastR2012b(c_X, b_mu, &b_emlrtECI, emlrtRootTLSGlobal);
  i = X->size[0];
  i2 = delta->size[0] * delta->size[1];
  delta->size[0] = i;
  delta->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)delta, i2, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  for (i2 = 0; i2 < 3; i2++) {
    for (i3 = 0; i3 < i; i3++) {
      delta->data[i3 + delta->size[0] * i2] = X->data[i3] - mu->data[i3 +
        mu->size[0] * i2];
    }
  }

  emxInit_real_T(&a, 2, &j_emlrtRTEI, TRUE);

  /* CxK */
  emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  i2 = a->size[0] * a->size[1];
  a->size[0] = 3;
  a->size[1] = delta->size[0];
  emxEnsureCapacity((emxArray__common *)a, i2, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  i = delta->size[0];
  for (i2 = 0; i2 < i; i2++) {
    for (i3 = 0; i3 < 3; i3++) {
      a->data[i3 + a->size[0] * i2] = delta->data[i2 + delta->size[0] * i3];
    }
  }

  emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  if (!(a->size[1] == delta->size[0])) {
    emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    y = NULL;
    m2 = mxCreateCharArray(2, iv4);
    for (i = 0; i < 21; i++) {
      cv6[i] = cv7[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m2, cv6);
    emlrtAssign(&y, m2);
    error(message(y, &g_emlrtMCI), &h_emlrtMCI);
    emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  if ((a->size[1] == 1) || (delta->size[0] == 1)) {
    for (i2 = 0; i2 < 3; i2++) {
      for (i3 = 0; i3 < 3; i3++) {
        b_y[i2 + 3 * i3] = 0.0;
        i = a->size[1];
        for (i4 = 0; i4 < i; i4++) {
          b_y[i2 + 3 * i3] += a->data[i2 + a->size[0] * i4] * delta->data[i4 +
            delta->size[0] * i3];
        }
      }
    }
  } else {
    emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
    memset(&b_y[0], 0, 9U * sizeof(real_T));
    if (a->size[1] < 1) {
    } else {
      emlrtPushRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      emlrtPushRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      m_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      n_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&hb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      k_t = (ptrdiff_t)(a->size[1]);
      emlrtPopRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&hb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      lda_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&jb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      ldb_t = (ptrdiff_t)(a->size[1]);
      emlrtPopRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&jb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      ldc_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
      alpha1_t = (double *)(&alpha1);
      emlrtPopRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mb_emlrtRSI, emlrtRootTLSGlobal);
      Aia0_t = (double *)(&a->data[0]);
      emlrtPopRtStackR2012b(&mb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&nb_emlrtRSI, emlrtRootTLSGlobal);
      Bib0_t = (double *)(&delta->data[0]);
      emlrtPopRtStackR2012b(&nb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ob_emlrtRSI, emlrtRootTLSGlobal);
      beta1_t = (double *)(&beta1);
      emlrtPopRtStackR2012b(&ob_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pb_emlrtRSI, emlrtRootTLSGlobal);
      Cic0_t = (double *)(&b_y[0]);
      emlrtPopRtStackR2012b(&pb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t, Bib0_t,
            &ldb_t, beta1_t, Cic0_t, &ldc_t);
      emlrtPopRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&bb_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&y_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&a);
  emxFree_real_T(&delta);
  for (i2 = 0; i2 < 3; i2++) {
    D[i2] = (b_y[i2 << 2] / sigma[i2] < 6.25);
  }

  emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);

  /* Mahalanobis distance^2 (faster) */
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (match.c) */
