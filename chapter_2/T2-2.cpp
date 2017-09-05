#define LOCAL
#include<stdio.h>

int main()
{
	FILE *fin,*fout;
	fin = fopen("T2.2.in","rb");
	fout = fopen("T2.2.out","wb");
	int a,b,c,kase=0;
	printf("scanf=%d\n");
	while(fscanf(fin,"%d %d %d",&a,&b,&c) == 1)
	{
		kase++;
		for(int i = 10 ; i <= 100 ;i++)
		{
			if(i%3 == a && i%5 == b && i%7 == c)
			{
				printf("case %d: %d\n", kase,i);
				fprintf(fout,"case %d: %d\n", kase,i);
				break;
			}
		}
		if(i == 101)
		{
			printf("case %d:no answer\n",kase);
			fprintf(fout,"case %d:no answer\n",kase);
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}