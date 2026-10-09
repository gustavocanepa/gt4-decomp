extern "C" int func_00443E90(int a, int b, int c);

extern "C" int func_00443E60(int a, long b) {
    return func_00443E90(a, (int)(b & 0xFFFFFFFF), (int)(b >> 32));
}
