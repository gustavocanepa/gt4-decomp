typedef struct S8 { char data[8]; } S8;

struct Obj0 {
    char pad[0x18];
    S8 unk18;
};

struct Obj1 {
    S8 unk0;
};

extern "C" void func_0060B1D0(struct Obj0 *arg0, struct Obj1 *arg1) {
    arg0->unk18 = arg1->unk0;
}
