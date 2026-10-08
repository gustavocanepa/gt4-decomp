typedef int s32;

struct Struct_0019A7F8 {
    char pad[0xA0];
    s32 unkA0;
};

extern "C" void func_0019A698(struct Struct_0019A7F8 *arg0);
extern "C" s32 func_001CA878(s32 arg0);

extern "C" s32 func_0019A7F8(struct Struct_0019A7F8 *arg0)
{
    struct Struct_0019A7F8 *s0 = arg0;
    func_0019A698(arg0);
    return func_001CA878(s0->unkA0);
}
