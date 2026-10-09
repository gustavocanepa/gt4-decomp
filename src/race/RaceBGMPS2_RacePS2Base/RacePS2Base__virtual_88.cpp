typedef int s32;

extern "C" void RaceBase__virtual_88(void *arg0);
extern "C" void func_00398B58(s32 *arg0);
extern "C" void func_003D3358(void *arg0);

extern "C" void RacePS2Base__virtual_88(void *arg0) {
    RaceBase__virtual_88(arg0);
    func_00398B58((s32 *)((char *)arg0 + 0xE170));
    func_003D3358((char *)arg0 + 0x3628);
}
