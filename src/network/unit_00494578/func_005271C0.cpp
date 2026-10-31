/* Counts the peers by state; when one peer is selected and none is busy, notifies the selection and
 * sends each ready peer (state 3 or 4) a 2-byte command through func_00527488 (flags 0xF000).
 * The loop tests self->count directly (the hoisted load gives retail's copy), and the Packet keeps
 * size/count in memory so loop.c does not hoist the constants. */
struct Item { int state; char pad4[0x18]; int pending; char pad20[0x24]; };
struct Self;
typedef void (*SelectFn)(int, int, int, int);
typedef void (*DoneFn)(int, int, int);
struct Self {
    char pad0[0x84]; Item *items; int active; unsigned char current; char pad8d[0xF];
    unsigned short count; char pad9e[0x32]; SelectFn onSelect; char padd4[8]; DoneFn onDone; char pade0[8]; int ctx;
};
struct Entry { void *ptr; int size; };
struct Packet {
    Entry entries[8]; int size, count;
    Packet() { count=0; size=0; }
    void add(void * const p, const int n) {
        entries[count].ptr=p;
        entries[count].size=n;
        size = size+n;
        count = count+1;
    }
};
extern "C" int func_00525648(int,int) throw() __attribute__((const));
extern "C" int func_00527488(Self *, Item *, unsigned short, Packet *) throw();
extern "C" int func_00524DD0(Self *, int);

extern "C" int func_005271C0(Self *self) {
    int state = 0;
    unsigned short selected = 0xFFFE;
    int ready = 0;
    int busy = 0;
    unsigned short i;
    for (i = 0; i < self->count; i++) {
        switch (self->items[i].state) {
        case 1:
        case 2:
            busy++;
            break;
        case 3:
        case 4:
            ready++;
            break;
        case 5:
            state = 5;
            selected = i;
            break;
        case 0:
        case 6:
        case 7:
            break;
        }
    }
    if (state != 5 || busy != 0 || ready == 0)
        return 0;
    self->items[selected].state = 6;
    if (self->onSelect == 0)
        return 3;
    self->onSelect(selected, ready + 1, 0, self->ctx);
    Item *item = self->items;
    for (i = 0; i < self->count; i++, item++) {
        if (item->state == 3 || item->state == 4) {
            Packet packet;
            short value = func_00525648(1, 2);
            packet.add(&value, 2);
            int r = func_00527488(self, item, 0xF000, &packet);
            if (r != 0)
                return r;
            if (item->pending) {
                item->pending = 0;
                self->onDone(i, 0, self->ctx);
            }
        }
    }
    if (self->active && self->current != 0xFF) {
        func_00524DD0(self, self->current);
        self->current = 0xFF;
    }
    return 0;
}
