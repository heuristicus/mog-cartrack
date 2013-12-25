/*
 * update.c
 *
 * Code generation for function 'update'
 *
 * C source code generated on: Wed Dec 25 12:08:53 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "update.h"
#include "mog_emxutil.h"
#include "match.h"
#include "mog_mexutil.h"
#include "mog_data.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 23, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

static emlrtRSInfo q_emlrtRSI = { 32, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

static emlrtRSInfo r_emlrtRSI = { 35, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

static emlrtRSInfo s_emlrtRSI = { 42, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

static emlrtRSInfo rb_emlrtRSI = { 42, "power",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/ops/power.m" };

static emlrtRSInfo sb_emlrtRSI = { 56, "power",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/ops/power.m" };

static emlrtRTEInfo h_emlrtRTEI = { 1, 32, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

static emlrtRTEInfo l_emlrtRTEI = { 15, 9, "eml_scalexp_alloc",
  "C:/Program Files/MATLAB/R2013a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 34, 1, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

static emlrtECInfo c_emlrtECI = { 2, 34, 6, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

static emlrtECInfo d_emlrtECI = { 2, 35, 63, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

static emlrtECInfo e_emlrtECI = { 2, 40, 6, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

static emlrtECInfo f_emlrtECI = { 2, 40, 24, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

static emlrtECInfo g_emlrtECI = { -1, 46, 4, "update",
  "C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m" };

/* Function Declarations */
static void b_eml_error(void);

/* Function Definitions */
static void b_eml_error(void)
{
  emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
  emlrtErrorWithMessageIdR2012b(emlrtRootTLSGlobal, &n_emlrtRTEI,
    "Coder:toolbox:power_domainError", 0);
  emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
}

void update(const emxArray_real_T *X, real_T weight[3], emxArray_real_T *mu,
            real_T sigma[3])
{
  real_T D[3];
  boolean_T D_in[3];
  int32_T i;
  real_T det_Q[3];
  int32_T ixstart;
  emxArray_real_T *b_X;
  int32_T ix;
  int32_T iy;
  int32_T c_X[2];
  int32_T b_mu[2];
  emxArray_real_T *nu;
  uint32_T uv0[2];
  emxArray_real_T *r9;
  int32_T rho[2];
  real_T c;
  real_T b_rho[3];
  real_T x[9];
  real_T s;
  emxArray_real_T *c_rho;
  emxArray_real_T *d_rho;
  emxArray_real_T *d_X;
  emxArray_real_T *a;
  const mxArray *y;
  static const int32_T iv11[2] = { 1, 21 };

  const mxArray *m8;
  char_T cv8[21];
  static const char_T cv9[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

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
  boolean_T b_y;
  boolean_T exitg2;
  boolean_T exitg1;
  emxArray_int32_T *r10;
  emxArray_int32_T *r11;
  int32_T iv12[1];
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);

  /* UPDATE Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  Inputs: */
  /*              X (pixel value):    Cx1 */
  /*              weight:             Kx1 */
  /*              mu:                 CxK */
  /*              sigma:              Kx1 */
  /*  Outputs: */
  /*              weight:             Kx1 */
  /*              mu:                 CxK */
  /*              sigma:              Kx1              */
  /* 2.5^2; */
  /* Check which distribution matches the pixel value */
  emlrtPushRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);
  match(X, mu, sigma, D);
  emlrtPopRtStackR2012b(&p_emlrtRSI, emlrtRootTLSGlobal);

  /* Kx1 */
  for (i = 0; i < 3; i++) {
    D_in[i] = (D[i] < 6.25);
  }

  /* Update weights, mu and sigma */
  /*  rho = zeros(K,1); */
  /* Vectorization over K gaussians */
  emlrtPushRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
  for (ixstart = 0; ixstart < 3; ixstart++) {
    det_Q[ixstart] = muDoubleScalarPower(sigma[ixstart], X->size[0]);
  }

  emxInit_real_T(&b_X, 2, &h_emlrtRTEI, TRUE);
  emlrtPopRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPopRtStackR2012b(&q_emlrtRSI, emlrtRootTLSGlobal);

  /* Kx1 (Sigma is a diagonal matrix with equal elements) */
  /* CxK */
  ixstart = X->size[0];
  ix = b_X->size[0] * b_X->size[1];
  b_X->size[0] = ixstart;
  b_X->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)b_X, ix, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  for (ix = 0; ix < 3; ix++) {
    for (iy = 0; iy < ixstart; iy++) {
      b_X->data[iy + b_X->size[0] * ix] = X->data[iy];
    }
  }

  for (ix = 0; ix < 2; ix++) {
    c_X[ix] = b_X->size[ix];
  }

  emxFree_real_T(&b_X);
  for (ix = 0; ix < 2; ix++) {
    b_mu[ix] = mu->size[ix];
  }

  emxInit_real_T(&nu, 2, &m_emlrtRTEI, TRUE);
  emlrtSizeEqCheck2DFastR2012b(c_X, b_mu, &c_emlrtECI, emlrtRootTLSGlobal);
  ixstart = X->size[0];
  ix = nu->size[0] * nu->size[1];
  nu->size[0] = ixstart;
  nu->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)nu, ix, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  for (ix = 0; ix < 3; ix++) {
    for (iy = 0; iy < ixstart; iy++) {
      nu->data[iy + nu->size[0] * ix] = X->data[iy] - mu->data[iy + mu->size[0] *
        ix];
    }
  }

  for (ix = 0; ix < 2; ix++) {
    uv0[ix] = (uint32_T)nu->size[ix];
  }

  emxInit_real_T(&r9, 2, &h_emlrtRTEI, TRUE);
  ix = r9->size[0] * r9->size[1];
  r9->size[0] = (int32_T)uv0[0];
  r9->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)r9, ix, (int32_T)sizeof(real_T),
                    &l_emlrtRTEI);
  ix = (int32_T)uv0[0] * 3;
  for (ixstart = 0; ixstart < ix; ixstart++) {
    r9->data[(int32_T)(1.0 + (real_T)ixstart) - 1] = nu->data[(int32_T)(1.0 +
      (real_T)ixstart) - 1] * nu->data[(int32_T)(1.0 + (real_T)ixstart) - 1];
  }

  for (ix = 0; ix < 2; ix++) {
    rho[ix] = r9->size[ix];
  }

  for (i = 0; i < 2; i++) {
    c_X[i] = 3;
  }

  emlrtSizeEqCheck2DFastR2012b(rho, c_X, &d_emlrtECI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
  c = muDoubleScalarPower(6.2831853071795862, (real_T)X->size[0] / 2.0);
  emlrtPushRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
  for (ixstart = 0; ixstart < 3; ixstart++) {
    if (det_Q[ixstart] < 0.0) {
      emlrtPushRtStackR2012b(&sb_emlrtRSI, emlrtRootTLSGlobal);
      b_eml_error();
      emlrtPopRtStackR2012b(&sb_emlrtRSI, emlrtRootTLSGlobal);
    }

    b_rho[ixstart] = muDoubleScalarSqrt(det_Q[ixstart]);
  }

  emlrtPopRtStackR2012b(&rb_emlrtRSI, emlrtRootTLSGlobal);
  for (ix = 0; ix < 3; ix++) {
    det_Q[ix] = 1.0 / sigma[ix];
  }

  for (ix = 0; ix < 3; ix++) {
    for (iy = 0; iy < 3; iy++) {
      x[iy + 3 * ix] = r9->data[iy + 3 * ix] * det_Q[ix];
    }
  }

  ix = -1;
  iy = -1;
  for (i = 0; i < 3; i++) {
    ixstart = ix + 1;
    ix++;
    s = x[ixstart];
    for (ixstart = 0; ixstart < 2; ixstart++) {
      ix++;
      s += x[ix];
    }

    iy++;
    det_Q[iy] = s;
  }

  for (ix = 0; ix < 3; ix++) {
    b_rho[ix] = 0.01 * (1.0 / (c * b_rho[ix])) * muDoubleScalarExp(-0.5 *
      det_Q[ix]);
  }

  emlrtPopRtStackR2012b(&r_emlrtRSI, emlrtRootTLSGlobal);
  for (ix = 0; ix < 3; ix++) {
    weight[ix] += 0.01 * ((real_T)D_in[ix] - weight[ix]);
  }

  emxInit_real_T(&c_rho, 2, &h_emlrtRTEI, TRUE);

  /* CxK */
  i = X->size[0];
  ix = c_rho->size[0] * c_rho->size[1];
  c_rho->size[0] = i;
  c_rho->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)c_rho, ix, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  for (ix = 0; ix < 3; ix++) {
    for (iy = 0; iy < i; iy++) {
      c_rho->data[iy + c_rho->size[0] * ix] = b_rho[ix];
    }
  }

  for (ix = 0; ix < 2; ix++) {
    rho[ix] = c_rho->size[ix];
  }

  emxFree_real_T(&c_rho);
  for (ix = 0; ix < 2; ix++) {
    b_mu[ix] = mu->size[ix];
  }

  emxInit_real_T(&d_rho, 2, &h_emlrtRTEI, TRUE);
  emlrtSizeEqCheck2DFastR2012b(rho, b_mu, &e_emlrtECI, emlrtRootTLSGlobal);
  i = X->size[0];
  ix = d_rho->size[0] * d_rho->size[1];
  d_rho->size[0] = i;
  d_rho->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)d_rho, ix, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  for (ix = 0; ix < 3; ix++) {
    for (iy = 0; iy < i; iy++) {
      d_rho->data[iy + d_rho->size[0] * ix] = b_rho[ix];
    }
  }

  for (ix = 0; ix < 2; ix++) {
    rho[ix] = d_rho->size[ix];
  }

  emxFree_real_T(&d_rho);
  emxInit_real_T(&d_X, 2, &h_emlrtRTEI, TRUE);
  ixstart = X->size[0];
  ix = d_X->size[0] * d_X->size[1];
  d_X->size[0] = ixstart;
  d_X->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)d_X, ix, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  for (ix = 0; ix < 3; ix++) {
    for (iy = 0; iy < ixstart; iy++) {
      d_X->data[iy + d_X->size[0] * ix] = X->data[iy];
    }
  }

  for (ix = 0; ix < 2; ix++) {
    c_X[ix] = d_X->size[ix];
  }

  emxFree_real_T(&d_X);
  emlrtSizeEqCheck2DFastR2012b(rho, c_X, &f_emlrtECI, emlrtRootTLSGlobal);
  i = X->size[0];
  ix = r9->size[0] * r9->size[1];
  r9->size[0] = i;
  r9->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)r9, ix, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  for (ix = 0; ix < 3; ix++) {
    for (iy = 0; iy < i; iy++) {
      r9->data[iy + r9->size[0] * ix] = (1.0 - b_rho[ix]) * mu->data[iy +
        mu->size[0] * ix];
    }
  }

  i = X->size[0];
  ix = mu->size[0] * mu->size[1];
  mu->size[0] = i;
  mu->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)mu, ix, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  for (ix = 0; ix < 3; ix++) {
    for (iy = 0; iy < i; iy++) {
      mu->data[iy + mu->size[0] * ix] = b_rho[ix] * X->data[iy];
    }
  }

  for (ix = 0; ix < 2; ix++) {
    rho[ix] = r9->size[ix];
  }

  for (ix = 0; ix < 2; ix++) {
    b_mu[ix] = mu->size[ix];
  }

  emlrtSizeEqCheck2DFastR2012b(rho, b_mu, &e_emlrtECI, emlrtRootTLSGlobal);
  ix = mu->size[0] * mu->size[1];
  mu->size[0] = r9->size[0];
  mu->size[1] = 3;
  emxEnsureCapacity((emxArray__common *)mu, ix, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  for (ix = 0; ix < 3; ix++) {
    ixstart = r9->size[0];
    for (iy = 0; iy < ixstart; iy++) {
      mu->data[iy + mu->size[0] * ix] += r9->data[iy + r9->size[0] * ix];
    }
  }

  emxFree_real_T(&r9);
  emxInit_real_T(&a, 2, &h_emlrtRTEI, TRUE);
  emlrtPushRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
  ix = a->size[0] * a->size[1];
  a->size[0] = 3;
  a->size[1] = nu->size[0];
  emxEnsureCapacity((emxArray__common *)a, ix, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  ixstart = nu->size[0];
  for (ix = 0; ix < ixstart; ix++) {
    for (iy = 0; iy < 3; iy++) {
      a->data[iy + a->size[0] * ix] = nu->data[ix + nu->size[0] * iy];
    }
  }

  emlrtPushRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
  if (!(a->size[1] == nu->size[0])) {
    emlrtPushRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
    y = NULL;
    m8 = mxCreateCharArray(2, iv11);
    for (i = 0; i < 21; i++) {
      cv8[i] = cv9[i];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 21, m8, cv8);
    emlrtAssign(&y, m8);
    error(message(y, &g_emlrtMCI), &h_emlrtMCI);
    emlrtPopRtStackR2012b(&w_emlrtRSI, emlrtRootTLSGlobal);
  }

  emlrtPopRtStackR2012b(&v_emlrtRSI, emlrtRootTLSGlobal);
  if ((a->size[1] == 1) || (nu->size[0] == 1)) {
    for (ix = 0; ix < 3; ix++) {
      for (iy = 0; iy < 3; iy++) {
        x[ix + 3 * iy] = 0.0;
        ixstart = a->size[1];
        for (i = 0; i < ixstart; i++) {
          x[ix + 3 * iy] += a->data[ix + a->size[0] * i] * nu->data[i + nu->
            size[0] * iy];
        }
      }
    }
  } else {
    emlrtPushRtStackR2012b(&u_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&x_emlrtRSI, emlrtRootTLSGlobal);
    memset(&x[0], 0, 9U * sizeof(real_T));
    if (a->size[1] < 1) {
    } else {
      emlrtPushRtStackR2012b(&ab_emlrtRSI, emlrtRootTLSGlobal);
      c = 1.0;
      s = 0.0;
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
      alpha1_t = (double *)(&c);
      emlrtPopRtStackR2012b(&kb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
      Aia0_t = (double *)(&a->data[0]);
      emlrtPopRtStackR2012b(&lb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&mb_emlrtRSI, emlrtRootTLSGlobal);
      Bib0_t = (double *)(&nu->data[0]);
      emlrtPopRtStackR2012b(&mb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&nb_emlrtRSI, emlrtRootTLSGlobal);
      beta1_t = (double *)(&s);
      emlrtPopRtStackR2012b(&nb_emlrtRSI, emlrtRootTLSGlobal);
      emlrtPushRtStackR2012b(&ob_emlrtRSI, emlrtRootTLSGlobal);
      Cic0_t = (double *)(&x[0]);
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
  emxFree_real_T(&nu);
  for (ix = 0; ix < 3; ix++) {
    sigma[ix] = (1.0 - b_rho[ix]) * sigma[ix] + b_rho[ix] * x[ix << 2];
  }

  emlrtPopRtStackR2012b(&s_emlrtRSI, emlrtRootTLSGlobal);
  b_y = TRUE;
  ixstart = 0;
  exitg2 = FALSE;
  while ((exitg2 == FALSE) && (ixstart < 3)) {
    if ((D_in[ixstart] == 0) == 0) {
      b_y = FALSE;
      exitg2 = TRUE;
    } else {
      ixstart++;
    }
  }

  if (b_y) {
    /* No matches */
    ixstart = 1;
    c = D[0];
    i = 0;
    if (muDoubleScalarIsNaN(D[0])) {
      ix = 1;
      exitg1 = FALSE;
      while ((exitg1 == FALSE) && (ix + 1 < 4)) {
        ixstart = ix + 1;
        if (!muDoubleScalarIsNaN(D[ix])) {
          c = D[ix];
          i = ix;
          exitg1 = TRUE;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < 3) {
      while (ixstart + 1 < 4) {
        if (D[ixstart] < c) {
          c = D[ixstart];
          i = ixstart;
        }

        ixstart++;
      }
    }

    emxInit_int32_T(&r10, 1, &h_emlrtRTEI, TRUE);
    ixstart = mu->size[0];
    ix = r10->size[0];
    r10->size[0] = ixstart;
    emxEnsureCapacity((emxArray__common *)r10, ix, (int32_T)sizeof(int32_T),
                      &h_emlrtRTEI);
    for (ix = 0; ix < ixstart; ix++) {
      r10->data[ix] = ix;
    }

    emxInit_int32_T(&r11, 1, &h_emlrtRTEI, TRUE);
    iv12[0] = r10->size[0];
    emlrtSubAssignSizeCheckR2012b(iv12, 1, *(int32_T (*)[1])X->size, 1,
      &g_emlrtECI, emlrtRootTLSGlobal);
    ix = r11->size[0];
    r11->size[0] = r10->size[0];
    emxEnsureCapacity((emxArray__common *)r11, ix, (int32_T)sizeof(int32_T),
                      &h_emlrtRTEI);
    ixstart = r10->size[0];
    for (ix = 0; ix < ixstart; ix++) {
      r11->data[ix] = r10->data[ix];
    }

    emxFree_int32_T(&r10);
    ixstart = X->size[0];
    for (ix = 0; ix < ixstart; ix++) {
      mu->data[r11->data[ix] + mu->size[0] * i] = X->data[ix];
    }

    emxFree_int32_T(&r11);
    sigma[i] = 100.0;
    weight[i] = 0.01;
  }

  /* Re-normalize weights */
  c = weight[0];
  for (ixstart = 0; ixstart < 2; ixstart++) {
    c += weight[ixstart + 1];
  }

  for (ix = 0; ix < 3; ix++) {
    weight[ix] /= c;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (update.c) */
