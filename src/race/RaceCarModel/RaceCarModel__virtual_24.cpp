typedef int s32;

struct Obj {
    s32 unk0;
};

extern "C" void func_00451D18(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void RaceCarModel__virtual_24(Obj *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00451D18((char *)arg0 + 0x18, arg0->unk0, arg1, arg2, arg3);
}
