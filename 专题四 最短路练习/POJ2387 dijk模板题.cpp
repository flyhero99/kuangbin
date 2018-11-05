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

int n;
int x[maxn], y[maxn];

struct qnode {
	int v; double c;
	qnode(int _v = 0, double _c = 0.0) : v(_v), c(_c) {}
	bool operator < (const qnode &r) const {
		return c > r.c;
	}
};

struct Edge {
	int s; double c;
	Edge(int _s = 0, double _c = 0.0) : s(_s), c(_c) {}
};

vector<Edge> vec[maxn];
bool vis[maxn];
double dist[maxn];

void dijk(int st) {
	for(int i = 0; i <= n; i++) dist[i] = inf; dist[st] = 0.0;
	memset(vis, 0, sizeof vis);
	priority_queue<qnode> pq; pq.push(qnode(st, 0.0));
	qnode tmp;
	while(!pq.empty()) {
		tmp = pq.top(); pq.pop();
		int u = tmp.v;
		if(!vis[u]) {
			vis[u] = true;
			for(int i = 0; i < vec[u].size(); i++) {
				int v = vec[u][i].s; double c = vec[u][i].c;
				if(!vis[v]) {
					dist[v] = min(dist[v], max(dist[u], c));
					pq.push(qnode(v, dist[v]));
				}
			}
		}
	}
}

double eulclid(int x1, int y1, int x2, int y2) {
	return sqrt( 1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2) );
}

int main() {
	// freopen("1.txt", "r", stdin);
    int cas = 0;
    while(~scanf("%d", &n) && n) {
    	cas++;
    	for(int i = 1; i <= n; i++) {
    		scanf("%d %d", &x[i], &y[i]);
    		vec[i].clear();
    	}
    	for(int i = 1; i <= n; i++) {
    		for(int j = i+1; j <= n; j++) {
    			vec[i].push_back(Edge(j, eulclid(x[i], y[i], x[j], y[j])));
    			vec[j].push_back(Edge(i, eulclid(x[i], y[i], x[j], y[j])));
    		}
    	}
    	// for(int i = 1; i <= n; i++) {
    	// 	for(int j = 0; j < vec[i].size(); j++) {
    	// 		cout << vec[i][j].s << ' ' << vec[i][j].c << "  ";
    	// 	}
    	// 	cout << endl;
    	// }
    	dijk(1);
    	printf("Scenario #%d\nFrog Distance = %.3f\n\n", cas, dist[2]);
    }
    return 0;
}