/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Msg { int from; int b; int a; int pad[3]; unsigned int len; unsigned char data[0xCC - 0x1C]; Msg *next; };
struct Src { char pad[0x58]; int id; };
struct Ctx { char pad[0x68]; int count; char pad2[0xE0 - 0x6C]; Msg **tail; char pad3[0x2230 - 0xE4]; int sema; };
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" void func_00574EE8(void *);

extern "C" void func_00553FC8(Ctx *c, Src *s, int a, int b, const void *data, unsigned int len, Msg *m)
{
    unsigned int n = len > 0x80 ? 0x80 : len;
    m->from = s->id;
    m->a = a;
    m->b = b;
    m->len = n;
    if (n) func_005A4724(m->data, data, n);
    c->count++;
    m->next = 0;
    *c->tail = m;
    c->tail = &m->next;
    func_00574EE8(&c->sema);
}
