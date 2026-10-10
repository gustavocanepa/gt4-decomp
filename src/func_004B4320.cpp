/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Cursor_004B4320 {
    s16 m0;
    s16 index;
};

extern "C" void func_004B4320(Cursor_004B4320 *c, s32 step, s32 count) {
    c->index += step;
    if (c->index >= count) {
        if (step < 2) {
            c->index = 0;
        } else {
            c->index = count - 1;
        }
    } else if (c->index < 0) {
        if (step >= -1) {
            c->index = count - 1;
        } else {
            c->index = 0;
        }
    }
}
