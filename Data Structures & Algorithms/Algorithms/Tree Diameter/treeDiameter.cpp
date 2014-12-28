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

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int> > vpii;
typedef set<int> si;

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int d8i [] = {0, 0, 1, -1, 1, 1, -1, -1};
int d8j [] = {1, -1, 0, 0, 1, -1, 1, -1};

    /*           \\^//           /*
    | |    Magic Starts Here     | |
    */           // \\           * /


vector< vector<int> > adjacencyList;
bool vis[100];
int maxDepth = 0;

int BFS(int start) {
	memset(vis, 0, sizeof vis);
	queue<int> Q;
	Q.push(start);
	int depth = 0;
	vis[start] = 1;
	while (int size = Q.size()) {
		while (size--) {
			int current = Q.front();
			Q.pop();
			for(int next : adjacencyList[current]) {
				if (!vis[next]) {
					Q.push(next);
					maxDepth = next;
					vis[next] = 1;
				}
			}
		}
		depth++;
	}
	return depth - 1;
}

int calcDiameter() {
	BFS(0);
	return BFS(maxDepth);
}

/*

Apply this to all data inputs

13
1 2
1 3
2 4
2 5
3 6
5 7
5 8
6 9
9 10
9 11
10 12
10 13
*/

int main() {

	#ifndef ONLINE_JUDGE
		// freopen("IntegerArray.txt", "rt", stdin);
		//freopen("out.txt", "wt", stdout);
	#endif
	std::ios_base::sync_with_stdio(false);

	int n, m;
	int u, v;
	string line;
	cin >> n;
	adjacencyList.resize(n);
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		adjacencyList[u - 1].push_back(v - 1);
		adjacencyList[v - 1].push_back(u - 1);
	}
	cout << calcDiameter() << endl;

	return 0;
}
