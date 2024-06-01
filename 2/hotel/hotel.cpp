 #include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int X) : val(X), left(NULL), right(NULL) {}
};

void insert(Node*& root, int val) {
    if (!root) {
        root = new Node(val);
        return;
    }
    if (val < root->val) insert(root->left, val);
    else insert(root->right, val);
}

bool findingPath(Node* root, int val, vector<int>& paths) {
    if (!root) return false;
    paths.push_back(root->val);
    if (root->val == val) return true;
    if (val < root->val && findingPath(root->left, val, paths)) return true;
    if (val > root->val && findingPath(root->right, val, paths)) return true;
    paths.pop_back();
    return false;
}

int main() {
    int n, g;
    cin >> n >> g;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert(root, val);
    }
    for (int i = 1; i <= g; i++) {
        int val;
        cin >> val;
        vector<int> paths;
        if (findingPath(root, val, paths)) {
            cout << i << ":";
            for (int j = 0; j < paths.size(); j++) {
                cout << " " << paths[j];
                if (paths[j] == val) break;
            }
            cout << endl;
        }
        else {
            cout << i << ": path not found" << endl;
        }
    }
}

