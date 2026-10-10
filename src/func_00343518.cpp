typedef unsigned int u32;
typedef float f32;

extern "C" f32 func_00343518(u32 *total, f32 amount) {
    int whole = (int)amount;
    if (amount <= 0.0f)
        return 0.0f;
    *total += whole;
    if (*total > 1599999999) {
        *total = 1600000000;
        return 0.0f;
    }
    return amount - whole;
}
