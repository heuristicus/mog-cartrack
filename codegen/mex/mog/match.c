/*
 * match.c
 *
 * Code generation for function 'match'
 *
 * C source code generated on: Wed Dec 25 12:08:53 2013
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
static emlrtRSInfo t_emlrtRSI = { 14, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

static emlrtRTEInfo i_emlrtRTEI = { 1, 16, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

static emlrtRTEInfo j_emlrtRTEI = { 13, 1, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

static emlrtECInfo b_emlrtECI = { 2, 13, 9, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

/* Function Definitions */
void match(const emxArray_real_T *X, const emxArray_real_T *mu, const real_T
           sigma[3], real_T D[3])
{
  emxArray_real_T *b_X;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T c_X[2];
  int32_T b_mu[2];
  emxArray_real_T *delta;
  emxArray_real_T *a;
  const mxArray *y;
  static const int32_T iv5[2] = { 1, 21 };

  const mxArray *m2;
  char_T cv6[21];
  static const char_T cv7[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  real_T b_y[9];
  int32_T i3;
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
  emxInit_real_T(&b_X, 2, &i_emlrtRTEI, TRUE);

  /* MATCH Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  Inputs: */
  /*              X:          Cx1 */
  /*              mu:         CxK */
  /*              sigma:      Kx1 */
  /*  Outputs: */
  /*              match:      Kx1 */
  /* Compute Mahalanobis distance */
  i = X->size[0];
  i1 = b_X->size[0] * b_X->size[1];
  b_X->size[0] = i;
  b_X->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)b_X, i1, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < i; i2++) {
      b_X->data[i2 + b_X->size[0] * i1] = X->data[i2];
    }
  }

  for (i1 = 0; i1 < 2; i1++) {
    c_X[i1] = b_X->size[i1];
  }

  emxFree_real_T(&b_X);
  for (i1 = 0; i1 < 2; i1++) {
    b_mu[i1] = mu->size[i1];
  }

  emxInit_real_T(&delta, 2, &j_emlrtRTEI, TRUE);
  emlrtSizeEqCheck2DFastR2012b(c_X, b_mu, &b_emlrtECI, emlrtRootTLSGlobal);
  i = X->size[0];
  i1 = delta->size[0] * delta->size[1];
  delta->size[0] = i;
  delta->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)delta, i1, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  for (i1 = 0; i1 < 3; i1++) {
    for (i2 = 0; i2 < i; i2++) {
      delta->data[i2 + delta->size[0] * i1] = X->data[i2] - mu->data[i2 +
        mu->size[0] * i1];
    }
  }

  emxInit_real_T(&a, 2, &i_emlrtRTEI, TRUE);

  /* CxK */
  emlrtPushRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);
  i1 = a->size[0] * a->size[1];
  a->size[0] = 3;
  a->size[1] = delta->size[0];
  emxEnsureCapacity((emxArray__common *)a, i1, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  i = delta->size[0];
  for (i1 = 0; i1 < i; i1++) {
    for (i2 = 0; i2 < 3; i2++) {
      a->data[i2 + a->size[0] * i1] = delta->data[i1 + delta->size[0] * i2];
    }
  }

  emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
  if (!(a->size[1] == delta->size[0])) {
    emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    y = NULL;
    m2 = mxCreateCharArray(2, iv5);
    for (i = 0; i < 21; i++) {
      cv6[i] = cv7[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m2, cv6);
    emlrtAssign(&y, m2);
    error(message(y, &g_emlrtMCI), &h_emlrtMCI);
    emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
  if ((a->size[1] == 1) || (delta->size[0] == 1)) {
    for (i1 = 0; i1 < 3; i1++) {
      for (i2 = 0; i2 < 3; i2++) {
        b_y[i1 + 3 * i2] = 0.0;
        i = a->size[1];
        for (i3 = 0; i3 < i; i3++) {
          b_y[i1 + 3 * i2] += a->data[i1 + a->size[0] * i3] * delta->data[i3 +
            delta->size[0] * i2];
        }
      }
    }
  } else {
    emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    memset(&b_y[0], 0, 9U * sizeof(real_T));
    if (a->size[1] < 1) {
    } else {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      emlrtPushRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      m_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&eb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      n_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&fb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      k_t = (ptrdiff_t)(a->size[1]);
      emlrtPopRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&gb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&hb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      lda_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&hb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      ldb_t = (ptrdiff_t)(a->size[1]);
      emlrtPopRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ib_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&jb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      ldc_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&qb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&jb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
      alpha1_t = (double *)(&alpha1);
      emlrtPopRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
      Aia0_t = (double *)(&a->data[0]);
      emlrtPopRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mb_emlrtRSI, emlrtRootTLSGlobal);
      Bib0_t = (double *)(&delta->data[0]);
      emlrtPopRtStackR2012b(&mb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&nb_emlrtRSI, emlrtRootTLSGlobal);
      beta1_t = (double *)(&beta1);
      emlrtPopRtStackR2012b(&nb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ob_emlrtRSI, emlrtRootTLSGlobal);
      Cic0_t = (double *)(&b_y[0]);
      emlrtPopRtStackR2012b(&ob_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&pb_emlrtRSI, emlrtRootTLSGlobal);
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t, Bib0_t,
            &ldb_t, beta1_t, Cic0_t, &ldc_t);
      emlrtPopRtStackR2012b(&pb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPopRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
    }

    emlrtPopRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
  }

  emxFree_real_T(&a);
  emxFree_real_T(&delta);
  for (i1 = 0; i1 < 3; i1++) {
    D[i1] = b_y[i1 << 2] / sigma[i1];
  }

  emlrtPopRtStackR2012b(&t_emlrtRSI, emlrtRootTLSGlobal);

  /* Mahalanobis distance^2 (faster) */
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (match.c) */
