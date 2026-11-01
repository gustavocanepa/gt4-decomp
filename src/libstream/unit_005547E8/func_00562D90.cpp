/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Restores the DMA/IPU state func_00562E90 saved: restarts channel 0x1000B000 when it had work,
   writes IPU_BP back (func_00562D58), then restarts 0x1000B400 rewound by the FIFO's unread
   quadwords (bits 8-11 and 16-17 of the saved IPU_BP). */
typedef unsigned int u32;
extern "C" void func_00562D58(u32 x);
#define REG(x) (*(volatile u32 *)(x))
#define SYNC() __asm__ volatile("sync")
struct Saved { u32 madr9, tadr9, qwc9, chcr9, madr8, qwc8, chcr8, bp, ctrl; };
extern "C" void func_00562D90(Saved *s) {
    u32 bp = s->bp;
    if (s->madr8 && s->qwc8) {
        REG(0x1000b010) = s->madr8; SYNC();
        REG(0x1000b020) = s->qwc8; SYNC();
        REG(0x1000b000) = s->chcr8 | 0x100; SYNC();
    }
    func_00562D58(bp);
    u32 n = ((bp >> 8) & 0xF) + ((bp >> 16) & 3);
    u32 qwc = s->qwc9 + n;
    u32 madr = s->madr9 - n * 16;
    if (qwc && madr) {
        REG(0x1000b410) = madr; SYNC();
        REG(0x1000b430) = s->tadr9; SYNC();
        REG(0x1000b420) = qwc; SYNC();
        REG(0x1000b400) = s->chcr9 | 0x100; SYNC();
    }
}
