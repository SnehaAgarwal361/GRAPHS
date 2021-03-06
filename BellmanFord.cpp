#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int u;
    int v;
    int wt;
    node(int first,int second,int weight)
    {
        u=first;
        v=second;
        wt=weight;
    }
};
int main()
{
  int n,m,u,v,wt;
  cin>>n>>m;
  vector<node>adj;
  for(int i=0;i<m;i++)
  {
      cin>>u>>v>>wt;
      adj.push_back(node(u,v,wt));
  }
  int src;
  cin>>src; 
   int inf = 10000000; 
   vector<int> dist(n, inf); 
  dist[src]=0;
  for(int i=1;i<=n-1;i++)
  {
  for(auto it:adj)

  {
      if(dist[it.u]+it.wt<dist[it.v]){
         dist[it.v]= dist[it.u]+it.wt;
      }
  }
  }
    int fl = 0; 
    for(auto it: adj) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle"; 
            fl = 1; 
            break; 
        }
    }

    if(!fl) {
        for(int i = 0;i<n;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }
    return 0;
}

/* 
6 7 
3 2 6 
5 3 1 
0 1 5 
1 5 -3 
1 2 -2 
3 4 -2 
2 4 3 
0
*/
