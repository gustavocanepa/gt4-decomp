/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
typedef signed char s8;

struct Obj {
    s32 unk0;
    char pad[0x1A - 4];
    s8 unk1A;
};

extern "C" s32 func_00615320(struct Obj *arg0, s32 arg1) {
    s32 cond = (arg1 == 0);
    s32 old = arg0->unk0;
    arg0->unk0 = arg1;
    arg0->unk1A = (s8)(cond << 2);
    return old;
}
