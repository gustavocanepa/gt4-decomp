extern "C" int func_00443F70(int a, int b, int c);

extern "C" int func_00443F40(int a, long b) {
    return func_00443F70(a, (int)(b & 0xFFFFFFFF), (int)(b >> 32));
}
