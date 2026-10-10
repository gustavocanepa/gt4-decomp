/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

extern u8 D_00657ACD;

s32 func_0058CE48(void);
void func_005ADD50(s32 *buf);

s32 func_0058CF48(void) {
    s32 buf[4];
    if (func_0058CE48() != 0) {
        return D_00657ACD;
    }
    func_005ADD50(buf);
    return buf[0] & 1;
}
