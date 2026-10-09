struct Obj {
    char pad[0x33];
    unsigned char unk33;
};

unsigned char func_00385EF8(struct Obj *arg0)
{
    return arg0->unk33;
}
