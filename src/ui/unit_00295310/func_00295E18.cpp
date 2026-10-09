typedef int s32;

struct Sub { char pad[1]; };
struct S { char pad[0xF4]; Sub sub; };

extern "C" Sub *func_00295E18(S *arg0) {
    return &arg0->sub;
}
