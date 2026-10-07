typedef int s32;

struct Sub { char pad[1]; };
struct S { char pad[0x44]; Sub sub; };

extern "C" Sub *func_0025BF58(S *arg0) {
    return &arg0->sub;
}
