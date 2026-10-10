typedef unsigned long u64;
typedef unsigned int u32;

struct Clock { char pad[0x80]; u32 now; };
extern struct Clock D_0086CC80;
void func_00576AD8(u32 *, int);

u64 func_005488A8(void) {
    struct Clock *c = &D_0086CC80;
    func_00576AD8(&c->now, 0x40);
    return (u64)c->now + 0x31510F5B40UL;
}
