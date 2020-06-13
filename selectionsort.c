#include<stdio.h>
void selectionsort(int a[],int n)
{
	int i,j,t,min,p;
	for(i=0;i<n-1;i++)
	{
		min=a[i];
		p=i;
		
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
			min=a[j];
			p=j;
			}
		
		}
		t=a[p];
		a[p]=a[i];
		a[i]=t;
	}
}
int main()
{	int a[20],n,i;
	printf(" enter nos of elements in array\n");
	scanf("%d",&n);
	
	printf("enter elements in array\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	printf(" original order of elements\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
	selectionsort(a,n);
	printf(" sorted order of elements\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	return 0;
}
