typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" u32 func_0055F0A0(void *self, int index);

extern "C" u64 func_0055F0F8(void *self, int index) {
    u64 lo = func_0055F0A0(self, index * 2);
    u64 hi = func_0055F0A0(self, index * 2 + 1);
    return lo | (hi << 32);
}
