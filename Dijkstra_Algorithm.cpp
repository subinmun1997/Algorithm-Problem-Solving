#include <stdio.h>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define INF INT_MAX
int E,V,K;
struct uvw{
	int v;
	int w;
};

vector<uvw> arr[300001];
int dist[20001];
void dijkstra(){
	priority_queue<pair<int,int>>pq;
	pq.push(make_pair(0,K));
	while(!pq.empty()){
		int now=pq.top().second;
		int cost=-1*pq.top().first;
		pq.pop();
		for(int k=0;k<arr[now].size();k++){
			int new_w=dist[now]+arr[now][k].w;
			int before_w=dist[arr[now][k].v];
			if(new_w<before_w){
				dist[arr[now][k].v]=new_w;
				pq.push(make_pair(-1*new_w,arr[now][k].v));
			}
		}	
	}
}

int main(){
	scanf("%d %d",&V,&E);
	scanf("%d",&K);
	for(int i=0;i<E;i++){
		int from;
		int to;
		int value;
		scanf("%d %d %d",&from,&to,&value);
		arr[from].push_back(uvw{to,value});
	}
	for(int i=1;i<=V;i++){
		dist[i]=INF;
	}
	dist[K]=0;
	dijkstra();
	for(int i=1;i<=V;i++){
		if(dist[i]!=INF){
			printf("%d\n",dist[i]);
		}
		else{
			printf("INF\N");
		}
	}
}













