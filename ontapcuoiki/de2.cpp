#include <bits/stdc++.h>
using namespace std;

struct TreeNode 
{
    string name;
    TreeNode *child, *sib;
};

void createTree(TreeNode* &root)
{
    TreeNode* h23 = new TreeNode{"TP Thu Duc", nullptr, nullptr};
    TreeNode* h22 = new TreeNode{"Quan Binh Thanh", nullptr, h23};
    TreeNode* h21 = new TreeNode{"Quan Mot", nullptr, h22};
    TreeNode* h14 = new TreeNode{"TP HCM", h21, nullptr};
    TreeNode* h13 = new TreeNode{"TP Ha Noi", nullptr, h14};
    TreeNode* h12 = new TreeNode{"Tp Da Nang", nullptr, h13};
    TreeNode* h11 = new TreeNode{"Tinh Binh Dinh", nullptr, h12};
    root = new TreeNode{"Dat nuoc Viet Nam", h11, nullptr};

}
void DFS(TreeNode* root)
{
    if (root)
    {
        cout << root->name << endl;
        DFS(root->child);
        DFS(root->sib);
    }
}

void isMostSib(TreeNode* root, int &max, TreeNode* &maxNode)
{
    queue<TreeNode*> q;
    // day tat ca cac tinh thanh pho vao queue
    root = root->child; // bo qua node goc
    while (root)
    {
        q.push(root);
        root = root->sib;
    }
    // xet tung mang thang trong queue
    while (!q.empty())
    {}
}

