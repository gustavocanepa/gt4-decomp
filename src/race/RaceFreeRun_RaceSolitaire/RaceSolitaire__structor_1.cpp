typedef int s32;

extern void *D_00620000;
extern void *RaceSolitaire__vtable;
extern "C" void func_00109A50(void *, void *);
extern "C" void func_00575DA0(void *);
extern "C" void func_003BDA40(void *, s32);
extern "C" void func_003467A0(void *, s32);
extern "C" void func_00444210(void *, s32);
extern "C" void RaceInput__structor_2(void *, s32);
extern "C" void func_0055FA30(void *, s32);
extern "C" void SimplePause__structor_1(void *, s32);
extern "C" void RaceBasic__structor_1(void *, s32);
extern "C" void func_005C1628(void *);
struct VEntry_vcall_0 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_0(char *o, s32 a0) {
    VEntry_vcall_0 *e = (VEntry_vcall_0 *)(*(char **)(o + 0x35cc) + 0x8);
    e->fn(o + e->delta, a0);
}

extern "C" void RaceSolitaire__structor_1(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x64) = &RaceSolitaire__vtable;
    func_00109A50(arg0, (char *)arg0 + 0xe48c);
    if (*(void **)((char *)arg0 + 0xf0ec) != 0) {
        if (*(void **)((char *)&D_00620000 + 0x1f20) == 0) {
            func_00575DA0(*(void **)((char *)arg0 + 0xf0ec));
        }
    }
    if (*(void **)((char *)arg0 + 0xf100) != 0) {
        vcall_0((char *)*(void **)((char *)arg0 + 0xf100), 0x3);
    }
    func_003BDA40((char *)arg0 + 0xf058, 0x2);
    func_003467A0((char *)arg0 + 0xefe0, 0x2);
    func_003467A0((char *)arg0 + 0xef70, 0x2);
    func_00444210((char *)arg0 + 0xedc0, 0x2);
    func_00444210((char *)arg0 + 0xec10, 0x2);
    RaceInput__structor_2((char *)arg0 + 0xea2c, 0x2);
    RaceInput__structor_2((char *)arg0 + 0xe84c, 0x2);
    RaceInput__structor_2((char *)arg0 + 0xe66c, 0x2);
    RaceInput__structor_2((char *)arg0 + 0xe48c, 0x2);
    func_0055FA30((char *)arg0 + 0xe44c, 0x2);
    SimplePause__structor_1((char *)arg0 + 0xe440, 0x2);
    RaceBasic__structor_1(arg0, 0x0);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}
