typedef int s32;
typedef signed char s8;

struct Obj0035A478 {
    char pad0[0x774];
    s8 unk774;
};

extern "C" s8 func_0035A478(char *arg0, s32 arg1) {
    if (arg1 < 4) {
        return ((struct Obj0035A478 *)(arg0 + arg1))->unk774;
    }
    return 0;
}
