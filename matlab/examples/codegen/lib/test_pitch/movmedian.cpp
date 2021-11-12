/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * movmedian.cpp
 *
 * Code generation for function 'movmedian'
 *
 */

/* Include files */
#include "movmedian.h"
#include "SortedBuffer.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"

/* Function Definitions */
void movmedian(const double x[17], double y[17])
{
  int i;
  coder_internal_SortedBuffer s;
  double d;
  int k;
  int inew;
  int b_i;
  int b_k;
  for (i = 0; i < 5; i++) {
    s.buf[i] = 0.0;
  }

  s.nbuf = 0;
  s.includenans = true;
  s.nnans = 0;
  SortedBuffer_insert(&s, x[0]);
  SortedBuffer_insert(&s, x[1]);
  SortedBuffer_insert(&s, x[2]);
  if (s.nnans > 0) {
    y[0] = rtNaN;
  } else if (s.nbuf == 0) {
    y[0] = rtNaN;
  } else {
    i = s.nbuf >> 1;
    if ((s.nbuf & 1) == 1) {
      y[0] = s.buf[i];
    } else {
      d = s.buf[i - 1];
      if (rtIsInf(d) || rtIsInf(s.buf[i])) {
        y[0] = (d + s.buf[i]) / 2.0;
      } else {
        y[0] = d + (s.buf[i] - d) / 2.0;
      }
    }
  }

  SortedBuffer_insert(&s, x[3]);
  if (s.nnans > 0) {
    y[1] = rtNaN;
  } else if (s.nbuf == 0) {
    y[1] = rtNaN;
  } else {
    i = s.nbuf >> 1;
    if ((s.nbuf & 1) == 1) {
      y[1] = s.buf[i];
    } else {
      d = s.buf[i - 1];
      if (rtIsInf(d) || rtIsInf(s.buf[i])) {
        y[1] = (d + s.buf[i]) / 2.0;
      } else {
        y[1] = d + (s.buf[i] - d) / 2.0;
      }
    }
  }

  SortedBuffer_insert(&s, x[4]);
  if (s.nnans > 0) {
    y[2] = rtNaN;
  } else if (s.nbuf == 0) {
    y[2] = rtNaN;
  } else {
    i = s.nbuf >> 1;
    if ((s.nbuf & 1) == 1) {
      y[2] = s.buf[i];
    } else {
      d = s.buf[i - 1];
      if (rtIsInf(d) || rtIsInf(s.buf[i])) {
        y[2] = (d + s.buf[i]) / 2.0;
      } else {
        y[2] = d + (s.buf[i] - d) / 2.0;
      }
    }
  }

  for (k = 0; k < 12; k++) {
    if (rtIsNaN(x[k])) {
      if (s.nnans > 0) {
        s.nnans--;
      }

      SortedBuffer_insert(&s, x[k + 5]);
    } else {
      d = x[k + 5];
      if (rtIsNaN(d)) {
        SortedBuffer_remove(&s, x[k]);
        s.nnans++;
      } else {
        i = SortedBuffer_locateElement(s.buf, s.nbuf, x[k]);
        if ((i > 0) && (s.buf[i - 1] == x[k])) {
          inew = SortedBuffer_locateElement(s.buf, s.nbuf, d);
          if (i <= inew) {
            b_i = inew - 1;
            for (b_k = i; b_k <= b_i; b_k++) {
              s.buf[b_k - 1] = s.buf[b_k];
            }

            s.buf[inew - 1] = d;
          } else if (i == inew + 1) {
            s.buf[i - 1] = d;
          } else {
            b_i = inew + 2;
            for (b_k = i; b_k >= b_i; b_k--) {
              s.buf[b_k - 1] = s.buf[b_k - 2];
            }

            s.buf[inew] = d;
          }
        } else {
          SortedBuffer_insert(&s, d);
        }
      }
    }

    if (s.nnans > 0) {
      y[k + 3] = rtNaN;
    } else if (s.nbuf == 0) {
      y[k + 3] = rtNaN;
    } else {
      i = s.nbuf >> 1;
      if ((s.nbuf & 1) == 1) {
        y[k + 3] = s.buf[i];
      } else {
        d = s.buf[i - 1];
        if (rtIsInf(d) || rtIsInf(s.buf[i])) {
          y[k + 3] = (d + s.buf[i]) / 2.0;
        } else {
          y[k + 3] = d + (s.buf[i] - d) / 2.0;
        }
      }
    }
  }

  SortedBuffer_remove(&s, x[12]);
  if (s.nnans > 0) {
    y[15] = rtNaN;
  } else if (s.nbuf == 0) {
    y[15] = rtNaN;
  } else {
    i = s.nbuf >> 1;
    if ((s.nbuf & 1) == 1) {
      y[15] = s.buf[i];
    } else {
      d = s.buf[i - 1];
      if (rtIsInf(d) || rtIsInf(s.buf[i])) {
        y[15] = (d + s.buf[i]) / 2.0;
      } else {
        y[15] = d + (s.buf[i] - d) / 2.0;
      }
    }
  }

  SortedBuffer_remove(&s, x[13]);
  if (s.nnans > 0) {
    y[16] = rtNaN;
  } else if (s.nbuf == 0) {
    y[16] = rtNaN;
  } else {
    i = s.nbuf >> 1;
    if ((s.nbuf & 1) == 1) {
      y[16] = s.buf[i];
    } else {
      d = s.buf[i - 1];
      if (rtIsInf(d) || rtIsInf(s.buf[i])) {
        y[16] = (d + s.buf[i]) / 2.0;
      } else {
        y[16] = d + (s.buf[i] - d) / 2.0;
      }
    }
  }
}

/* End of code generation (movmedian.cpp) */
