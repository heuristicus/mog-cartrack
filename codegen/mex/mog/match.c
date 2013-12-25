/*
 * match.c
 *
 * Code generation for function 'match'
 *
 * C source code generated on: Wed Dec 25 11:02:59 2013
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
static emlrtRSInfo r_emlrtRSI = { 14, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

static emlrtRTEInfo n_emlrtRTEI = { 1, 16, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

static emlrtRTEInfo o_emlrtRTEI = { 13, 1, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

static emlrtECInfo emlrtECI = { 2, 13, 9, "match",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m" };

/* Function Definitions */
void match(emlrtCTX aTLS, const emxArray_real_T *X, const emxArray_real_T *mu,
           const real_T sigma[3], real_T D[3])
{
  emxArray_real_T *b_X;
  int32_T i;
  int32_T i7;
  int32_T i8;
  int32_T c_X[2];
  int32_T b_mu[2];
  emxArray_real_T *delta;
  emxArray_real_T *a;
  const mxArray *y;
  static const int32_T iv4[2] = { 1, 21 };

  const mxArray *m2;
  char_T cv8[21];
  static const char_T cv9[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  real_T b_y[9];
  int32_T i9;
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
  emlrtHeapReferenceStackEnterFcnR2012b(aTLS);
  emxInit_real_T(aTLS, &b_X, 2, &n_emlrtRTEI, TRUE);

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
  i7 = b_X->size[0] * b_X->size[1];
  b_X->size[0] = i;
  b_X->size[1] = 3;
  emxEnsureCapacity(aTLS, (emxArray__common *)b_X, i7, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  for (i7 = 0; i7 < 3; i7++) {
    for (i8 = 0; i8 < i; i8++) {
      b_X->data[i8 + b_X->size[0] * i7] = X->data[i8];
    }
  }

  for (i7 = 0; i7 < 2; i7++) {
    c_X[i7] = b_X->size[i7];
  }

  emxFree_real_T(&b_X);
  for (i7 = 0; i7 < 2; i7++) {
    b_mu[i7] = mu->size[i7];
  }

  emxInit_real_T(aTLS, &delta, 2, &o_emlrtRTEI, TRUE);
  emlrtSizeEqCheck2DFastR2012b(c_X, b_mu, &emlrtECI, aTLS);
  i = X->size[0];
  i7 = delta->size[0] * delta->size[1];
  delta->size[0] = i;
  delta->size[1] = 3;
  emxEnsureCapacity(aTLS, (emxArray__common *)delta, i7, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  for (i7 = 0; i7 < 3; i7++) {
    for (i8 = 0; i8 < i; i8++) {
      delta->data[i8 + delta->size[0] * i7] = X->data[i8] - mu->data[i8 +
        mu->size[0] * i7];
    }
  }

  emxInit_real_T(aTLS, &a, 2, &n_emlrtRTEI, TRUE);

  /* CxK */
  emlrtPushRtStackR2012b(&r_emlrtRSI, aTLS);
  i7 = a->size[0] * a->size[1];
  a->size[0] = 3;
  a->size[1] = delta->size[0];
  emxEnsureCapacity(aTLS, (emxArray__common *)a, i7, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  i = delta->size[0];
  for (i7 = 0; i7 < i; i7++) {
    for (i8 = 0; i8 < 3; i8++) {
      a->data[i8 + a->size[0] * i7] = delta->data[i7 + delta->size[0] * i8];
    }
  }

  emlrtPushRtStackR2012b(&t_emlrtRSI, aTLS);
  if (!(a->size[1] == delta->size[0])) {
    emlrtAssertMATLABThread(aTLS, &d_emlrtRTEI);
    emlrtPushRtStackR2012b(&u_emlrtRSI, aTLS);
    y = NULL;
    m2 = mxCreateCharArray(2, iv4);
    for (i = 0; i < 21; i++) {
      cv8[i] = cv9[i];
    }

    emlrtInitCharArrayR2013a(aTLS, 21, m2, cv8);
    emlrtAssign(&y, m2);
    error(aTLS, message(aTLS, y, &g_emlrtMCI), &h_emlrtMCI);
    emlrtPopRtStackR2012b(&u_emlrtRSI, aTLS);
  }

  emlrtPopRtStackR2012b(&t_emlrtRSI, aTLS);
  if ((a->size[1] == 1) || (delta->size[0] == 1)) {
    for (i7 = 0; i7 < 3; i7++) {
      for (i8 = 0; i8 < 3; i8++) {
        b_y[i7 + 3 * i8] = 0.0;
        i = a->size[1];
        for (i9 = 0; i9 < i; i9++) {
          b_y[i7 + 3 * i8] += a->data[i7 + a->size[0] * i9] * delta->data[i9 +
            delta->size[0] * i8];
        }
      }
    }
  } else {
    emlrtPushRtStackR2012b(&s_emlrtRSI, aTLS);
    emlrtPushRtStackR2012b(&v_emlrtRSI, aTLS);
    memset(&b_y[0], 0, 9U * sizeof(real_T));
    if (a->size[1] < 1) {
    } else {
      emlrtPushRtStackR2012b(&x_emlrtRSI, aTLS);
      alpha1 = 1.0;
      beta1 = 0.0;
      TRANSB = 'N';
      TRANSA = 'N';
      emlrtPushRtStackR2012b(&cb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&ob_emlrtRSI, aTLS);
      m_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&ob_emlrtRSI, aTLS);
      emlrtPopRtStackR2012b(&cb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&db_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&ob_emlrtRSI, aTLS);
      n_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&ob_emlrtRSI, aTLS);
      emlrtPopRtStackR2012b(&db_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&eb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&ob_emlrtRSI, aTLS);
      k_t = (ptrdiff_t)(a->size[1]);
      emlrtPopRtStackR2012b(&ob_emlrtRSI, aTLS);
      emlrtPopRtStackR2012b(&eb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&fb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&ob_emlrtRSI, aTLS);
      lda_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&ob_emlrtRSI, aTLS);
      emlrtPopRtStackR2012b(&fb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&gb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&ob_emlrtRSI, aTLS);
      ldb_t = (ptrdiff_t)(a->size[1]);
      emlrtPopRtStackR2012b(&ob_emlrtRSI, aTLS);
      emlrtPopRtStackR2012b(&gb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&hb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&ob_emlrtRSI, aTLS);
      ldc_t = (ptrdiff_t)(3);
      emlrtPopRtStackR2012b(&ob_emlrtRSI, aTLS);
      emlrtPopRtStackR2012b(&hb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&ib_emlrtRSI, aTLS);
      alpha1_t = (double *)(&alpha1);
      emlrtPopRtStackR2012b(&ib_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&jb_emlrtRSI, aTLS);
      Aia0_t = (double *)(&a->data[0]);
      emlrtPopRtStackR2012b(&jb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&kb_emlrtRSI, aTLS);
      Bib0_t = (double *)(&delta->data[0]);
      emlrtPopRtStackR2012b(&kb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&lb_emlrtRSI, aTLS);
      beta1_t = (double *)(&beta1);
      emlrtPopRtStackR2012b(&lb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&mb_emlrtRSI, aTLS);
      Cic0_t = (double *)(&b_y[0]);
      emlrtPopRtStackR2012b(&mb_emlrtRSI, aTLS);
      emlrtPushRtStackR2012b(&nb_emlrtRSI, aTLS);
      dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, alpha1_t, Aia0_t, &lda_t, Bib0_t,
            &ldb_t, beta1_t, Cic0_t, &ldc_t);
      emlrtPopRtStackR2012b(&nb_emlrtRSI, aTLS);
      emlrtPopRtStackR2012b(&x_emlrtRSI, aTLS);
    }

    emlrtPopRtStackR2012b(&v_emlrtRSI, aTLS);
    emlrtPopRtStackR2012b(&s_emlrtRSI, aTLS);
  }

  emxFree_real_T(&a);
  emxFree_real_T(&delta);
  for (i7 = 0; i7 < 3; i7++) {
    D[i7] = b_y[i7 << 2] / sigma[i7];
  }

  emlrtPopRtStackR2012b(&r_emlrtRSI, aTLS);

  /* Mahalanobis distance^2 (faster) */
  emlrtHeapReferenceStackLeaveFcnR2012b(aTLS);
}

/* End of code generation (match.c) */
