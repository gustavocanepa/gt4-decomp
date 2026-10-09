typedef int s32;

struct Obj {
    char pad[0x208];
    s32 unk208;
    s32 unk20C;
};

extern "C" void func_00501A58(Obj *arg0) {
    arg0->unk208 = 0;
    arg0->unk20C = 1;
}
