struct Sub_00395C68 { char pad[4]; };
struct Obj_00395C68 { char pad[0x1C]; Sub_00395C68 sub; };

extern "C" Sub_00395C68 *func_00395C68(Obj_00395C68 *arg0) {
    return &arg0->sub;
}
