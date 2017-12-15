#include <stdio.h>

#include "base.h"

void Save(TYPE *stu, int top)
{
	FILE *fp;
	if( (fp=fopen(FNAME, "wb+"))==NULL ) 
	{
		printf("不能打开文件!\n");
		return ;
	}
	fwrite(&top, sizeof(int), 1, fp);
	//fseek(fp, 1, SEEK_SET);
	int i;
	for(i=0; i<top; i++)
		if( fwrite(stu+i, sizeof(TYPE), 1, fp)!=1 )
			printf("写文件出错!\n");
	fclose(fp);
}


int Load(TYPE *stu)
{
	FILE *fp;
	if( (fp=fopen(FNAME, "rb+"))==NULL )
	{
		printf("不能打开文件!\n");
		return -1;
	}
	int top;
	fread(&top, sizeof(int), 1, fp);
	int i;
	for(i=0; i<top; i++)
		if( fread(stu+i, sizeof(TYPE), 1, fp)!=1 )
			printf("读文件出错!\n");
	fclose(fp);
	return top;
}
