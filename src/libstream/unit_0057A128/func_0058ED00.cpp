/* compiler: ee-gcc2.9-991111 */
typedef int s32;

struct Ent { s32 a, b, c, d; char pad[0x324]; };
extern s32 D_00657B10;
extern Ent D_0087FA80[16];

extern "C" s32 func_0058ED00(void) {
    s32 i;
    D_00657B10 = 1;
    for (i = 0; i < 16; i++) {
        D_0087FA80[i].a = 0;
        D_0087FA80[i].b = 0;
        D_0087FA80[i].c = 0;
        D_0087FA80[i].d = 0;
    }
    return 1;
}
