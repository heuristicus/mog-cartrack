/*
 * mog_api.c
 *
 * Code generation for function 'mog_api'
 *
 * C source code generated on: Wed Dec 25 12:08:53 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "mog.h"
#include "mog_api.h"
#include "mog_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo k_emlrtRTEI = { 1, 1, "mog_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u);
static void b_info_helper(ResolvedFunctionInfo info[161]);
static real_T c_emlrt_marshallIn(const mxArray *count, const char_T *identifier);
static const mxArray *c_emlrt_marshallOut(emxArray_uint8_T *u);
static void c_info_helper(ResolvedFunctionInfo info[161]);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const mxArray *image, const char_T *identifier,
  emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(ResolvedFunctionInfo u[161]);
static real_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static void info_helper(ResolvedFunctionInfo info[161]);

/* Function Definitions */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y)
{
  e_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv7[2] = { 0, 0 };

  const mxArray *m4;
  y = NULL;
  m4 = mxCreateNumericArray(2, (int32_T *)&iv7, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m4, (void *)u->data);
  mxSetDimensions((mxArray *)m4, u->size, 2);
  emlrtAssign(&y, m4);
  return y;
}

static void b_info_helper(ResolvedFunctionInfo info[161])
{
  info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[64].name = "eml_int_forloop_overflow_check";
  info[64].dominantType = "";
  info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[64].fileTimeLo = 1346510340U;
  info[64].fileTimeHi = 0U;
  info[64].mFileTimeLo = 0U;
  info[64].mFileTimeHi = 0U;
  info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[65].name = "eml_index_plus";
  info[65].dominantType = "double";
  info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[65].fileTimeLo = 1286818778U;
  info[65].fileTimeHi = 0U;
  info[65].mFileTimeLo = 0U;
  info[65].mFileTimeHi = 0U;
  info[66].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m";
  info[66].name = "diag";
  info[66].dominantType = "double";
  info[66].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  info[66].fileTimeLo = 1286818686U;
  info[66].fileTimeHi = 0U;
  info[66].mFileTimeLo = 0U;
  info[66].mFileTimeHi = 0U;
  info[67].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  info[67].name = "eml_index_class";
  info[67].dominantType = "";
  info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[67].fileTimeLo = 1323170578U;
  info[67].fileTimeHi = 0U;
  info[67].mFileTimeLo = 0U;
  info[67].mFileTimeHi = 0U;
  info[68].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  info[68].name = "eml_index_plus";
  info[68].dominantType = "double";
  info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[68].fileTimeLo = 1286818778U;
  info[68].fileTimeHi = 0U;
  info[68].mFileTimeLo = 0U;
  info[68].mFileTimeHi = 0U;
  info[69].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  info[69].name = "eml_index_times";
  info[69].dominantType = "coder.internal.indexInt";
  info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[69].fileTimeLo = 1286818780U;
  info[69].fileTimeHi = 0U;
  info[69].mFileTimeLo = 0U;
  info[69].mFileTimeHi = 0U;
  info[70].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  info[70].name = "eml_index_minus";
  info[70].dominantType = "coder.internal.indexInt";
  info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[70].fileTimeLo = 1286818778U;
  info[70].fileTimeHi = 0U;
  info[70].mFileTimeLo = 0U;
  info[70].mFileTimeHi = 0U;
  info[71].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  info[71].name = "min";
  info[71].dominantType = "coder.internal.indexInt";
  info[71].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[71].fileTimeLo = 1311255318U;
  info[71].fileTimeHi = 0U;
  info[71].mFileTimeLo = 0U;
  info[71].mFileTimeHi = 0U;
  info[72].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[72].name = "eml_min_or_max";
  info[72].dominantType = "char";
  info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  info[72].fileTimeLo = 1334071490U;
  info[72].fileTimeHi = 0U;
  info[72].mFileTimeLo = 0U;
  info[72].mFileTimeHi = 0U;
  info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  info[73].name = "eml_scalar_eg";
  info[73].dominantType = "coder.internal.indexInt";
  info[73].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[73].fileTimeLo = 1286818796U;
  info[73].fileTimeHi = 0U;
  info[73].mFileTimeLo = 0U;
  info[73].mFileTimeHi = 0U;
  info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  info[74].name = "eml_scalexp_alloc";
  info[74].dominantType = "coder.internal.indexInt";
  info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  info[74].fileTimeLo = 1352424860U;
  info[74].fileTimeHi = 0U;
  info[74].mFileTimeLo = 0U;
  info[74].mFileTimeHi = 0U;
  info[75].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  info[75].name = "eml_scalar_eg";
  info[75].dominantType = "coder.internal.indexInt";
  info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[75].fileTimeLo = 1286818796U;
  info[75].fileTimeHi = 0U;
  info[75].mFileTimeLo = 0U;
  info[75].mFileTimeHi = 0U;
  info[76].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  info[76].name = "eml_index_minus";
  info[76].dominantType = "double";
  info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[76].fileTimeLo = 1286818778U;
  info[76].fileTimeHi = 0U;
  info[76].mFileTimeLo = 0U;
  info[76].mFileTimeHi = 0U;
  info[77].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  info[77].name = "eml_index_plus";
  info[77].dominantType = "coder.internal.indexInt";
  info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[77].fileTimeLo = 1286818778U;
  info[77].fileTimeHi = 0U;
  info[77].mFileTimeLo = 0U;
  info[77].mFileTimeHi = 0U;
  info[78].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m";
  info[78].name = "rdivide";
  info[78].dominantType = "double";
  info[78].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[78].fileTimeLo = 1346510388U;
  info[78].fileTimeHi = 0U;
  info[78].mFileTimeLo = 0U;
  info[78].mFileTimeHi = 0U;
  info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  info[79].name = "isequal";
  info[79].dominantType = "double";
  info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  info[79].fileTimeLo = 1286818758U;
  info[79].fileTimeHi = 0U;
  info[79].mFileTimeLo = 0U;
  info[79].mFileTimeHi = 0U;
  info[80].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  info[80].name = "eml_isequal_core";
  info[80].dominantType = "double";
  info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  info[80].fileTimeLo = 1286818786U;
  info[80].fileTimeHi = 0U;
  info[80].mFileTimeLo = 0U;
  info[80].mFileTimeHi = 0U;
  info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  info[81].name = "isnan";
  info[81].dominantType = "double";
  info[81].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[81].fileTimeLo = 1286818760U;
  info[81].fileTimeHi = 0U;
  info[81].mFileTimeLo = 0U;
  info[81].mFileTimeHi = 0U;
  info[82].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[82].name = "rdivide";
  info[82].dominantType = "double";
  info[82].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[82].fileTimeLo = 1346510388U;
  info[82].fileTimeHi = 0U;
  info[82].mFileTimeLo = 0U;
  info[82].mFileTimeHi = 0U;
  info[83].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[83].name = "power";
  info[83].dominantType = "double";
  info[83].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  info[83].fileTimeLo = 1348191930U;
  info[83].fileTimeHi = 0U;
  info[83].mFileTimeLo = 0U;
  info[83].mFileTimeHi = 0U;
  info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  info[84].name = "eml_scalar_eg";
  info[84].dominantType = "double";
  info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[84].fileTimeLo = 1286818796U;
  info[84].fileTimeHi = 0U;
  info[84].mFileTimeLo = 0U;
  info[84].mFileTimeHi = 0U;
  info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  info[85].name = "eml_scalexp_alloc";
  info[85].dominantType = "double";
  info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  info[85].fileTimeLo = 1352424860U;
  info[85].fileTimeHi = 0U;
  info[85].mFileTimeLo = 0U;
  info[85].mFileTimeHi = 0U;
  info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  info[86].name = "floor";
  info[86].dominantType = "double";
  info[86].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[86].fileTimeLo = 1343830380U;
  info[86].fileTimeHi = 0U;
  info[86].mFileTimeLo = 0U;
  info[86].mFileTimeHi = 0U;
  info[87].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[87].name = "eml_scalar_floor";
  info[87].dominantType = "double";
  info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  info[87].fileTimeLo = 1286818726U;
  info[87].fileTimeHi = 0U;
  info[87].mFileTimeLo = 0U;
  info[87].mFileTimeHi = 0U;
  info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower";
  info[88].name = "eml_error";
  info[88].dominantType = "char";
  info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  info[88].fileTimeLo = 1343830358U;
  info[88].fileTimeHi = 0U;
  info[88].mFileTimeLo = 0U;
  info[88].mFileTimeHi = 0U;
  info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  info[89].name = "eml_scalar_eg";
  info[89].dominantType = "double";
  info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[89].fileTimeLo = 1286818796U;
  info[89].fileTimeHi = 0U;
  info[89].mFileTimeLo = 0U;
  info[89].mFileTimeHi = 0U;
  info[90].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[90].name = "mtimes";
  info[90].dominantType = "double";
  info[90].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[90].fileTimeLo = 1289519692U;
  info[90].fileTimeHi = 0U;
  info[90].mFileTimeLo = 0U;
  info[90].mFileTimeHi = 0U;
  info[91].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[91].name = "mrdivide";
  info[91].dominantType = "double";
  info[91].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[91].fileTimeLo = 1357951548U;
  info[91].fileTimeHi = 0U;
  info[91].mFileTimeLo = 1319729966U;
  info[91].mFileTimeHi = 0U;
  info[92].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[92].name = "mpower";
  info[92].dominantType = "double";
  info[92].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  info[92].fileTimeLo = 1286818842U;
  info[92].fileTimeHi = 0U;
  info[92].mFileTimeLo = 0U;
  info[92].mFileTimeHi = 0U;
  info[93].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  info[93].name = "power";
  info[93].dominantType = "double";
  info[93].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  info[93].fileTimeLo = 1348191930U;
  info[93].fileTimeHi = 0U;
  info[93].mFileTimeLo = 0U;
  info[93].mFileTimeHi = 0U;
  info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  info[94].name = "sqrt";
  info[94].dominantType = "double";
  info[94].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[94].fileTimeLo = 1343830386U;
  info[94].fileTimeHi = 0U;
  info[94].mFileTimeLo = 0U;
  info[94].mFileTimeHi = 0U;
  info[95].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[95].name = "eml_error";
  info[95].dominantType = "char";
  info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  info[95].fileTimeLo = 1343830358U;
  info[95].fileTimeHi = 0U;
  info[95].mFileTimeLo = 0U;
  info[95].mFileTimeHi = 0U;
  info[96].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  info[96].name = "eml_scalar_sqrt";
  info[96].dominantType = "double";
  info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  info[96].fileTimeLo = 1286818738U;
  info[96].fileTimeHi = 0U;
  info[96].mFileTimeLo = 0U;
  info[96].mFileTimeHi = 0U;
  info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power";
  info[97].name = "mtimes";
  info[97].dominantType = "double";
  info[97].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[97].fileTimeLo = 1289519692U;
  info[97].fileTimeHi = 0U;
  info[97].mFileTimeLo = 0U;
  info[97].mFileTimeHi = 0U;
  info[98].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[98].name = "sum";
  info[98].dominantType = "double";
  info[98].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[98].fileTimeLo = 1314736612U;
  info[98].fileTimeHi = 0U;
  info[98].mFileTimeLo = 0U;
  info[98].mFileTimeHi = 0U;
  info[99].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[99].name = "eml_assert_valid_dim";
  info[99].dominantType = "double";
  info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  info[99].fileTimeLo = 1286818694U;
  info[99].fileTimeHi = 0U;
  info[99].mFileTimeLo = 0U;
  info[99].mFileTimeHi = 0U;
  info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  info[100].name = "eml_scalar_floor";
  info[100].dominantType = "double";
  info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  info[100].fileTimeLo = 1286818726U;
  info[100].fileTimeHi = 0U;
  info[100].mFileTimeLo = 0U;
  info[100].mFileTimeHi = 0U;
  info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  info[101].name = "eml_index_class";
  info[101].dominantType = "";
  info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[101].fileTimeLo = 1323170578U;
  info[101].fileTimeHi = 0U;
  info[101].mFileTimeLo = 0U;
  info[101].mFileTimeHi = 0U;
  info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  info[102].name = "intmax";
  info[102].dominantType = "char";
  info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[102].fileTimeLo = 1311255316U;
  info[102].fileTimeHi = 0U;
  info[102].mFileTimeLo = 0U;
  info[102].mFileTimeHi = 0U;
  info[103].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[103].name = "eml_index_class";
  info[103].dominantType = "";
  info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[103].fileTimeLo = 1323170578U;
  info[103].fileTimeHi = 0U;
  info[103].mFileTimeLo = 0U;
  info[103].mFileTimeHi = 0U;
  info[104].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[104].name = "eml_scalar_eg";
  info[104].dominantType = "double";
  info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[104].fileTimeLo = 1286818796U;
  info[104].fileTimeHi = 0U;
  info[104].mFileTimeLo = 0U;
  info[104].mFileTimeHi = 0U;
  info[105].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[105].name = "eml_matrix_vstride";
  info[105].dominantType = "double";
  info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[105].fileTimeLo = 1286818788U;
  info[105].fileTimeHi = 0U;
  info[105].mFileTimeLo = 0U;
  info[105].mFileTimeHi = 0U;
  info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[106].name = "eml_index_minus";
  info[106].dominantType = "double";
  info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[106].fileTimeLo = 1286818778U;
  info[106].fileTimeHi = 0U;
  info[106].mFileTimeLo = 0U;
  info[106].mFileTimeHi = 0U;
  info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[107].name = "eml_index_class";
  info[107].dominantType = "";
  info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[107].fileTimeLo = 1323170578U;
  info[107].fileTimeHi = 0U;
  info[107].mFileTimeLo = 0U;
  info[107].mFileTimeHi = 0U;
  info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[108].name = "eml_size_prod";
  info[108].dominantType = "double";
  info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  info[108].fileTimeLo = 1286818798U;
  info[108].fileTimeHi = 0U;
  info[108].mFileTimeLo = 0U;
  info[108].mFileTimeHi = 0U;
  info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  info[109].name = "eml_index_class";
  info[109].dominantType = "";
  info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[109].fileTimeLo = 1323170578U;
  info[109].fileTimeHi = 0U;
  info[109].mFileTimeLo = 0U;
  info[109].mFileTimeHi = 0U;
  info[110].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[110].name = "eml_matrix_npages";
  info[110].dominantType = "double";
  info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[110].fileTimeLo = 1286818786U;
  info[110].fileTimeHi = 0U;
  info[110].mFileTimeLo = 0U;
  info[110].mFileTimeHi = 0U;
  info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[111].name = "eml_index_plus";
  info[111].dominantType = "double";
  info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[111].fileTimeLo = 1286818778U;
  info[111].fileTimeHi = 0U;
  info[111].mFileTimeLo = 0U;
  info[111].mFileTimeHi = 0U;
  info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[112].name = "eml_index_class";
  info[112].dominantType = "";
  info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[112].fileTimeLo = 1323170578U;
  info[112].fileTimeHi = 0U;
  info[112].mFileTimeLo = 0U;
  info[112].mFileTimeHi = 0U;
  info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[113].name = "eml_size_prod";
  info[113].dominantType = "double";
  info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  info[113].fileTimeLo = 1286818798U;
  info[113].fileTimeHi = 0U;
  info[113].mFileTimeLo = 0U;
  info[113].mFileTimeHi = 0U;
  info[114].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_prod.m";
  info[114].name = "eml_index_times";
  info[114].dominantType = "double";
  info[114].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[114].fileTimeLo = 1286818780U;
  info[114].fileTimeHi = 0U;
  info[114].mFileTimeLo = 0U;
  info[114].mFileTimeHi = 0U;
  info[115].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[115].name = "eml_int_forloop_overflow_check";
  info[115].dominantType = "";
  info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[115].fileTimeLo = 1346510340U;
  info[115].fileTimeHi = 0U;
  info[115].mFileTimeLo = 0U;
  info[115].mFileTimeHi = 0U;
  info[116].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[116].name = "eml_index_plus";
  info[116].dominantType = "double";
  info[116].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[116].fileTimeLo = 1286818778U;
  info[116].fileTimeHi = 0U;
  info[116].mFileTimeLo = 0U;
  info[116].mFileTimeHi = 0U;
  info[117].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  info[117].name = "eml_index_plus";
  info[117].dominantType = "coder.internal.indexInt";
  info[117].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[117].fileTimeLo = 1286818778U;
  info[117].fileTimeHi = 0U;
  info[117].mFileTimeLo = 0U;
  info[117].mFileTimeHi = 0U;
  info[118].context =
    "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[118].name = "exp";
  info[118].dominantType = "double";
  info[118].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  info[118].fileTimeLo = 1343830380U;
  info[118].fileTimeHi = 0U;
  info[118].mFileTimeLo = 0U;
  info[118].mFileTimeHi = 0U;
  info[119].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/exp.m";
  info[119].name = "eml_scalar_exp";
  info[119].dominantType = "double";
  info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_exp.m";
  info[119].fileTimeLo = 1301328464U;
  info[119].fileTimeHi = 0U;
  info[119].mFileTimeLo = 0U;
  info[119].mFileTimeHi = 0U;
  info[120].context =
    "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[120].name = "diag";
  info[120].dominantType = "double";
  info[120].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m";
  info[120].fileTimeLo = 1286818686U;
  info[120].fileTimeHi = 0U;
  info[120].mFileTimeLo = 0U;
  info[120].mFileTimeHi = 0U;
  info[121].context =
    "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[121].name = "all";
  info[121].dominantType = "logical";
  info[121].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  info[121].fileTimeLo = 1286818834U;
  info[121].fileTimeHi = 0U;
  info[121].mFileTimeLo = 0U;
  info[121].mFileTimeHi = 0U;
  info[122].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  info[122].name = "eml_all_or_any";
  info[122].dominantType = "char";
  info[122].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[122].fileTimeLo = 1286818694U;
  info[122].fileTimeHi = 0U;
  info[122].mFileTimeLo = 0U;
  info[122].mFileTimeHi = 0U;
  info[123].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[123].name = "isequal";
  info[123].dominantType = "double";
  info[123].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  info[123].fileTimeLo = 1286818758U;
  info[123].fileTimeHi = 0U;
  info[123].mFileTimeLo = 0U;
  info[123].mFileTimeHi = 0U;
  info[124].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  info[124].name = "eml_const_nonsingleton_dim";
  info[124].dominantType = "logical";
  info[124].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  info[124].fileTimeLo = 1286818696U;
  info[124].fileTimeHi = 0U;
  info[124].mFileTimeLo = 0U;
  info[124].mFileTimeHi = 0U;
  info[125].context =
    "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[125].name = "min";
  info[125].dominantType = "double";
  info[125].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[125].fileTimeLo = 1311255318U;
  info[125].fileTimeHi = 0U;
  info[125].mFileTimeLo = 0U;
  info[125].mFileTimeHi = 0U;
  info[126].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m";
  info[126].name = "rdivide";
  info[126].dominantType = "double";
  info[126].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[126].fileTimeLo = 1346510388U;
  info[126].fileTimeHi = 0U;
  info[126].mFileTimeLo = 0U;
  info[126].mFileTimeHi = 0U;
  info[127].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m";
  info[127].name = "sort";
  info[127].dominantType = "double";
  info[127].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m";
  info[127].fileTimeLo = 1303146208U;
  info[127].fileTimeHi = 0U;
  info[127].mFileTimeLo = 0U;
  info[127].mFileTimeHi = 0U;
}

static real_T c_emlrt_marshallIn(const mxArray *count, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(emlrtAlias(count), &thisId);
  emlrtDestroyArray(&count);
  return y;
}

static const mxArray *c_emlrt_marshallOut(emxArray_uint8_T *u)
{
  const mxArray *y;
  static const int32_T iv8[3] = { 0, 0, 0 };

  const mxArray *m5;
  y = NULL;
  m5 = mxCreateNumericArray(3, (int32_T *)&iv8, mxUINT8_CLASS, mxREAL);
  mxSetData((mxArray *)m5, (void *)u->data);
  mxSetDimensions((mxArray *)m5, u->size, 3);
  emlrtAssign(&y, m5);
  return y;
}

static void c_info_helper(ResolvedFunctionInfo info[161])
{
  info[128].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m";
  info[128].name = "eml_sort";
  info[128].dominantType = "double";
  info[128].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m";
  info[128].fileTimeLo = 1314736612U;
  info[128].fileTimeHi = 0U;
  info[128].mFileTimeLo = 0U;
  info[128].mFileTimeHi = 0U;
  info[129].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m";
  info[129].name = "eml_assert_valid_dim";
  info[129].dominantType = "double";
  info[129].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  info[129].fileTimeLo = 1286818694U;
  info[129].fileTimeHi = 0U;
  info[129].mFileTimeLo = 0U;
  info[129].mFileTimeHi = 0U;
  info[130].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m";
  info[130].name = "eml_scalar_eg";
  info[130].dominantType = "double";
  info[130].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[130].fileTimeLo = 1286818796U;
  info[130].fileTimeHi = 0U;
  info[130].mFileTimeLo = 0U;
  info[130].mFileTimeHi = 0U;
  info[131].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m";
  info[131].name = "eml_sort_idx";
  info[131].dominantType = "double";
  info[131].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  info[131].fileTimeLo = 1305318004U;
  info[131].fileTimeHi = 0U;
  info[131].mFileTimeLo = 0U;
  info[131].mFileTimeHi = 0U;
  info[132].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  info[132].name = "eml_index_class";
  info[132].dominantType = "";
  info[132].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[132].fileTimeLo = 1323170578U;
  info[132].fileTimeHi = 0U;
  info[132].mFileTimeLo = 0U;
  info[132].mFileTimeHi = 0U;
  info[133].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  info[133].name = "eml_size_ispow2";
  info[133].dominantType = "coder.internal.indexInt";
  info[133].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  info[133].fileTimeLo = 1286818798U;
  info[133].fileTimeHi = 0U;
  info[133].mFileTimeLo = 0U;
  info[133].mFileTimeHi = 0U;
  info[134].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  info[134].name = "eml_unsigned_class";
  info[134].dominantType = "char";
  info[134].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  info[134].fileTimeLo = 1323170580U;
  info[134].fileTimeHi = 0U;
  info[134].mFileTimeLo = 0U;
  info[134].mFileTimeHi = 0U;
  info[135].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  info[135].name = "eml_index_class";
  info[135].dominantType = "";
  info[135].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[135].fileTimeLo = 1323170578U;
  info[135].fileTimeHi = 0U;
  info[135].mFileTimeLo = 0U;
  info[135].mFileTimeHi = 0U;
  info[136].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  info[136].name = "eml_index_plus";
  info[136].dominantType = "coder.internal.indexInt";
  info[136].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[136].fileTimeLo = 1286818778U;
  info[136].fileTimeHi = 0U;
  info[136].mFileTimeLo = 0U;
  info[136].mFileTimeHi = 0U;
  info[137].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  info[137].name = "eml_sort_le";
  info[137].dominantType = "double";
  info[137].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m";
  info[137].fileTimeLo = 1292190510U;
  info[137].fileTimeHi = 0U;
  info[137].mFileTimeLo = 0U;
  info[137].mFileTimeHi = 0U;
  info[138].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_descending_le";
  info[138].name = "eml_relop";
  info[138].dominantType = "function_handle";
  info[138].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  info[138].fileTimeLo = 1342451182U;
  info[138].fileTimeHi = 0U;
  info[138].mFileTimeLo = 0U;
  info[138].mFileTimeHi = 0U;
  info[139].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_descending_le";
  info[139].name = "isnan";
  info[139].dominantType = "double";
  info[139].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[139].fileTimeLo = 1286818760U;
  info[139].fileTimeHi = 0U;
  info[139].mFileTimeLo = 0U;
  info[139].mFileTimeHi = 0U;
  info[140].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m";
  info[140].name = "cumsum";
  info[140].dominantType = "double";
  info[140].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/cumsum.m";
  info[140].fileTimeLo = 1344472034U;
  info[140].fileTimeHi = 0U;
  info[140].mFileTimeLo = 0U;
  info[140].mFileTimeHi = 0U;
  info[141].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/cumsum.m";
  info[141].name = "eml_nonsingleton_dim";
  info[141].dominantType = "double";
  info[141].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  info[141].fileTimeLo = 1307651242U;
  info[141].fileTimeHi = 0U;
  info[141].mFileTimeLo = 0U;
  info[141].mFileTimeHi = 0U;
  info[142].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m";
  info[142].name = "eml_index_class";
  info[142].dominantType = "";
  info[142].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[142].fileTimeLo = 1323170578U;
  info[142].fileTimeHi = 0U;
  info[142].mFileTimeLo = 0U;
  info[142].mFileTimeHi = 0U;
  info[143].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/cumsum.m!cumulativesum";
  info[143].name = "eml_matrix_vstride";
  info[143].dominantType = "double";
  info[143].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_vstride.m";
  info[143].fileTimeLo = 1286818788U;
  info[143].fileTimeHi = 0U;
  info[143].mFileTimeLo = 0U;
  info[143].mFileTimeHi = 0U;
  info[144].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/cumsum.m!cumulativesum";
  info[144].name = "eml_matrix_npages";
  info[144].dominantType = "double";
  info[144].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_matrix_npages.m";
  info[144].fileTimeLo = 1286818786U;
  info[144].fileTimeHi = 0U;
  info[144].mFileTimeLo = 0U;
  info[144].mFileTimeHi = 0U;
  info[145].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/cumsum.m!cumulativesum";
  info[145].name = "eml_index_class";
  info[145].dominantType = "";
  info[145].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[145].fileTimeLo = 1323170578U;
  info[145].fileTimeHi = 0U;
  info[145].mFileTimeLo = 0U;
  info[145].mFileTimeHi = 0U;
  info[146].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/cumsum.m!cumulativesum";
  info[146].name = "eml_index_plus";
  info[146].dominantType = "double";
  info[146].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[146].fileTimeLo = 1286818778U;
  info[146].fileTimeHi = 0U;
  info[146].mFileTimeLo = 0U;
  info[146].mFileTimeHi = 0U;
  info[147].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/cumsum.m!cumulativesum";
  info[147].name = "eml_index_plus";
  info[147].dominantType = "coder.internal.indexInt";
  info[147].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[147].fileTimeLo = 1286818778U;
  info[147].fileTimeHi = 0U;
  info[147].mFileTimeLo = 0U;
  info[147].mFileTimeHi = 0U;
  info[148].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m";
  info[148].name = "min";
  info[148].dominantType = "logical";
  info[148].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[148].fileTimeLo = 1311255318U;
  info[148].fileTimeHi = 0U;
  info[148].mFileTimeLo = 0U;
  info[148].mFileTimeHi = 0U;
  info[149].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  info[149].name = "eml_const_nonsingleton_dim";
  info[149].dominantType = "logical";
  info[149].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  info[149].fileTimeLo = 1286818696U;
  info[149].fileTimeHi = 0U;
  info[149].mFileTimeLo = 0U;
  info[149].mFileTimeHi = 0U;
  info[150].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  info[150].name = "eml_scalar_eg";
  info[150].dominantType = "logical";
  info[150].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[150].fileTimeLo = 1286818796U;
  info[150].fileTimeHi = 0U;
  info[150].mFileTimeLo = 0U;
  info[150].mFileTimeHi = 0U;
  info[151].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[151].name = "isnan";
  info[151].dominantType = "logical";
  info[151].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[151].fileTimeLo = 1286818760U;
  info[151].fileTimeHi = 0U;
  info[151].mFileTimeLo = 0U;
  info[151].mFileTimeHi = 0U;
  info[152].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m";
  info[152].name = "match";
  info[152].dominantType = "double";
  info[152].resolved =
    "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m";
  info[152].fileTimeLo = 1387965636U;
  info[152].fileTimeHi = 0U;
  info[152].mFileTimeLo = 0U;
  info[152].mFileTimeHi = 0U;
  info[153].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m";
  info[153].name = "find";
  info[153].dominantType = "double";
  info[153].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  info[153].fileTimeLo = 1303146206U;
  info[153].fileTimeHi = 0U;
  info[153].mFileTimeLo = 0U;
  info[153].mFileTimeHi = 0U;
  info[154].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[154].name = "eml_index_class";
  info[154].dominantType = "";
  info[154].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[154].fileTimeLo = 1323170578U;
  info[154].fileTimeHi = 0U;
  info[154].mFileTimeLo = 0U;
  info[154].mFileTimeHi = 0U;
  info[155].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[155].name = "eml_scalar_eg";
  info[155].dominantType = "double";
  info[155].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[155].fileTimeLo = 1286818796U;
  info[155].fileTimeHi = 0U;
  info[155].mFileTimeLo = 0U;
  info[155].mFileTimeHi = 0U;
  info[156].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[156].name = "eml_int_forloop_overflow_check";
  info[156].dominantType = "";
  info[156].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[156].fileTimeLo = 1346510340U;
  info[156].fileTimeHi = 0U;
  info[156].mFileTimeLo = 0U;
  info[156].mFileTimeHi = 0U;
  info[157].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[157].name = "eml_index_plus";
  info[157].dominantType = "double";
  info[157].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[157].fileTimeLo = 1286818778U;
  info[157].fileTimeHi = 0U;
  info[157].mFileTimeLo = 0U;
  info[157].mFileTimeHi = 0U;
  info[158].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[158].name = "eml_scalar_eg";
  info[158].dominantType = "logical";
  info[158].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[158].fileTimeLo = 1286818796U;
  info[158].fileTimeHi = 0U;
  info[158].mFileTimeLo = 0U;
  info[158].mFileTimeHi = 0U;
  info[159].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[159].name = "floor";
  info[159].dominantType = "double";
  info[159].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  info[159].fileTimeLo = 1343830380U;
  info[159].fileTimeHi = 0U;
  info[159].mFileTimeLo = 0U;
  info[159].mFileTimeHi = 0U;
  info[160].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m!eml_find";
  info[160].name = "min";
  info[160].dominantType = "coder.internal.indexInt";
  info[160].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  info[160].fileTimeLo = 1311255318U;
  info[160].fileTimeHi = 0U;
  info[160].mFileTimeLo = 0U;
  info[160].mFileTimeHi = 0U;
}

static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret)
{
  int32_T iv9[3];
  boolean_T bv0[3];
  int32_T i;
  int32_T iv10[3];
  for (i = 0; i < 3; i++) {
    iv9[i] = -1;
    bv0[i] = TRUE;
  }

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 3U,
    iv9, bv0, iv10);
  ret->size[0] = iv10[0];
  ret->size[1] = iv10[1];
  ret->size[2] = iv10[2];
  ret->allocatedSize = ret->size[0] * ret->size[1] * ret->size[2];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = FALSE;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const mxArray *image, const char_T *identifier,
  emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(emlrtAlias(image), &thisId, y);
  emlrtDestroyArray(&image);
}

static const mxArray *emlrt_marshallOut(ResolvedFunctionInfo u[161])
{
  const mxArray *y;
  int32_T iv6[1];
  int32_T i4;
  ResolvedFunctionInfo *r8;
  const char * b_u;
  const mxArray *b_y;
  const mxArray *m3;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  uint32_T c_u;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  y = NULL;
  iv6[0] = 161;
  emlrtAssign(&y, mxCreateStructArray(1, iv6, 0, NULL));
  for (i4 = 0; i4 < 161; i4++) {
    r8 = &u[i4];
    b_u = r8->context;
    b_y = NULL;
    m3 = mxCreateString(b_u);
    emlrtAssign(&b_y, m3);
    emlrtAddField(y, b_y, "context", i4);
    b_u = r8->name;
    c_y = NULL;
    m3 = mxCreateString(b_u);
    emlrtAssign(&c_y, m3);
    emlrtAddField(y, c_y, "name", i4);
    b_u = r8->dominantType;
    d_y = NULL;
    m3 = mxCreateString(b_u);
    emlrtAssign(&d_y, m3);
    emlrtAddField(y, d_y, "dominantType", i4);
    b_u = r8->resolved;
    e_y = NULL;
    m3 = mxCreateString(b_u);
    emlrtAssign(&e_y, m3);
    emlrtAddField(y, e_y, "resolved", i4);
    c_u = r8->fileTimeLo;
    f_y = NULL;
    m3 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m3) = c_u;
    emlrtAssign(&f_y, m3);
    emlrtAddField(y, f_y, "fileTimeLo", i4);
    c_u = r8->fileTimeHi;
    g_y = NULL;
    m3 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m3) = c_u;
    emlrtAssign(&g_y, m3);
    emlrtAddField(y, g_y, "fileTimeHi", i4);
    c_u = r8->mFileTimeLo;
    h_y = NULL;
    m3 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m3) = c_u;
    emlrtAssign(&h_y, m3);
    emlrtAddField(y, h_y, "mFileTimeLo", i4);
    c_u = r8->mFileTimeHi;
    i_y = NULL;
    m3 = mxCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
    *(uint32_T *)mxGetData(m3) = c_u;
    emlrtAssign(&i_y, m3);
    emlrtAddField(y, i_y, "mFileTimeHi", i4);
  }

  return y;
}

static real_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void info_helper(ResolvedFunctionInfo info[161])
{
  info[0].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m";
  info[0].name = "repmat";
  info[0].dominantType = "struct";
  info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[0].fileTimeLo = 1352424860U;
  info[0].fileTimeHi = 0U;
  info[0].mFileTimeLo = 0U;
  info[0].mFileTimeHi = 0U;
  info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[1].name = "eml_assert_valid_size_arg";
  info[1].dominantType = "double";
  info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[1].fileTimeLo = 1286818694U;
  info[1].fileTimeHi = 0U;
  info[1].mFileTimeLo = 0U;
  info[1].mFileTimeHi = 0U;
  info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  info[2].name = "isinf";
  info[2].dominantType = "double";
  info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  info[2].fileTimeLo = 1286818760U;
  info[2].fileTimeHi = 0U;
  info[2].mFileTimeLo = 0U;
  info[2].mFileTimeHi = 0U;
  info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  info[3].name = "mtimes";
  info[3].dominantType = "double";
  info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[3].fileTimeLo = 1289519692U;
  info[3].fileTimeHi = 0U;
  info[3].mFileTimeLo = 0U;
  info[3].mFileTimeHi = 0U;
  info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[4].name = "eml_index_class";
  info[4].dominantType = "";
  info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[4].fileTimeLo = 1323170578U;
  info[4].fileTimeHi = 0U;
  info[4].mFileTimeLo = 0U;
  info[4].mFileTimeHi = 0U;
  info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[5].name = "intmax";
  info[5].dominantType = "char";
  info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[5].fileTimeLo = 1311255316U;
  info[5].fileTimeHi = 0U;
  info[5].mFileTimeLo = 0U;
  info[5].mFileTimeHi = 0U;
  info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[6].name = "coder.internal.indexIntRelop";
  info[6].dominantType = "";
  info[6].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  info[6].fileTimeLo = 1326728322U;
  info[6].fileTimeHi = 0U;
  info[6].mFileTimeLo = 0U;
  info[6].mFileTimeHi = 0U;
  info[7].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass";
  info[7].name = "eml_float_model";
  info[7].dominantType = "char";
  info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  info[7].fileTimeLo = 1326727996U;
  info[7].fileTimeHi = 0U;
  info[7].mFileTimeLo = 0U;
  info[7].mFileTimeHi = 0U;
  info[8].context =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass";
  info[8].name = "intmin";
  info[8].dominantType = "char";
  info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  info[8].fileTimeLo = 1311255318U;
  info[8].fileTimeHi = 0U;
  info[8].mFileTimeLo = 0U;
  info[8].mFileTimeHi = 0U;
  info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[9].name = "eml_index_class";
  info[9].dominantType = "";
  info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[9].fileTimeLo = 1323170578U;
  info[9].fileTimeHi = 0U;
  info[9].mFileTimeLo = 0U;
  info[9].mFileTimeHi = 0U;
  info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  info[10].name = "eml_index_minus";
  info[10].dominantType = "coder.internal.indexInt";
  info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[10].fileTimeLo = 1286818778U;
  info[10].fileTimeHi = 0U;
  info[10].mFileTimeLo = 0U;
  info[10].mFileTimeHi = 0U;
  info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[11].name = "eml_index_class";
  info[11].dominantType = "";
  info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[11].fileTimeLo = 1323170578U;
  info[11].fileTimeHi = 0U;
  info[11].mFileTimeLo = 0U;
  info[11].mFileTimeHi = 0U;
  info[12].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m";
  info[12].name = "reshape";
  info[12].dominantType = "double";
  info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[12].fileTimeLo = 1286818768U;
  info[12].fileTimeHi = 0U;
  info[12].mFileTimeLo = 0U;
  info[12].mFileTimeHi = 0U;
  info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[13].name = "eml_index_class";
  info[13].dominantType = "";
  info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[13].fileTimeLo = 1323170578U;
  info[13].fileTimeHi = 0U;
  info[13].mFileTimeLo = 0U;
  info[13].mFileTimeHi = 0U;
  info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!varargin_nempty";
  info[14].name = "eml_index_class";
  info[14].dominantType = "";
  info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[14].fileTimeLo = 1323170578U;
  info[14].fileTimeHi = 0U;
  info[14].mFileTimeLo = 0U;
  info[14].mFileTimeHi = 0U;
  info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[15].name = "eml_assert_valid_size_arg";
  info[15].dominantType = "double";
  info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  info[15].fileTimeLo = 1286818694U;
  info[15].fileTimeHi = 0U;
  info[15].mFileTimeLo = 0U;
  info[15].mFileTimeHi = 0U;
  info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[16].name = "eml_index_prod";
  info[16].dominantType = "coder.internal.indexInt";
  info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  info[16].fileTimeLo = 1286818780U;
  info[16].fileTimeHi = 0U;
  info[16].mFileTimeLo = 0U;
  info[16].mFileTimeHi = 0U;
  info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  info[17].name = "eml_index_class";
  info[17].dominantType = "";
  info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[17].fileTimeLo = 1323170578U;
  info[17].fileTimeHi = 0U;
  info[17].mFileTimeLo = 0U;
  info[17].mFileTimeHi = 0U;
  info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  info[18].name = "eml_int_forloop_overflow_check";
  info[18].dominantType = "";
  info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[18].fileTimeLo = 1346510340U;
  info[18].fileTimeHi = 0U;
  info[18].mFileTimeLo = 0U;
  info[18].mFileTimeHi = 0U;
  info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  info[19].name = "intmax";
  info[19].dominantType = "char";
  info[19].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  info[19].fileTimeLo = 1311255316U;
  info[19].fileTimeHi = 0U;
  info[19].mFileTimeLo = 0U;
  info[19].mFileTimeHi = 0U;
  info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  info[20].name = "eml_index_times";
  info[20].dominantType = "coder.internal.indexInt";
  info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[20].fileTimeLo = 1286818780U;
  info[20].fileTimeHi = 0U;
  info[20].mFileTimeLo = 0U;
  info[20].mFileTimeHi = 0U;
  info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[21].name = "eml_index_class";
  info[21].dominantType = "";
  info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[21].fileTimeLo = 1323170578U;
  info[21].fileTimeHi = 0U;
  info[21].mFileTimeLo = 0U;
  info[21].mFileTimeHi = 0U;
  info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[22].name = "max";
  info[22].dominantType = "double";
  info[22].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  info[22].fileTimeLo = 1311255316U;
  info[22].fileTimeHi = 0U;
  info[22].mFileTimeLo = 0U;
  info[22].mFileTimeHi = 0U;
  info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  info[23].name = "eml_min_or_max";
  info[23].dominantType = "char";
  info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  info[23].fileTimeLo = 1334071490U;
  info[23].fileTimeHi = 0U;
  info[23].mFileTimeLo = 0U;
  info[23].mFileTimeHi = 0U;
  info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  info[24].name = "eml_const_nonsingleton_dim";
  info[24].dominantType = "double";
  info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  info[24].fileTimeLo = 1286818696U;
  info[24].fileTimeHi = 0U;
  info[24].mFileTimeLo = 0U;
  info[24].mFileTimeHi = 0U;
  info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  info[25].name = "eml_scalar_eg";
  info[25].dominantType = "double";
  info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[25].fileTimeLo = 1286818796U;
  info[25].fileTimeHi = 0U;
  info[25].mFileTimeLo = 0U;
  info[25].mFileTimeHi = 0U;
  info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum";
  info[26].name = "eml_index_class";
  info[26].dominantType = "";
  info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[26].fileTimeLo = 1323170578U;
  info[26].fileTimeHi = 0U;
  info[26].mFileTimeLo = 0U;
  info[26].mFileTimeHi = 0U;
  info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[27].name = "eml_index_class";
  info[27].dominantType = "";
  info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[27].fileTimeLo = 1323170578U;
  info[27].fileTimeHi = 0U;
  info[27].mFileTimeLo = 0U;
  info[27].mFileTimeHi = 0U;
  info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[28].name = "isnan";
  info[28].dominantType = "double";
  info[28].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[28].fileTimeLo = 1286818760U;
  info[28].fileTimeHi = 0U;
  info[28].mFileTimeLo = 0U;
  info[28].mFileTimeHi = 0U;
  info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[29].name = "eml_index_plus";
  info[29].dominantType = "coder.internal.indexInt";
  info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[29].fileTimeLo = 1286818778U;
  info[29].fileTimeHi = 0U;
  info[29].mFileTimeLo = 0U;
  info[29].mFileTimeHi = 0U;
  info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[30].name = "eml_index_class";
  info[30].dominantType = "";
  info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[30].fileTimeLo = 1323170578U;
  info[30].fileTimeHi = 0U;
  info[30].mFileTimeLo = 0U;
  info[30].mFileTimeHi = 0U;
  info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[31].name = "eml_int_forloop_overflow_check";
  info[31].dominantType = "";
  info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[31].fileTimeLo = 1346510340U;
  info[31].fileTimeHi = 0U;
  info[31].mFileTimeLo = 0U;
  info[31].mFileTimeHi = 0U;
  info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  info[32].name = "eml_relop";
  info[32].dominantType = "function_handle";
  info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  info[32].fileTimeLo = 1342451182U;
  info[32].fileTimeHi = 0U;
  info[32].mFileTimeLo = 0U;
  info[32].mFileTimeHi = 0U;
  info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  info[33].name = "eml_scalar_eg";
  info[33].dominantType = "double";
  info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[33].fileTimeLo = 1286818796U;
  info[33].fileTimeHi = 0U;
  info[33].mFileTimeLo = 0U;
  info[33].mFileTimeHi = 0U;
  info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  info[34].name = "eml_scalexp_alloc";
  info[34].dominantType = "double";
  info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  info[34].fileTimeLo = 1352424860U;
  info[34].fileTimeHi = 0U;
  info[34].mFileTimeLo = 0U;
  info[34].mFileTimeHi = 0U;
  info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  info[35].name = "eml_index_class";
  info[35].dominantType = "";
  info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[35].fileTimeLo = 1323170578U;
  info[35].fileTimeHi = 0U;
  info[35].mFileTimeLo = 0U;
  info[35].mFileTimeHi = 0U;
  info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  info[36].name = "eml_scalar_eg";
  info[36].dominantType = "double";
  info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[36].fileTimeLo = 1286818796U;
  info[36].fileTimeHi = 0U;
  info[36].mFileTimeLo = 0U;
  info[36].mFileTimeHi = 0U;
  info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  info[37].name = "eml_relop";
  info[37].dominantType = "function_handle";
  info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  info[37].fileTimeLo = 1342451182U;
  info[37].fileTimeHi = 0U;
  info[37].mFileTimeLo = 0U;
  info[37].mFileTimeHi = 0U;
  info[38].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  info[38].name = "coder.internal.indexIntRelop";
  info[38].dominantType = "";
  info[38].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  info[38].fileTimeLo = 1326728322U;
  info[38].fileTimeHi = 0U;
  info[38].mFileTimeLo = 0U;
  info[38].mFileTimeHi = 0U;
  info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  info[39].name = "isnan";
  info[39].dominantType = "coder.internal.indexInt";
  info[39].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  info[39].fileTimeLo = 1286818760U;
  info[39].fileTimeHi = 0U;
  info[39].mFileTimeLo = 0U;
  info[39].mFileTimeHi = 0U;
  info[40].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[40].name = "eml_error";
  info[40].dominantType = "char";
  info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  info[40].fileTimeLo = 1343830358U;
  info[40].fileTimeHi = 0U;
  info[40].mFileTimeLo = 0U;
  info[40].mFileTimeHi = 0U;
  info[41].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[41].name = "eml_scalar_eg";
  info[41].dominantType = "double";
  info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[41].fileTimeLo = 1286818796U;
  info[41].fileTimeHi = 0U;
  info[41].mFileTimeLo = 0U;
  info[41].mFileTimeHi = 0U;
  info[42].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[42].name = "coder.internal.indexIntRelop";
  info[42].dominantType = "";
  info[42].resolved =
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m";
  info[42].fileTimeLo = 1326728322U;
  info[42].fileTimeHi = 0U;
  info[42].mFileTimeLo = 0U;
  info[42].mFileTimeHi = 0U;
  info[43].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  info[43].name = "eml_int_forloop_overflow_check";
  info[43].dominantType = "";
  info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  info[43].fileTimeLo = 1346510340U;
  info[43].fileTimeHi = 0U;
  info[43].mFileTimeLo = 0U;
  info[43].mFileTimeHi = 0U;
  info[44].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m";
  info[44].name = "modelInit";
  info[44].dominantType = "double";
  info[44].resolved =
    "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/modelInit.m";
  info[44].fileTimeLo = 1387965645U;
  info[44].fileTimeHi = 0U;
  info[44].mFileTimeLo = 0U;
  info[44].mFileTimeHi = 0U;
  info[45].context =
    "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/modelInit.m";
  info[45].name = "mrdivide";
  info[45].dominantType = "double";
  info[45].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[45].fileTimeLo = 1357951548U;
  info[45].fileTimeHi = 0U;
  info[45].mFileTimeLo = 1319729966U;
  info[45].mFileTimeHi = 0U;
  info[46].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  info[46].name = "rdivide";
  info[46].dominantType = "double";
  info[46].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[46].fileTimeLo = 1346510388U;
  info[46].fileTimeHi = 0U;
  info[46].mFileTimeLo = 0U;
  info[46].mFileTimeHi = 0U;
  info[47].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[47].name = "eml_scalexp_compatible";
  info[47].dominantType = "double";
  info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  info[47].fileTimeLo = 1286818796U;
  info[47].fileTimeHi = 0U;
  info[47].mFileTimeLo = 0U;
  info[47].mFileTimeHi = 0U;
  info[48].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  info[48].name = "eml_div";
  info[48].dominantType = "double";
  info[48].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  info[48].fileTimeLo = 1313347810U;
  info[48].fileTimeHi = 0U;
  info[48].mFileTimeLo = 0U;
  info[48].mFileTimeHi = 0U;
  info[49].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/mog.m";
  info[49].name = "update";
  info[49].dominantType = "double";
  info[49].resolved =
    "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[49].fileTimeLo = 1387965616U;
  info[49].fileTimeHi = 0U;
  info[49].mFileTimeLo = 0U;
  info[49].mFileTimeHi = 0U;
  info[50].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/update.m";
  info[50].name = "match";
  info[50].dominantType = "double";
  info[50].resolved = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m";
  info[50].fileTimeLo = 1387965636U;
  info[50].fileTimeHi = 0U;
  info[50].mFileTimeLo = 0U;
  info[50].mFileTimeHi = 0U;
  info[51].context = "[E]C:/Users/Carlos/Documents/GitHub/mog-cartrack/match.m";
  info[51].name = "mtimes";
  info[51].dominantType = "double";
  info[51].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[51].fileTimeLo = 1289519692U;
  info[51].fileTimeHi = 0U;
  info[51].mFileTimeLo = 0U;
  info[51].mFileTimeHi = 0U;
  info[52].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[52].name = "eml_index_class";
  info[52].dominantType = "";
  info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[52].fileTimeLo = 1323170578U;
  info[52].fileTimeHi = 0U;
  info[52].mFileTimeLo = 0U;
  info[52].mFileTimeHi = 0U;
  info[53].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[53].name = "eml_scalar_eg";
  info[53].dominantType = "double";
  info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[53].fileTimeLo = 1286818796U;
  info[53].fileTimeHi = 0U;
  info[53].mFileTimeLo = 0U;
  info[53].mFileTimeHi = 0U;
  info[54].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  info[54].name = "eml_xgemm";
  info[54].dominantType = "char";
  info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  info[54].fileTimeLo = 1299076772U;
  info[54].fileTimeHi = 0U;
  info[54].mFileTimeLo = 0U;
  info[54].mFileTimeHi = 0U;
  info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  info[55].name = "eml_blas_inline";
  info[55].dominantType = "";
  info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  info[55].fileTimeLo = 1299076768U;
  info[55].fileTimeHi = 0U;
  info[55].mFileTimeLo = 0U;
  info[55].mFileTimeHi = 0U;
  info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  info[56].name = "eml_index_class";
  info[56].dominantType = "";
  info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[56].fileTimeLo = 1323170578U;
  info[56].fileTimeHi = 0U;
  info[56].mFileTimeLo = 0U;
  info[56].mFileTimeHi = 0U;
  info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  info[57].name = "eml_scalar_eg";
  info[57].dominantType = "double";
  info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[57].fileTimeLo = 1286818796U;
  info[57].fileTimeHi = 0U;
  info[57].mFileTimeLo = 0U;
  info[57].mFileTimeHi = 0U;
  info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  info[58].name = "eml_refblas_xgemm";
  info[58].dominantType = "char";
  info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[58].fileTimeLo = 1299076774U;
  info[58].fileTimeHi = 0U;
  info[58].mFileTimeLo = 0U;
  info[58].mFileTimeHi = 0U;
  info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[59].name = "eml_index_minus";
  info[59].dominantType = "double";
  info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  info[59].fileTimeLo = 1286818778U;
  info[59].fileTimeHi = 0U;
  info[59].mFileTimeLo = 0U;
  info[59].mFileTimeHi = 0U;
  info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[60].name = "eml_index_class";
  info[60].dominantType = "";
  info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  info[60].fileTimeLo = 1323170578U;
  info[60].fileTimeHi = 0U;
  info[60].mFileTimeLo = 0U;
  info[60].mFileTimeHi = 0U;
  info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[61].name = "eml_scalar_eg";
  info[61].dominantType = "double";
  info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  info[61].fileTimeLo = 1286818796U;
  info[61].fileTimeHi = 0U;
  info[61].mFileTimeLo = 0U;
  info[61].mFileTimeHi = 0U;
  info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[62].name = "eml_index_times";
  info[62].dominantType = "coder.internal.indexInt";
  info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  info[62].fileTimeLo = 1286818780U;
  info[62].fileTimeHi = 0U;
  info[62].mFileTimeLo = 0U;
  info[62].mFileTimeHi = 0U;
  info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  info[63].name = "eml_index_plus";
  info[63].dominantType = "coder.internal.indexInt";
  info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  info[63].fileTimeLo = 1286818778U;
  info[63].fileTimeHi = 0U;
  info[63].mFileTimeLo = 0U;
  info[63].mFileTimeHi = 0U;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  ResolvedFunctionInfo info[161];
  nameCaptureInfo = NULL;
  info_helper(info);
  b_info_helper(info);
  c_info_helper(info);
  emlrtAssign(&nameCaptureInfo, emlrt_marshallOut(info));
  emlrtNameCapturePostProcessR2012a(emlrtAlias(nameCaptureInfo));
  return nameCaptureInfo;
}

void mog_api(const mxArray * const prhs[2], const mxArray *plhs[2])
{
  emxArray_real_T *image;
  emxArray_real_T *foreground;
  emxArray_uint8_T *background;
  real_T count;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  c_emxInit_real_T(&image, 3, &k_emlrtRTEI, TRUE);
  emxInit_real_T(&foreground, 2, &k_emlrtRTEI, TRUE);
  emxInit_uint8_T(&background, 3, &k_emlrtRTEI, TRUE);

  /* Marshall function inputs */
  emlrt_marshallIn(emlrtAlias(prhs[0]), "image", image);
  count = c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "count");

  /* Invoke the target function */
  mog(image, count, foreground, background);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(foreground);
  plhs[1] = c_emlrt_marshallOut(background);
  background->canFreeData = FALSE;
  emxFree_uint8_T(&background);
  foreground->canFreeData = FALSE;
  emxFree_real_T(&foreground);
  image->canFreeData = FALSE;
  emxFree_real_T(&image);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (mog_api.c) */
