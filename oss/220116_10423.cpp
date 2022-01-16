#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K, par[1001], res;
bool power[1001];
vector<pair<int, pair<int, int>>>v;
int find(int x)
{
    if (par[x] == x)return x;
    else return par[x] = find(par[x]);
}
void merge(int a, int b)
{
    a = find(par[a]), b = find(par[b]);
    if (a == b)return;
    if (power[a] && power[b])return;
    if (power[a])par[b] = a;
    else if (power[b])par[a] = b;
    else if (a < b)par[a] = b;
    else par[b] = a;
}
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)par[i] = i;
    for (int i = 0, a; i < K; i++) {
        cin >> a; power[a] = true;
    }
    for (int i = 0, a, b, c; i < M; i++) {
        cin >> a >> b >> c; v.push_back({ c,{a,b} });
    }
    sort(v.begin(), v.end());
    for (pair<int, pair<int, int>>p : v) {
        int a = p.second.first, b = p.second.second, c = p.first;
        a = find(par[a]); b = find(par[b]);
        if (a == b || (power[a] && power[b]))continue;
        res += c;
        merge(a, b);
    }cout << res;
}