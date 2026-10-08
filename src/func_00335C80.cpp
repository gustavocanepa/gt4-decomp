extern "C" void *func_00426800(void *arg0);
extern "C" char D_00678620[];

struct S00335C80 {
    char pad[0xD0];
    void *unkD0;
};

extern "C" void func_00335C80(struct S00335C80 *arg0)
{
    func_00426800(arg0);
    arg0->unkD0 = D_00678620;
}
