/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"

/* Inferred: sets up the network library's context block at D_00645288 and publishes it through
 * D_006452D4, the context pointer the other functions of this unit read (state at +0x2C, data at
 * +0x30). Each slot points at one of the library's static buffers; the data, +0x0, +0xC and +0x44
 * slots start empty, and the string buffer at D_0085118C is cleared before it is attached. */

struct Context { void *slot[0x13]; };
extern Context D_00645288;
extern Context *D_006452D4;
extern char D_006452D8[];
extern char D_006452DC[];
extern char D_00634F78[];
extern char D_00644F78[];
extern char D_00644F7A[];
extern char D_00644F7C[];
extern char D_00644F7E[];
extern char D_00644F80[];
extern char D_00645038[];
extern char D_00645090[];
extern char D_00645098[];
extern char D_00645180[];
extern char D_00645280[];
extern char D_00645188[];
extern char D_0085118C[];

extern "C" void func_004C4BB8(void) {
    D_0085118C[0] = 0;
    D_00645288.slot[18] = D_0085118C;
    D_00645288.slot[0] = 0;
    D_00645288.slot[1] = D_006452D8;
    D_00645288.slot[2] = D_006452DC;
    D_00645288.slot[3] = 0;
    D_00645288.slot[4] = D_00634F78;
    D_00645288.slot[5] = D_00644F78;
    D_00645288.slot[6] = D_00644F7A;
    D_00645288.slot[7] = D_00644F7C;
    D_00645288.slot[8] = D_00644F7E;
    D_00645288.slot[9] = D_00644F80;
    D_00645288.slot[10] = D_00645038;
    D_00645288.slot[11] = D_00645090;
    D_00645288.slot[12] = 0;
    D_00645288.slot[13] = D_00645098;
    D_00645288.slot[14] = D_00645180;
    D_00645288.slot[16] = D_00645188;
    D_00645288.slot[15] = D_00645280;
    D_00645288.slot[17] = 0;
    D_006452D4 = &D_00645288;
}
