typedef int s32;

extern "C" s32 DisplayRText__rtext_ptrs_;

extern "C" void func_005C1628(s32 arg0);

extern "C" void func_003AE970(void) {
    func_005C1628(DisplayRText__rtext_ptrs_);
    DisplayRText__rtext_ptrs_ = 0;
}
