#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, lv[1001], sem[1001];
vector<int>v[1001];
queue<int>q;
int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b; lv[b]++; v[a].push_back(b);
    }for (int i = 1; i <= N; i++)if (lv[i] == 0)q.push(i);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int nx : v[x]) {
            if (--lv[nx] == 0) {
                q.push(nx); if (sem[x] + 1 > sem[nx])sem[nx] = sem[x] + 1;
            }
        }
    }for (int i = 1; i <= N; i++)cout << sem[i] + 1 << " ";
}