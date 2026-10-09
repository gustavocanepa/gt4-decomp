typedef long long s64;

struct Obj { char pad[0x8]; s64 *ptr8; };

extern "C" s64 func_00449F58(Obj *arg0) {
    return *arg0->ptr8;
}
