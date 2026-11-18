/* compiler: ee-gcc2.96-g */
/* libio 2.8.0 (gcc 2000-10-03 snapshot): _IO_dtoa from floatconv.c, David M. Gay's dtoa: converts
 * a double to its shortest (mode 0/1), ecvt-style (2) or fcvt-style (3) decimal digit string in a
 * static Bigint buffer, with the decimal exponent in *decpt, the sign in *sign and the end in *rve.
 * The public body; the changes the original's translation unit needed are marked where they are.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
/* 
Copyright (C) 1993, 1994 Free Software Foundation

This file is part of the GNU IO Library.  This library is free
software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option)
any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this library; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

As a special exception, if you link this library with files
compiled with a GNU compiler to produce an executable, this does not cause
the resulting executable to be covered by the GNU General Public License.
This exception does not however invalidate any other reasons why
the executable file might be covered by the GNU General Public License. */

/****************************************************************
 *
 * The author of this software is David M. Gay.
 *
 * Copyright (c) 1991 by AT&T.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 *
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR AT&T MAKES ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 ***************************************************************/
typedef int _G_int32_t;
typedef unsigned int unsigned32;
#define NULL 0
#define CONST const
union doubleword {
  double d;
  unsigned32 u[2];
};
#define HIWORD 1
#define LOWORD 0
#define TEST_ENDIANNESS
/* The word accessors as inline functions rather than the public statement-expression macros: g++
   2.96 keeps an `if` condition whose first `&&` operand is a statement expression under its
   cleanup point and computes the whole chain as a value, which the original does not do. */
static inline unsigned32 word0_(double x) { union doubleword _du; _du.d = x; return _du.u[HIWORD]; }
static inline unsigned32 word1_(double x) { union doubleword _du; _du.d = x; return _du.u[LOWORD]; }
#define word0(x) word0_(x)
#define word1(x) word1_(x)
#define setword0(D,W) \
  ({ union doubleword _du; _du.d = (D); _du.u[HIWORD]=(W); (D)=_du.d; })
#define addword0(D,W) \
  ({ union doubleword _du; _du.d = (D); _du.u[HIWORD]+=(W); (D)=_du.d; })
#define Exp_shift  20
#define Exp_shift1 20
#define Exp_msk1    0x100000
#define Exp_msk11   0x100000
#define Exp_mask  0x7ff00000
#define P 53
#define Bias 1023
#define IEEE_Arith
#define Exp_11 0x3ff00000
#define Frac_mask  0xfffff
#define Frac_mask1 0xfffff
#define Ten_pmax 22
#define Bletch 0x10
#define Bndry_mask  0xfffff
#define Sign_bit 0x80000000
#define Log2P 1
#define Quick_max 14
#define Int_max 14
#define BIGINT_MINIMUM_K 3
struct Bigint {
  struct Bigint *next;
  int k;
  int maxwds;
  short on_stack;
  short sign;
  int wds;
  unsigned32 x[1<<BIGINT_MINIMUM_K];
};
#define BIGINT_HEADER_SIZE \
  (sizeof(Bigint) - (1<<BIGINT_MINIMUM_K) * sizeof(unsigned32))
typedef struct Bigint Bigint;

/* The helpers defined earlier in floatconv.c, at their addresses. The unit was compiled as C++,
   where they cannot throw (they reach only malloc and free, which the C++ headers declare
   throw()); the declarations carry that, as for quorem. */
extern "C" {
Bigint *func_005978E8(Bigint *v) throw();
Bigint *func_00597910(int k) throw();
void func_00597970(Bigint *v) throw();
void func_005979A8(Bigint *x, Bigint *y) throw();
Bigint *func_005979F0(Bigint *b, int k) throw();
Bigint *func_00597A70(Bigint *b, int m, int a) throw();
int func_00597C58(unsigned32 x) throw();
Bigint *func_00597D98(Bigint *result, int i) throw();
Bigint *func_00597DD0(Bigint *c, Bigint *a, Bigint *b) throw();
Bigint *func_00597FE0(Bigint *b, int k) throw();
Bigint *func_00598058(Bigint *b, int k) throw();
int func_005981C0(Bigint *a, Bigint *b) throw();
Bigint *func_00598228(Bigint *c, Bigint *a, Bigint *b) throw();
Bigint *func_005985C8(Bigint *result, double d, _G_int32_t *e, _G_int32_t *bits) throw();
int func_00599788(Bigint *b, Bigint *S) throw();
}
#define Binit func_005978E8
#define Balloc func_00597910
#define Bfree func_00597970
#define Bcopy func_005979A8
#define Brealloc func_005979F0
#define multadd func_00597A70
#define hi0bits func_00597C58
#define i2b func_00597D98
#define mult func_00597DD0
#define pow5mult func_00597FE0
#define lshift func_00598058
#define cmp func_005981C0
#define diff func_00598228
#define d2b func_005985C8
#define quorem func_00599788
extern "C" const double D_006CFDB0[25], D_006CFE68[5];
#define tens D_006CFDB0
#define bigtens D_006CFE68
#define n_bigtens 5
/* the function-local statics result and result_k, at their addresses */
extern "C" Bigint *D_00657EF8;
extern "C" int D_00885AD4;
#define result D_00657EF8
#define result_k D_00885AD4
#define _IO_dtoa _IO_dtoa

extern "C" char *
_IO_dtoa
        (double d, int mode, int ndigits, int *decpt, int *sign, char **rve)
{
 /*     Arguments ndigits, decpt, sign are similar to those
        of ecvt and fcvt; trailing zeros are suppressed from
        the returned string.  If not null, *rve is set to point
        to the end of the return value.  If d is +-Infinity or NaN,
        then *decpt is set to 9999.

        mode:
                0 ==> shortest string that yields d when read in
                        and rounded to nearest.
                1 ==> like 0, but with Steele & White stopping rule;
                        e.g. with IEEE P754 arithmetic , mode 0 gives
                        1e23 whereas mode 1 gives 9.999999999999999e22.
                2 ==> max(1,ndigits) significant digits.  This gives a
                        return value similar to that of ecvt, except
                        that trailing zeros are suppressed.
                3 ==> through ndigits past the decimal point.  This
                        gives a return value similar to that from fcvt,
                        except that trailing zeros are suppressed, and
                        ndigits can be negative.
                4-9 should give the same return values as 2-3, i.e.,
                        4 <= mode <= 9 ==> same return as mode
                        2 + (mode & 1).  These modes are mainly for
                        debugging; often they run slower but sometimes
                        faster than modes 2-3.
                4,5,8,9 ==> left-to-right digit generation.
                6-9 ==> don't try fast floating-point estimate
                        (if applicable).

                Values of mode other than 0-9 are treated as mode 0.

                Sufficient space is allocated to the return value
                to hold the suppressed trailing zeros.
        */

	/* Declared in this order (the public source declares the integers first, bbits before be):
	   C++ gives addressable locals their frame slots in declaration order. */
	Bigint _b_avail, _b, _mhi, _mlo, _S;
        _G_int32_t be, bbits, b2, b5, dig, i, ieps, ilim, ilim0, ilim1,
                j, j1, k, k0, k_check, leftright, m2, m5, s2, s5,
                spec_case, try_quick;
        _G_int32_t L;
#ifndef Sudden_Underflow
        int denorm;
#endif
	Bigint *b_avail = Binit(&_b_avail);
	Bigint *b = Binit(&_b);
	Bigint *S = Binit(&_S);
	/* mhi and mlo are only set and used if leftright. */
        Bigint *mhi = NULL, *mlo = NULL;
        double d2, ds, eps;
        char *s, *s0;

	TEST_ENDIANNESS;
        if (result) {
		/* result is contains a string, so its fields (interpreted
		   as a Bigint have been trashed.  Restore them.
		   This is a really ugly interface - result should
		   not be static, since that is not thread-safe.  FIXME. */
                result->k = result_k;
                result->maxwds = 1 << result_k;
                result->on_stack = 0;
                }

        if (word0(d) & Sign_bit) {
                /* set sign for everything, including 0's and NaNs */
                *sign = 1;
                setword0(d, word0(d) & ~Sign_bit);  /* clear sign bit */
                }
        else
                *sign = 0;

#if defined(IEEE_Arith) + defined(VAX)
#ifdef IEEE_Arith
        if ((word0(d) & Exp_mask) == Exp_mask)
#else
        if (word0(d)  == 0x8000)
#endif
                {
                /* Infinity or NaN */
                *decpt = 9999;
#ifdef IEEE_Arith
		if (!word1(d) && !(word0(d) & 0xfffff))
		  {
		    s = "Infinity";
		    if (rve)
		      *rve = s + 8;
		  }
		else
#endif
		  {
		    s = "NaN";
		    if (rve)
		      *rve = s +3;
		  }
                return s;
                }
#endif
#ifdef IBM
        d += 0; /* normalize */
#endif
        if (!d) {
                *decpt = 1;
                s = "0";
                if (rve)
                        *rve = s + 1;
                return s;
                }

        b = d2b(b, d, &be, &bbits);
        i = (int)(word0(d) >> Exp_shift1 & (Exp_mask>>Exp_shift1));
#ifndef Sudden_Underflow
        if (i) {
#endif
                d2 = d;
                setword0(d2, (word0(d2) & Frac_mask1) | Exp_11);
#ifdef IBM
                if (j = 11 - hi0bits(word0(d2) & Frac_mask))
                        d2 /= 1 << j;
#endif

                i -= Bias;
#ifdef IBM
                i <<= 2;
                i += j;
#endif
#ifndef Sudden_Underflow
                denorm = 0;
                }
        else {
                /* d is denormalized */
		unsigned32 x;

                i = bbits + be + (Bias + (P-1) - 1);
                x = i > 32  ? word0(d) << (64 - i) | word1(d) >> (i - 32)
                            : word1(d) << (32 - i);
                d2 = x;
                addword0(d2, - 31*Exp_msk1); /* adjust exponent */
                i -= (Bias + (P-1) - 1) + 1;
                denorm = 1;
                }
#endif

	/* Now i is the unbiased base-2 exponent. */

        /* log(x)       ~=~ log(1.5) + (x-1.5)/1.5
         * log10(x)      =  log(x) / log(10)
         *              ~=~ log(1.5)/log(10) + (x-1.5)/(1.5*log(10))
         * log10(d) = i*log(2)/log(10) + log10(d2)
         *
         * This suggests computing an approximation k to log10(d) by
         *
         * k = i*0.301029995663981
         *      + ( (d2-1.5)*0.289529654602168 + 0.176091259055681 );
         *
         * We want k to be too large rather than too small.
         * The error in the first-order Taylor series approximation
         * is in our favor, so we just round up the constant enough
         * to compensate for any error in the multiplication of
         * (i) by 0.301029995663981; since |i| <= 1077,
         * and 1077 * 0.30103 * 2^-52 ~=~ 7.2e-14,
         * adding 1e-13 to the constant term more than suffices.
         * Hence we adjust the constant term to 0.1760912590558.
         * (We could get a more accurate k by invoking log10,
         *  but this is probably not worthwhile.)
         */

        ds = (d2-1.5)*0.289529654602168 + 0.1760912590558 + i*0.301029995663981;
        k = (int)ds;
        if (ds < 0. && ds != k)
                k--;    /* want k = floor(ds) */
        k_check = 1;
        if (k >= 0 && k <= Ten_pmax) {
                if (d < tens[k])
                        k--;
                k_check = 0;
                }
        j = bbits - i - 1;
        if (j >= 0) {
                b2 = 0;
                s2 = j;
                }
        else {
                b2 = -j;
                s2 = 0;
                }
        if (k >= 0) {
                b5 = 0;
                s5 = k;
                s2 += k;
                }
        else {
                b2 -= k;
                b5 = -k;
                s5 = 0;
                }
        if (mode < 0 || mode > 9)
                mode = 0;
        try_quick = 1;
        if (mode > 5) {
                mode -= 4;
                try_quick = 0;
                }
        leftright = 1;
        switch(mode) {
                case 0:
                case 1:
                        ilim = ilim1 = -1;
                        i = 18;
                        ndigits = 0;
                        break;
                case 2:
                        leftright = 0;
                        /* no break */
                case 4:
                        if (ndigits <= 0)
                                ndigits = 1;
                        ilim = ilim1 = i = ndigits;
                        break;
                case 3:
                        leftright = 0;
                        /* no break */
                case 5:
                        i = ndigits + k + 1;
                        ilim = i;
                        ilim1 = i - 1;
                        if (i <= 0)
                                i = 1;
                }
	/* i is now an upper bound of the number of digits to generate. */
        j = sizeof(unsigned32) * (1<<BIGINT_MINIMUM_K);
	/* The test is <= so as to allow room for the final '\0'. */
        for(result_k = BIGINT_MINIMUM_K; BIGINT_HEADER_SIZE + j <= i;
                j <<= 1) result_k++;
        if (!result || result_k > result->k)
        {
          Bfree (result);
          result = Balloc(result_k);
        }
        s = s0 = (char *)result;

        if (ilim >= 0 && ilim <= Quick_max && try_quick) {

                /* Try to get by with floating-point arithmetic. */

                i = 0;
                d2 = d;
                k0 = k;
                ilim0 = ilim;
                ieps = 2; /* conservative */
                if (k > 0) {
                        ds = tens[k&0xf];
                        j = k >> 4;
                        if (j & Bletch) {
                                /* prevent overflows */
                                j &= Bletch - 1;
                                d /= bigtens[n_bigtens-1];
                                ieps++;
                                }
                        for(; j; j >>= 1, i++)
                                if (j & 1) {
                                        ieps++;
                                        ds *= bigtens[i];
                                        }
                        d /= ds;
                        }
                else if ((j1 = -k)) {
                        d *= tens[j1 & 0xf];
                        for(j = j1 >> 4; j; j >>= 1, i++)
                                if (j & 1) {
                                        ieps++;
                                        d *= bigtens[i];
                                        }
                        }
                if (k_check && d < 1. && ilim > 0) {
                        if (ilim1 <= 0)
                                goto fast_failed;
                        ilim = ilim1;
                        k--;
                        d *= 10.;
                        ieps++;
                        }
                eps = ieps*d + 7.;
                addword0(eps, - (P-1)*Exp_msk1);
                if (ilim == 0) {
                        d -= 5.;
                        if (d > eps)
                                goto one_digit;
                        if (d < -eps)
                                goto no_digits;
                        goto fast_failed;
                        }
#ifndef No_leftright
                if (leftright) {
                        /* Use Steele & White method of only
                         * generating digits needed.
                         */
                        eps = 0.5/tens[ilim-1] - eps;
                        for(i = 0;;) {
                                L = (_G_int32_t)d;
                                d -= L;
                                *s++ = '0' + (int)L;
                                if (d < eps)
                                        goto ret1;
                                if (1. - d < eps)
                                        goto bump_up;
                                if (++i >= ilim)
                                        break;
                                eps *= 10.;
                                d *= 10.;
                                }
                        }
                else {
#endif
                        /* Generate ilim digits, then fix them up. */
                        eps *= tens[ilim-1];
                        for(i = 1;; i++, d *= 10.) {
                                L = (_G_int32_t)d;
                                d -= L;
                                *s++ = '0' + (int)L;
                                if (i == ilim) {
                                        if (d > 0.5 + eps)
                                                goto bump_up;
                                        else if (d < 0.5 - eps) {
                                                while(*--s == '0');
                                                s++;
                                                goto ret1;
                                                }
                                        break;
                                        }
                                }
#ifndef No_leftright
                        }
#endif
 fast_failed:
                s = s0;
                d = d2;
                k = k0;
                ilim = ilim0;
                }

        /* Do we have a "small" integer? */

        if (be >= 0 && k <= Int_max) {
                /* Yes. */
                ds = tens[k];
                if (ndigits < 0 && ilim <= 0) {
                        if (ilim < 0 || d <= 5*ds)
                                goto no_digits;
                        goto one_digit;
                        }
                for(i = 1;; i++) {
                        L = (_G_int32_t)(d / ds);
                        d -= L*ds;
#ifdef Check_FLT_ROUNDS
                        /* If FLT_ROUNDS == 2, L will usually be high by 1 */
                        if (d < 0) {
                                L--;
                                d += ds;
                                }
#endif
                        *s++ = '0' + (int)L;
                        if (i == ilim) {
                                d += d;
                                if (d > ds || (d == ds && L & 1)) {
 bump_up:
                                        while(*--s == '9')
                                                if (s == s0) {
                                                        k++;
                                                        *s = '0';
                                                        break;
                                                        }
                                        ++*s++;
                                        }
                                break;
                                }
                        if (!(d *= 10.))
                                break;
                        }
                goto ret1;
                }

        m2 = b2;
        m5 = b5;
        if (leftright) {
                if (mode < 2) {
                        i =
#ifndef Sudden_Underflow
                                denorm ? be + (Bias + (P-1) - 1 + 1) :
#endif
#ifdef IBM
                                1 + 4*P - 3 - bbits + ((bbits + be - 1) & 3);
#else
                                1 + P - bbits;
#endif
                        }
                else {
                        j = ilim - 1;
                        if (m5 >= j)
                                m5 -= j;
                        else {
                                s5 += j -= m5;
                                b5 += j;
                                m5 = 0;
                                }
                        if ((i = ilim) < 0) {
                                m2 -= i;
                                i = 0;
                                }
                        }
                b2 += i;
                s2 += i;
                mhi = i2b(Binit(&_mhi), 1);
                }
        if (m2 > 0 && s2 > 0) {
                i = m2 < s2 ? m2 : s2;
                b2 -= i;
                m2 -= i;
                s2 -= i;
                }
        if (b5 > 0) {
                if (leftright) {
                        if (m5 > 0) {
				Bigint *b_tmp;
                                mhi = pow5mult(mhi, m5);
                                b_tmp = mult(b_avail, mhi, b);
                                b_avail = b;
                                b = b_tmp;
                                }
                        if ((j = b5 - m5))
                                b = pow5mult(b, j);
                        }
                else
                        b = pow5mult(b, b5);
                }
        S = i2b(S, 1);
        if (s5 > 0)
                S = pow5mult(S, s5);

        /* Check for special case that d is a normalized power of 2. */

        if (mode < 2) {
                if (!word1(d) && !(word0(d) & Bndry_mask)
#ifndef Sudden_Underflow
                 && word0(d) & Exp_mask
#endif
                                ) {
                        /* The special case */
                        b2 += Log2P;
                        s2 += Log2P;
                        spec_case = 1;
                        }
                else
                        spec_case = 0;
                }

        /* Arrange for convenient computation of quotients:
         * shift left if necessary so divisor has 4 leading 0 bits.
         *
         * Perhaps we should just compute leading 28 bits of S once
         * and for all and pass them and a shift to quorem, so it
         * can do shifts and ors to compute the numerator for q.
         */
        if ((i = ((s5 ? 32 - hi0bits(S->x[S->wds-1]) : 1) + s2) & 0x1f))
                i = 32 - i;
        if (i > 4) {
                i -= 4;
                b2 += i;
                m2 += i;
                s2 += i;
                }
        else if (i < 4) {
                i += 28;
                b2 += i;
                m2 += i;
                s2 += i;
                }
        if (b2 > 0)
                b = lshift(b, b2);
        if (s2 > 0)
                S = lshift(S, s2);
        if (k_check) {
                if (cmp(b,S) < 0) {
                        k--;
                        b = multadd(b, 10, 0);  /* we botched the k estimate */
                        if (leftright)
                                mhi = multadd(mhi, 10, 0);
                        ilim = ilim1;
                        }
                }
        if (ilim <= 0 && mode > 2) {
                if (ilim < 0 || cmp(b,S = multadd(S,5,0)) <= 0) {
                        /* no digits, fcvt style */
 no_digits:
                        k = -1 - ndigits;
                        goto ret;
                        }
 one_digit:
                *s++ = '1';
                k++;
                goto ret;
                }
        if (leftright) {
                if (m2 > 0)
                        mhi = lshift(mhi, m2);

                /* Compute mlo -- check for special case
                 * that d is a normalized power of 2.
                 */

                if (spec_case) {
			mlo = Brealloc(Binit(&_mlo), mhi->k);
                        Bcopy(mlo, mhi);
                        mhi = lshift(mhi, Log2P);
                        }
		else
			mlo = mhi;

                for(i = 1;;i++) {
                        dig = quorem(b,S) + '0';
                        /* Do we yet have the shortest decimal string
                         * that will round to d?
                         */
                        j = cmp(b, mlo);
                        b_avail = diff(b_avail, S, mhi); /* b_avail = S - mi */
                        j1 = b_avail->sign ? 1 : cmp(b, b_avail);
#ifndef ROUND_BIASED
                        /* `(word1(d) & 1) == 0` here and below, the public source has
                           `!(word1(d) & 1)`: with the inline accessor fold rewrites that one into
                           a computed bit test. */
                        if (j1 == 0 && !mode && (word1(d) & 1) == 0) {
                                if (dig == '9')
                                        goto round_9_up;
                                if (j > 0)
                                        dig++;
                                *s++ = dig;
                                goto ret;
                                }
#endif
                        if (j < 0 || (j == 0 && !mode
#ifndef ROUND_BIASED
                                                        && (word1(d) & 1) == 0
#endif
                                        )) {
                                if (j1 > 0) {
                                        b = lshift(b, 1);
                                        j1 = cmp(b, S);
                                        if ((j1 > 0 || (j1 == 0 && dig & 1))
                                        && dig++ == '9')
                                                goto round_9_up;
                                        }
                                *s++ = dig;
                                goto ret;
                                }
                        if (j1 > 0) {
                                if (dig == '9') { /* possible if i == 1 */
 round_9_up:
                                        *s++ = '9';
                                        goto roundoff;
                                        }
                                *s++ = dig + 1;
                                goto ret;
                                }
                        *s++ = dig;
                        if (i == ilim)
                                break;
                        b = multadd(b, 10, 0);
                        if (mlo == mhi)
                                mlo = mhi = multadd(mhi, 10, 0);
                        else {
                                mlo = multadd(mlo, 10, 0);
                                mhi = multadd(mhi, 10, 0);
                                }
                        }
                }
        else
                for(i = 1;; i++) {
                        *s++ = dig = quorem(b,S) + '0';
                        if (i >= ilim)
                                break;
                        b = multadd(b, 10, 0);
                        }

        /* Round off last digit */

        b = lshift(b, 1);
        j = cmp(b, S);
        if (j > 0 || (j == 0 && dig & 1)) {
 roundoff:
                while(*--s == '9')
                        if (s == s0) {
                                k++;
                                *s++ = '1';
                                goto ret;
                                }
                ++*s++;
                }
        else {
                while(*--s == '0');
                s++;
                }
 ret:
	Bfree(b_avail);
        Bfree(S);
        if (mhi) {
                if (mlo && mlo != mhi)
                        Bfree(mlo);
                Bfree(mhi);
                }
 ret1:
        Bfree(b);
        *s = 0;
        *decpt = k + 1;
        if (rve)
                *rve = s;
        return s0;
        }
