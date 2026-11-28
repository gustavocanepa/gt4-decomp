/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Desc { u16 index; char pad[0x1E]; };
struct Entry { u8 *data; char pad4[4]; u16 count; char padA[6]; };
struct Obj { char pad[0x24]; char *table; };
extern "C" void func_004BC818(u16 *, u8 *, int);
extern "C" int func_004BC978(char *, int, Desc *, int);
extern "C" int func_004BDAE8(char *, int, Desc *, int, const u8 **, int *);
extern "C" int func_004C92D8(const u8 *, const u8 *, u32);
extern "C" int func_004BD9A8(const u8 *, const u8 *, int, int, int);
extern "C" int func_004BDB48(Obj *self, u16 id, const u8 *key, int keyLength, int mode, int start, u16 *first, int *exact) {
    Desc d;
    const u8 *name;
    int length;
    int count;
    int found;
    int total;
    int i;
    u8 *p;
    int off;
    int kind = id & 0xFF00;
    Desc *pd = &d;
    *first = 0;
    name = 0;
    length = 0;
    *exact = 0;
    count = 0;
    found = 0;
    if (kind == 0x200) {
        char *table = self->table;
        total = ((Entry *)(table + (id & 0xFF) * 16 + 0x40))->count;
    } else {
        char *table = self->table;
        total = ((Entry *)(table + (id & 0xFF) * 16 + 0x50))->count;
    }
    off = start * 6;
    if (kind == 0x200) {
        p = ((Entry *)(self->table + (id & 0xFF) * 16 + 0x40))->data + off + mode;
    } else {
        p = ((Entry *)(self->table + (id & 0xFF) * 16 + 0x50))->data + off + mode;
    }
    for (i = start; i < total; i++) {
        int r;
        func_004BC818(&d.index, p, 2);
        p += 6;
        if (func_004BC978(self->table, id, pd, 0) <= 0) return 0x80001E7C;
        func_004BDAE8(self->table, id, pd, mode, &name, &length);
        if (length >= keyLength) {
            if (mode == 0) {
                r = func_004C92D8(key, name, keyLength);
            } else {
                r = func_004BD9A8(key, name, keyLength, length, keyLength);
            }
            if (r == 0) {
                count++;
                if (!found) {
                    *first = i;
                    found = 1;
                }
                if (keyLength == length) (*exact)++;
            } else if (r < 0) {
                break;
            }
        } else if (found) {
            break;
        }
    }
    return count;
}
