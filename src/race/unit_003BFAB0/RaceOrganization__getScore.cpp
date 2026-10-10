struct Obj {
    char pad[0x96C];
    unsigned char unk96C;
};

extern "C" unsigned char RaceOrganization__getScore(struct Obj *arg0)
{
    return arg0->unk96C;
}
