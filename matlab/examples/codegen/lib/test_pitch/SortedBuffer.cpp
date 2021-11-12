/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SortedBuffer.cpp
 *
 * Code generation for function 'SortedBuffer'
 *
 */

/* Include files */
#include "SortedBuffer.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"

/* Function Definitions */
void SortedBuffer_insert(coder_internal_SortedBuffer *obj, double x)
{
  int i;
  int b_i;
  int k;
  int i1;
  if (obj->nbuf < 5) {
    if (rtIsNaN(x)) {
      obj->nnans++;
    } else if (obj->nbuf == 0) {
      obj->buf[0] = x;
      obj->nbuf = 1;
    } else {
      i = SortedBuffer_locateElement(obj->buf, obj->nbuf, x);
      if (i == 0) {
        b_i = obj->nbuf;
        for (k = b_i; k >= 1; k--) {
          obj->buf[k] = obj->buf[k - 1];
        }

        obj->buf[0] = x;
        obj->nbuf++;
      } else if (i >= obj->nbuf) {
        obj->nbuf++;
        obj->buf[obj->nbuf - 1] = x;
      } else {
        b_i = obj->nbuf;
        i1 = i + 1;
        for (k = b_i; k >= i1; k--) {
          obj->buf[k] = obj->buf[k - 1];
        }

        obj->buf[i] = x;
        obj->nbuf++;
      }
    }
  }
}

int SortedBuffer_locateElement(const double obj_buf[5], int obj_nbuf, double x)
{
  int i;
  int ip1;
  int upper;
  int m;
  if ((obj_nbuf == 0) || (x < obj_buf[0])) {
    i = 0;
  } else if (x < obj_buf[obj_nbuf - 1]) {
    i = 1;
    ip1 = 2;
    upper = obj_nbuf;
    while (upper > ip1) {
      m = (i + upper) >> 1;
      if (x < obj_buf[m - 1]) {
        upper = m;
      } else {
        i = m;
        ip1 = m + 1;
      }
    }
  } else {
    i = obj_nbuf;
  }

  return i;
}

void SortedBuffer_remove(coder_internal_SortedBuffer *obj, double x)
{
  int i;
  int b_i;
  int k;
  if (rtIsNaN(x)) {
    if (obj->nnans >= 1) {
      obj->nnans--;
    }
  } else if (obj->nbuf == 1) {
    if (x == obj->buf[0]) {
      obj->nbuf = 0;
    }
  } else {
    i = SortedBuffer_locateElement(obj->buf, obj->nbuf, x);
    if ((i > 0) && (x == obj->buf[i - 1])) {
      i++;
      b_i = obj->nbuf;
      for (k = i; k <= b_i; k++) {
        obj->buf[k - 2] = obj->buf[k - 1];
      }

      obj->nbuf--;
    }
  }
}

/* End of code generation (SortedBuffer.cpp) */
