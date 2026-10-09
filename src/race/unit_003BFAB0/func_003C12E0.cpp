typedef int s32;

struct Obj {
    char pad[0x24];
    s32 unk24;
};

extern "C" s32 func_005A609C(char *arg0);

extern "C" void func_003C12E0(struct Obj *arg0) {
    func_005A609C((char *)arg0 + 0x14);
    arg0->unk24 = 1;
}
