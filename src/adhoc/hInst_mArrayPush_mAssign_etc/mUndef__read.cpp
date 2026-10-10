typedef int s32;

extern "C" void HScopePath__read(s32 arg0);

extern "C" void mUndef__read(s32 arg0) {
    HScopePath__read(arg0 + 8);
}
