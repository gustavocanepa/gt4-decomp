/* One request of the link layer, as its sender fills it in. */
struct Packet {
    char pad00[0x14];
    char busy;
    char pad15[3];
    int a, b, c, d, f, e;
};

/* The copy of the last request that func_0050E828 sends again. */
struct Saved {
    int a, b, c, d, e, f, flag;
};

/* The two blocks that carry the completion callback and its argument (func_00514760 calls
   D_008A03B8.callback(packet, D_008A0190.arg)). Only the member at 0x120 is used here. Both
   are written as members: a member store has the alias set of its type, so the int loads from
   the packet do not wait for these two pointer stores, which is the order the original has.
   A plain global would conflict with every load. */
struct Request {
    char pad000[0x120];
    void *arg;
};
struct Reply {
    char pad000[0x120];
    void (*callback)(Packet *, void *);
};

extern int D_0064A308;      /* 1 while the link is up */
extern int D_0064A30C;      /* the link's handle, 0 without one */
extern short D_0064A310;    /* cleared here; func_00514760 sets it to 1 */
extern Request D_008A0190;
extern Reply D_008A03B8;
extern Saved D_008A0398;

extern "C" int func_0050B460(int, int, int, Packet *) throw();

/* Sends request 0x12 with `packet` and remembers it, with the callback to run on the answer.
   Returns -15 when the link is down, -16 without a handle, -5 when the send fails. */
extern "C" int func_0050E6E8(Packet *packet, void (*callback)(Packet *, void *), void *arg) {
    packet->busy = 0;
    if (D_0064A308 != 1) return -15;
    if (D_0064A30C == 0) return -16;
    D_0064A310 = 0;
    D_008A03B8.callback = callback;
    int e = packet->e;
    int f = packet->f;
    D_008A0398.e = e;
    D_008A0398.f = f;
    D_008A0190.arg = arg;
    D_008A0398.a = packet->a;
    D_008A0398.b = packet->b;
    D_008A0398.c = packet->c;
    D_008A0398.d = packet->d;
    return func_0050B460(4, 0x12, 0x30, packet) == 0 ? 0 : -5;
}
