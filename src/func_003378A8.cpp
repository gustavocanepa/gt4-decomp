typedef int s32;

struct Obj {
    char pad[0xE458];
    s32 unkE458;
};

extern "C" s32 func_00341CC8(struct Obj *arg0);

extern "C" s32 func_003378A8(struct Obj *arg0) {
    s32 v1 = 0;

    if (arg0->unkE458 != 0) {
        v1 = func_00341CC8(arg0) != 0;
    }
    return v1;
}
