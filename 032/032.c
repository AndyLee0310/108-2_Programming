#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct mc{
	int state;
}machine_t;

typedef struct amc{
	machine_t mc[100];
}allmachine_t;

typedef struct dg{
	int name;
	int hours;
	int usemachine;
}go_t;

typedef struct dw{
	int workname;
	go_t go[100];
	int state;
	int time;
}work_t;

typedef struct daw{
	work_t work[100];
}allwork_t;

int max(work_t work,allmachine_t amc,int state){
	int use=work.go[state].usemachine,sum1,sum2;
	sum1=(amc.mc[use].state)+(work.go[state].hours);
	sum2=(work.time)+(work.go[state].hours);
	if(sum1>=sum2)return sum1;
	else return sum2;
}

int start(allwork_t allwork,allmachine_t amc,int mcs,int wns,int rtns[],int as[]){
	int i=0,j,a,pk[100],MIN,checkmachine,checkmachine2,breaktime[100],checkvalue,breakwhile=1;
	while(1){
		breakwhile=1;
		for(j=0;j<wns;j++){
			if(breaktime[j]==1)continue;
			pk[j]=max(allwork.work[j],amc,allwork.work[j].state);
		}
		MIN=pk[0];
		for(j=0;j<wns;j++){
			if(breaktime[j]==1)continue;
			if(pk[j]<MIN)MIN=pk[j];
		}
		for(j=0;j<wns;j++){
			if(pk[j]==MIN){
				if(breaktime[j]==1)continue;
				checkmachine=allwork.work[j].go[allwork.work[j].state].usemachine;
				amc.mc[checkmachine].state=pk[j];
				allwork.work[j].time=pk[j];
				allwork.work[j].state+=1;
				break;
			}
		}
		for(j=0;j<wns;j++){
			if(allwork.work[j].state==rtns[j]){
			breaktime[j]=1;
			pk[j]=200;
			as[j]=allwork.work[j].time;
			}
		}
		for(j=0;j<wns;j++){
			if(breaktime[j]==0){
				breakwhile=0;
				}
		}
		for(j=0;j<wns;j++){
		}
		for(j=0;j<mcs;j++){
		}

		if(breakwhile==1)break;
	}
	return 0;
}

int main() {
	int mcs,wns,rtns[100],i,j,a,as[100],s=0;
	allwork_t allwork;
	allmachine_t amc;
	scanf(" %d %d",&mcs,&wns);
	for(i=0;i<wns;i++){
		scanf(" %d",&rtns[i]);
		for(j=0;j<rtns[i];j++){
			scanf(" %d",&allwork.work[i].go[j].usemachine);
			scanf(" %d",&allwork.work[i].go[j].hours);
			allwork.work[i].workname=i;
			allwork.work[i].go[j].name=j;
		}
	}
	start(allwork,amc,mcs,wns,rtns,as);
	for(j=0;j<wns;j++){
		s+=as[j];
		}
	printf("%d",s);
	
	return 0;
}

