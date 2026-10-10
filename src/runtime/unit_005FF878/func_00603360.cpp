typedef int s32;
typedef unsigned short u16;
extern "C" {
s32 func_00441248(void);
void func_00446AE0(s32 a, s32 b);
}
extern "C" void func_00603360(s32 arg0, u16 arg1) {
    func_00446AE0(func_00441248(), arg1);
}
