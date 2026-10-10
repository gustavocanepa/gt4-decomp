typedef unsigned long long u64;

struct Key_001D1478 {
    u64 id : 56;
    u64 kind : 8;
};

extern "C" u64 func_001CD840(void *src);
extern "C" unsigned char func_001CD860(void *src);

extern "C" void func_001D1478(Key_001D1478 *key, char *src) {
    key->id = func_001CD840(src);
    key->kind = func_001CD860(src + 0x24);
}
