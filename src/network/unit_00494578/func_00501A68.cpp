struct Obj { char pad[0x9C]; int *unk9C; };

extern "C" void func_00501A68(Obj *arg0, int *arg1) {
    arg0->unk9C = arg1 + 1;
}
