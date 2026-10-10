typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

struct Rec {
    s64 value;
    s64 pad;
};

extern char D_006235A8[];
extern "C" u64 func_004454C0(void *arg);
extern "C" bool SPEC_DATABASE__DatabaseStorage__getRow_2(void *db, int key, int type, Rec *out);

extern "C" s64 func_004457B0(void *arg) {
    u64 id = func_004454C0(arg) & 0xFFFFFFFF;
    Rec rec;
    if (SPEC_DATABASE__DatabaseStorage__getRow_2(D_006235A8, id, 0x29, &rec))
        return rec.value;
    return -1;
}
