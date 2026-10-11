extern signed char D_0088D8C8[];

extern "C" int func_005BD110(int ch, int a, int b);
extern "C" int memcpy(int a, int b, int c);

extern "C" int func_005BD1A0(int ch, int a, int b) {
    int x = func_005BD110(ch, a, 0);
    int y = func_005BD110(ch, b, 0);
    return memcpy(y, x, D_0088D8C8[ch]);
}
