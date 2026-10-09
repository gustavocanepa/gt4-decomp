typedef int s32;

extern "C" void *exception__structor_0(s32 size);
extern "C" void RaceBasic__structor_0(void *arg0);

extern "C" void *func_0038A5F8(void) {
    void *v0 = exception__structor_0(0xE440);

    RaceBasic__structor_0(v0);
    return v0;
}
