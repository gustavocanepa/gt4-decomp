typedef float f32;

struct S003983E0 {
    char pad[0xAB0];
    f32 unkAB0;
    char pad2[0xAB8 - 0xAB0 - 4];
    f32 unkAB8;
};

extern "C" f32 func_003983E0(S003983E0 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f2 = arg0->unkAB8;
    return ((fparg0 * (arg0->unkAB0 - temp_f2)) + temp_f2) * fparg1;
}
