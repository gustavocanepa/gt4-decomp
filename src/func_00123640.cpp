struct S {
    char pad[0x3A35B];
    unsigned char flag;
};

extern struct S *D_00622F4C;

int func_00123640(void)
{
    return D_00622F4C->flag != 0;
}
