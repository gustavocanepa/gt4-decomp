typedef int s32;

struct Obj0 {
    char pad0[8];
    s32 unk8;
};

struct Elem {
    char pad[0x38];
    s32 unk38;
};

extern "C" void func_0031F258(struct Obj0 *arg0, void *arg1) {
    s32 temp_v0 = arg0->unk8;
    *(s32 *)((char *)arg1 + 0x34) = temp_v0;
    s32 temp_v1 = ((struct Elem *)((char *)arg1 + temp_v0 * 4))->unk38;
    *(s32 *)((char *)arg1 + 0x48) = temp_v1;
}
