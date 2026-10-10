struct Config {
    char pad[0xED];
    unsigned char a;
    unsigned char b;
    unsigned char angle[2];
    unsigned char scale[2];
    unsigned char count[2];
};

struct Settings {
    int a;
    int b;
    float angle[2];
    float scale[2];
    float count[2];
};

extern Config D_00620CD8;
extern Settings D_00845BF0;

extern "C" void func_003F7BE0(void) {
    D_00845BF0.a = D_00620CD8.a;
    D_00845BF0.b = D_00620CD8.b;
    for (int i = 0; i < 2; i++) {
        float f = D_00620CD8.angle[i];
        if (D_00620CD8.angle[i] == 0) D_00845BF0.a = 0;
        D_00845BF0.angle[i] = f * 0.0017453288892284036f;
        D_00845BF0.scale[i] = D_00620CD8.scale[i] * 10.0f;
        D_00845BF0.count[i] = D_00620CD8.count[i];
    }
}
