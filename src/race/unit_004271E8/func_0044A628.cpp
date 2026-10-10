typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char unk10[0x30];
    void *unk40;
};

extern char D_00688368[];

extern "C" void *func_00574D78(void *p);

extern "C" void func_0044A628(Obj *self) {
    self->unk40 = D_00688368;
    func_00574D78(self->unk10);
    self->unk0 = -1;
    self->unk4 = -1;
    self->unk8 = -1;
    self->unkC = 0;
}
