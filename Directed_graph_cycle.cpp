//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int> &recNode, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        recNode[node] = 1;
        for(auto adjNode : adj[node])
        {
            if(!vis[adjNode])
            {
                if(dfs(adjNode, recNode, vis, adj))
                    return true;
            }
            else if(recNode[adjNode])
                return true;
        }
        recNode[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> recStack(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, recStack, vis, adj))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends