typedef struct S16 { char data[16]; } S16;

struct Dst {
    char pad[0x44];
    S16 unk44;
};

struct Src {
    S16 unk0;
};

extern "C" void func_0025BF68(struct Dst *arg0, struct Src *arg1) {
    arg0->unk44 = arg1->unk0;
}
