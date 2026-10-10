struct Elem {
    char data[0x34];
    Elem() __asm__("func_00559E58");
};

struct ElemArray {
    Elem elems[48];
    ElemArray() __asm__("func_0055A3D8");
};

ElemArray::ElemArray() {
}
