struct A { char pad[0x20]; float f; };
struct B { char pad[0x48]; float g; };
float func_00379578(struct A *a, struct B *b) { float x = a->f; return b->g * x; }
