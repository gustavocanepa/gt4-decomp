extern "C" void *func_00378AE0(void *arg0);
extern "C" char D_0067A8A0[];

struct func_0037CBB8_arg0 {
    void *unk0;
    char pad4[0x17C];
    int unk180;
};

extern "C" void func_0037CBB8(struct func_0037CBB8_arg0 *arg0)
{
    func_00378AE0(arg0);
    arg0->unk180 = 0;
    arg0->unk0 = D_0067A8A0;
}
