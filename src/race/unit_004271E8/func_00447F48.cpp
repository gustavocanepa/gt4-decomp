typedef long long s64;
typedef unsigned long long u64;
struct Rec { char b[24]; };
extern char D_006235A8[];
extern "C" bool SPEC_DATABASE__DatabaseStorage__getRow_2(void *db, int key, int type, Rec *out);

extern "C" bool func_00447F48(u64 id, Rec *out) {
    Rec rec;
    if (!SPEC_DATABASE__DatabaseStorage__getRow_2(D_006235A8, id & 0xFFFFFFFF, 0x22, &rec))
        return false;
    *out = rec;
    return true;
}
