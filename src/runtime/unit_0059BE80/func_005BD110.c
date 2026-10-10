/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): get_reg_addr (libgcc2.c, static).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* get_reg_addr: follow REG_SAVED_REG chains, then return cfa + offset or abort (func_005A2E68).
   In_reg_window is the no-window inline returning 0; its dead `udata = sub_udata` still shapes
   the loop. The game's frame_state has its 64-bit reg_or_offset[] at 0x20 and saved[] at 0x3FC
   (one 8-byte field more than the snapshot's frame.h before the array). */
typedef struct frame_state {
    void *cfa;
    void *eh_ptr;
    long long cfa_offset;
    long long args_size;
    long long unknown18;
    long long reg_or_offset[123];
    unsigned short cfa_reg;
    unsigned short retaddr_column;
    char saved[123];
} frame_state;
typedef int word_type;
extern void func_005A2E68(void) __attribute__((noreturn)); /* abort */

#define REG_SAVED_OFFSET 1
#define REG_SAVED_REG 2

static inline int in_reg_window(int reg __attribute__((__unused__)),
                                frame_state *udata __attribute__((__unused__)))
{
    return 0;
}

word_type *func_005BD110(unsigned reg, frame_state *udata, frame_state *sub_udata)
{
    while (udata->saved[reg] == REG_SAVED_REG) {
        reg = udata->reg_or_offset[reg];
        if (in_reg_window(reg, udata)) {
            udata = sub_udata;
            sub_udata = 0;
        }
    }
    if (udata->saved[reg] == REG_SAVED_OFFSET)
        return (word_type *)((char *)udata->cfa + udata->reg_or_offset[reg]);
    else
        func_005A2E68();
}
