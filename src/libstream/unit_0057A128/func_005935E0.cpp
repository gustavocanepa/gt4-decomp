/* libio (GNU iostream library, gcc 2000-10-03 snapshot): istream::skip.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
typedef unsigned long long u64;

struct Obj {
    char pad[0x10];
    u64 flags;
};

extern "C" s32 func_005935E0(Obj **h, s32 on) {
    Obj *o = *h;
    u64 old = o->flags;
    s32 r = old & 1;
    if (on)
        o->flags = old | 1;
    else
        o->flags = old & ~1ULL;
    return r;
}
