/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bluesteinSetup.cpp
 *
 * Code generation for function 'bluesteinSetup'
 *
 */

/* Include files */
#include "bluesteinSetup.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"
#include <cmath>

/* Function Definitions */
void bluesteinSetup(creal_T wwc[15999])
{
  int idx;
  int rt;
  int k;
  int y;
  double nt_im;
  double nt_re;
  idx = 7998;
  rt = 0;
  wwc[7999].re = 1.0;
  wwc[7999].im = 0.0;
  for (k = 0; k < 7999; k++) {
    y = ((k + 1) << 1) - 1;
    if (16000 - rt <= y) {
      rt = (y + rt) - 16000;
    } else {
      rt += y;
    }

    nt_im = -3.1415926535897931 * static_cast<double>(rt) / 8000.0;
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
    }

    wwc[idx].re = nt_re;
    wwc[idx].im = -nt_im;
    idx--;
  }

  idx = 0;
  for (k = 7998; k >= 0; k--) {
    wwc[k + 8000] = wwc[idx];
    idx++;
  }
}

/* End of code generation (bluesteinSetup.cpp) */
