typedef int s32;

struct Obj003BB958 {
    char pad0[0x40];
    s32 unk40;
};

extern "C" s32 func_003BB978(s32 arg0, s32 arg1);

extern "C" s32 func_003BB958(struct Obj003BB958 *arg0, struct Obj003BB958 *arg1) {
    return func_003BB978(arg0->unk40, arg1->unk40);
}
