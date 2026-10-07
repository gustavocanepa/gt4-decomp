typedef int s32;

struct Obj0035A458 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_0035A080(s32 arg0);

extern "C" s32 func_0035A458(struct Obj0035A458 *arg0) {
    return func_0035A080(arg0->unk10) != 0;
}
