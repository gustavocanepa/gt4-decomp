typedef int s32;

struct S0039A4F8 { char pad[0x1C]; void *unk1C; };

extern "C" void func_005C1628(struct S0039A4F8 *arg0);
extern "C" char D_00688888;

extern "C" void func_00462530(struct S0039A4F8 *arg0, s32 arg1) {
    arg1 = arg1 & 1;
    arg0->unk1C = &D_00688888;
    if (arg1) {
        func_005C1628(arg0);
        return;
    }
}
