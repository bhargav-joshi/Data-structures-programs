#include<stdio.h>
int findmax(int a[],int n)
{
	int max,i;
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	return max;
}

void radixsort(int a[],int n)
{
	int bucket[10][10]={0},count[10];
    int i,j,k,rem,nop=0,div=1,max,pass;
    //count no of pass required
    max=findmax(a,n);
    while(max>0)
    {
    	nop++;
    	max=max/10;
	}
	
	for(pass=0;pass<nop;pass++)
	{
        	for(i=0;i<n;i++)
        	count[i]=0;
		for(i=0;i<n;i++)
		{
			//sort nos to digit as per pass th place
			rem=(a[i]/div)%10;
			bucket[rem][count[rem]]=a[i];
			count[rem]++;
		}
		//collect nos after that pass
		i=0;
		for(k=0;k<10;k++)
		{
			for(j=0;j<count[k];j++)
			{
				a[i]=bucket[k][j];
				i++;
			}
		}
		div=div*10;
	}
	
	
	
}

int main()
{
		int a[20],n,i;
	printf(" enter nos of elements in array\n");
	scanf("%d",&n);
	
	printf("enter elements in array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf(" original order of elements\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	printf("\n");
	
    radixsort(a,n);
	
	printf(" sorted order of elements\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	return 0;
}
