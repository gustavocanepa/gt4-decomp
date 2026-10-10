typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 arr[4];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

extern "C" void func_0043A0C0(Obj *self, s32 v) {
    s32 i;
    self->unk0 = v;
    self->unk4 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    for (i = 3; i >= 0; i--) {
        self->arr[i] = 0;
    }
}
