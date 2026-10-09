typedef int s32;

struct Obj {
    char pad[0x6C];
    s32 unk6C;
};

extern "C" void func_003C0008(s32 arg0);

extern "C" void func_00335558(Obj **arg0) {
    Obj *obj = *arg0;
    if (obj != 0) {
        func_003C0008(obj->unk6C);
    }
}
