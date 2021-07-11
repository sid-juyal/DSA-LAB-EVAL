#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
class Graph
{
    map<T,list<T>>l;
public:
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void BFS(T start, T stop, T v, int pred[], int dist[])
    {
        map<T,bool>visited;
        queue<T>q;

        for(auto node_pair:l)
        {
            T node=node_pair.first;
            dist[node]=INT_MAX;
            pred[node]= -1;
            visited[node]= false;
        }

        q.push(start);
        visited[start]=true;
        dist[start]=0;

        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            for(int nbr:l[node])
            {
                if(!visited[nbr])
                {
                    visited[nbr]=true;
                    dist[nbr]=dist[node]+1;
                    pred[nbr]=node;
                    q.push(nbr);
                    if(nbr==stop)
                    {
                        return;
                    }
                }
            }
        }
    }
    void print_path(T start, T stop, T v)
    {
        int pred[v];
        int dist[v];
        BFS(start,stop,v,pred,dist);
        vector<int> path;
        int move_forw = stop;
        path.push_back(move_forw);
        while (pred[move_forw] != -1)
        {
            path.push_back(pred[move_forw]);
            move_forw = pred[move_forw];
        }
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << " ";
    }
};

int main()
{
    Graph<int> g;
    int m,n,s;
    cin>>m>>n>>s;
    int a[m*n][9];
    for(int i=0;i<m*n;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m*n;i++)
    {
        for(int j=1;j<9;j++)
        {
            if(a[i][j]==1)
            {
                if(j==1)
                {
                    g.addEdge(a[i][0],a[i][0]-n);
                }
                else if(j==2)
                {
                    g.addEdge(a[i][0],a[i][0]-n+1);
                }
                else if(j==3)
                {
                    g.addEdge(a[i][0],a[i][0]+1);
                }
                else if(j==4)
                {
                    g.addEdge(a[i][0],a[i][0]+n+1);
                }
                else if(j==5)
                {
                    g.addEdge(a[i][0],a[i][0]+n);
                }
                else if(j==6)
                {
                    g.addEdge(a[i][0],a[i][0]+n-1);
                }
                else if(j==7)
                {
                    g.addEdge(a[i][0],a[i][0]-1);
                }
                else
                {
                    g.addEdge(a[i][0],a[i][0]-n-1);
                }
            }
        }
    }
    g.print_path(s,1,m*n);
    cout<<endl;
    g.print_path(s,n,m*n);
    cout<<endl;
    g.print_path(s,m*n-n+1,m*n);
    cout<<endl;
    g.print_path(s,m*n,m*n);
    return 0;
}
