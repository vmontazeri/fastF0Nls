/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_test_pitch_api.c
 *
 * Code generation for function '_coder_test_pitch_api'
 *
 */

/* Include files */
#include "_coder_test_pitch_api.h"
#include "_coder_test_pitch_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131483U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "test_pitch",                        /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static const mxArray *emlrt_marshallOut(const real_T u[16]);

/* Function Definitions */
static const mxArray *emlrt_marshallOut(const real_T u[16])
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 16 };

  y = NULL;
  m = emlrtCreateNumericArray(1, iv, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, *(int32_T (*)[1])&iv1[0], 1);
  emlrtAssign(&y, m);
  return y;
}

void test_pitch_api(int32_T nlhs, const mxArray *plhs[2])
{
  real_T (*f0_LHS)[16];
  real_T (*f0_SRH)[16];
  f0_LHS = (real_T (*)[16])mxMalloc(sizeof(real_T [16]));
  f0_SRH = (real_T (*)[16])mxMalloc(sizeof(real_T [16]));

  /* Invoke the target function */
  test_pitch(*f0_LHS, *f0_SRH);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*f0_LHS);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*f0_SRH);
  }
}

void test_pitch_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  test_pitch_xil_terminate();
  test_pitch_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void test_pitch_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void test_pitch_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (_coder_test_pitch_api.c) */
