/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.cpp
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "fft.h"
#include "fft1.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"
#include <cmath>

/* Function Definitions */
void fft(const double x[4080], creal_T y[136000])
{
  double costab1q[4097];
  int k;
  static double costab[8193];
  static double sintab[8193];
  static double sintabinv[8193];
  double sintabinv_tmp;
  double b_sintabinv_tmp;
  costab1q[0] = 1.0;
  for (k = 0; k < 2048; k++) {
    costab1q[k + 1] = std::cos(0.00038349519697141029 * (static_cast<double>(k)
      + 1.0));
  }

  for (k = 0; k < 2047; k++) {
    costab1q[k + 2049] = std::sin(0.00038349519697141029 * (4096.0 - (
      static_cast<double>(k) + 2049.0)));
  }

  costab1q[4096] = 0.0;
  costab[0] = 1.0;
  sintab[0] = 0.0;
  for (k = 0; k < 4096; k++) {
    sintabinv_tmp = costab1q[4095 - k];
    sintabinv[k + 1] = sintabinv_tmp;
    b_sintabinv_tmp = costab1q[k + 1];
    sintabinv[k + 4097] = b_sintabinv_tmp;
    costab[k + 1] = b_sintabinv_tmp;
    sintab[k + 1] = -sintabinv_tmp;
    costab[k + 4097] = -sintabinv_tmp;
    sintab[k + 4097] = -b_sintabinv_tmp;
  }

  dobluesteinfft(x, costab, sintab, sintabinv, y);
}

/* End of code generation (fft.cpp) */
