struct Obj {
    char pad[0x6FD];
    unsigned char unk6FD;
};

extern "C" unsigned char func_00344638(struct Obj *arg0)
{
    return arg0->unk6FD;
}
