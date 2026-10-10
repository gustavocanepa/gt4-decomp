typedef int s32;

extern "C" void func_003AE970(void);
extern "C" void *func_005C15B0(s32 size);
extern "C" void func_005A48D8(void *p, s32 c, s32 n);
extern "C" s32 *DisplayRText__rtext_ptrs_;

extern "C" void func_003AE918(s32 n) {
    func_003AE970();
    DisplayRText__rtext_ptrs_ = (s32 *)func_005C15B0(n * 4);
    func_005A48D8(DisplayRText__rtext_ptrs_, 0, n * 4);
}
