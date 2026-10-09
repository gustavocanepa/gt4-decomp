typedef unsigned int u32;
typedef unsigned long long u64;

struct Obj {
    char pad[0xA8];
    u64 unkA8;
};

extern Obj *D_00658288;

extern "C" void func_005A55E8(u32 arg0) {
    D_00658288->unkA8 = (u64)arg0;
}
