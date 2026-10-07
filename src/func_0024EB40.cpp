typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0024E3D0(struct Buf00109C40 *arg0);
extern "C" void func_00251CE8(s32 arg0);
extern "C" void func_0024E378(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0024EB40(void) {
    struct Buf00109C40 buf;

    func_0024E3D0(&buf);
    func_00251CE8(buf.unk0);
    func_0024E378(&buf, 2);
}
