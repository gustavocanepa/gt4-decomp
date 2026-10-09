typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x5C4];
    f32 unk5C4;
};

extern char D_006244D8;

extern "C" s32 func_00472A78(void *arg0, f32 arg1);

extern "C" s32 func_00354DE8(Obj *arg0) {
    return func_00472A78(&D_006244D8, arg0->unk5C4);
}
