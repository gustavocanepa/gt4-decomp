typedef int s32;
typedef long long s64;

struct Global;
extern Global D_006235A8;

struct Info {
    s64 id;
    char pad8[0x18];
};

extern "C" s64 func_00443E00(Global *g, const char *key, s32 kind);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__IsExistID(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" s32 func_00443E60(Global *g, s64 id);

extern "C" s32 func_00447E38(const char *key) {
    Info info;
    s64 id = func_00443E00(&D_006235A8, key, 0);
    if (id == -1) {
        id = func_00443E00(&D_006235A8, key, 0x26);
        if (id == -1) {
            return 0;
        }
        if (SPEC_DATABASE__DatabaseStorage__IsExistID(&D_006235A8, id) == 0) {
            return 0;
        }
        SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info);
        id = info.id;
    }
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info);
    return func_00443E60(&D_006235A8, id);
}
