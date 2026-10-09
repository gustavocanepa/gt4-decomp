typedef long long s64;

struct Obj { char pad[0x10]; s64 unk10; };

extern "C" s64 func_001D3138(Obj **arg0) {
    volatile char buf[0x10];
    (void)buf;
    return (*arg0)->unk10;
}
