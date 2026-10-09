typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00254110(struct Buf00109C40 *arg0);
extern "C" void func_002547F0(s32 arg0);
extern "C" void func_002540B8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MWatcher__append(void) {
    struct Buf00109C40 buf;

    func_00254110(&buf);
    func_002547F0(buf.unk0);
    func_002540B8(&buf, 2);
}
