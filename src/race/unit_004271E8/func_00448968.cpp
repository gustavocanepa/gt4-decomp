struct Obj {
    char pad[0x14];
    unsigned char unk14;
};

extern "C" unsigned char func_00448968(struct Obj *arg0)
{
    return arg0->unk14;
}
