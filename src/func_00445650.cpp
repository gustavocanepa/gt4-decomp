typedef int s32;
typedef long long s64;
typedef unsigned char u8;

struct Info { char pad[9]; u8 m9; char pad2[0x16]; };
struct Self { char pad[0xB0]; s64 id; };
extern char D_006235A8[];
extern "C" void func_00443ED0(char *, s64, Info *);

extern "C" s32 func_00445650(Self *self) {
    Info info;
    if (self->id == -1) return 0;
    func_00443ED0(D_006235A8, self->id, &info);
    return info.m9 != 0;
}
