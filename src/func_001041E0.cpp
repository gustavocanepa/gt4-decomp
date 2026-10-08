typedef struct S16 { char data[16]; } S16;
typedef int s32;

struct Obj1_001041E0 {
    char pad0[8];
    s32 unk8;
    S16 unkC;
    S16 unk1C;
};

extern "C" void *func_001041E0(void *arg0, struct Obj1_001041E0 *arg1) {
    S16 *src = arg1->unk8 ? &arg1->unk1C : &arg1->unkC;
    *(S16 *)arg0 = *src;
    return arg0;
}
