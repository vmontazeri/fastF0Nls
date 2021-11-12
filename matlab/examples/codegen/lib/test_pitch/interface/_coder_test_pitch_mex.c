/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_test_pitch_mex.c
 *
 * Code generation for function '_coder_test_pitch_mex'
 *
 */

/* Include files */
#include "_coder_test_pitch_mex.h"
#include "_coder_test_pitch_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void test_pitch_mexFunction(int32_T nlhs, mxArray *plhs[2],
  int32_T nrhs);

/* Function Definitions */
void test_pitch_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs)
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        10, "test_pitch");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "test_pitch");
  }

  /* Call the function. */
  test_pitch_api(nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  (void)prhs;
  mexAtExit(test_pitch_atexit);

  /* Module initialization. */
  test_pitch_initialize();

  /* Dispatch the entry-point. */
  test_pitch_mexFunction(nlhs, plhs, nrhs);

  /* Module termination. */
  test_pitch_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_test_pitch_mex.c) */
