/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Entry_00559CC8 {
    char data[0x18];
};

extern "C" Entry_00559CC8 D_00650438[8];
extern "C" s32 func_00559970(Entry_00559CC8 *e);

extern "C" Entry_00559CC8 *func_00559CC8(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (func_00559970(&D_00650438[i])) {
            return &D_00650438[i];
        }
    }
    return 0;
}
