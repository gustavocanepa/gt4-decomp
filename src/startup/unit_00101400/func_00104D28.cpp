extern "C" void *func_00104048(void *arg0);
extern char D_00659C50[];

struct func_00104D28_arg0 {
    void *unk0;
    char pad4[0x2C];
    int unk30;
};

extern "C" void func_00104D28(struct func_00104D28_arg0 *arg0)
{
    func_00104048(arg0);
    arg0->unk30 = 0;
    arg0->unk0 = D_00659C50;
}
