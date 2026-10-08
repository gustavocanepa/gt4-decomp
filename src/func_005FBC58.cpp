typedef int s32;

struct Target005FBC58 {
    char pad[0x3444];
    s32 unk3444;
};

struct Inner005FBC58 {
    char pad[0x8];
    Target005FBC58 **unk8;
};

struct Obj005FBC58 {
    char pad[0x60];
    Inner005FBC58 *unk60;
};

extern "C" void func_005FBC58(struct Obj005FBC58 *arg0, s32 arg1, s32 arg2) {
    arg0->unk60->unk8[arg1]->unk3444 = arg2;
}
