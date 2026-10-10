typedef int s32;

extern "C" void ADHOC__PoolAllocator__dump(s32 a0, s32 a1);

extern "C" void ADHOC__PoolAllocator__Report(s32 arg0, s32 arg1) {
    ADHOC__PoolAllocator__dump(arg1, arg0);
}
