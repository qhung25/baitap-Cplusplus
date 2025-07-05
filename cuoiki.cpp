#include <iostream>
#include <string>
using namespace std;


// Khai báo cấu trúc dữ liệu cây tìm kiếm nhị phân
struct HanhTinh {
    string ten;
    double khoangCach; // đơn vị: triệu km
};

struct Node {
    HanhTinh data;
    Node* left;
    Node* right;
};

//thêm một hành tinh vào cây
Node* themNode(Node* root, HanhTinh ht) {
    if (root == nullptr) {
        Node* newNode = new Node{ht, nullptr, nullptr};
        return newNode;
    }

    if (ht.khoangCach < root->data.khoangCach)
        root->left = themNode(root->left, ht);
    else
        root->right = themNode(root->right, ht);

    return root;
}


//liệt kê các hành tinh có khoảng cách từ Mặt Trời lớn hơn 100 và nhỏ hơn 500 triệu km
void lietKeTrongKhoang(Node* root) {
    if (root == nullptr) return;

    lietKeTrongKhoang(root->left);

    if (root->data.khoangCach > 100 && root->data.khoangCach < 500)
        cout << root->data.ten << " (" << root->data.khoangCach << " triệu km)" << endl;

    lietKeTrongKhoang(root->right);
}

//kiểm tra hành tinh có tên X có tồn tại trong cây hay không
bool timHanhTinhTheoTen(Node* root, string tenX) {
    if (root == nullptr) return false;

    if (root->data.ten == tenX) return true;

    // Duyệt cả trái và phải vì tên không phải là khóa chính của cây
    return timHanhTinhTheoTen(root->left, tenX) || timHanhTinhTheoTen(root->right, tenX);
}

int main() {
    Node* root = nullptr;

    root = themNode(root, {"Sao Thuy", 57});
    root = themNode(root, {"Sao Kim", 108});
    root = themNode(root, {"Trai Dat", 149});
    root = themNode(root, {"Sao Hoa", 227});
    root = themNode(root, {"Sao Moc", 778});

    cout << "Hanh tinh co khoang cach >100 va <500 trieu km:\n";
    lietKeTrongKhoang(root);

    string tenCanTim = "Sao Tho";
    if (timHanhTinhTheoTen(root, tenCanTim))
        cout << tenCanTim << " co trong cay.\n";
    else
        cout << tenCanTim << " khong co trong cay.\n";

    return 0;
}




