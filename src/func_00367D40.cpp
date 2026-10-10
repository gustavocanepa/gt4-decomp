typedef int s32;

extern "C" s32 func_00367D20(void *);
extern "C" s32 func_00367D30(void *);

extern "C" s32 func_00367D40(void *o) {
    s32 r = 0;
    if (func_00367D20(o) || func_00367D30(o))
        r = 1;
    return r;
}
