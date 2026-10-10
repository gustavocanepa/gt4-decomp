struct Strings { char pad[0x138]; const char *one; const char *many; };
extern Strings *DisplayRText__rtext_ptrs_;
extern const char D_006A37E8[];
struct Label { int m0; char text[0xB0]; int dirty; };
extern "C" int func_0057DA20(char *, const char *, ...);
extern "C" char *func_005A5DC8(char *, const char *);

extern "C" void func_003E0348(Label *l, int n, int plus)
{
    func_0057DA20(l->text, D_006A37E8, plus ? '+' : ' ', n);
    func_005A5DC8(l->text, n < 2 ? DisplayRText__rtext_ptrs_->one : DisplayRText__rtext_ptrs_->many);
    l->dirty = 1;
}
