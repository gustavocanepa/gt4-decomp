typedef unsigned short u16;

struct B { char pad[0xD9E4]; u16 arr[1]; };

u16 func_003FA498(struct B *arg0, int arg1) {
    return arg0->arr[arg1];
}
