typedef int s32;

struct Obj001D26A8 {
    char pad[0x6E0];
    s32 unk6E0;
};

extern "C" void func_001D2610(struct Obj001D26A8 *arg0, s32 arg1);
extern "C" void func_00578908(s32 arg0);

extern "C" void func_001D26A8(struct Obj001D26A8 *arg0) {
    struct Obj001D26A8 *s0 = arg0;

    func_001D2610(s0, 4);
    func_00578908(s0->unk6E0);
}
