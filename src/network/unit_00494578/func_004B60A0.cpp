/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;

struct Range_004B60A0 {
    char pad0[4];
    s16 start;
    s16 end;
};

extern "C" void func_004B60A0(void *self, Range_004B60A0 *dst, Range_004B60A0 *src) {
    if (src->end - src->start > 0) {
        src->start++;
        if (src->end < src->start) {
            src->start = src->end;
        }
        dst->end++;
        if (dst->end < dst->start) {
            dst->end = dst->start;
        }
    }
}
