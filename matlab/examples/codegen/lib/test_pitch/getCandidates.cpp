/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getCandidates.cpp
 *
 * Code generation for function 'getCandidates'
 *
 */

/* Include files */
#include "getCandidates.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"
#include <cstring>

/* Function Definitions */
void b_getCandidates(double domain[6800], double peaks[17], double locs[17])
{
  int c;
  int i;
  int idx;
  int k;
  boolean_T exitg1;
  double ex;
  double d;
  int y_size_idx_1;
  short tmp_data[351];
  short y_data[2048];
  for (c = 0; c < 17; c++) {
    i = 400 * c + 49;
    if (!rtIsNaN(domain[i])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 352)) {
        if (!rtIsNaN(domain[(k + 400 * c) + 48])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      peaks[c] = domain[i];
      idx = 1;
    } else {
      ex = domain[(idx + 400 * c) + 48];
      i = idx + 1;
      for (k = i; k < 352; k++) {
        d = domain[(k + 400 * c) + 48];
        if (ex < d) {
          ex = d;
          idx = k;
        }
      }

      peaks[c] = ex;
    }

    k = idx + 51;
    if (k >= 400) {
      k = 400;
    }

    if (k < idx + 49) {
      y_size_idx_1 = 0;
    } else {
      k = (k - idx) - 49;
      y_size_idx_1 = k + 1;
      for (i = 0; i <= k; i++) {
        y_data[i] = static_cast<short>(((idx + i) + 49));
      }
    }

    if (0 <= y_size_idx_1 - 1) {
      std::memcpy(&tmp_data[0], &y_data[0], y_size_idx_1 * sizeof(short));
    }

    for (i = 0; i < y_size_idx_1; i++) {
      domain[(tmp_data[i] + 400 * c) - 1] = rtNaN;
    }

    locs[c] = (static_cast<double>(idx) + 50.0) - 1.0;
  }
}

void getCandidates(double domain[6817], double peaks[17], double locs[17])
{
  int c;
  int i;
  int idx;
  int k;
  boolean_T exitg1;
  double ex;
  double d;
  int y_size_idx_1;
  short tmp_data[351];
  short y_data[2048];
  for (c = 0; c < 17; c++) {
    i = 401 * c + 49;
    if (!rtIsNaN(domain[i])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 352)) {
        if (!rtIsNaN(domain[(k + 401 * c) + 48])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (idx == 0) {
      peaks[c] = domain[i];
      idx = 1;
    } else {
      ex = domain[(idx + 401 * c) + 48];
      i = idx + 1;
      for (k = i; k < 352; k++) {
        d = domain[(k + 401 * c) + 48];
        if (ex < d) {
          ex = d;
          idx = k;
        }
      }

      peaks[c] = ex;
    }

    k = idx + 51;
    if (k >= 400) {
      k = 400;
    }

    if (k < idx + 49) {
      y_size_idx_1 = 0;
    } else {
      k = (k - idx) - 49;
      y_size_idx_1 = k + 1;
      for (i = 0; i <= k; i++) {
        y_data[i] = static_cast<short>(((idx + i) + 49));
      }
    }

    if (0 <= y_size_idx_1 - 1) {
      std::memcpy(&tmp_data[0], &y_data[0], y_size_idx_1 * sizeof(short));
    }

    for (i = 0; i < y_size_idx_1; i++) {
      domain[(tmp_data[i] + 401 * c) - 1] = rtNaN;
    }

    locs[c] = (static_cast<double>(idx) + 50.0) - 1.0;
  }
}

/* End of code generation (getCandidates.cpp) */
