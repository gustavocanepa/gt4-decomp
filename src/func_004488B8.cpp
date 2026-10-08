struct Obj {
    char pad[0x10];
    unsigned char unk10;
};

extern "C" unsigned char func_004488B8(struct Obj *arg0)
{
    return arg0->unk10;
}
