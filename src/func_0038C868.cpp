typedef float f32;

extern "C" void *func_0044F4C0(void);
extern "C" f32 func_0044F990(void *p);

extern "C" f32 func_0038C868(void) {
    void *p = func_0044F4C0();
    if (p) {
        return func_0044F990(p) + 0.1f;
    }
    return 0.1f;
}
