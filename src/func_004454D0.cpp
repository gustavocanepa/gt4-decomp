typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

struct Info {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    char pad[0x40 - 0xC];
};

struct Obj {
    char pad[0x18];
    s8 unk18;
};

extern "C" void func_004458D0(Obj *, s32, Info *);

extern "C" unsigned long long func_004454D0(Obj *self) {
    Info info;
    if (self->unk18 == -1)
        self->unk18 = 0;
    func_004458D0(self, self->unk18, &info);
    return info.unk8;
}
