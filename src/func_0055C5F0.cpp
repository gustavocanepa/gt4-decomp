/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef float f32;

extern "C" f32 D_00654730;
extern "C" u32 D_00654734;

extern "C" f32 func_0055C5F0(f32 v) {
    f32 old = D_00654730;
    D_00654730 = v;
    D_00654734 = (u32)(v * 127.0f);
    return old;
}
