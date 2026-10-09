typedef int s32;

struct Obj0060F078 {
    char pad0[0x3F48];
    s32 arr[1];
};

extern "C" s32 func_004F9B88(struct Obj0060F078 *arg0, s32 arg1);

extern "C" s32 func_0060F078(struct Obj0060F078 *arg0, s32 arg1) {
    return func_004F9B88(arg0, arg0->arr[arg1]);
}
