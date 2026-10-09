typedef unsigned long long u64;

struct Dst {
    char pad[0x64];
    u64 unk64;
} __attribute__((packed, aligned(4)));

struct Src {
    u64 unk0;
} __attribute__((packed, aligned(4)));

extern "C" void func_0060AE48(Dst *arg0, Src *arg1) {
    arg0->unk64 = arg1->unk0;
}
