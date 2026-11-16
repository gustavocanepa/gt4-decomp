/* compiler: ee-gcc2.96-no-strict-aliasing */
#define NULL 0

typedef int s32;
typedef short s16;
typedef float f32;

#define FLD(p, t, o) (*(t)((char *)(p) + (o)))

void mScrollable__deepCopy(void *arg0, void *arg1);                                   /* extern */
void *__dynamic_cast_2(s32, s32, s32, void *, s32, void *);                      /* extern */

extern char mSelectBox__tf[];
extern char hObject__tf[];

void mSelectBox__deepCopy(void *arg0, void *arg1) {
    void *temp_v0;
    void *var_v1;

    mScrollable__deepCopy(arg0, arg1);
    var_v1 = NULL;
    if (arg1 != NULL) {
        temp_v0 = FLD(arg1, void **, 4);
        var_v1 = __dynamic_cast_2(FLD(temp_v0, s32 *, 4), (s32)mSelectBox__tf, 0,
                               (char *)arg1 + FLD(temp_v0, s16 *, 0), (s32)hObject__tf, arg1);
    }
    if (var_v1 != NULL) {
        FLD(arg0, f32 *, 0xE4) = FLD(var_v1, f32 *, 0xE4);
        FLD(arg0, f32 *, 0xE8) = FLD(var_v1, f32 *, 0xE8);
        FLD(arg0, f32 *, 0xD4) = FLD(var_v1, f32 *, 0xD4);
        FLD(arg0, s32 *, 0xD8) = FLD(var_v1, s32 *, 0xD8);
        FLD(arg0, s32 *, 0xDC) = FLD(var_v1, s32 *, 0xDC);
    }
}
