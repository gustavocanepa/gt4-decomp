typedef int s32;

struct Hdr {
    s32 unk0;
    s32 unk4;
};

struct Obj {
    s32 unk0;
    s32 unk4;
    char pad8[0x38 - 0x8];
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    Hdr *unk48;
};

extern "C" void func_00345FD0(Obj *self, s32 arg) throw();

extern "C" void func_00346498(Obj *self) {
    if (self->unk38 == 0 && self->unk3C != 0) {
        func_00345FD0(self, self->unk44);
        func_00345FD0(self, 1);
        Hdr *h = self->unk48;
        h->unk0 = self->unk40;
        h->unk4 = self->unk4 - self->unk0 + 8;
    }
    self->unk38 = 1;
}
