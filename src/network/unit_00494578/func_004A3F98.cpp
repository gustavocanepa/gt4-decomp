/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float clamp01(float x) { return minf(maxf(x, 0.0f), 1.0f); }
extern "C" int func_004A7C00(void);
struct Spr { char pad[0x138]; unsigned char r,g,b; char pad2[0x1D8-0x13B]; unsigned long bits; };

/* float twin of func_004A4050: clamp each channel to [0, 1] and store it as a byte */
extern "C" int func_004A3F98(float r, float g, float b) {
    int result = func_004A7C00();
    r = clamp01(r);
    g = clamp01(g);
    b = clamp01(b);
    struct Spr *p = (struct Spr *)spr_base();
    p->bits |= 0x800000000UL;
    p->r = (int)(r * 255.0f);
    p->g = (int)(g * 255.0f);
    p->b = (int)(b * 255.0f);
    return result;
}
