typedef struct S8 { char data[8]; } S8;

struct Obj0 {
    char pad[0x6C];
    S8 unk6C;
};

struct Obj1 {
    S8 unk0;
};

extern "C" void func_0060AE70(struct Obj0 *arg0, struct Obj1 *arg1) {
    arg0->unk6C = arg1->unk0;
}
