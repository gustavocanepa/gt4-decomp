struct Box {
    float row[2][4];
    float extra;
};

extern "C" void func_0048D6C0(Box *out, int row, const Box *a, const Box *b);

extern "C" void func_0048DAA0(Box *out, const Box *a, const Box *b)
{
    func_0048D6C0(out, 0, a, b);
    func_0048D6C0(out, 1, a, b);
    out->extra = a->extra - b->extra;
}
