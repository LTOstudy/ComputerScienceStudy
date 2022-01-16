#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
int N, K, R, a, b, c, d, r;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
set<pair<pair<int, int>, pair<int, int>>>s;
pair<int, int>pos[100];
bool visit[101][101];
void can(int x1, int y1)
{
    queue<pair<int, int>>q;
    q.push({ x1,y1 }); visit[y1][x1] = true;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx<1 || nx>N || ny<1 || ny>N || visit[ny][nx] || s.count({ {x,y},{nx,ny} }) != 0)continue;
            q.push({ nx,ny }); visit[ny][nx] = true;
        }
    }
}
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false); cin >> N >> K >> R;
    while (R--) { cin >> a >> b >> c >> d; s.insert({ {b,a},{d,c} }); s.insert({ {d,c},{b,a} }); }
    for (int i = 0; i < K; i++) { cin >> a >> b; pos[i] = { b,a }; }
    for (int i = 0; i < K; i++) {
        memset(visit, false, sizeof(visit)); can(pos[i].first, pos[i].second);
        for (int j = i + 1; j < K; j++) if (!visit[pos[j].second][pos[j].first]) r++;
    }cout << r;
}