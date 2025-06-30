#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode 
{
    int data;
    BinaryTreeNode *left, *right;
};

void unitTree(BinaryTreeNode* &root)
{
    BinaryTreeNode* r8 = new BinaryTreeNode{13, nullptr, nullptr};
    BinaryTreeNode* r7 = new BinaryTreeNode{14, r8, nullptr};
    BinaryTreeNode* r6 = new BinaryTreeNode{10, nullptr, r7};
    BinaryTreeNode* r5 = new BinaryTreeNode{7, nullptr, nullptr};
    BinaryTreeNode* r4 = new BinaryTreeNode{4, nullptr, nullptr};
    BinaryTreeNode* r3 = new BinaryTreeNode{6, r4, r5};
    BinaryTreeNode* r2 = new BinaryTreeNode{1, nullptr, nullptr};
    BinaryTreeNode* r1 = new BinaryTreeNode{3, r2, r3};
    root = new BinaryTreeNode{8, r1, r6};
}

void print(BinaryTreeNode *root)
{
    if(root != nullptr){
        cout << root->data << " " ;
        print(root->left);
        print(root->right);
    }
}

void insert(BinaryTreeNode* &root, int x)
{
    if (root == nullptr)
    {
        root = new BinaryTreeNode();
        root->data = x;
        root->left = root->right = nullptr;
    }
    else
    {
        if (root->data > x)
            insert(root->left, x);
        else
            if (root->data < x)
                insert(root->right, x);
    }
}

int sumEven(BinaryTreeNode* root)
{
    if (root == nullptr) return 0;

    int sum = 0;
    if (root->data % 2 == 0) sum += root->data;
    return sum + sumEven(root->left) + sumEven(root->right);
}

int findLevel(BinaryTreeNode* root, int x, int level = 1)
{
    if (root == nullptr) return 0;
    if (root->data == x) return level;
    if (x < root->data)
        return findLevel(root->left, x, level + 1);
    else 
        return findLevel(root->right, x, level + 1);
}

int main() 
{
    BinaryTreeNode* root = nullptr;
    unitTree(root);
    cout << "Sum of even numbers in the tree: " << sumEven(root) << endl;

    cout << "Level of node with value 6 in the tree: " << findLevel(root, 6) << endl;
    print(root);
    cout << endl;
    return 0;
}
