/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * levinson.cpp
 *
 * Code generation for function 'levinson'
 *
 */

/* Include files */
#include "levinson.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"

/* Function Definitions */
void levinson(const creal_T R_in[12], creal_T A_out[12])
{
  boolean_T isIEven;
  double rTmpP;
  int i;
  double acc_re;
  double acc_im;
  int offset1;
  int offset2;
  int j;
  int upLim;
  double rTmpA_re;
  double rTmpA_im;
  double rTmpA1_re;

  /* System object Constructor function: dsp.LevinsonSolver */
  /* System object Outputs function: dsp.LevinsonSolver */
  isIEven = false;
  rTmpP = R_in[0].re;
  for (i = 0; i < 11; i++) {
    acc_re = R_in[i + 1].re;
    acc_im = R_in[i + 1].im;
    offset1 = 1;
    offset2 = i;
    for (j = 1; j < i + 1; j++) {
      acc_re += A_out[offset1].re * R_in[offset2].re - A_out[offset1].im *
        R_in[offset2].im;
      acc_im += A_out[offset1].re * R_in[offset2].im + A_out[offset1].im *
        R_in[offset2].re;
      offset1++;
      offset2--;
    }

    acc_re *= -(1.0 / rTmpP);
    acc_im *= -(1.0 / rTmpP);
    rTmpP *= 1.0 - (acc_re * acc_re + acc_im * acc_im);
    upLim = i >> 1;
    offset1 = 1;
    offset2 = i;
    for (j = 1; j <= upLim; j++) {
      rTmpA_re = A_out[offset1].re;
      rTmpA_im = A_out[offset1].im;
      rTmpA1_re = A_out[offset2].re;
      A_out[offset1].re += acc_re * A_out[offset2].re - acc_im * -A_out[offset2]
        .im;
      A_out[offset1].im += acc_re * -A_out[offset2].im + acc_im * rTmpA1_re;
      A_out[offset2].re += acc_re * rTmpA_re - acc_im * -rTmpA_im;
      A_out[offset2].im += acc_re * -rTmpA_im + acc_im * rTmpA_re;
      offset1++;
      offset2--;
    }

    if (isIEven) {
      offset1 = (i + 1) >> 1;
      rTmpA1_re = A_out[offset1].re;
      A_out[offset1].re += acc_re * A_out[offset1].re - acc_im * -A_out[offset1]
        .im;
      A_out[offset1].im += acc_re * -A_out[offset1].im + acc_im * rTmpA1_re;
    }

    isIEven = !isIEven;
    A_out[i + 1].re = acc_re;
    A_out[i + 1].im = acc_im;
  }

  A_out[0].re = 1.0;
  A_out[0].im = 0.0;
}

/* End of code generation (levinson.cpp) */
