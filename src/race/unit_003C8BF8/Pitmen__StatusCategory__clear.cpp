typedef int s32;

struct Obj {
    s32 unk0;
    char pad[0xAA0 - 4];
    s32 unkAA0;
};

extern "C" void Pitmen__StatusCategory__clear(Obj *arg0) {
    arg0->unk0 = 0;
    arg0->unkAA0 = 1;
}
