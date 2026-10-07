typedef int s32;

struct Sub {
    char pad[0x8];
    s32 unk8;
};

struct Obj {
    char pad[0x40];
    Sub sub;
};

extern "C" void func_0026F9C8(Obj *arg0) {
    Sub *temp = &arg0->sub;
    temp->unk8 = temp->unk8 - 0x10;
}
