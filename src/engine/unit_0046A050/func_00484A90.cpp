/* compiler: ee-gcc2.96-nsa-nosched1 */
typedef int s32;

/* The base class, named after its constructor (func_0047D280); its vptr sits at 0x5C. */
struct func_0047D280 {
    char pad[0x5C];
    func_0047D280(s32 a, s32 b, s32 c, s32 d, s32 e);
    virtual ~func_0047D280();
};

struct List {
    s32 count;
    List *next;
    List *prev;
    void init() { prev = this; count = 0; next = this; }
};

/* Named after its vtable (0x00688AE0). */
struct D_00688AE0 : func_0047D280 {
    s32 m60, m64, m68, m6C, m70;
    List l74;
    List l80;
    s32 m8C;
    s32 pad90[2];
    s32 m98;
    D_00688AE0(s32 a, s32 b, s32 c, s32 d, s32 e);
    virtual ~D_00688AE0();
};

extern "C" void func_00484B10(D_00688AE0 *self, s32 c, List *l);

/* Compiled without sched1 (ee-gcc2.96-nsa-nosched1): the &l80 argument copy stays after the
 * list stores, so &l80 lives in $a2 itself. */
D_00688AE0::D_00688AE0(s32 a, s32 b, s32 c, s32 d, s32 e) : func_0047D280(a, b, c, d, e) {
    m60 = 0;
    m64 = 0;
    m68 = 0;
    m6C = 0;
    m70 = 0;
    l74.init();
    l80.init();
    m8C = 0;
    m98 = 0;
    func_00484B10(this, c, &l80);
}
