/* func_00519E08 (inferred): receives a shared-data block from a peer. The header names an entry
 * id and one of 16 field layouts (SyncRecord); the field data follows the header. A block whose
 * owner is the local session and whose name already exists only reports its size; otherwise a
 * free entry id is taken. An inactive entry is created (0x44-byte SyncEntry plus its data, copy,
 * per-peer and per-field buffers; everything is released and the entry table restored if one
 * allocation fails), then the header fields and every field's bytes are copied in with a time
 * stamp, and the created/updated callback runs. Returns the number of bytes consumed (header plus
 * field data), sizeof(SyncHeader) when nothing was stored, -1 for a block that is not for us. */
typedef unsigned int u32;

typedef struct SyncField {
    int type;
    int width, height;
} SyncField;

typedef struct SyncRecord {
    int size;                   /* bytes of one entry's data */
    int count;                  /* fields in use */
    char pad8[0x20];
    SyncField *fields[64];
    int offsets[64];            /* offset of each field in the entry's data */
} SyncRecord;

typedef struct SyncEntry {
    unsigned char layout, attr1, attr2, attr3;
    int value;
    int owner;
    char name[16];
    char *data;
    char *previous;
    int pad24, pad28;
    int param0, param1;
    int stamp;
    int *peerFlags;
    int *fieldStamps;
    int pad40;
} SyncEntry;

typedef struct SyncHeader {
    unsigned char owner, layout, attr1, attr3, attr2;
    short value;
    unsigned short id;
    int param0, param1;
    char name[16];
} SyncHeader;

typedef struct Session {
    char pad[0x104];
    int id;
    char pad108[0x150 - 0x108];
    int peerCount;
} Session;

typedef struct SyncState {
    char pad[0x104];
    int entryCount;             /* highest entry id in use + 1 */
    char pad108[0x118 - 0x108];
    Session *session;
    char pad11C[0x82F8 - 0x11C];
    SyncRecord records[16];
    char padA578[0xA638 - 0xA578];
    SyncEntry *entries[0x1000];
    signed char states[0x1000];
} SyncState;

typedef struct Clock {
    char pad[0x5C];
    int tick;
} Clock;

enum { ENTRY_ACTIVE = 2 };

extern SyncState *D_0064B4B4;
extern Clock *D_0064B47C;
SyncEntry *func_00515DD8(unsigned id);
int func_00516348(const char *name, Session *session, int owner);
int func_00516430(void);
void func_00515FC0(int owner, int id);
void func_00516030(int owner, int id, unsigned reason);
char *func_005316F8(unsigned size);
void func_00531738(void *pointer);
void *func_005A48D8(void *dst, int value, unsigned size);
void *func_005A4724(void *dst, const void *src, unsigned size);
char *func_005A609C(char *dst, const char *src);

int func_00519E08(Session *self, int unused, u32 from, SyncHeader *h) {
    SyncState *g = D_0064B4B4;
    int result = -1;
    SyncEntry *entry = 0;
    int created = 0;
    int total;
    int i;
    signed char state;
    SyncRecord *rec;
    unsigned id;
    const char *src;
    SyncField *field;

    if (self != g->session) return result;
    if (from >= 64) return result;
    if (!self) return result;
    rec = &g->records[h->layout];
    id = h->id;
    if (h->owner == self->id) {
        if (g->states[id] == ENTRY_ACTIVE) goto existing;
        entry = 0; /* cleared again before the lookup, as the original does */
        if (func_00516348(h->name, self, h->owner) < 0) {
            id = func_00516430();
            if ((int)id >= 0) entry = func_00515DD8(id);
        } else {
            total = sizeof(SyncHeader);
            for (i = 0; i < rec->count; i++) {
                field = rec->fields[i];
                total += field->width * field->height;
            }
            return total;
        }
    }
    state = D_0064B4B4->states[id];
    if (state != ENTRY_ACTIVE) {
        int entryCount = D_0064B4B4->entryCount;
        entry = (SyncEntry *)func_005316F8(sizeof(SyncEntry));
        if (!entry) return sizeof(SyncHeader);
        D_0064B4B4->states[id] = ENTRY_ACTIVE;
        D_0064B4B4->entries[id] = entry;
        if (D_0064B4B4->entryCount < (int)id + 1) D_0064B4B4->entryCount = id + 1;
        entry->owner = h->owner;
        entry->param0 = h->param0;
        entry->param1 = h->param1;
        entry->stamp = 0;
        entry->data = func_005316F8(rec->size);
        entry->previous = func_005316F8(rec->size);
        entry->peerFlags = (int *)func_005316F8(self->peerCount * 4);
        entry->fieldStamps = (int *)func_005316F8(rec->count * 4);
        if (!entry->data || !entry->previous || !entry->peerFlags || !entry->fieldStamps) {
            func_00531738(&entry->data);
            func_00531738(&entry->previous);
            func_00531738(&entry->peerFlags);
            func_00531738(&entry->fieldStamps);
            func_00531738(&entry);
            D_0064B4B4->entryCount = entryCount;
            D_0064B4B4->entries[id] = 0;
            D_0064B4B4->states[id] = state;
            return sizeof(SyncHeader);
        }
        created = 1;
        func_005A48D8(entry->peerFlags, 0, self->peerCount * 4);
        func_005A48D8(entry->fieldStamps, 0, rec->count * 4);
    } else {
    existing:
        entry = func_00515DD8(id);
    }
    if (!entry) return sizeof(SyncHeader);

    total = sizeof(SyncHeader);
    entry->value = h->value;
    entry->layout = h->layout;
    func_005A609C(entry->name, h->name);
    entry->attr1 = h->attr1;
    entry->attr2 = h->attr2;
    entry->attr3 = h->attr3;
    src = (const char *)h + total;
    for (i = 0; i < rec->count; i++) {
        int n;
        field = rec->fields[i];
        n = field->width * field->height;
        if (entry) func_005A4724(entry->data + rec->offsets[i], src, n);
        src += n;
        total += n;
        entry->fieldStamps[i] = D_0064B47C->tick;
    }
    func_005A4724(entry->previous, entry->data, rec->size);
    entry->stamp = D_0064B47C->tick;
    if (created) func_00515FC0(entry->owner, id);
    else func_00516030(entry->owner, id, -1);
    return total;
}
