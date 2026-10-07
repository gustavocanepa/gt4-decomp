typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002E4BD8(struct Buf00109C40 *arg0);
extern "C" void func_002E54F0(s32 arg0);
extern "C" void func_002E4B80(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_002E50B0(void) {
    struct Buf00109C40 buf;

    func_002E4BD8(&buf);
    func_002E54F0(buf.unk0);
    func_002E4B80(&buf, 2);
}
