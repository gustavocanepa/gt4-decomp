extern "C" void *func_0042A5B8(void *arg0);
extern "C" char D_00686900[];

struct func_0042A868_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x20];
    int unk28;
};

extern "C" void func_0042A868(struct func_0042A868_arg0 *arg0)
{
    func_0042A5B8(arg0);
    arg0->unk28 = 0;
    arg0->unk4 = D_00686900;
}
