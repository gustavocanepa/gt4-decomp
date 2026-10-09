struct S { char pad[0xA4]; int unkA4; };

extern "C" int func_00206868(S *arg0) {
    return arg0->unkA4;
}
