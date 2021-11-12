/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft1.cpp
 *
 * Code generation for function 'fft1'
 *
 */

/* Include files */
#include "fft1.h"
#include "bluesteinSetup.h"
#include "rt_nonfinite.h"
#include "test_pitch.h"
#include "test_pitch_rtwutil.h"
#include <cstring>

/* Function Declarations */
static void b_r2br_r2dit_trig(const creal_T x[16384], const double costab[8193],
  const double sintab[8193], creal_T y[16384]);
static void b_r2br_r2dit_trig_impl(const double x[9600], int xoffInit, const
  double costab[257], const double sintab[257], creal_T y[512]);
static void bluestein(const double x[4080], int xoffInit, const double costab
                      [8193], const double sintab[8193], const double costabinv
                      [8193], const double sintabinv[8193], const creal_T wwc
                      [15999], creal_T y[8000]);
static void c_r2br_r2dit_trig_impl(const double x[24576], int xoffInit, const
  double costab[257], const double sintab[257], creal_T y[512]);
static void r2br_r2dit_trig(const creal_T x[15999], const double costab[8193],
  const double sintab[8193], creal_T y[16384]);
static void r2br_r2dit_trig_impl(const creal_T x[8000], const double costab[8193],
  const double sintab[8193], creal_T y[16384]);

/* Function Definitions */
static void b_r2br_r2dit_trig(const creal_T x[16384], const double costab[8193],
  const double sintab[8193], creal_T y[16384])
{
  int ix;
  int ju;
  int iy;
  int i;
  boolean_T tst;
  double twid_re;
  double temp_re;
  double twid_im;
  int iheight;
  double temp_im;
  double re;
  double im;
  int istart;
  int temp_re_tmp;
  int j;
  int ihi;
  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 16383; i++) {
    y[iy] = x[ix];
    iy = 16384;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 16382; i += 2) {
    twid_re = y[i + 1].re;
    temp_re = twid_re;
    twid_im = y[i + 1].im;
    temp_im = twid_im;
    re = y[i].re;
    im = y[i].im;
    twid_re = y[i].re - twid_re;
    y[i + 1].re = twid_re;
    twid_im = y[i].im - twid_im;
    y[i + 1].im = twid_im;
    y[i].re = re + temp_re;
    y[i].im = im + temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 4096;
  iheight = 16381;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - y[temp_re_tmp].im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 8192; j += ju) {
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[temp_re_tmp].im;
        temp_im = twid_re * y[temp_re_tmp].im + twid_im * y[temp_re_tmp].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }

  for (iy = 0; iy < 16384; iy++) {
    y[iy].re *= 6.103515625E-5;
    y[iy].im *= 6.103515625E-5;
  }
}

static void b_r2br_r2dit_trig_impl(const double x[9600], int xoffInit, const
  double costab[257], const double sintab[257], creal_T y[512])
{
  int ix;
  int ju;
  int iy;
  int i;
  boolean_T tst;
  double twid_re;
  double temp_re;
  double twid_im;
  int iheight;
  double temp_im;
  double re;
  double im;
  int istart;
  int temp_re_tmp;
  int j;
  int ihi;
  std::memset(&y[0], 0, 512U * sizeof(creal_T));
  ix = xoffInit;
  ju = 0;
  iy = 0;
  for (i = 0; i < 199; i++) {
    y[iy].re = x[ix];
    y[iy].im = 0.0;
    iy = 512;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy].re = x[ix];
  y[iy].im = 0.0;
  for (i = 0; i <= 510; i += 2) {
    twid_re = y[i + 1].re;
    temp_re = twid_re;
    twid_im = y[i + 1].im;
    temp_im = twid_im;
    re = y[i].re;
    im = y[i].im;
    twid_re = y[i].re - twid_re;
    y[i + 1].re = twid_re;
    twid_im = y[i].im - twid_im;
    y[i + 1].im = twid_im;
    y[i].re = re + temp_re;
    y[i].im = im + temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 128;
  iheight = 509;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - y[temp_re_tmp].im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 256; j += ju) {
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[temp_re_tmp].im;
        temp_im = twid_re * y[temp_re_tmp].im + twid_im * y[temp_re_tmp].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }
}

static void bluestein(const double x[4080], int xoffInit, const double costab
                      [8193], const double sintab[8193], const double costabinv
                      [8193], const double sintabinv[8193], const creal_T wwc
                      [15999], creal_T y[8000])
{
  int xidx;
  int k;
  double im;
  double d;
  double d1;
  double d2;
  test_pitchTLS *test_pitchTLSThread;
  test_pitchTLSThread = emlrtGetThreadStackData();
  std::memset(&y[0], 0, 8000U * sizeof(creal_T));
  xidx = xoffInit;
  for (k = 0; k < 240; k++) {
    y[k].re = wwc[k + 7999].re * x[xidx];
    y[k].im = wwc[k + 7999].im * -x[xidx];
    xidx++;
  }

  std::memset(&y[240], 0, 7760U * sizeof(creal_T));
  r2br_r2dit_trig_impl(y, costab, sintab, test_pitchTLSThread->f0.fv);
  r2br_r2dit_trig(wwc, costab, sintab, test_pitchTLSThread->f0.b_fv);
  for (xidx = 0; xidx < 16384; xidx++) {
    im = test_pitchTLSThread->f0.fv[xidx].re * test_pitchTLSThread->f0.b_fv[xidx]
      .im + test_pitchTLSThread->f0.fv[xidx].im * test_pitchTLSThread->
      f0.b_fv[xidx].re;
    test_pitchTLSThread->f0.b_fv[xidx].re = test_pitchTLSThread->f0.fv[xidx].re *
      test_pitchTLSThread->f0.b_fv[xidx].re - test_pitchTLSThread->f0.fv[xidx].
      im * test_pitchTLSThread->f0.b_fv[xidx].im;
    test_pitchTLSThread->f0.b_fv[xidx].im = im;
  }

  b_r2br_r2dit_trig(test_pitchTLSThread->f0.b_fv, costabinv, sintabinv,
                    test_pitchTLSThread->f0.fv);
  xidx = 0;
  for (k = 0; k < 8000; k++) {
    im = wwc[k + 7999].re;
    d = wwc[k + 7999].im;
    d1 = test_pitchTLSThread->f0.fv[k + 7999].re;
    d2 = test_pitchTLSThread->f0.fv[k + 7999].im;
    y[xidx].re = im * d1 + d * d2;
    y[xidx].im = im * d2 - d * d1;
    xidx++;
  }
}

static void c_r2br_r2dit_trig_impl(const double x[24576], int xoffInit, const
  double costab[257], const double sintab[257], creal_T y[512])
{
  int ix;
  int ju;
  int iy;
  int i;
  boolean_T tst;
  double twid_re;
  double temp_re;
  double twid_im;
  int iheight;
  double temp_im;
  double re;
  double im;
  int istart;
  int temp_re_tmp;
  int j;
  int ihi;
  ix = xoffInit;
  ju = 0;
  iy = 0;
  for (i = 0; i < 511; i++) {
    y[iy].re = x[ix];
    y[iy].im = 0.0;
    iy = 512;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy].re = x[ix];
  y[iy].im = 0.0;
  for (i = 0; i <= 510; i += 2) {
    twid_re = y[i + 1].re;
    temp_re = twid_re;
    twid_im = y[i + 1].im;
    temp_im = twid_im;
    re = y[i].re;
    im = y[i].im;
    twid_re = y[i].re - twid_re;
    y[i + 1].re = twid_re;
    twid_im = y[i].im - twid_im;
    y[i + 1].im = twid_im;
    y[i].re = re + temp_re;
    y[i].im = im + temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 128;
  iheight = 509;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - y[temp_re_tmp].im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 256; j += ju) {
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[temp_re_tmp].im;
        temp_im = twid_re * y[temp_re_tmp].im + twid_im * y[temp_re_tmp].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }
}

static void r2br_r2dit_trig(const creal_T x[15999], const double costab[8193],
  const double sintab[8193], creal_T y[16384])
{
  int ix;
  int ju;
  int iy;
  int i;
  boolean_T tst;
  double twid_re;
  double temp_re;
  double twid_im;
  int iheight;
  double temp_im;
  double re;
  double im;
  int istart;
  int temp_re_tmp;
  int j;
  int ihi;
  std::memset(&y[0], 0, 16384U * sizeof(creal_T));
  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 15998; i++) {
    y[iy] = x[ix];
    iy = 16384;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 16382; i += 2) {
    twid_re = y[i + 1].re;
    temp_re = twid_re;
    twid_im = y[i + 1].im;
    temp_im = twid_im;
    re = y[i].re;
    im = y[i].im;
    twid_re = y[i].re - twid_re;
    y[i + 1].re = twid_re;
    twid_im = y[i].im - twid_im;
    y[i + 1].im = twid_im;
    y[i].re = re + temp_re;
    y[i].im = im + temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 4096;
  iheight = 16381;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - y[temp_re_tmp].im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 8192; j += ju) {
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[temp_re_tmp].im;
        temp_im = twid_re * y[temp_re_tmp].im + twid_im * y[temp_re_tmp].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }
}

static void r2br_r2dit_trig_impl(const creal_T x[8000], const double costab[8193],
  const double sintab[8193], creal_T y[16384])
{
  int ix;
  int ju;
  int iy;
  int i;
  boolean_T tst;
  double twid_re;
  double temp_re;
  double twid_im;
  int iheight;
  double temp_im;
  double re;
  double im;
  int istart;
  int temp_re_tmp;
  int j;
  int ihi;
  std::memset(&y[0], 0, 16384U * sizeof(creal_T));
  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 7999; i++) {
    y[iy] = x[ix];
    iy = 16384;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 16382; i += 2) {
    twid_re = y[i + 1].re;
    temp_re = twid_re;
    twid_im = y[i + 1].im;
    temp_im = twid_im;
    re = y[i].re;
    im = y[i].im;
    twid_re = y[i].re - twid_re;
    y[i + 1].re = twid_re;
    twid_im = y[i].im - twid_im;
    y[i + 1].im = twid_im;
    y[i].re = re + temp_re;
    y[i].im = im + temp_im;
  }

  iy = 2;
  ix = 4;
  ju = 4096;
  iheight = 16381;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - y[temp_re_tmp].im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 8192; j += ju) {
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[temp_re_tmp].im;
        temp_im = twid_re * y[temp_re_tmp].im + twid_im * y[temp_re_tmp].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }
}

void c_r2br_r2dit_trig(const double x[9600], const double costab[257], const
  double sintab[257], creal_T y[24576])
{
  int k;
  creal_T rwork[512];
  int xoff;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(rwork,xoff)

  for (k = 0; k < 48; k++) {
    xoff = k * 200;
    b_r2br_r2dit_trig_impl(x, xoff, costab, sintab, rwork);
    std::memcpy(&y[k * 512], &rwork[0], 512U * sizeof(creal_T));
  }
}

void d_r2br_r2dit_trig(const double x[24576], const double costab[257], const
  double sintab[257], creal_T y[24576])
{
  int k;
  int i;
  creal_T rwork[512];
  int xoff_tmp;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(rwork,xoff_tmp)

  for (k = 0; k < 48; k++) {
    xoff_tmp = k << 9;
    c_r2br_r2dit_trig_impl(x, xoff_tmp, costab, sintab, rwork);
    std::memcpy(&y[xoff_tmp], &rwork[0], 512U * sizeof(creal_T));
  }

  for (i = 0; i < 24576; i++) {
    y[i].re *= 0.001953125;
    y[i].im *= 0.001953125;
  }
}

void dobluesteinfft(const double x[4080], const double costab[8193], const
                    double sintab[8193], const double sintabinv[8193], creal_T
                    y[136000])
{
  static creal_T wwc[15999];
  int k;
  int xoff;
  test_pitchTLS *test_pitchTLSThread;
  test_pitchTLSThread = emlrtGetThreadStackData();
  bluesteinSetup(wwc);

#pragma omp parallel \
 num_threads(omp_get_max_threads()) \
 private(test_pitchTLSThread,xoff)

  {
    test_pitchTLSThread = emlrtGetThreadStackData();

#pragma omp for nowait

    for (k = 0; k < 17; k++) {
      xoff = k * 240;
      bluestein(x, xoff, costab, sintab, costab, sintabinv, wwc,
                test_pitchTLSThread->f1.rwork);
      std::memcpy(&y[k * 8000], &test_pitchTLSThread->f1.rwork[0], 8000U *
                  sizeof(creal_T));
    }
  }
}

/* End of code generation (fft1.cpp) */
