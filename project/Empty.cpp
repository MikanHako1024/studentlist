#include <stdio.h>
#include "base.h"

void Empty() 	// ��� 
{
	FILE *fp;
	if( (fp=fopen(FNAME, "w"))==NULL )
	{
		printf("���ܴ��ļ�!\n");
		return ;
	}
	fclose(fp);
}
