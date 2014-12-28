#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <set>
#include <utility>
#include <iterator>
#include <list>
#include <cmath>
#include <iomanip>
#include <memory>
#include <map>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert
#define getmax(a,b) ((a)>(b)?(a):(b))
#define OOR out_of_range

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

vector<vector<bool> > adjacencyMatrix;
vector<vector<int> > adjacencyList;
bool findInAdjacencyList(int from, int to) {
	for (int i = 0; i < sz(adjacencyList) ; ++i)
		if (adjacencyList[from][i] == to)
			return true;
	return false;
}

bool* visited = new bool[adjacencyList.size()]; // size == number of nodes
int dest = 5;
bool DFS(int node) {
	if (node == dest)
		return false;
	visited[node] = true;
	for (int i = 0; i < sz(adjacencyList[node]) ; ++i) {
		if (visited[adjacencyList[node][i]])
			continue;
		if (DFS(adjacencyList[node][i]))
			return true;
	}
	return false;
}

//number of steps to reach the destination
int DFS2(int node) {
	if (node == dest)
		return false;
	visited[node] = true;
	for (int i = 0; i < sz(adjacencyList[node]) ; ++i) {
		if (visited[adjacencyList[node][i]])
			continue;
		int res = (DFS(adjacencyList[node][i]));
		if (res >= 0)
			return res + 1;
	}
	return false;
}
const int nodes = 10;
bool vis[nodes];
int BFS(int source, int dsnt) {
	int crrntLve = 0, temp;
	queue<int> Q;
	Q.push(source);
	vis[source] = true;
	while (!Q.empty()) {
		int sz = sz(Q);
		for (int i = 0; i < sz; ++i) {
			temp = Q.front();
			Q.pop();
			if (temp == dsnt)
				return crrntLve;
			for (int j = 0; j < sz(adjacencyList[temp]) ; ++j) {
				if (!vis[adjacencyList[temp][j]])
					Q.push(adjacencyList[temp][j]), vis[adjacencyList[temp][j]] = 1;
			}
			++crrntLve;
		}
	}
	return -1;
}

int main() {

	memset(visited, 0, sizeof(visited));
	memset(vis, 0, sizeof(vis));
	int n, e, r, c, q;

//	bool** adjacencyMat = new bool*[n];
//	for (int i = 0; i < n; i++)
//		adjacencyMat[i] = new bool[n];

//	cin >> n;
////	 vector<vector<bool> > adjacencyMatrix(n, vector<bool>(n, 0));
//	adjacencyMatrix.resize(n, vector<bool>(n, false));
//	cin >> e;
//	while (e--) {
//		cin >> r >> c;
//		adjacencyMatrix[r][c] = true;
//	}
//	cin >> q;
//	while (q--) {
//		cin >> r >> c;
//		(adjacencyMatrix[r][c]) ? cout << "YES" << endl : cout << "NO" << endl;
//	}

//	n = 0, e = 0, r = 0, c = 0, q = 0;

	cin >> n;
	adjacencyList.resize(n);
	cin >> e;
	while (e--) {
		cin >> r >> c;
		adjacencyList[r].pb(c);
	}

	cin >> q;
//	bool found = false;
	while (q--) {
		cin >> r >> c;
		cout << BFS(r, c) << endl;

//		if (findInAdjacencyList(r, c))
//			found = true;
//
//		(found) ? cout << "YES" << endl : cout << "NO" << endl;
//		found = false;
	}
	return 0;
}
