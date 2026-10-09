typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0xF866];
    u8 unkF866;
};

extern "C" s32 DynamicsConductorBattle2P__virtual_09(Obj *arg0) {
    return arg0->unkF866 == 0;
}
