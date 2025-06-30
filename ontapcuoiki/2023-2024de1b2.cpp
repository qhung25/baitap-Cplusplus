#include<bits/stdc++.h>

using namespace std;

const int MAX = 100;

vector<int> adj[MAX];

int timduongdi(int x, int y, int n){
    vector<bool> visited(n, false);
    vector<int> dist(n, -1);
    queue<int> q;

    q.push(x);
    visited[x] = true;
    dist[x] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for (int v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);

                if (v == y) return dist[v] - 1;
            }
        }
    }
    return -1;
}
void lkra(int k) {
    cout << "Sinh vien " << k << " biet nha sinh vien: ";
    for (int v : adj[k])
        cout << v << " ";
    cout << endl;
}
int main(){
    int n = 9;
    adj[1] = {0};
    adj[2] = {7,4};
    adj[3] = {1};
    adj[5]  = {2,0};
    adj[6]  = {5,3};
    adj[7]  = {6, 8};

    int kq = timduongdi(5, 8, n);
if (kq == -1)
    cout << "Sinh vien 5 KHONG the biet nha sinh vien 8\n";
else
    cout << "Sinh vien 5 CO the biet nha sinh vien 8, qua " << kq << " sinh vien trung gian\n";
    lkra(3);
return 0;

}