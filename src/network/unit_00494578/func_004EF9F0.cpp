extern void func_0056F8F8(void *, int, int);

struct func_004EF9F0_arg0 {
    char pad0[0x7C];
    int unk7C;
};

void func_004EF9F0(void *arg0, int arg1)
{
    func_0056F8F8((char *)arg0 + 4, ((struct func_004EF9F0_arg0 *)arg0)->unk7C, arg1);
}
