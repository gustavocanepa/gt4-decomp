typedef unsigned char u8;
struct Rec { char pad0[0x80]; u8 v80; u8 v81; u8 v82; u8 v83; u8 v84; };
extern "C" u8 func_00447778(Rec *r, int index) {
    if (index < 1 || index > 5) return 0;
    switch (index) {
    case 1: return r->v80;
    case 2: return r->v81;
    case 3: return r->v82;
    case 4: return r->v83;
    case 5: return r->v84;
    }
    return 0;
}
