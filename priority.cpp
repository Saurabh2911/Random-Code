#include<stdio.h> 
#include<conio.h> 
# define max 30 
int main() 
{ 
 int i,n,j,k=1,t,b=0,min,temp[max],bt[max],wt[max],at[max],pr[max],tat[max];
 float awt=0,atat=0; 
 printf("Enter the number of process \n"); 
 scanf("%d",&n); 
 printf("Enter the burst time, arrival time & priority of the process\n");
 for (int i=0; i<n; i++) 
 
 { 
 scanf("%d %d %d",&bt[i],&at[i],&pr[i]); 
 }  
 for(int i=0;i<n;i++) 
 { 
 for(int j=0;j<n;j++) 
 { 
 if (at[i]<at[j]) 
 { 
 
 t=at[j]; 
 at[j]=at[i]; 
 at[i]=t; 
 t=bt[j]; 
 bt[j]=bt[i]; 
 bt[i]=t; 
 } 
 }
 } 
 
 for(int j=0;i<n;j++)  
 { 
 
 b=b+bt[j]; 
 min=bt[k]; 
 for(int i=k; i<n; i++)  { 
 
 min=pr[k]; 
 if (b>=at[i])  { 
 if (pr[i]<min)  { 
 
 t=at[k];  at[k]=at[i];
 at[i]=t; 
 
 t=bt[k];  bt[k]=bt[i];
 bt[i]=t; 
 
 t=pr[k];  pr[k]=pr[i];
 pr[i]=t;  } 
 
 } 
 } 
 k++; 
 } 

 temp[0]=0;
 printf("\nprocess\t burst time\t arrival time\t priority\t waiting time\t turn around time\n");
 for (int i=0;i<n;i++) 
 { 
 
 wt[i]=0; 
 tat[i]=0; 
 temp[i+1]=temp[i]+bt[i]; 
 wt[i]=temp[i]-at[i]; 
 tat[i]=wt[i]+bt[i]; 
 awt=awt+wt[i]; 
 atat=atat+tat[i]; 
 printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],at[i],pr[i],wt[i],tat[i]);  } 
 awt=awt/n; 
 atat=atat/n; 
 printf("Average waiting time = %f\n",awt); 
 printf("Average turn around time=%f",atat); 
 getch(); 
}
