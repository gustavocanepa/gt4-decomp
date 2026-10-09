typedef int s32;

struct Obj {
    char pad[0x50];
    s32 unk50;
};

extern "C" s32 func_004ED410(struct Obj *arg0, s32 arg1);

extern "C" s32 func_0060E7B0(struct Obj *arg0) {
    return func_004ED410(arg0, arg0->unk50);
}
