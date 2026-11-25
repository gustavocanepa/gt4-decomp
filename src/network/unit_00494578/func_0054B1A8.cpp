/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Stamp {
    u8 reserved;
    u8 second;
    u8 minute;
    u8 hour;
    u8 day;
    u8 month;
    u16 year;
};

/* the memory card library's directory entry */
struct CardEntry {
    Stamp created;
    Stamp modified;
    u32 size;
    u16 attributes;
    u16 reserved1;
    u32 reserved2;
    u32 application;
    char name[32];
};

/* the entry handed to the caller */
struct Entry {
    Stamp created;
    Stamp modified;
    u32 size;
    u16 attributes;
    u16 pad16;
    u32 application;
    char name[36];
};

struct Slot {
    char path[0x40];
    int position;
    int listed;
    int pad48;
    int port;
    int slot;
};

extern char *D_0064C3E4;
extern int D_0064C400;
extern CardEntry D_0086DE00[32];
extern "C" int func_0054A370(int) throw();
extern "C" int func_0054A8A8(int, int) throw() __attribute__((const));
extern "C" void func_00549858(char *, int, int) throw();
extern "C" int func_00561F68(int, int, const char *, int, int, CardEntry *);
extern "C" void func_00576788(char *);
extern "C" void func_005767C0(char *);
extern "C" int func_0057F238(const char *, const char *);
extern "C" char *func_005A609C(char *, const char *);
extern "C" void *func_005A48D8(void *, int, u32);

extern "C" int func_0054B1A8(int id, const char *path, Entry *out, int start, u32 count) {
    int status = 1;
    func_00576788(D_0064C3E4 + 0x34);
    if (func_0054A370(id)) {
        int q = id / 4;
        int r = id - q * 4;
        int result;
        int i;
        int offset = (q * 111 + r * 27) * 4;
        Slot *slot = (Slot *)((char *)(offset + (int)D_0064C3E4) + 0x78);
        status = 8;
        slot->listed = 0;
        if (D_0064C400 != id) {
            D_0064C400 = id;
            slot->position = 0x7FFFFFFF;
        }
        if (func_0057F238(slot->path, path) != 0) {
            func_005A609C(slot->path, path);
            slot->position = 0x7FFFFFFF;
        }
        int skip = start - slot->position;
        int first = start == 0;
        if (skip < 0) {
            slot->position = 0;
            skip = start;
            first = 1;
        }
        while (skip != 0) {
            int n = skip < 0x21 ? skip : 0x20;
            result = func_00561F68(slot->port, slot->slot, path, first ^ 1, n, D_0086DE00);
            first = 0;
            skip -= result;
            if (result != n) goto done;
            slot->position += result;
        }
        /* a statement between the two loops: without it the skip loop's entry test jumps
           straight to this loop's top label and loop.c ignores the loop */
        result = 0;
        do {
            func_005A48D8(D_0086DE00, 0, sizeof(D_0086DE00));
            u32 n = count < 0x21 ? count : 0x20;
            result = func_00561F68(slot->port, slot->slot, path, first ^ 1, n, D_0086DE00);
            if (result < 0) goto done;
            CardEntry *in = D_0086DE00;
            for (i = 0; i < result; i++) {
                func_005A48D8(out, 0, sizeof(Entry));
                out->created.second = in->created.second;
                out->created.minute = in->created.minute;
                out->created.hour = in->created.hour;
                out->created.day = in->created.day;
                out->created.month = in->created.month;
                out->created.year = in->created.year;
                out->modified.second = in->modified.second;
                out->modified.minute = in->modified.minute;
                out->modified.hour = in->modified.hour;
                out->modified.day = in->modified.day;
                out->modified.month = in->modified.month;
                out->modified.year = in->modified.year;
                out->size = in->size;
                out->attributes = in->attributes;
                out->application = in->application;
                func_005A609C(out->name, in->name);
                in++;
                out++;
                slot->listed++;
                slot->position++;
            }
            first = 0;
            count -= n;
            if (result != (int)n) break;
        } while (count != 0);
        for (i = 0; i < count; i++) {
            func_005A48D8(out, 0, sizeof(Entry));
            out++;
        }
    done:
        if (result >= 0) status = 0;
        status = func_0054A8A8(status, result);
        func_00549858((char *)slot, result, status);
    }
    func_005767C0(D_0064C3E4 + 0x34);
    return status;
}
