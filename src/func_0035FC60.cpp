typedef unsigned short u16;

struct S { char pad[0x60E]; u16 unk60E; };

extern "C" u16 func_0035FC60(S *arg0) {
    return arg0->unk60E;
}
