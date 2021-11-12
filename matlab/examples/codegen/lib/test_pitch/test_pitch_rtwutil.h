/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_pitch_rtwutil.h
 *
 * Code generation for function 'test_pitch_rtwutil'
 *
 */

#ifndef TEST_PITCH_RTWUTIL_H
#define TEST_PITCH_RTWUTIL_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "test_pitch_types.h"

/* Function Declarations */
extern void emlrtFreeThreadStackData();
extern test_pitchTLS *emlrtGetThreadStackData();
extern void emlrtInitThreadStackData();
extern double rt_hypotd_snf(double u0, double u1);

#endif

/* End of code generation (test_pitch_rtwutil.h) */
