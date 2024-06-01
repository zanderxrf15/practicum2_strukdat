 #include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    int count;
    Node* left;
    Node* right;
    Node(int X) : val(X), count(1), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int X) {
    if (!root) return new Node(X);
    if (X <= root->val) root->left = insert(root->left, X);
    else root->right = insert(root->right, X);
    root->count++;
    return root;
}

int nthLargestNumber(Node* root, int N) {
    int rightCount = root->right ? root->right->count : 0;
    if (N <= rightCount) return nthLargestNumber(root->right, N);
    else if (N == rightCount + 1) return root->val;
    else return nthLargestNumber(root->left, N - rightCount - 1);
}

int main() {
    int T, N, X;
    cin >> T >> N;
    Node* root = NULL;
    for (int i = 0; i < T; i++) {
        cin >> X;
        root = insert(root, X);
    }
    cout << nthLargestNumber(root, N) << endl;
}
