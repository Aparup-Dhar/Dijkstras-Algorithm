#include<bits/stdc++.h>
using namespace std;

int main(){
    int node,edge,source;
    
    cin>>node>>edge; //taking input of number of nodes and edges
    vector<pair<int,int>>adjlist[node]; //pair adjacentcy list

    int a,b,wt;
    for(int i=0;i<edge;i++){
        cin>>a>>b>>wt; //push back 2 times beacuse it is undirected graph for directed push back only 1 time
        adjlist[a].push_back(make_pair(b,wt));
        adjlist[b].push_back(make_pair(a,wt));
    }

    cin>>source; //taking input of source node

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //min-heap priority queue(puts minimum value at first/top)
    vector<int>disTo(node,INT_MAX); //distance array(vector) INT_MAX means
                                      //vector is initialized by infinity,vector(size,initial-value)

    disTo[source]=0; //initialize value of source node
    pq.push(make_pair(0,source)); //insert into priorityqueue source node in form of (distance,node)

    while(!pq.empty()){
        int dist=pq.top().first; //taking distace of current node
        int prev=pq.top().second; //taking number(value) of current node
        pq.pop(); //poping the node

        vector<pair<int,int>>::iterator it; //finding the adjacent nodes of current node (Dont know how work??)
        for(auto it:adjlist[prev]){ //interation will be equal to number of adjacent nodes (e.g- node 1 has adj node 2,4) 
                                    //so it runs 2 time
                                    //one for node (2) and another for node (4)


            int next=it.first; //adjacent node number(value)
            int nextDist=it.second; //distance of adjacent node to current node

            if(disTo[next]>disTo[prev]+nextDist){ //distTo[next] here is initially infinity remember?(look line 21)
                disTo[next]=disTo[prev]+nextDist;
                pq.push(make_pair(disTo[next],next)); //push adjacent node to priorityqueue
                                                      //disTo[next] is weight of adjacent node
                                                      //next is number(value) of adjacent node
            }
        }
    }
    cout<<"The distances from source are :\n";
    for(int i=1;i<node;i++){
        cout<<source<<"----"<<i<<":"<<disTo[i]<<" ";
        cout<<"\n";
    } 
return 0;

}