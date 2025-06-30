#include <iostream>
#include <climits> // Để sử dụng INT_MIN

// Định nghĩa cấu trúc Node cho cây nhị phân
struct Node {
    int data;           // Giá trị của node
    Node* left;         // Con trỏ đến node con bên trái
    Node* right;        // Con trỏ đến node con bên phải
    
    // Constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Hàm tạo cây theo sơ đồ đã cho
Node* createTree() {
    // Tạo các node
    Node* root = new Node(1);        // Node gốc
    root->left = new Node(2);        // Node 2 là con trái của 1
    root->right = new Node(3);       // Node 3 là con phải của 1
    root->left->left = new Node(4);  // Node 4 là con trái của 2
    root->left->right = new Node(5); // Node 5 là con phải của 2
    root->right->left = new Node(6); // Node 6 là con trái của 3
    root->right->right = new Node(7);// Node 7 là con phải của 3
    
    return root;
}

// Hàm tìm một số trong cây
bool findNumber(Node* root, int number) {
    // Nếu cây rỗng hoặc đến node lá mà không tìm thấy
    if (root == nullptr) {
        return false;
    }
    
    // Nếu tìm thấy số tại node hiện tại
    if (root->data == number) {
        return true;
    }
    
    // Tìm ở nhánh trái hoặc nhánh phải
    return findNumber(root->left, number) || findNumber(root->right, number);
}

// Hàm tìm số lớn nhất trong cây
int findMax(Node* root) {
    // Nếu cây rỗng, trả về giá trị nhỏ nhất có thể
    if (root == nullptr) {
        return INT_MIN;
    }
    
    // Lấy giá trị của node hiện tại
    int max = root->data;
    
    // Tìm giá trị lớn nhất ở nhánh trái
    int leftMax = findMax(root->left);
    // Tìm giá trị lớn nhất ở nhánh phải
    int rightMax = findMax(root->right);
    
    // So sánh và trả về giá trị lớn nhất
    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }
    
    return max;
}

// Hàm main thực hiện các yêu cầu
int main() {
    // 1. Tạo cây
    Node* root = createTree();
    
    // 2. Tìm số 5
    int numberToFind = 5;
    bool found = findNumber(root, numberToFind);
    std::cout << "So " << numberToFind << " "
              << (found ? "co trong cay" : "khong co trong cay") << std::endl;
    
    // 3. Tìm số lớn nhất
    int maxNumber = findMax(root);
    std::cout << "So lon nhat trong cay: " << maxNumber << std::endl;
    
    // Giải phóng bộ nhớ (nếu cần)
    // TODO: Thêm hàm giải phóng bộ nhớ
    return 0;
}