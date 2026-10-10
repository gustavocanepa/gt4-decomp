struct Info { char pad[0x40]; unsigned char m40; unsigned char m41; };
struct Obj {
    char pad0[0x70];
    Info *info;
    char pad1[0x88 - 0x74];
    char m88[0xB0 - 0x88];
    int mB0;
    int mB4;
    int mB8;
    char pad2[0xD4 - 0xBC];
    float mD4;
    float mD8;
    char pad3[0xE8 - 0xDC];
    int mE8;
    char pad4[0xF4 - 0xEC];
    char mF4[0x96C - 0xF4];
    unsigned char m96C;
};
extern "C" void func_003C12B0(void *p);
extern "C" void func_003B7470(void *p);
extern "C" void func_003C00B8(Obj *o);

extern "C" void func_003C0190(Obj *o)
{
    func_003C12B0(o->m88);
    func_003B7470(o->mF4);
    Info *info = o->info;
    o->mB4 = info->m40;
    o->mB8 = info->m41;
    o->mB0 = 1;
    func_003C00B8(o);
    o->mD4 = -1.0f;
    o->mD8 = 1.0f;
    o->mE8 = 0;
    o->m96C = 0;
}
