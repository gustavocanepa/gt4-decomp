/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef int s32;

extern "C" s32 *func_005BC6E8(void);

extern "C" s32 func_005C1700(void) {
    return *func_005BC6E8();
}
