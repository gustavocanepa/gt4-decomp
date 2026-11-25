/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Entry {
    char pad00[0x11];
    u8 length;
    char pad12[0x1C - 0x12];
};

struct State {
    Entry entries[42];
    u8 count;
    u8 total;
    char pad49a[6];
    int slots[42];
    u16 index;
    char pad54a[2];
    Entry *cache;
    u16 used;
    u16 data[58];
};

struct Context {
    char pad[0x28];
    u16 *names;
    int *type;
    State *state;
};

extern "C" Context *D_006452D4;
extern "C" void func_004BC740(char *, char *);
extern "C" int func_004C5DC8(Context *, u16 *, int, Entry **, Entry *);
extern "C" int func_004C8718(Context *, u16 *, int, u16 *, Entry *);
extern "C" void func_004C8C38(Context *, int);
extern "C" u16 *func_004C8E38(u16 *, u16 *, int);
extern "C" void func_004C90F0(char *, u16 *);
extern "C" int func_004C9410(char *);

extern "C" int func_004BAA70(int index, int item, char *buffer, int size) {
    struct {
        u16 wide[0x40];
        char text[0x80];
    } stack;
    Entry *entry;

    if ((u32)size > 0x7fff) return 0x8000154D;
    if (index < 0) return 0x8000194D;
    if (buffer && size > 0) *buffer = 0;
    if (*D_006452D4->type != 0x65) return 0x8000014D;
    State *state = D_006452D4->state;
    if (index >= state->count) return 0x8000134D;
    u16 expected = state->count - index - 1;
    int selected = state->index;
    if (selected == 0x7fff || (selected & 0x7fff) != expected || (selected & 0x8000)) {
        if (D_006452D4->state->index != 0x7fff) {
            int p = (int)D_006452D4->state->cache;
            if (p) {
                func_004C8C38(D_006452D4, p);
                D_006452D4->state->cache = 0;
                D_006452D4->state->used = 0;
                D_006452D4->state->index = 0x7fff;
            }
        }
        int offset = expected * 4 + 0x4a0;
        int p = *(int *)((char *)D_006452D4->state + offset);
        if (p) {
            func_004C8C38(D_006452D4, p);
            *(int *)((char *)D_006452D4->state + offset) = 0;
        }
        int i = 0;
        /* one counter: characters left before the entry, then the cached item count */
        int count = state->total;
        for (int j = state->count - 1; j >= 0; j--) {
            entry = &state->entries[j];
            count -= entry->length;
            if (i++ == index) {
                func_004C8E38(D_006452D4->state->data, D_006452D4->names + count, entry->length);
                D_006452D4->state->data[entry->length] = 0;
                break;
            }
        }
        entry = 0;
        count = func_004C5DC8(D_006452D4, D_006452D4->state->data, 0, &entry, &state->entries[expected]);
        if (count < 0) return count;
        if (entry == 0) return 0x8000034D;
        D_006452D4->state->cache = entry;
        D_006452D4->state->used = count;
        D_006452D4->state->index = expected;
    }
    if (item < 0) return D_006452D4->state->used;
    if (item >= D_006452D4->state->used) return 0;
    if (func_004C8718(D_006452D4, stack.wide, 0x74, D_006452D4->state->data, D_006452D4->state->cache + item) < 0) {
        int p = (int)D_006452D4->state->cache;
        if (p) {
            func_004C8C38(D_006452D4, p);
            D_006452D4->state->cache = 0;
        }
        D_006452D4->state->index = 0x7fff;
        int offset = expected * 4 + 0x4a0;
        D_006452D4->state->used = 0;
        p = *(int *)((char *)D_006452D4->state + offset);
        if (p) {
            func_004C8C38(D_006452D4, p);
            *(int *)((char *)D_006452D4->state + offset) = 0;
        }
        return 0x8000474D;
    }
    func_004C90F0(stack.text, stack.wide);
    int length = func_004C9410(stack.text) + 1;
    if (buffer) {
        if (size >= length) {
            func_004BC740(buffer, stack.text);
            return length;
        }
        return 0x8000104D;
    }
    return length;
}
