struct Obj {
    char pad[0x96C];
    unsigned char unk96C;
};

extern "C" unsigned char func_003C0FF0(struct Obj *arg0)
{
    return arg0->unk96C;
}
