typedef short s16;
struct Rec { char pad0[0x2E]; s16 v2E; s16 v30; s16 v32; s16 v34; s16 v36; };
extern "C" s16 func_004477D0(Rec *r, int index) {
    if (index < 1 || index > 5) return 0;
    switch (index) {
    case 1: return r->v2E;
    case 2: return r->v30;
    case 3: return r->v32;
    case 4: return r->v34;
    case 5: return r->v36;
    }
    return 0;
}
