typedef int s32;

struct Obj003354B8 {
    char pad[0x140];
    s32 unk140;
};

extern "C" void func_00330AE8(char *arg0, s32 arg1, s32 arg2);

extern "C" void func_003354B8(struct Obj003354B8 *arg0, s32 arg1) {
    func_00330AE8((char *)arg0 + 0xCC, arg1, 0);
    arg0->unk140 = 0;
}
