typedef int s32;

struct Buf0013FF38 {
    void *unk0;
    char pad[0xC];
};

extern "C" void func_0013BDC0(struct Buf0013FF38 *arg0);
extern "C" s32 func_00147D80(void *arg0);
extern "C" void func_00441350(s32 arg0);
extern "C" void func_0013BD68(struct Buf0013FF38 *arg0, s32 arg1);

extern "C" void MCarGarage__syncWheel(void)
{
    struct Buf0013FF38 buf;

    func_0013BDC0(&buf);
    func_00441350(func_00147D80(buf.unk0));
    func_0013BD68(&buf, 2);
}
