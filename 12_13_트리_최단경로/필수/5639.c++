#include <iostream>
#include <vector>

using namespace std;

void postorder(int start, int end, vector<int> &preorder) {
    if (start > end) return;

    int root = preorder[start];
    int idx = start + 1;

    while (idx <= end && preorder[idx] < root) {
        idx++;
    }

    postorder(start + 1, idx - 1, preorder);
    postorder(idx, end, preorder);

    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> preorder;
    int input;

    while (cin >> input) {
        preorder.push_back(input);
    }

    postorder(0, preorder.size() - 1, preorder);

    return 0;
}