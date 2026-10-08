typedef int s32;

extern "C" s32 func_00329858(s32 *arg0, const char *arg1);

extern "C" s32 func_001C6AA0(void) {
    s32 local;
    s32 result = func_00329858(&local, "DemonstrationSlideNum");
    return (result == 0) ? 0 : local;
}
