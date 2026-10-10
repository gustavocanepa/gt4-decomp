/* libio (GNU iostream library, gcc 2000-10-03 snapshot): Binit.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
typedef short s16;

struct Obj {
    char pad0[4];
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s32 unk10;
};

extern "C" Obj *func_005978E8(Obj *arg0) {
    arg0->unkC = 1;
    arg0->unk4 = 3;
    arg0->unk8 = 8;
    arg0->unk10 = 0;
    arg0->unkE = 0;
    return arg0;
}
