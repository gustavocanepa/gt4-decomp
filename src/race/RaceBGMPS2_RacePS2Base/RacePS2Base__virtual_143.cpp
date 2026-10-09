typedef int s32;

struct Struct_0033C158 {
    char pad[0xCF4C];
    s32 unkCF4C;
};

struct Obj;
extern "C" void func_00387E40(Obj *arg0, s32 arg1);

extern "C" void RacePS2Base__virtual_143(struct Struct_0033C158 *arg0) {
    arg0->unkCF4C = 0;
    func_00387E40((Obj *)arg0, 2);
}
