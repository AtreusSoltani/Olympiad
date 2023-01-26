const int INF = 1e9;

struct Node {
    Node* lc;
    Node* rc;
    int value;

    int get(int L, int R, int st, int en) {
        if (R <= st or en <= L)
            return -INF;
        if (st <= L and R <= en)
            return value;
        int mid = (L + R) >> 1;
        return max(lc->get(L, mid, st, en), rc->get(mid, R, st, en));
    }
};