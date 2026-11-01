/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Stops the scratchpad DMA channels 0x1000B400 and 0x1000B000: with interrupts
   off and the DMAC suspended through D_ENABLEW, clears CHCR.STR, then zeroes the
   channel's MADR/QWC/TADR. Each register write is read back and followed by sync. */
typedef unsigned int u32;
extern "C" int func_005B72A8(void);
extern "C" int func_005B72F8(void);
#define REG(x) (*(volatile u32 *)(x))
#define SYNC() __asm__ volatile("sync")
extern "C" void func_00563028(void) {
 {
  u32 saved;
  func_005B72A8();
  volatile u32 *chcr = (volatile u32 *)0x1000b400;
  saved = REG(0x1000f520);
  REG(0x1000f590) = saved | 0x10000; REG(0x1000f590); SYNC();
  *chcr &= ~0x100; (void)*chcr; SYNC();
  REG(0x1000f590) = saved; REG(0x1000f590); SYNC();
  func_005B72F8();
 }
 REG(0x1000b420) = 0; SYNC();
 REG(0x1000b410) = 0; SYNC();
 REG(0x1000b430) = 0; SYNC();
 {
  u32 saved;
  func_005B72A8();
  saved = REG(0x1000f520);
  volatile u32 *chcr = (volatile u32 *)0x1000b000;
  REG(0x1000f590) = saved | 0x10000; REG(0x1000f590); SYNC();
  *chcr &= ~0x100; (void)*chcr; SYNC();
  REG(0x1000f590) = saved; REG(0x1000f590); SYNC();
  func_005B72F8();
 }
 REG(0x1000b020) = 0; SYNC();
 REG(0x1000b010) = 0; SYNC();
}
