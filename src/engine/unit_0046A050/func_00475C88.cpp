struct Obj { char pad[0x24]; void *unk24; };
struct Obj2 { char pad[0x8C]; void *unk8C; };

extern "C" void func_00475C88(Obj *arg0, Obj2 *arg1) {
    arg1->unk8C = arg0->unk24;
    arg0->unk24 = arg1;
}
