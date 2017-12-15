#include <stdio.h>
#include "base.h"

void Empty() 	// 清空 
{
	FILE *fp;
	if( (fp=fopen(FNAME, "w"))==NULL )
	{
		printf("不能打开文件!\n");
		return ;
	}
	fclose(fp);
}
