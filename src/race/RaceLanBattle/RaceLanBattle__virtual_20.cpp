typedef int s32;

struct Struct_003377F8 {
    char pad[0xE448];
    s32 unkE448;
    char pad2[0xF388 - 0xE448 - 4];
    s32 unkF388;
};

extern "C" s32 RaceLanBattle__virtual_20(struct Struct_003377F8 *arg0) {
    return arg0->unkF388 == arg0->unkE448;
}
