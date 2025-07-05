#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

    int n, m;
    vector<vector<int>> adj; // danh sach nguoi ma x theo doi
    vector<vector<int>> reverseAdj; // danh sach nguoi theo doi x

// doc du lieu tu file

void docDuLieu(const string& tenFile){
    ifstream f(tenFile);
    f >> n >> m;
    adj.assign(n,{});
    reverseAdj.assign(n, {});
    int u, v;
    for (int i = 0; i < m; i++) {
        f >> u >> v;
        adk[u].push_back(v); // u theo doi v
        reverseAdj[v].push_back(u); // v duoc u theo doi

    }
    f.close
}

// b

int soNguoiTheoDoi(int x) {
    return reverseAdj[x].size();

}

// c Kiểm tra x có thể nhận được bài viết từ y không 
bool nhanBaiViet(int x, int y) {
    // Sử dụng BFS để kiểm tra xem có đường đi từ y đến x không
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(y);
    visited[y] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == x) {
            visited[nguoi] {
                q.push(nguoi);
            }
        }
    }
    return false; // Không tìm thấy đường đi từ y đến x
}

// d Kiem tra x va y co nhan duoc bai viet cua nhau khong
bool nhanBaiVietCuaNhau(int x, int y) {
    return nhanBaiViet(x, y) && nhanBaiViet(y, x);
}


int main () {
    docDuLieu("dothi.txt");
    cout << "Nguoi 1 co " << soNguoiTheoDoi(1) << "nguoi theo doi.\n";
    cout << "Nguoi 4 co nhan duoc bai viet cua nguoi 0 khong? ";
    cout << (nhanBaiViet(4, 0) ? "Co\n" : "Khong\n"); 
    cout << "Nguoi 0 va 4 co nhan duoc bai viet cua nhau khong? ";
    cout << (nhanBaiVietCuaNhau(0, 4) ? "Co\n" : "Khong\n");
    return 0;
}