struct Obj { char pad[0x164]; int unk164; char pad2[0x5A8 - 0x168]; int unk5A8; };
extern "C" void func_004F8890(Obj *p, int a);
extern "C" int func_004F0C38(Obj *p) {
    if (p->unk5A8 == 0) {
        func_004F8890(p, 5);
        return 1;
    }
    int v = p->unk164;
    p->unk164 = 0;
    if (v != 0) {
        func_004F8890(p, 1);
        return 1;
    }
    return 0;
}
