#include<stdio.h>
void shellsort(int a[],int n)
{
	

    int i, j, k, t;
    for (i = n/ 2; i > 0; i = i / 2)
    {
        for (j = i; j < n; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (a[k+i] >= a[k])
                    break;
                else
                {
                    t = a[k];
                    a[k] = a[k+i];
                    a[k+i] = t;
                }
            }
        }
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
	
    shellsort(a,n);
	
	printf(" sorted order of elements\n");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	
	return 0;
}
