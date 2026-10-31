/* Validates a typed message and sends it, payload plus a 2-byte {type, sub} header, either to the
 * default peer (id 0xFFFF, through the Id that func_00535D78 returns) or to the given id. The Id
 * is passed straight from the call: a named local would add a by-value copy. */
struct Entry { void *ptr; int size; };
struct Packet {
    Entry entries[8]; int size, count;
    void init() { count=0; size=0; }
    void add(void * const p, const int n) {
        if (count < 8) {
            entries[count].ptr=p;
            entries[count].size=n;
            size = size+n;
            count = count+1;
        }
    }
};
struct Id { unsigned int lo, hi; };
struct Header { unsigned char type, sub; };
struct Settings { char pad[0x6C]; unsigned short port; };
struct Api { char pad[0x48]; int (*send)(int, Id, unsigned short, Packet *); };
struct Api2 { char pad[0x44]; int (*send)(int, unsigned short, unsigned short, Packet *); };
struct Obj { char pad[0x104]; unsigned int id; char pad108[0x164 - 0x108]; int handle; };
extern Settings *D_0064B47C;
extern Api *D_0064B4BC;
extern Api2 *D_0064B4B8;
extern int D_0064B4F4;
extern "C" int func_00536590(int, unsigned short *);
extern "C" Id func_00535D78(Obj *);

extern "C" int func_00532080(signed char c, Obj *obj, unsigned int id, unsigned int type, unsigned int sub,
                             int len, void *data) {
    Packet packet;
    Header hdr;
    unsigned short x = 0;
    int r;
    if (type >= 6)
        return 0x17;
    if (sub >= 0x100)
        return 0x17;
    if (len <= 0)
        return 0x17;
    if (len >= 0x1FF)
        return 0x1F;
    if (data == 0)
        return 0x17;
    r = func_00536590(c, &x);
    if (r != 0)
        return r;
    packet.init();
    hdr.type = type;
    hdr.sub = sub;
    packet.add(data, len);
    packet.add(&hdr, 2);
    if (id == 0xFFFF) {
        if (D_0064B4BC->send(D_0064B4F4, func_00535D78(obj), D_0064B47C->port, &packet) != 0)
            return 0x25;
    } else if (id != obj->id) {
        if (D_0064B4B8->send(obj->handle, id, x, &packet) != 0)
            return 0x25;
    }
    return r;
}
