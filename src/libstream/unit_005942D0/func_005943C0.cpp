/* libio (GNU iostream library, gcc 2000-10-03 snapshot): ios::writable.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

struct Obj {
    s32 unk0;
};

extern "C" s32 func_005943C0(Obj **arg0) {
    return (((*arg0)->unk0 >> 3) ^ 1) & 1;
}
