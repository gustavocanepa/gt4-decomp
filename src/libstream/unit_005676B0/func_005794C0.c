/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Mersenne Twister MT19937 (mt19937ar.c, 2002/1/26): genrand_int32 (tempering; the refill of the N words is func_005795E0), with the generator's state in an object
 * (mt[624] at 0, mti at 0x9C0).
 *
 * Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, All rights reserved.
 * BSD 3-clause licence: see THIRD_PARTY.md, "Mersenne Twister". */
#define N 624

struct MT {
    unsigned int mt[N];
    int mti;
    unsigned int seed;
};

void func_005795E0(struct MT *m);

unsigned int func_005794C0(struct MT *m) {
    unsigned int y;

    if (m->mti >= N)
        func_005795E0(m);

    y = m->mt[m->mti++];

    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

    return y;
}
