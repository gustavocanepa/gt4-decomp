/* compiler: ee-gcc2.96-nogcse */
/* Walks the records of table id (row id & 0xff, list 0x40 or 0x50 by the 0x200 type bit): each next
   record is checked against the table, and its x14 field is lowered to the value computed from the
   previous record when smaller (func_004BCC50). 0x80001E6E when a record is missing or rejected. */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
struct Obj { int pad0; int *p4; int pad8; u32 *pC; char pad10[0x14]; char *p24; };
struct Info { u16 id; char pad2[0x12]; u16 x14; char pad16[0xA]; };
extern "C" int func_004BEC88(Obj *, int) throw();
extern "C" int func_004BC978(char *, u16, Info *, int) throw();
extern "C" void func_004BC818(u16 *, u8 *, int) throw();
extern "C" u32 func_004BC758(char *, u16, Info *) throw();
extern "C" void func_004BCC50(Obj *, Info *, u16) throw();
extern "C" int func_004BE980(Obj *self, u16 id) {
    Info prev, info;
    if (*self->p4 == 0) func_004BEC88(self, 1);
    int type = id & 0xff00;
    char *base;
    int index;
    u16 count;
    if (type == 0x200) {
        base = self->p24;
        index = id & 0xff;
        count = *(u16 *)(base + index * 16 + 0x48);
    } else {
        base = self->p24;
        index = id & 0xff;
        count = *(u16 *)(base + index * 16 + 0x58);
    }
    u8 *data;
    if (type == 0x200) data = *(u8 **)(base + index * 16 + 0x40) + 8;
    else data = *(u8 **)(base + index * 16 + 0x50) + 8;
    prev.id = 0;
    if (func_004BC978(base, id, &prev, 0) <= 0) return 0x80001e6e;
    Info *pi;
    int i = 1;
    if (i < count) {
        pi = &info;
        for (; i < count; i++, data += 6) {
            func_004BC818(&info.id, data, 2);
            if (info.id == 0 || func_004BC978(self->p24, id, pi, 1) <= 0) return 0x80001e6e;
            u32 v = func_004BC758(self->p24, id, &prev);
            if (v < info.x14) {
                info.x14 = v;
                func_004BCC50(self, &info, id);
            }
            prev = info;
        }
    }
    return 0;
}
