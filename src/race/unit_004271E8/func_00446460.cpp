typedef int s32;
typedef long long s64;
typedef unsigned char u8;

/* Looks up a record by its 64-bit id through SPEC_DATABASE__DatabaseStorage__getRow (the manager D_006235A8) and returns
   one byte of it, or -1 when the id is unset. */
struct Info { u8 pad[0x2]; u8 field; u8 pad2[0x1D]; };
struct Self { char pad[0x58]; s64 id; };
extern char D_006235A8[];
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(char *, s64, Info *);

extern "C" s32 func_00446460(Self *self) {
    Info info;
    if (self->id == -1) return -1;
    SPEC_DATABASE__DatabaseStorage__getRow(D_006235A8, self->id, &info);
    return info.field;
}
