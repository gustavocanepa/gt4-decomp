typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00211460(struct Buf00109C40 *arg0);
extern "C" void func_00219A88(s32 arg0);
extern "C" void func_00211408(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MManager__finishProject(void) {
    struct Buf00109C40 buf;

    func_00211460(&buf);
    func_00219A88(buf.unk0);
    func_00211408(&buf, 2);
}
