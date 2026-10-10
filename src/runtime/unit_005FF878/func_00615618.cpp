/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

struct Obj {
    s32 unk0;
    char pad[0x4];
    s32 unk8;
    char pad2[0x20];
    s32 unk2C;
};

extern "C" s32 func_00615618(Obj *arg0) {
    if (arg0->unk0 & 0x100) {
        return arg0->unk8;
    }
    return arg0->unk2C;
}
