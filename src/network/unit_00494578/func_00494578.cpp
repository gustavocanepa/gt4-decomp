typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x954];
    s32 unk960;
    s32 unk964;
    s32 unk968;
    s32 unk96C;
    s32 unk970;
    s32 unk974;
    s32 unk978;
    s32 unk97C;
    s32 unk980;
    s32 unk984;
    s32 unk988;
};

extern "C" void func_00494578(Obj *p, s32 a) {
    p->unk0 = a;
    p->unk4 = a;
    p->unk8 = 0;
    p->unk960 = -1;
    p->unk964 = 0;
    p->unk968 = 0;
    p->unk96C = 0;
    p->unk970 = 0;
    p->unk974 = 0;
    p->unk97C = 0;
    p->unk980 = 0;
    p->unk978 = 1;
    p->unk984 = 1;
    p->unk988 = 0;
}
