#include "types.h"
#include "gt4/SparkParticle.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GT4Model__BinStreamReader__read8u(s32);                             /* extern */
s32 GT4Model__BinStreamReader__read8(s32);                             /* extern */
f32 GT4Model__BinStreamReader__readFloat(s32);                             /* extern */

void SparkParticle__read(struct SparkParticle *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;
    s32 temp_v0;

    arg0->unkC = GT4Model__BinStreamReader__readFloat(arg1);
    arg0->unk10 = GT4Model__BinStreamReader__readFloat(arg1);
    temp_f0 = GT4Model__BinStreamReader__readFloat(arg1);
    arg0->unk18 = 0x1.0000000000000p+0f;
    arg0->unk14 = temp_f0;
    arg0->unk1C = (f32) ((f32) GT4Model__BinStreamReader__read8(arg1) * 0x1.0000000000000p-2f);
    arg0->unk20 = (f32) ((f32) GT4Model__BinStreamReader__read8(arg1) * 0x1.0000000000000p-2f);
    arg0->unk24 = (f32) ((f32) GT4Model__BinStreamReader__read8(arg1) * 0x1.0000000000000p-2f);
    arg0->unk2C = (f32) ((f32) GT4Model__BinStreamReader__read8u(arg1) * 0x1.47ae140000000p-6f * 0x1.0000000000000p-8f);
    temp_v0 = GT4Model__BinStreamReader__read8u(arg1);
    arg0->unk28 = 0x1.0000000000000p+0f;
    arg0->unk34 = 0x1.0000000000000p+0f;
    arg0->unk48 = 0x80808080;
    arg0->unk8 = 0;
    arg0->unk30 = 0;
    arg0->unk38 = 0;
    arg0->unk3C = 0;
    arg0->unk4C = 0;
    temp_f0_2 = 0x1.0000000000000p+1f * (f32) temp_v0 * 0x1.0000000000000p-8f;
    arg0->unk50 = 0;
    arg0->unk54 = 0;
    arg0->unkA = 0;
    arg0->unk40 = temp_f0_2;
    arg0->unk44 = temp_f0_2;
}
