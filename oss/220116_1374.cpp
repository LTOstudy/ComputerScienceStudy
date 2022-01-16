#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, r;
pair<int, int>p[100000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0, a, b, c; i < N; i++) { cin >> a >> b >> c; p[i] = { b,c }; }
    sort(p, p + N);
    for (int i = 0; i < N; i++) {
        if (pq.empty())r++;
        else {
            if (pq.top().first <= p[i].first)pq.pop();
            else r++;
        }
        pq.push({ p[i].second,p[i].first });
    }cout << r;
}

