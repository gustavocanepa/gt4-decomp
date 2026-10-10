typedef float f32;

extern "C" void func_00348588(f32 *p, f32 target, f32 step) {
    f32 v = *p;
    if (v < target) {
        v += step;
        if (target < v) v = target;
    } else if (target < v) {
        v -= step;
        if (v < target) v = target;
    }
    *p = v;
}
