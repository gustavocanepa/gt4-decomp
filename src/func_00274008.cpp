/* compiler: ee-gcc2.96-nosib */
typedef int s32;

extern s32 D_00618EF4;
extern "C" s32 func_0054EDA0(s32 arg0);

extern "C" s32 mMoviePS2__virtual_17(void) {
    s32 temp_v1 = D_00618EF4;
    if (temp_v1 != 0) {
        return func_0054EDA0(temp_v1);
    }
    return 1;
}
