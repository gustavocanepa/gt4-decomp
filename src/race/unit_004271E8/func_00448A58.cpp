typedef int s32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;

struct Global;
extern Global D_006235A8;

struct Ref {
    s64 id;
    char pad8[0x18];
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, void *info);

extern "C" s32 func_00448A58(s64 id, void *out) {
    if ((id >> 32) == 0x26) {
        Ref r;
        if (SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &r) == 0) {
            return 0;
        }
        id = r.id;
    }
    return SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, out) != 0;
}
