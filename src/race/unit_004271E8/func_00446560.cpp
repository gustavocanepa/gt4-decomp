typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

struct Obj {
    char pad[0x78];
    s64 key;
};

struct Rec {
    char pad[0x4];
    u8 value;
    char tail[0xB];
};

extern char D_006235A8[];
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(void *, s64, void *);

extern "C" s32 func_00446560(Obj *self) {
    Rec rec;
    if (self->key == -1)
        return -1;
    SPEC_DATABASE__DatabaseStorage__getRow(D_006235A8, self->key, &rec);
    return rec.value;
}
