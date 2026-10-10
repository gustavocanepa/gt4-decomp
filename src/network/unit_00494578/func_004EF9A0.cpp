extern void func_0056F868(void *, int, int);

struct func_004EF9A0_arg0 {
    char pad0[0x7C];
    int unk7C;
};

void func_004EF9A0(void *arg0, int arg1)
{
    func_0056F868((char *)arg0 + 4, ((struct func_004EF9A0_arg0 *)arg0)->unk7C, arg1);
}
