typedef float f32;

struct S_00624980 {
    char pad[0x3C];
    f32 unk3C;
    f32 unk40;
};

struct Obj {
    char pad[0x54];
    f32 unk54;
    char pad2[0x58 - 0x54 - 4];
    f32 unk58;
};

extern S_00624980 *D_00624980;

extern "C" void func_00247428(Obj *arg0) {
    S_00624980 *temp = D_00624980;
    arg0->unk54 = temp->unk3C;
    arg0->unk58 = temp->unk40;
}
