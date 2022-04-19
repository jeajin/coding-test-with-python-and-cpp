#include <stdio.h>
int main() {
	int N;	
	scanf("%d",&N);
	
	int A[N][2]={0,};
	for(int i=0;i<N;i++) scanf("%d %d",&A[i][0],&A[i][1]);
	
	int minEndTime,index,temp;
	for( int i=0;i<N-1;i++){
		minEndTime = A[i][1];
		index=i;
		for( int j=i+1;j<N;j++){
			if(minEndTime>A[j][1]){	
			minEndTime=	A[j][1];
			index=j;
			}
		}
		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;
	}

	
	int shortEndTime,TimeIndex=0,nextStartTime=-1,count=0;
	bool find = true;
	while(find){
	
		find = false;
		shortEndTime = 2147483647;
		for(int i=TimeIndex;i<N;i++){
			if(shortEndTime>=A[i][1] && A[i][0]>nextStartTime){
				shortEndTime = A[i][1];
				TimeIndex = i;
				find =true;	
			}	
		}
		
		nextStartTime = A[TimeIndex][1];
		if(find){
			count ++;	
			printf("(%d %d)",A[TimeIndex][0],A[TimeIndex][1]);
		}	
	} 
	printf("%d",count );
	return 0;
}

