/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Mersenne Twister MT19937 (mt19937ar.c, 2002/1/26): init_genrand, with the generator's state in
 * an object (mt[624] at 0, mti at 0x9C0, the seed kept at 0x9C4). unsigned long is 64-bit on the
 * EE, so the multiply by 1812433253UL is 64-bit and the reference's "&= 0xffffffffUL" stays.
 *
 * Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, All rights reserved.
 * BSD 3-clause licence: see THIRD_PARTY.md, "Mersenne Twister". */
#define N 624

struct MT {
    unsigned int mt[N];
    int mti;
    unsigned int seed;
};

void func_00579438(struct MT *m, unsigned int s) {
    m->seed = s;
    m->mt[0] = s;
    for (m->mti = 1; m->mti < N; m->mti++) {
        m->mt[m->mti] = 1812433253UL * (m->mt[m->mti - 1] ^ (m->mt[m->mti - 1] >> 30)) + m->mti;
        m->mt[m->mti] &= 0xffffffffUL;
    }
}
