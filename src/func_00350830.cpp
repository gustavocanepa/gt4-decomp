typedef float f32;

extern "C" void func_00350678(f32 *arg0);

extern "C" f32 func_00350830(f32 *arg0)
{
    func_00350678(arg0);
    return arg0[8];
}
