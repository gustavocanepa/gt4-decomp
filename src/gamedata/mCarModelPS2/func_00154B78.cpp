typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern "C" void func_005C1628(void *p);

extern "C" void func_00154B78(Obj *self, s32 flags) {
    self->unk8 = 0;
    self->unk4 = 0;
    self->unk10 = 0;
    if (flags & 1) {
        return func_005C1628(self);
    }
}
