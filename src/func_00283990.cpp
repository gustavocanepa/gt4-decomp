typedef int s32;

struct Buf00283990 {
    void *unk0;
    char pad[0xC];
};

extern "C" void func_00283708(struct Buf00283990 *arg0);
extern "C" void func_002841B0(void *arg0, s32 arg1);
extern "C" void func_002836B0(struct Buf00283990 *arg0, int arg1);

extern "C" void func_00283990(void) {
    struct Buf00283990 buf;

    func_00283708(&buf);
    func_002841B0(buf.unk0, 0);
    func_002836B0(&buf, 2);
}
