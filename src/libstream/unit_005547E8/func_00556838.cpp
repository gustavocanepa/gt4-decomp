struct func_005563F0 {
    char pad[0x60];
    func_005563F0();
    virtual ~func_005563F0();
};
struct D_00689970;
extern D_00689970 *D_008A1A58;
struct D_00689970 : func_005563F0 {
    D_00689970();
    virtual ~D_00689970();
};
D_00689970::D_00689970() {
    D_008A1A58 = this;
}
