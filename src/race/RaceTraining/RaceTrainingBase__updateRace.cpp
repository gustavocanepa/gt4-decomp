/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct E0 { s16 delta; s16 index; void *(*fn)(void *); };
struct E1 { s16 delta; s16 index; void *(*fn)(void *, s32); };
struct E3 { s16 delta; s16 index; void *(*fn)(void *, s32, s32, s32); };
struct EV0 { s16 delta; s16 index; void (*fn)(void *); };
struct EV1 { s16 delta; s16 index; void (*fn)(void *, s32); };
struct EV3 { s16 delta; s16 index; void (*fn)(void *, s32, s32, s32); };
struct VObj { char *vtbl; };
struct Self {
    char pad0[0x64];
    char *vtbl;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    char pad74[0xD44 - 0x74];
    s32 unkD44;
    char padD48[0x125F8 - 0xD48];
    s32 unk125F8;
    s32 unk125FC;
};
struct Self2 { char pad[0xE420]; VObj *unkE420; };
extern "C" char RaceDisplay__tf[], RaceDisplayBase__tf[];
extern "C" void *__dynamic_cast_2(void *, void *, int, void *, void *, void *);
extern "C" void RacePS2Base__updateRace(void *);

typedef void *(*Fn0)(void *);
typedef void *(*Fn1)(void *, s32);
typedef void *(*Fn3)(void *, s32, s32, s32);

extern "C" void RaceTrainingBase__updateRace(Self *self) {
    if (self->unk125F8 != 0) {
        VObj *o = ((Self2 *)self)->unkE420;
        if (o != 0) {
            char *vt = o->vtbl;
            VObj *p = (VObj *)__dynamic_cast_2(*(void **)(vt + 4), RaceDisplay__tf, 0, (char *)o + *(s16 *)vt, RaceDisplayBase__tf, o);
            if (p != 0) {
                EV1 *e = (EV1 *)(p->vtbl + 0x88);
                e->fn((char *)p + e->delta, self->unk125FC != 0);
                EV1 *e2 = (EV1 *)(p->vtbl + 0x1C0);
                e2->fn((char *)p + e2->delta, 2);
            }
        }
        if (self->unk125FC == 0) {
            E1 *e1 = (E1 *)(self->vtbl + 0xD0);
            VObj *q = (VObj *)e1->fn((char *)self + e1->delta, 0);
            E0 *e0 = (E0 *)(q->vtbl + 0x158);
            if (e0->fn((char *)q + e0->delta) == 0) {
                EV3 *e3 = (EV3 *)(q->vtbl + 0xB0);
                e3->fn((char *)q + e3->delta, self->unk6C, self->unk70, self->unkD44 == 0);
                return;
            }
            EV0 * e0_2 = (EV0 *)(self->vtbl + 0x178);
            e0_2->fn((char *)self + e0_2->delta);
            EV0 * e0_2_2 = (EV0 *)(self->vtbl + 0x180);
            e0_2_2->fn((char *)self + e0_2_2->delta);
            self->unk125FC = 1;
        }
    }
    RacePS2Base__updateRace(self);
}
