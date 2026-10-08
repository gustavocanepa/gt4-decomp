typedef int s32;
typedef unsigned char u8;

struct Obj {
    u8 pad[0x24];
    s32 unk24;
};

extern "C" void func_003B0428(char *arg0, s32 arg1, s32 arg2);

extern "C" void func_003A4308(Obj *arg0, s32 arg1) {
    func_003B0428((char *)arg0 + 0x46, arg1, 0x20);
    arg0->unk24 = 0;
}
