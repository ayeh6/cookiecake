#include <iostream>
#include <climits>

using namespace std;

struct edge {
	int u;
	int v;
	int w;
};

struct graph {
	struct edge* arr;
}

int main() {
	int V, E, u, v, w;
	cin >> V;
	cin >> E;
	struct graph* G = new graph;
	int cost[V];
	edge* edges = new edge[E];
	bool cycleFound = FALSE;
	G->arr = edges;
	for (int i = 0; i < E; i++) {
		cin >> u;
		cin >> v;
		cin >> w;
		G->arr[i].u = u;
		G->arr[i].v = v;
		G->arr[i].w = w;
	}
	
	for (i = 0; i < V; i++) {
		if (i = 0)
			cost[i] = 0;
		else
			cost[i] = INT_MAX;
	}
	
	for (i = 1; i <= V-1; i++) {
		for (int j = 0; j < E; j++) {
			if (cost[G->arr[j].u] != INT_MAX && (cost[G->arr[j].u] + G->arr[j].w < cost[G->arr[j].v])) {
				cost[G->arr[j].v] = cost[G->arr[j].u] + G->arr[j].w;
			}
		}
	}
	
	for (i = 0; i < E; i++) {
		if (cost[G->arr[i].src] != INT_MAX && (cost[G->arr[j].u] + G->arr[j].w < cost[G->arr[j].v])) {
			cycleFound = TRUE;
		}
	}
	
	if (cycleFound == TRUE) {
		cout << "FALSE" << endl;
	}
	else if (cycleFound == FALSE){
		for (i = 0; i < V; i++) {
			cout << cost[i] << endl;
		}
	}
}