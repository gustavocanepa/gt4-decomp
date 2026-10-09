typedef int s32;

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" void func_0017FAD0(void *arg0, int arg1);
extern "C" s32 func_0017FB28(void *arg0);
extern "C" void func_00435D48(s32 arg0);

extern "C" void MOption__setGameZoneDefault(void) {
    struct Buf buf;
    struct Inner *p;

    func_0017FB28(&buf);
    p = buf.ptr;
    func_00435D48(p->unk10 + 0x11C8);
    func_0017FAD0(&buf, 2);
}
