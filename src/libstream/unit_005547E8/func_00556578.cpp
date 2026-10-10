struct func_005563F0 {
    char pad[0x60];
    func_005563F0();
    virtual ~func_005563F0();
};
struct D_006899C0;
extern D_006899C0 *D_008A1A54;
struct D_006899C0 : func_005563F0 {
    D_006899C0();
    virtual ~D_006899C0();
};
D_006899C0::D_006899C0() {
    D_008A1A54 = this;
}
