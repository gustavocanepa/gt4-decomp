typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

struct Obj {
    char pad[0x50];
    s64 key;
};

struct Rec {
    char pad[0xE];
    s8 value;
    char tail[0x61];
};

extern char D_006235A8[];
extern "C" void func_00443ED0(void *, s64, void *);

extern "C" s32 func_004463E0(Obj *self) {
    Rec rec;
    if (self->key == -1)
        return -1;
    func_00443ED0(D_006235A8, self->key, &rec);
    return rec.value;
}
