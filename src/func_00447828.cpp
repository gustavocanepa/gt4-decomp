typedef unsigned char u8;
struct Rec { char pad0[0x8C]; u8 v8C; u8 v8D; u8 v8E; u8 v8F; u8 v90; u8 v91; };
extern "C" u8 func_00447828(Rec *r, unsigned int index) {
    if (index >= 6) return 0;
    switch (index) {
    case 0: return r->v91;
    case 1: return r->v8C;
    case 2: return r->v8D;
    case 3: return r->v8E;
    case 4: return r->v8F;
    case 5: return r->v90;
    }
    return 0;
}
