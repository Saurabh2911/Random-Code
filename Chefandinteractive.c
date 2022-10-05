#include<stdio.h>
int main()
{
	int n,r;
	scanf("%d %d",&n,&r);
	while(n--)
	{
		int R;
		scanf("%d",&R);
		if (R<r)
		{
			printf("Bad boi\n");
		}
		else
		{
			printf("Good boi\n");
		}
	}
	return 0;
}