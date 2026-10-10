/* libio (GNU iostream library, gcc 2000-10-03 snapshot): func_0059B838.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

struct Obj {
    char pad0[0x38];
    s32 unk38;
};

extern "C" s32 func_005AE398(s32 arg0);

extern "C" s32 func_0059B838(Obj *arg0) {
    return func_005AE398(arg0->unk38);
}
