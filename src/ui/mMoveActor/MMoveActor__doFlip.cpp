typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002C03E0(struct Buf00109C40 *arg0);
extern "C" void func_002C1840(s32 arg0);
extern "C" void func_002C0388(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MMoveActor__doFlip(void) {
    struct Buf00109C40 buf;

    func_002C03E0(&buf);
    func_002C1840(buf.unk0);
    func_002C0388(&buf, 2);
}
