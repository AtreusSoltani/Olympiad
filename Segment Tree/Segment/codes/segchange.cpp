struct Node {
    Node* lc;
    Node* rc;
    int value;

    void change(int L, int R, int idx, int new_value) {
        if (L + 1 == R) {
            value = new_value;
            return;
        }
        int mid = (L + R) >> 1;
        if (idx < mid)
            lc->change(L, mid, idx, new_value);
        else
            rc->change(mid, R, idx, new_value);
        value = max(lc->value, rc->value);
    }
};