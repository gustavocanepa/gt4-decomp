extern "C" void *func_0057CA20(void *arg0);
extern "C" char D_00689890[];

struct func_00610A98_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_00610A98(struct func_00610A98_arg0 *arg0)
{
    func_0057CA20(arg0);
    arg0->unk8 = D_00689890;
}
