/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft1.h
 *
 * Code generation for function 'fft1'
 *
 */

#ifndef FFT1_H
#define FFT1_H

/* Include files */
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "test_pitch_types.h"

/* Function Declarations */
extern void c_r2br_r2dit_trig(const double x[9600], const double costab[257],
  const double sintab[257], creal_T y[24576]);
extern void d_r2br_r2dit_trig(const double x[24576], const double costab[257],
  const double sintab[257], creal_T y[24576]);
extern void dobluesteinfft(const double x[4080], const double costab[8193],
  const double sintab[8193], const double sintabinv[8193], creal_T y[136000]);

#endif

/* End of code generation (fft1.h) */
