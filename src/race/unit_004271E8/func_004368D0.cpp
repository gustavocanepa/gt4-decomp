typedef unsigned char u8;

struct Obj {
    char pad[0x12];
    u8 unk12;
};

extern char D_00846338[];

extern "C" void func_0057B1A8(void *arg0, u8 arg1);

extern "C" void func_004368D0(struct Obj *arg0) {
    func_0057B1A8(D_00846338, arg0->unk12);
}
