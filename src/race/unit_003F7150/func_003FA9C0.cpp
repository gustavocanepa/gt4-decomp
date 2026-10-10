typedef unsigned char u8;

extern "C" void func_003FA9C0(u8 *lo, u8 *hi) {
    if (*hi > *lo)
        return;
    if (*lo != 0xFF) {
        *hi = *lo + 1;
        return;
    }
    if (*hi != 0)
        *lo = *hi - 1;
    else
        *lo = 0xFF;
}
