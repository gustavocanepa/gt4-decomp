typedef struct S16 { char data[16]; } S16;

struct Obj0 {
    char pad[0x204];
    S16 unk204;
};

struct Obj1 {
    S16 unk0;
};

extern "C" void func_00335DB0(struct Obj0 *arg0, struct Obj1 *arg1) {
    arg0->unk204 = arg1->unk0;
}
