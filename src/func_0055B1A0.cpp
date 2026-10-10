/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

struct State {
    char pad0[0x34];
    s32 mode;
    char pad38[0x20];
    u8 *cur;
    char pad5C[0x4];
    s32 status;
};

extern "C" void func_0055B1A0(State *st) {
    u8 **pp = &st->cur;
    if (st->mode == 0xFF) {
        u8 *p = *pp;
        u8 c = *p;
        *pp = p + 2;
        if (c == '/') {
            st->status = 3;
            *pp = 0;
        }
    }
}
