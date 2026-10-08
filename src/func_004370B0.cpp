typedef int s32;

struct Obj {
    char pad[0x1130];
    s32 unk1130;
};

extern char D_00846360[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_004370B0(struct Obj *arg0) {
    func_0057B1A8(D_00846360, arg0->unk1130);
}
