/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_test_pitch_api.h
 *
 * Code generation for function '_coder_test_pitch_api'
 *
 */

#ifndef _CODER_TEST_PITCH_API_H
#define _CODER_TEST_PITCH_API_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void test_pitch(real_T f0_LHS[16], real_T f0_SRH[16]);
extern void test_pitch_api(int32_T nlhs, const mxArray *plhs[2]);
extern void test_pitch_atexit(void);
extern void test_pitch_initialize(void);
extern void test_pitch_terminate(void);
extern void test_pitch_xil_shutdown(void);
extern void test_pitch_xil_terminate(void);

#endif

/* End of code generation (_coder_test_pitch_api.h) */
