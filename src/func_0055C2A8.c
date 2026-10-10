/* compiler: ee-gcc2.96-nsa-nosib */
typedef struct {
    char pad0[0x5C];
    void (*m5C)(void);
    char pad60[8];
    void (*m68)(void);
} Handlers_0055C2A8;

extern Handlers_0055C2A8 D_006518C8;

void func_0055C398(int mask, int a, int b);
void func_0055C458(int mask, int a);
void func_0055C268(void);
void func_0055C288(void);
void func_00568060(int n, void (*fn)(void), int arg);

void func_0055C2A8(void) {
    func_0055C398(0x3FFF, 0, 0);
    func_0055C458(0x3FFF, 0);
    {
        void (*f)(void) = func_0055C268;
        D_006518C8.m68 = f;
        D_006518C8.m5C = f;
    }
    func_00568060(1, func_0055C288, 0);
}
