/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Clock {
    float time;
    float rate;
    s32 unk8;
    s32 unkC;
};

extern float D_00654730;

extern "C" void func_0055D420(Clock *c, s32 hz, s32 now, s32 prev) {
    float k = 1000.0f / (D_00654730 * (float)hz);
    float d = (float)(now - prev);
    c->time += d;
    c->unkC = 0;
    c->rate = d * k;
}
