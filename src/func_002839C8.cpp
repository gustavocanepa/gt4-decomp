typedef int s32;

struct Buf002839C8 {
    void *unk0;
    char pad[0xC];
};

extern "C" void func_00283708(struct Buf002839C8 *arg0);
extern "C" void func_002841B0(void *arg0, s32 arg1);
extern "C" void func_002836B0(struct Buf002839C8 *arg0, int arg1);

extern "C" void func_002839C8(void) {
    struct Buf002839C8 buf;

    func_00283708(&buf);
    func_002841B0(buf.unk0, 1);
    func_002836B0(&buf, 2);
}
