typedef int s32;

struct Obj;

struct Outer {
    struct Obj *unk0;
};

extern "C" s32 hValue__isValid(struct Obj *arg0);

extern "C" s32 HValue__isValid(struct Outer *arg0) {
    s32 var_v1 = 0;
    struct Obj *temp_v0 = arg0->unk0;

    if (temp_v0 != 0) {
        var_v1 = hValue__isValid(temp_v0) != 0;
    }
    return var_v1;
}
