typedef unsigned int u32;
typedef unsigned long long u64;

struct Obj {
    char pad[0xA8];
    u64 unkA8;
};

extern Obj *_impure_ptr;

extern "C" void func_005A55E8(u32 arg0) {
    _impure_ptr->unkA8 = (u64)arg0;
}
