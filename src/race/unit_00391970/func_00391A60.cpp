struct Pair { float a, b; };
struct Item { char pad[0x2C]; };
extern Item D_00621350[3];
extern int D_006213D4;
extern Pair D_006A0250[][3];
extern "C" int SystemSoundGetOutputMode(void);
extern "C" void func_0039A7A0(Item *, int, float, float);

extern "C" void func_00391A60(void)
{
    int n = SystemSoundGetOutputMode();
    for (int i = 0; i < 3; i++)
        func_0039A7A0(&D_00621350[i], 1, D_006A0250[n][i].a, D_006A0250[n][i].b);
    D_006213D4 = n;
}
