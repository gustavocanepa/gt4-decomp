/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 D_00657ACA;
extern "C" s32 func_0058CE48(void);
extern "C" void func_005ADD50(u32 *);

extern "C" s32 func_0058CF08(void) {
    u32 cfg[4];
    if (func_0058CE48() != 0)
        return D_00657ACA;
    func_005ADD50(cfg);
    return (cfg[0] >> 1) & 3;
}
