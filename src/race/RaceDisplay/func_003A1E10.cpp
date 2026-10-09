typedef int s32;

extern "C" void func_0057DA20(void *dst, const char *fmt, s32 arg);
extern "C" s32 func_0048F628(void *globalObj, const char *path, s32 *outObj, s32 flag);

extern "C" char D_00621518[];

extern "C" void func_003A1E10(s32 arg0) {
    char buf[0x80];
    s32 obj;

    func_0057DA20(buf, "image/%s.png", arg0);
    obj = 0;
    if (func_0048F628(D_00621518, buf, &obj, 0) == 0) {
        obj = 0;
        func_0048F628(D_00621518, "image/00no_texture.png", &obj, 0);
    }
}
