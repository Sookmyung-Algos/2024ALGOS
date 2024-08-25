#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
int parent[100001];
bool visited[100001];

void findParent(int a) {
    visited[a] = true;
    for (int i = 0; i < tree[a].size(); i++) {
        int next = tree[a][i];
        if (!visited[next]) {
            parent[next] = a;
            findParent(next);
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    parent[1] = 1;
    findParent(1);
    
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}
