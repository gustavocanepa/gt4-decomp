typedef int s32;

struct Item { char pad[0x74]; };
extern "C" void func_003D36C0(Item *);

extern "C" void func_003D4BF0(Item *items) {
    s32 i;
    for (i = 3; i >= 0; i--) {
        func_003D36C0(items++);
    }
}
