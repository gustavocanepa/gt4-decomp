typedef int s32;
extern "C" char D_0083F0B0[];

extern "C" void HModule__dynamicAssign(s32 *buf, void *src);
extern "C" void func_003285A8(s32 obj);
extern "C" void func_003285F8(s32 obj);
extern "C" void func_003041B8(s32 *buf, s32 flags);

extern "C" void Module__global_0083F010(s32 *ret)
{
    s32 buf[4];

    HModule__dynamicAssign(buf, D_0083F0B0);
    if (ret != buf) {
        s32 obj = buf[0];
        if (obj != 0)
            func_003285A8(obj);
        s32 old = *ret;
        if (old != 0)
            func_003285F8(old);
        *ret = obj;
    }
    func_003041B8(buf, 2);
}
