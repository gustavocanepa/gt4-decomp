typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

struct Obj00613BC0 {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
};

extern "C" void func_00613BC0(void *arg0, struct Obj00613BC0 *arg1, u32 arg2) {
    arg1->unk0 = (s8)arg2;
    arg1->unk1 = (s8)(arg2 >> 8);
    arg1->unk2 = (s8)(arg2 >> 0x10);
    arg1->unk3 = (s8)(arg2 >> 0x18);
}
