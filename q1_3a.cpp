#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
/* Do not include any other headers */

/*
To use the minheap, first declare it with the appropriate data type T as, minheap<T>
For example, 
1. minheap<int> pq; 
2. minheap<pair<int,int>> pq; 
3. minheap<vector<int>> pq;

After this, you may use functions such as push, pop, top, empty:
pq.push(2); // Insert an element into the heap
int x = pq.top(); // Get the min element of the heap
pq.pop(); // Delete the min of the heap
pq.empty(); // Returns if the heap is empty
*/
template <class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

/*  
    Telephone Line Cost
    --------------------------
    Return the minimum cost of laying the telephone line for the input graph
    adj is the adjacency list representation of the graph
    V = No of vertices, E = No of edges
*/
const int INT_MAX = 2147483647;
struct Edge{
	int from;
	int to;
	int weight;
	bool operator > (Edge rhs) const {
		return this->weight > rhs.weight;
	}
};
long long telephone_line_cost(int V, int E, map<int, map<int,int>> &adj) {   
   int n = V;
   vector<long long> dist(n, INT_MAX);
   vector<vector<Edge>> graph(n, vector<Edge>{});
 //  for (int i = 0; i < V; i++){
	//   for (int j = 0; j < V; j++) {
		//   if(adj[i].find(j) != adj[i].end()){
			//   graph[i].push_back({i, j, adj[i][j]});
		   //}
	//   }
  // }
  for(int i = 0; i < V; i++){
	  for(pair<const int,int>& edge: adj[i]){
		  graph[i].push_back({i, edge.first, edge.second});
	  }
  }
   
	dist[0] = 0;
	minheap<Edge> pq;
	long long mst = 0;
   for(Edge e: graph[0]){
	   pq.push(e);
   }
   vector<int> visited(n, 0);
   visited[0] = 1;
   while(!pq.empty()){
	Edge cut = pq.top();
	pq.pop();
	if (visited[cut.to]) {
		continue;
	}
	
	visited[cut.to] = 1;
	mst += cut.weight;
	for(Edge e: graph[cut.to]){
		if(e.weight < dist[e.to]){
			pq.push(e);
		}
	}
   }
   for (int i = 0; i < n; i++){
	   if (!visited[i]){
		   return -1;
	   }
   }
   return mst;
}

/* MAIN FUNCTION */ /* You may add couts here for debugging, but do not write any logic here */
/* This function will be overwritten by our scripts during evaluation */
int main() {

    for(int j = 1; j < 11; j++){
    string tc_filename = "tests_q1/testcase" + to_string(j) + ".txt";
    string res_filename = "tests_q1/output" + to_string(j) + ".txt";

    ifstream tc(tc_filename);
    ifstream res(res_filename);

    if (!tc) {
        cout << "Could not open the testcase file!" << endl;
    } 

    if (!res) {
        cout << "Could not open the output file" << endl;
    }

    // Get the sizes of the graphs
    int n, m;
    tc >> n >> m;

    // Get the graph
    map<int, map<int,int>> graph;
    
    for(int i=0; i< m; i++) {
        int u,v,w;
        tc >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    long long ans = telephone_line_cost(n, m, graph);
    long long true_ans;

    res >> true_ans;

    if (ans == true_ans){
        cout << "Passed" << endl;
    } else {
        cout << "Failed! Expected: " << true_ans << ", Received: " << ans << endl;
    }

    tc.close();
    res.close();
    

}}
