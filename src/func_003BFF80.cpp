struct ObjB;

struct ObjA {
    char pad0[0x80];
    ObjB *unk80;
};

struct ObjB {
    char pad0[0x14];
    ObjA *unk14;
};

extern "C" void func_003BFF38(ObjA *arg0);

extern "C" void func_003BFF80(ObjA *arg0, ObjB *arg1) {
    func_003BFF38(arg0);
    arg0->unk80 = arg1;
    arg1->unk14 = arg0;
}
