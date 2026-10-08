typedef int s32;

struct Obj;

struct Outer {
    struct Obj *unk0;
};

extern "C" s32 func_00323BF8(struct Obj *arg0);

extern "C" s32 func_00323D28(struct Outer *arg0) {
    s32 var_v1 = 0;
    struct Obj *temp_v0 = arg0->unk0;

    if (temp_v0 != 0) {
        var_v1 = func_00323BF8(temp_v0) != 0;
    }
    return var_v1;
}
