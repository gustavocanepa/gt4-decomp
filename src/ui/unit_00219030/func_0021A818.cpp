typedef int s32;

struct Sub { char pad[1]; };
struct S { char pad[0x30]; Sub sub; };

extern "C" Sub *func_0021A818(S *arg0) {
    return &arg0->sub;
}
