typedef int s32;
typedef short s16;

struct Obj {
    char pad[0x64C];
    s16 unk64C;
};

extern "C" void func_0035BCC8(char *arg0) {
    struct Obj *obj = (struct Obj *)(arg0 + 0x104);
    if (obj->unk64C > 0) {
        obj->unk64C = 0;
        return;
    }
    obj->unk64C = -1;
}
