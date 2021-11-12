/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_pitch_terminate.cpp
 *
 * Code generation for function 'test_pitch_terminate'
 *
 */

/* Include files */
#include "test_pitch_terminate.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"
#include "test_pitch_data.h"
#include "test_pitch_rtwutil.h"

/* Function Definitions */
void test_pitch_terminate()
{
  emlrtFreeThreadStackData();
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
  isInitialized_test_pitch = false;
}

/* End of code generation (test_pitch_terminate.cpp) */
