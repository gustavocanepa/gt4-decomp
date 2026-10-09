typedef int s32;

struct Obj {
    char pad[0x20];
    s32 unk20;
};

extern char D_00846350[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_00436C60(struct Obj *arg0) {
    func_0057B1A8(D_00846350, arg0->unk20);
}
