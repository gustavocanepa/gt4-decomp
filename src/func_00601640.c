/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct {
    int w[11];
} Value_00601640;

typedef struct {
    char pad0[0x24];
    Value_00601640 value;
} Node_00601640;

void func_00601640(Node_00601640 *node, const Value_00601640 *v) {
    node->value = *v;
}
