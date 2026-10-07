typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002A5E18(struct Buf00109C40 *arg0);
extern "C" void func_002A7AD8(s32 arg0);
extern "C" void func_002A5DC0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_002A65E0(void) {
    struct Buf00109C40 buf;

    func_002A5E18(&buf);
    func_002A7AD8(buf.unk0);
    func_002A5DC0(&buf, 2);
}
