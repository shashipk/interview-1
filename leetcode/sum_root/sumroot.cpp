#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

stack<int> s[2];
int sum = 0;
int c = 0;
void previsit(TreeNode *p) {
    s[c].push(p->val);
    if (p->left) previsit(p->left);
    if (p->right) previsit(p->right);
    if (!(p->left) && !(p->right)) {
        int n = 0;
        int t = 1;
        while (!s[c].empty()) {
            int num = s[c].top();
            n = n + num * t;
            t *= 10;
            s[c].pop();
            s[1 - c].push(num);
        }
        c = 1 - c;
        sum += n;
        cout << n << endl;
    }
    s[c].pop();
}

int main() {
    // Start typing your code here...
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
	t->right = new TreeNode(3);
    previsit(t);
    cout << "sum: " << sum << endl;
    return 0;
}
/*
int sumNumbers(TreeNode *root) {
        if (root) {
            previsit(root);
        }
        return sum;    
    }
int main() {
	TreeNode *t = new TreeNode(4);
	t->left = new TreeNode(9);
	t->right = new TreeNode(0);
	t->left->right = new TreeNode(1);
	cout <<  sumNumbers(t) << endl;
	return 0;
}
*/
