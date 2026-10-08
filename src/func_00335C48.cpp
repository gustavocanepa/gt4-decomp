typedef long s64;

struct Obj {
    char pad[0xAB0];
    s64 unkAB0;
};

extern "C" s64 func_003BB4D0(void);

extern "C" s64 func_00335C48(struct Obj *arg0) {
    s64 v1 = arg0->unkAB0;

    if (v1 != 0) {
        return v1;
    }
    return func_003BB4D0();
}
