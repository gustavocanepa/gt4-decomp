/* Grows a square from (x, y) over an 8-bit mask image one ring at a time (one new column and one
   new row per step), summing the pixels it covers, and checks the density sum * n^2 / side^2
   against table[n] within a (1 - tol, 1 + tol) window; a single miss is tolerated. Leading empty
   rings (up to 2 * n0 of them) are skipped first. A second phase keeps extending one side while
   n runs up to minSize + range. On success the square is recorded and 1 is returned.
   Called by func_001C27C0 (scan of every set pixel) and func_001C3DE0. */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

struct MaskImage { u32 width; u32 height; s32 stride; char padC[8]; u8 *pixels; };
struct SquareDetector {
    f32 tol; char pad4[4]; u32 minSize; u32 n0; u32 range; char pad14[4]; u32 *table;
    char pad1C[4]; s32 x; s32 y; u32 n; u32 side; u32 side2;
};

/* The statement order below is load-bearing: it decides the allocator's register homes (lim before
   base for x/y, skipMax computed from n0 before n = n0, miss cleared just before the loop). */
extern "C" s32 func_001C2388(SquareDetector *d, MaskImage *img, s32 x, s32 y) {
    u32 n0;
    s32 skip;
    u32 skipMax;
    f32 loK, hiK;
    s32 base;
    u32 lim, limW;
    u32 n;
    s32 k = 0;
    s32 off = 0;
    u32 side = 0;
    u32 sum = 0;
    s32 miss;
    u32 prev;
    u32 i;
    s32 p;
    lim = img->height - y;
    limW = img->width - x;
    base = img->stride * y + x;
    loK = 1.0f - d->tol;
    hiK = d->tol + 1.0f;
    n0 = d->n0;
    skip = n0 != 0;
    skipMax = n0 * 2;
    n = n0;
    if (limW < lim) lim = limW;
    miss = 0;
    do {
        prev = sum;
        sum += img->pixels[base + k + off];
        p = base + k;
        for (i = n; i != 0; i--) { sum += img->pixels[p]; p += img->stride; }
        p = base + off;
        for (i = n; i != 0; i--) { sum += img->pixels[p]; p++; }
        if (skip) {
            if (sum == 0 && side < skipMax) goto next;
            skip = 0;
            n = n0;
        }
        {
            f32 ref = (f32)d->table[n];
            f32 lo = ref * loK;
            f32 hi = ref * hiK;
            f32 fn = (f32)n;
            f32 nn = fn * fn;
            f32 fs = (f32)side;
            f32 ss = fs * fs;
            f32 r = (f32)sum * nn / ss;
            if (hi < r) return 0;
            if (r < lo) {
                if (miss) return 0;
                miss = 1;
            } else {
                miss = 0;
                n++;
            }
        }
    next:
        side++;
        if (side > lim) return 0;
        k++;
        off += img->stride;
    } while (n < d->minSize);

    if (miss) {
        sum = prev;
        side--;
        miss = 0;
    }
    {
        u32 end = d->minSize + d->range;
        u32 sq = n * n;
        f32 fs = (f32)side;
        while (n != end) {
            f32 ref, hi, lo, den, r;
            sq += d->minSize;
            p = k++;
            den = (f32)k * fs;
            for (i = side; i != 0; i--) { sum += img->pixels[p]; p += img->stride; }
            ref = (f32)d->table[n];
            lo = ref * loK;
            hi = ref * hiK;
            r = (f32)sum * (f32)sq / den;
            if (hi < r) return 0;
            if (r < lo) {
                if (miss) return 0;
                miss = 1;
            } else {
                miss = 0;
                n++;
            }
        }
    }
    d->x = x;
    d->y = y;
    d->n = n;
    d->side = side;
    d->side2 = side;
    return 1;
}
