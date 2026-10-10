/* compiler: ee-gcc2.9-991111 */
typedef struct Request {
    int type;
    int arg;
} Request;

extern void func_0058B708(void *ctx, Request *req);
extern void func_0058B770(void *ctx, Request *req, int arg);
extern void func_005ADF20(int id);

int func_0058B608(void *ctx, Request *req) {
    switch (req->type) {
    case 1:
        func_0058B708(ctx, req);
        break;
    case 2:
        func_0058B770(ctx, req, req->arg);
        break;
    default:
        return -1;
    }
    func_005ADF20(0);
    func_005ADF20(2);
    return 0;
}
