/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Mersenne Twister MT19937 (mt19937ar.c, 2002/1/26): the refill loop of genrand_int32 (generate N words at one time), with the generator's state in an object
 * (mt[624] at 0, mti at 0x9C0).
 *
 * Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, All rights reserved.
 * BSD 3-clause licence: see THIRD_PARTY.md, "Mersenne Twister". */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfUL
#define UPPER_MASK 0x80000000UL
#define LOWER_MASK 0x7fffffffUL

struct MT {
    unsigned int mt[N];
    int mti;
    unsigned int seed;
};

void func_005795E0(struct MT *m) {
    unsigned int y;
    unsigned int mag01[2] = {0x0UL, MATRIX_A};
    int kk;

    for (kk = 0; kk < N - M; kk++) {
        y = (m->mt[kk] & UPPER_MASK) | (m->mt[kk + 1] & LOWER_MASK);
        m->mt[kk] = m->mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1UL];
    }
    for (; kk < N - 1; kk++) {
        y = (m->mt[kk] & UPPER_MASK) | (m->mt[kk + 1] & LOWER_MASK);
        m->mt[kk] = m->mt[kk + (M - N)] ^ (y >> 1) ^ mag01[y & 0x1UL];
    }
    y = (m->mt[N - 1] & UPPER_MASK) | (m->mt[0] & LOWER_MASK);
    m->mt[N - 1] = m->mt[M - 1] ^ (y >> 1) ^ mag01[y & 0x1UL];

    m->mti = 0;
}
