/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef float f32;

u32 func_005794C0(void);

f32 func_00579548(void) {
    return (f32)func_005794C0() * 0x1.000000p-32f;
}
