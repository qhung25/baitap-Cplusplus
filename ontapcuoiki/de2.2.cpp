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

int main () {
    docDuLieu("dothi.txt");
    cout << "Nguoi 1 co " << soNguoiTheoDoi(1) << "nguoi theo doi.\n";
    return 0;
}