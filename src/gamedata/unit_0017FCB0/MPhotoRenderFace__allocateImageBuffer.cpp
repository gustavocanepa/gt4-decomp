typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001978D0(struct Buf00109C40 *arg0);
extern "C" void func_0019AEF0(s32 arg0);
extern "C" void func_00197878(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MPhotoRenderFace__allocateImageBuffer(void) {
    struct Buf00109C40 buf;

    func_001978D0(&buf);
    func_0019AEF0(buf.unk0);
    func_00197878(&buf, 2);
}
