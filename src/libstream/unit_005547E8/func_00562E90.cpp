/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Saves the scratchpad DMA and IPU state into s: stops channel 0x1000B400 (see
   func_00563028) and records MADR/TADR/QWC/CHCR, waits for the IPU input FIFO
   (IPU_CTRL bits 4-7) to drain, stops 0x1000B000 and records it, IPU_BP, IPU_CTRL. */
typedef unsigned int u32;
extern "C" int func_005B72A8(void);
extern "C" int func_005B72F8(void);
#define REG(x) (*(volatile u32 *)(x))
#define SYNC() __asm__ volatile("sync")
struct Saved { u32 madr9, tadr9, qwc9, chcr9, madr8, qwc8, chcr8, bp, ctrl; };
extern "C" void func_00562E90(Saved *s) {
 {
  u32 saved;
  func_005B72A8();
  volatile u32 *chcr = (volatile u32 *)0x1000b400;
  saved = REG(0x1000f520);
  REG(0x1000f590) = saved | 0x10000; REG(0x1000f590); SYNC();
  *chcr &= ~0x100; (void)*chcr; SYNC();
  REG(0x1000f590) = saved; REG(0x1000f590); SYNC();
  func_005B72F8();
  s->madr9 = REG(0x1000b410);
  s->tadr9 = REG(0x1000b430);
  s->qwc9 = REG(0x1000b420);
  s->chcr9 = *chcr;
 }
 while ((REG(0x10002010) >> 4) & 0xF) ;
 {
  u32 saved;
  func_005B72A8();
  saved = REG(0x1000f520);
  volatile u32 *chcr = (volatile u32 *)0x1000b000;
  REG(0x1000f590) = saved | 0x10000; REG(0x1000f590); SYNC();
  *chcr &= ~0x100; (void)*chcr; SYNC();
  REG(0x1000f590) = saved; REG(0x1000f590); SYNC();
  func_005B72F8();
  s->madr8 = REG(0x1000b010);
  s->qwc8 = REG(0x1000b020);
  s->chcr8 = *chcr;
  s->bp = REG(0x10002020);
  s->ctrl = REG(0x10002010);
 }
}
