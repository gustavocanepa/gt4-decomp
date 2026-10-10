struct Reader;
extern "C" int func_0020FAD8(Reader *r);

extern "C" void func_0020FC58(Reader *r, int depth) {
    while (depth == 0) {
        if (func_0020FAD8(r) == '{')
            depth++;
    }
    while (depth > 0) {
        int c = func_0020FAD8(r);
        if (c == '{')
            depth++;
        if (c == '}')
            depth--;
    }
}
