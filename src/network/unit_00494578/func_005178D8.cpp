/* Project default compiler (strict aliasing): no `compiler:` marker. Under
   ee-gcc2.96-no-strict-aliasing the `p.id` store is scheduled before the `p.kind` store. */
struct Field { int a; int w, h; int c; unsigned int period; int active; int d; unsigned char flags; };
struct Sub { char pad[0x20]; Field *fields[64]; unsigned int offsets[64]; };
struct Record { int size, count; Sub sub; };
/* func_005174F0.cpp calls this `Self`; the fields it does not use are named here. */
struct Node {
    unsigned char id, active, b2, b3;
    int owner;
    int kind;
    char name[0x10];
    char *src, *dst;
    int bitsHi, bitsLo;
    int value, other;
    unsigned int sent;
    unsigned int *sentTo;
    unsigned int *times;
};
struct Obj { char pad[0x104]; int id; };
struct Out { char flags[8]; int count; int index; };
typedef int (*Callback)(int, unsigned int);
struct Global { char pad[0x118]; Obj *cur; char pad11c[0xdc]; Callback cb[1]; };
struct Context { char p[0x5c]; unsigned int time; };
/* Same header as func_00516950.cpp's Packet, with the short name of an update packet. */
struct Packet {
    unsigned char kind, index, active, b3, b2;
    char pad5;
    short owner;
    short id;
    char pada[2];
    int value, other;
    char name[0x1c];
};
extern Global D_00854038;
extern Record D_0085C330[16];
extern char D_00853C38[];
extern Context *D_0064B47C;
extern "C" Node *func_00515DD8(unsigned int);
extern "C" void func_005173E8(Out *, unsigned int);
extern "C" int func_00536568(int);
extern "C" char *func_005A609C(char *, const char *);
extern "C" void *func_005A4724(void *, const void *, unsigned int);
/* func_00517798.cpp declares the next one void with an int second argument; here the object
   pointer is passed and the status is read. */
extern "C" int func_00519A20(signed char, Obj *, int, int, int, void *, void *);
extern "C" int func_00532588(Obj *, int, int, int, void *);

enum { HEADER_SIZE = 0x24, PACKET_MAX = 0x1fe };

extern "C" int func_005178D8(int target, unsigned int id) {
    Packet p;
    Out extra;
    Node *n = func_00515DD8(id);
    if (n == 0) return 10;
    Global *g = &D_00854038;
    Obj *cur = g->cur;
    if (cur == 0) return 8;
    if (n->active) {
        if (target == -1) func_005173E8(&extra, id);
        else if (g->cb[n->active](target, id) == 0) return 0;
    }
    Record *rec = D_0085C330 + n->id;
    if (rec == 0) return 10;
    if (n->owner != -1 && n->owner != cur->id) return 8;
    p.kind = func_00536568(n->kind);
    p.id = id;
    p.owner = n->owner;
    p.index = n->id;
    p.active = n->active;
    p.b2 = n->b2;
    p.b3 = n->b3;
    p.value = n->value;
    p.other = n->other;
    func_005A609C(p.name, n->name);
    char *dst = D_00853C38;
    func_005A4724(dst, &p, HEADER_SIZE);
    int len = HEADER_SIZE;
    for (int i = 0; i < rec->count; i++) {
        /* One scratch pointer: first the field's descriptor, then its bytes in the node.
           (A separate `Field *` gives the descriptor $v1 and the table base $a1.) */
        void *q = rec->sub.fields[i];
        if (q == 0) return 10;
        int size = ((Field *)q)->w * ((Field *)q)->h;
        if (PACKET_MAX - len < size) break;
        q = n->src + rec->sub.offsets[i];
        func_005A4724(D_00853C38 + len, q, size);
        len += size;
        n->times[i] = D_0064B47C->time;
    }
    int result;
    if (n->active && target == -1) result = func_00519A20(0x50, cur, 0, 4, len, D_00853C38, &extra);
    else result = func_00532588(cur, target, 4, len, D_00853C38);
    if (target == -1) {
        n->sent = D_0064B47C->time;
        func_005A4724(n->dst, n->src, rec->size);
    } else if (result == 0) {
        n->sentTo[target] = D_0064B47C->time;
    }
    return 0;
}
