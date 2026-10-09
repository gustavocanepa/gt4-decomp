typedef int s32;

struct Buf {
    s32 val;
    char pad[0xC];
};

extern "C" void func_00192A00(void *arg0, int arg1);
extern "C" void func_00192A58(void *arg0, void *arg1);
extern "C" void func_00192EA8(s32 arg0, const char *arg1);

extern "C" void func_00195778(void *arg0, void *arg1) {
    struct Buf buf;
    func_00192A58(&buf, arg1);
    func_00192EA8(buf.val, "car");
    func_00192A00(&buf, 2);
}
