typedef int s32;

extern "C" void func_003228E0(s32 *buf);
extern "C" s32 *func_00323080(s32 h);
extern "C" void func_003285A8(s32 obj);
extern "C" void func_003285F8(s32 obj);
extern "C" void func_00322888(s32 *buf, s32 flags);

extern "C" void func_003229B8(s32 *ret)
{
    s32 buf[4];

    func_003228E0(buf);
    s32 *src = func_00323080(buf[0]);
    if (ret != src) {
        s32 obj = *src;
        if (obj != 0)
            func_003285A8(obj);
        s32 old = *ret;
        if (old != 0)
            func_003285F8(old);
        *ret = obj;
    }
    func_00322888(buf, 2);
}
