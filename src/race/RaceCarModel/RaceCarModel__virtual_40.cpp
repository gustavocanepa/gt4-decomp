typedef int s32;

struct Obj {
    char pad[0x18];
};

struct Result {
    char pad[0x38];
    s32 unk38;
};

extern "C" Result *func_00450FB0(void *arg0);

extern "C" s32 RaceCarModel__virtual_40(Obj *arg0) {
    s32 var_v1;
    Result *temp_v0;

    temp_v0 = func_00450FB0((char *)arg0 + 0x18);
    var_v1 = 0;
    if (temp_v0 != 0) {
        var_v1 = temp_v0->unk38;
    }
    return var_v1;
}
