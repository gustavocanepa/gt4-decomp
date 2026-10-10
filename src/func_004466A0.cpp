typedef int s32;
typedef long long s64;
typedef unsigned char u8;

/* Looks up a record by its 64-bit id through func_00443ED0 (the manager D_006235A8) and returns
   one byte of it, or -1 when the id is unset. */
struct Info { u8 pad[0x8]; u8 field; u8 pad2[0x7]; };
struct Self { char pad[0xA8]; s64 id; };
extern char D_006235A8[];
extern "C" void func_00443ED0(char *, s64, Info *);

extern "C" s32 func_004466A0(Self *self) {
    Info info;
    if (self->id == -1) return -1;
    func_00443ED0(D_006235A8, self->id, &info);
    return info.field;
}
