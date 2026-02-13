#include <stdio.h>
#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <vector<int>> adjList;
vector <int> path;
vector <int> visited;
int V;

bool hasEdge(int u, int v)
{
    for(int x: adjList[u]){
        if(x==v)
        return true;
    }
    return false;
}
bool solve(int u, int count)
{
    if(count==V){
        return hasEdge(u, path[0]);
    }
    for(int v:adjList[u])
    {
        if(!visited[v]){
            visited[v]=true;
            path.push_back(v);
            if(solve(v, count+1))
            return true;
            visited[v]=false;
            path.pop_back();
        }
    }
    return false;
}
int main()
{
    V=5;
    adjList={
        {1, 2},
        {0},
        {0}
            /*{1,3},
            {0,2,3,4},
            {1,4},
            {0,1,4},
            {1,2,3}*/
    };
    visited.assign(V, false);
    path.push_back(0);
    visited[0]=true;
    if(solve(0, 1)){
        for(int i: path)
        cout << i <<"  ";
    }
    else
    cout << "No path exists"<<endl;
}