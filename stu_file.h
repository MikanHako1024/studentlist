// Save, Load, Empty, PriFname Functions


#define FNAME "stu_list.dat"
	// the name of file 

void PriFname() // ��ӡ�ļ��� 
{
	printf(FNAME);
}

void Save(TYPE *stu, int top) // ���� 
{
	FILE *fp;
	if( (fp=fopen(FNAME, "wb+"))==NULL ) 
	{
		printf("���ܴ��ļ�!\n");
		return ;
	}
	fwrite(&top, sizeof(int), 1, fp);
	//fseek(fp, 1, SEEK_SET);
	int i;
	for(i=0; i<top; i++)
		if( fwrite(stu+i, sizeof(TYPE), 1, fp)!=1 )
			printf("д�ļ�����!\n");
	fclose(fp);
}


int Load(TYPE *stu) // ��ȡ 
{
	FILE *fp;
	if( (fp=fopen(FNAME, "rb+"))==NULL )
	{
		printf("���ܴ��ļ�!\n");
		return -1;
	}
	int top;
	fread(&top, sizeof(int), 1, fp);
	int i;
	for(i=0; i<top; i++)
		if( fread(stu+i, sizeof(TYPE), 1, fp)!=1 )
			printf("���ļ�����!\n");
	fclose(fp);
	return top;
}


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
