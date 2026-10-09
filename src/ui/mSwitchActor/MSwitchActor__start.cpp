typedef int s32;

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002E2038(struct Buf00109C40 *arg0);
extern "C" void func_002E28D8(s32 arg0);
extern "C" void func_002E1FE0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void MSwitchActor__start(void) {
    struct Buf00109C40 buf;

    func_002E2038(&buf);
    func_002E28D8(buf.unk0);
    func_002E1FE0(&buf, 2);
}
