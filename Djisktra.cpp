#include <bits/stdc++.h> 
#define INF INT_MAX 
#include<queue>
using namespace std;

int main() 
{ 
	int n, m,src;
	cin >> n >> m;
	vector<pair<it,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> vn >> wt; 
	    adj[u].push_back({v, wt}); 
	}
    cin>>src;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist{n+1,INT_MAX};
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int prev=pq.top().second;
        pq.pop();
        for(auto next:adj[prev])
        {
            int nextval=next.first;
            int nextdist=next.second;
            if(dist[prev]+next.second<dist[nextval])
            {
                dist[nextval]=dist[prev]+next.second;
                pq.push(make_pair(dist[nextval], nextval));
            }
            
        }
    }


	cout << "The distances from source, " << src << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << dist[i] << " ";
	cout << "\n";
	return 0; 
} 
