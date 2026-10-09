typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002BAB38(struct Buf00109C40 *arg0);
extern "C" void func_002BCB00(s32 arg0);
extern "C" void func_002BAAE0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MModelFace__reset(void) {
    struct Buf00109C40 buf;

    func_002BAB38(&buf);
    func_002BCB00(buf.unk0);
    func_002BAAE0(&buf, 2);
}
