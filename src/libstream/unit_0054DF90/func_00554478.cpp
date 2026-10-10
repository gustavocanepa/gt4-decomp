/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Packet {
    int a;
    int b;
    char data[0x38];
};

struct Client {
    int sema;
    char pad4[0x38];
    Packet *buf;
};

extern "C" void func_00578500(int sema);
extern "C" void func_00578168(Client *c, int cmd, int flags, Packet *p, int size);

extern "C" char *func_00554478(Client *c, int a, int b)
{
    func_00578500(c->sema);
    c->buf->a = a;
    c->buf->b = b;
    func_00578168(c, 3, 0, c->buf, 0x40);
    return c->buf->data;
}
