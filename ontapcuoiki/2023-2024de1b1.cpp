#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode 
{
    int data;
    BinaryTreeNode *left, *right;
};

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
            insert(root->right, x);
    }
}

int sumEven(BinaryTreeNode* root)
{
    if (root == nullptr) return 0;
    int sum = 0;
    if (root->data % 2 == 0) sum += root->data;
    sum += sumEven(root->left);
    sum += sumEven(root->right);
    return sum;
}

int findLevel(BinaryTreeNode* root, int x, int level = 0)
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
    int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for (int i = 0; i < 9; i++)
        insert(root, a[i]);
    cout << "Sum of even numbers in the tree: " << sumEven(root) << endl;

    cout << "Level of node with value 6 in the tree: " << findLevel(root, 6, 0) << endl;

    return 0;
}