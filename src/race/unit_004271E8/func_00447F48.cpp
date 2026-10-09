typedef int s32;
struct Info { long long fields[3]; } __attribute__((packed));
extern char D_006235A8[];
extern "C" s32 func_00443F00(void *, s32, s32, Info *);
extern "C" s32 func_00447F48(long long code, Info *dest) {
    Info info;
    if (!func_00443F00(D_006235A8, (s32)(code & 0xffffffffU), 0x22, &info)) return 0;
    *dest = info;
    return 1;
}
