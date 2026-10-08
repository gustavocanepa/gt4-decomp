typedef int s32;

struct Struct_00156700 {
    char pad[0x174];
    s32 unk174;
};

extern "C" void func_00156728(void);

extern "C" void func_00156700(struct Struct_00156700 *arg0)
{
    if (arg0->unk174 == 0) {
        return;
    }
    func_00156728();
}
