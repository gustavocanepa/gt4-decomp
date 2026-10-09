typedef int s32;

struct Sub {
    char pad[1];
};

extern "C" s32 func_0057CE60(Sub *arg0);

extern "C" s32 func_002C9B50(char *arg0) {
    return func_0057CE60((Sub *)(arg0 + 0xD8));
}
