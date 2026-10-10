/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Range {
    s32 cur;
    s32 min;
    s32 max;
};

extern "C" void func_0057CD48(Range *r) {
    if (r->min == r->max) {
        r->cur = r->max;
    } else if (r->cur < r->min) {
        r->cur = r->min;
    } else if (r->cur >= r->max) {
        r->cur = r->max - 1;
    }
}
