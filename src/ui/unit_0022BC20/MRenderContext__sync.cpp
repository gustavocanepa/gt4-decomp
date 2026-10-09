typedef int s32;

extern "C" void MUpdateContext__Sync(s32 arg0, s32 arg1, s32 arg2);

extern "C" void MRenderContext__sync(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    MUpdateContext__Sync(arg0, arg2, arg3);
}
