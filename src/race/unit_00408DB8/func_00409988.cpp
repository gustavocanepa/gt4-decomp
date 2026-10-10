/* The element class has no known name: named after its constructor (func_00409940) so that
   __13func_00409940 resolves. */
struct func_00409940 {
    func_00409940();
    char pad[0x50];
};

/* Named after its own constructor. The array member is built by the compiler's countdown loop. */
struct func_00409988 {
    float a;
    float b;
    int c;
    func_00409940 e[4];
    func_00409988();
};

func_00409988::func_00409988() : a(1.0f), b(1.0f), c(0)
{
}
