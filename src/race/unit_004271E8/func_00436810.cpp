typedef unsigned char u8;
typedef int s32;

struct Obj {
    char pad[0x10];
    u8 unk10;
};

extern char D_00846328[];

extern "C" void func_0057B1A8(void *arg0, u8 arg1);

extern "C" void func_00436810(struct Obj *arg0) {
    func_0057B1A8(D_00846328, arg0->unk10);
}
