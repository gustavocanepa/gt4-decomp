typedef int s32;

struct Buf001DD348 {
    void *unk0;
    char pad[0xC];
};

struct Target001DD348 {
    char pad[0x14];
    s32 unk14;
};

extern "C" void func_001DC650(struct Buf001DD348 *arg0);
extern "C" void func_001DC5F8(struct Buf001DD348 *arg0, int arg1);

extern "C" void MNetwork__beginEnableAbort(void) {
    struct Buf001DD348 buf;
    struct Target001DD348 *p;

    func_001DC650(&buf);
    p = (struct Target001DD348 *)buf.unk0;
    p->unk14 = 1;
    func_001DC5F8(&buf, 2);
}
