/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_pitch_types.h
 *
 * Code generation for function 'test_pitch_types'
 *
 */

#ifndef TEST_PITCH_TYPES_H
#define TEST_PITCH_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
struct test_pitchTLS
{
  struct {
    creal_T fv[16384];
    creal_T b_fv[16384];
  } f0;

  struct {
    creal_T rwork[8000];
  } f1;
};

struct coder_internal_SortedBuffer
{
  double buf[5];
  int nbuf;
  boolean_T includenans;
  int nnans;
};

#endif

/* End of code generation (test_pitch_types.h) */
