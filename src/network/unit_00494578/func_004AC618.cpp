typedef int s32;

struct Obj {
    char pad[0x48];
    s32 unk48;
};

extern "C" void func_004AC7E0(s32 arg0);

extern "C" void func_004AC618(Obj *arg0) {
    s32 temp_v0 = arg0->unk48;
    if (temp_v0 != 0) {
        func_004AC7E0(temp_v0);
    }
}
