/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_pitch_initialize.cpp
 *
 * Code generation for function 'test_pitch_initialize'
 *
 */

/* Include files */
#include "test_pitch_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"
#include "test_pitch_data.h"
#include "test_pitch_rtwutil.h"

/* Function Definitions */
void test_pitch_initialize()
{
  rt_InitInfAndNaN();
  omp_init_nest_lock(&emlrtNestLockGlobal);
  c_eml_rand_mt19937ar_stateful_i();
  emlrtInitThreadStackData();
  isInitialized_test_pitch = true;
}

/* End of code generation (test_pitch_initialize.cpp) */
