extern "C" void *func_0057CA20(void *arg0);
extern "C" char D_00688E18[];

struct func_0060AB60_arg0 {
    char pad0[0x8];
    void *unk8;
};

extern "C" void func_0060AB60(struct func_0060AB60_arg0 *arg0)
{
    func_0057CA20(arg0);
    arg0->unk8 = D_00688E18;
}
