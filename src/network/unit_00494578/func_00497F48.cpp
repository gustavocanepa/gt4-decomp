typedef int s32;

struct Obj {
    char pad[8];
    s32 count;
    char padC[0x2C];
    s32 *words;
};

extern "C" void func_00497838(Obj *, s32, s32 *, s32);

extern "C" void func_00497F48(Obj *o, s32 value) {
    s32 n = o->count;
    func_00497838(o, value, &o->words[n & ~3], n & 3);
    o->count++;
}
