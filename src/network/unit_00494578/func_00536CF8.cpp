struct Obj { char pad[0x74]; int unk74; char unk78[1]; };
extern "C" int func_00539818(void *a, int b);
extern "C" Obj *D_0064B47C;
extern "C" int func_00536CF8(void) {
    Obj *p = D_0064B47C;
    if (p->unk74 == 0) return 5;
    return func_00539818(p->unk78, 0);
}
