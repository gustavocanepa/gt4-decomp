/* A real C++ constructor: the class (named after its vtable, 0x00681AB8) keeps its vptr after
   its 0x974 bytes of fields; members are named after their constructors. */
struct RaceEventQueue__structor_0 {
    char data[0x82C];
    RaceEventQueue__structor_0();
};

struct func_003DD7C8 {
    int handle;
    func_003DD7C8();
};

struct func_003BB840 {
    char data[0x44];
    func_003BB840();
};

struct D_00681AB8 {
    char pad0[0x60];
    int f60;
    char pad64[0xC];
    int f70;
    char pad74[0xC];
    int f80;
    int f84;
    char pad88[0x30];
    int fB8;
    int fBC;
    int fC0;
    int fC4;
    int fC8;
    int fCC;
    char padD0[0xC];
    int fDC;
    int fE0;
    int fE4;
    char padE8[0x4];
    int fEC;
    int fF0;
    RaceEventQueue__structor_0 queue;
    func_003DD7C8 h0;
    func_003DD7C8 h1;
    func_003BB840 list;
    unsigned char flag;
    char pad96D[3];
    int active;
    D_00681AB8();
    virtual ~D_00681AB8();

};

extern "C" void func_003BFB10(D_00681AB8 *self);

D_00681AB8::D_00681AB8() {
    func_003BFB10(this);
    f60 = 0;
    f70 = 0;
    f80 = 0;
    f84 = 0;
    fB8 = 0;
    fBC = 0;
    fC0 = 1;
    fC4 = 0;
    fC8 = 0;
    fCC = 0;
    fDC = 0;
    fE0 = 0;
    fE4 = 0;
    fEC = 0;
    fF0 = 0;
    flag = 0;
    active = 1;
}
