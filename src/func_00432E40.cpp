typedef int s32;
typedef short s16;
typedef long long s64;
typedef unsigned char u8;

struct Obj {
    s32 magic;
    s16 unk4;
    u8 unk6;
    u8 unk7;
    s64 unk8;
    char name[9];
};

extern "C" char *strcpy(char *dst, const char *src);

extern "C" void func_00432E40(Obj *self) {
    self->magic = 0x157529FF;
    self->unk4 = 0;
    self->unk6 = 0;
    self->unk7 = 0;
    self->unk8 = -1;
    strcpy(self->name, "--------");
}
