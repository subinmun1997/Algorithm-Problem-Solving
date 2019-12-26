#include <stdio.h>
#include <stdlib.h>
#define MAXN 55

typedef struct {
	int row;
	int col;
}index;

int M,N,K;
int ground[MAXN][MAXN];

index queue[3000];

void enqueue2(int* rear, index p){
	queue[(*rear)++]=p;
	ground[p.row][p.col] = 1;
}

void search_cabbage(index first){
	int front = 0;
	int rear = 0;
	
	enqueue2(&rear,first);
	while(rear != front){
		index p = queue[front++];
		index up = p;
		up.row = p.row-1;
		if(up.row>=0 && ground[up.row][up.col] == -1){
			enqueue2(&rear,up);
		}
		index right = p;
		right.col = p.col +1;
		if(right.col < N && ground[right.row][right.col]== -1){
			enqueue2(&rear,right);
		}
		index down = p;
		down.row = p.row+1;
		if(down.row < M&& ground[down.row][down.col]== -1){
			enqueue2(&rear,down);
		}
		index left = p;
		left.col = p.col -1;
		if(left.row >=0 && ground[left.row][left.col] == -1){
			enqueue2(&rear,left);
		}
	}
	
}

int main(void){
	int T;
	int i,j,l;
	int r,c;
	
	scanf("%d",&T);
	for(i=0;i<T;i++){
		int worm = 0;
		scanf("%d%d%d",&M,&N,&K);
		
		for(j=0;j<M;j++){
			for(l=0;l<N;l++)
				ground[j][l]=0;
		}
		for(j=0;j<K;j++){
			scanf("%d%d",&r,&c);
			ground[r][c]= -1;
		}
		
		for(r=0;r<M;r++){
			for(c=0;c<N;c++){
				if(ground[r][c]== -1){
					index tmp = {r,c};
					search_cabbage(tmp);
					worm++;
				}
			}
		}
		printf("%d\n",worm);
	}
	return 0;
}














