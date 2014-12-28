#include <iostream>
#include <algorithm>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib> 
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int> > vpii;
typedef set<int> si;

#define sz(x) (int)x.size()
#define round(x) (int)(x + 0.5)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define ins insert
#define getmax(a,b) ((a) > (b) ? (a) : (b))
#define getmin(a,b) ((a) > (b) ? (b) : (a))
#define mms(x,n,s) memset(x, n, sizeof(x) * s)
#define CV(x,n) count(all(x),(n))
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define rep(i, x, n) for (int (i) = (x); (i) < (n); (i)++)


const ll OO = 1e8;
int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int d8i [] = {0, 0, 1, -1, 1, 1, -1, -1};
int d8j [] = {1, -1, 0, 0, 1, -1, 1, -1};

    /*           \\^//           /*
    | |    Magic Starts Here     | |
    */           // \\           * /

struct edge {
	ll from, to, weight;
	edge(ll f, ll t, ll w): from(f), to(t), weight(w) {}	

	bool operator< (const edge& e)
	const {
		return weight > e.weight;
	}
};

pair<int, vector<edge> > prim_algorithm(vector< vector<edge> > adjacencyList) {
	int n = sz(adjacencyList);
	ll MST_COST = 0;
	vector<bool> vis(n, 0);
	vector<edge> edges;
	priority_queue<edge> Q;

	Q.push(edge(-1, 0, 0));
	while (!Q.empty()) {
		edge E = Q.top(); Q.pop();
		if (vis[E.to]) continue;
		vis[E.to] = true;
		MST_COST += E.weight;
		if (E.to) edges.pb(E);
		FOR(i, sz(adjacencyList[E.to])) {
			edge ee = adjacencyList[E.to][i];
			if (!vis[ee.to])
				Q.push(ee);
		}
	}
	if (sz(edges) != n - 1) return make_pair(-OO, vector<edge>() );
	return make_pair(MST_COST, edges);
}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("graphs.txt", "rt", stdin);
		//freopen("out.txt", "wt", stdout);
	#endif
	std::ios_base::sync_with_stdio(false);

	int n, m;
	ll i, j, k;
	
	while (cin >> n >> m) {
		vector< vector<edge> > nodes(n);

		while(m--) {
			cin >> i >> j >> k;
			nodes[i - 1].pb(edge(i - 1, j - 1, k));
			nodes[j - 1].pb(edge(j - 1, i - 1, k));
		}
		pair<int, vector<edge> > res = prim_algorithm(nodes);
		cout << "Total cost = " << res.first << endl;
		FOR(i, sz(res.second)) {
				cout << char(res.second[i].from + 'a') << " " << char(res.second[i].to + 'a') << " " << res.second[i].weight << endl;
		}
		cout << "\n\n";		
	}
	
	return 0;
}

