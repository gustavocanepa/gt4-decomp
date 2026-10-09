typedef int s32;

struct Obj002676A8 {
    char pad[0x98];
    s32 unk98;
};

extern "C" void func_002676A8(Obj002676A8 *arg0, s32 arg1) {
    arg0->unk98 = (arg0->unk98 & 0xFE7FFFFF) | ((arg1 & 3) << 23);
}
