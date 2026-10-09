typedef unsigned char u8;

struct Obj {
    char pad[0x11];
    u8 unk11;
};

extern char D_00846330[];

extern "C" void func_0057B1A8(void *arg0, u8 arg1);

extern "C" void func_00436870(struct Obj *arg0) {
    func_0057B1A8(D_00846330, arg0->unk11);
}
