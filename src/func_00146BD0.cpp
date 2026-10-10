/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;

struct WString { int f0; u16 *begin; u16 *end; };

extern "C" void func_00146BD0(WString *s) {
    for (u16 *p = s->begin; p != s->end; ++p) {
        if ((u16)(*p - 'A') < 26)
            *p = *p + 0x20;
    }
}
