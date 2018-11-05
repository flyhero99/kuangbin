#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#define mem(a, b) memset(a, b, sizeof a)
#define inf 0x3f3f3f3f
#define fi first
#define se second
typedef long long ll;
const int maxn = 2005;
using namespace std;

int n, m;

int mp[maxn][maxn];
int dist[maxn];
bool vis[maxn];

void dijk(int st) {
	memset(vis, 0, sizeof vis);
	for(int i = 0; i <= n; i++) dist[i] = mp[1][i];
	for(int i = 1; i <= n; i++) {
		int pos = -1, maxx = -1;
		for(int j = 1; j <= n; j++) {
			if(!vis[j] && dist[j] > maxx)
				maxx = dist[pos=j];
		}
		if(pos == -1) continue;
		vis[pos] = 1;
		for(int j = 1; j <= n; j++) {
			if(!vis[j] && dist[j] < min(dist[pos], mp[pos][j]))
				dist[j] = min(dist[pos], mp[pos][j]);
		}
	}
}

int main() {
	// freopen("1.txt", "r", stdin);
	int t; cin >> t;
	for(int cas = 1; cas <= t; cas++) {
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) mp[i][j] = (i==j) ? 0 : -1;
		for(int i = 1; i <= m; i++) {
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			if(mp[u][v] < w) mp[u][v] = mp[v][u] = w;
		}
		dijk(1);
		printf("Scenario #%d:\n%d\n\n", cas, dist[n]);
	}
	return 0;
}