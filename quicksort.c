#include<stdio.h>
int partition(int a[],int low,int high)
{
int x,i,j,t;
x=a[low];
i=low;
j=high;
	
	while(i<=j)
	{
		while(a[i]<=x)//i is looking for greater value than x
		i++;
		
		while(a[j]>x)//j is looking for <= value than x
		j--;
		
		if(i<j)
		{
		
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	   
	   }
	}
	
	t=a[low];
	a[low]=a[j];
	a[j]=t;
	
	return j;
	}
void quicksort(int a[],int low,int high)
{
int pos;
if(low<high)//array ka size 1 nahi hojata
{
	pos=partition(a,low,high);
	quicksort(a,low,pos-1);
	quicksort(a,pos+1,high);
	
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
	
    quicksort(a,0,n-1);
	
	printf(" sorted order of elements\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	return 0;
}
