/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

struct Obj {
    s32 unk0;
    char pad[0xC - 4];
    s32 unkC;
    char pad2[0x24 - 0xC - 4];
    s32 unk24;
};

extern "C" s32 func_00615440(Obj *arg0) {
    if (arg0->unk0 & 0x100) {
        return arg0->unk24;
    }
    return arg0->unkC;
}
