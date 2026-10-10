typedef int s32;
typedef unsigned long long u64;

struct Seed_00435A10 {
    u64 a;
    u64 b;
};

struct Obj_00435A10 {
    char pad0[0x81CC];
    s32 m81CC;
    char pad81D0[0x81E0 - 0x81D0];
    s32 m81E0;
    char pad81E4[0x81F0 - 0x81E4];
    s32 m81F0;
};

extern "C" u64 func_00548918(void);
extern "C" u64 func_00578560(void);
extern "C" s32 func_00572C90(void *data, s32 size);

extern "C" void func_00435A10(Obj_00435A10 *o) {
    Seed_00435A10 seed;
    seed.a = func_00548918();
    seed.b = func_00578560();
    o->m81CC = func_00572C90(&seed, sizeof(seed));
    o->m81E0 = 0;
    o->m81F0 = 0;
}
