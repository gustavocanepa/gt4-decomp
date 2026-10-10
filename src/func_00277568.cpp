typedef int s32;

extern "C" void func_00277850(s32 *buf, s32 a, s32 b);
extern "C" void func_003285A8(s32 obj);
extern "C" void func_003285F8(s32 obj);
extern "C" void func_00277438(s32 *buf, s32 flags);

extern "C" void func_00277568(s32 *ret)
{
    s32 buf[4];

    func_00277850(buf, 0, 0);
    if (ret != buf) {
        s32 obj = buf[0];
        if (obj != 0)
            func_003285A8(obj);
        s32 old = *ret;
        if (old != 0)
            func_003285F8(old);
        *ret = obj;
    }
    func_00277438(buf, 2);
}
