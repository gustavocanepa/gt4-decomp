/* compiler: ee-gcc2.9-991111 */
typedef int s32;

extern "C" void func_005AE0D0(s32 arg0, void *arg1);

extern "C" void func_005B9760(s32 arg0) {
    s32 buf = arg0;
    func_005AE0D0(-8, &buf);
}
