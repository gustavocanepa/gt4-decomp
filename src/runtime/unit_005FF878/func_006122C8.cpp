extern "C" void *func_0057CA20(void *arg0);
extern "C" char D_00689B70[];

struct func_006122C8_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_006122C8(struct func_006122C8_arg0 *arg0)
{
    func_0057CA20(arg0);
    arg0->unk8 = D_00689B70;
}
