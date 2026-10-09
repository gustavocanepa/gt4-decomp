typedef struct S8 { char data[8]; } S8;

struct Obj1 {
    S8 unk0;
};

extern S8 D_00657AC8;

extern "C" void func_0058CEE8(struct Obj1 *arg0) {
    D_00657AC8 = arg0->unk0;
}
