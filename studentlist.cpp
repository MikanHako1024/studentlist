#define MAX_SIZE 100

#define FNAME "stu_list.dat"
#define TYPE struct student_type

TYPE 
{
	int sno;
	char name[12];
	double score;
};


#include <stdio.h>
#include <stdlib.h>

// ？调整参数顺序 

// 指针还是数据的选择 

void Pri(TYPE stu)
{
	printf("输入学生学号 : %d\n", stu.sno);
	printf("输入学生姓名 : %s\n", stu.name);
	printf("输入学生成绩 : %.2lf\n", stu.score);
}

void PriAll(TYPE *headstu, int top)
{
	int i;
	for(i=0; i<top; i++)
		Pri( *(headstu+i) );
}

TYPE Sca()
{
	TYPE stu;
	printf("输入学生学号 : ");
	scanf("%d", &stu.sno);
	printf("输入学生姓名 : ");
	scanf("%s", stu.name);
	printf("输入学生成绩 : ");
	scanf("%lf", &stu.score);
	return stu;
}	


void Add(TYPE *headstu, int *ptop, TYPE stu)
{
	headstu[(*ptop)++]=stu;
}

TYPE Change(TYPE *pstu, TYPE stu)
{
	TYPE tstu=*pstu;
	*pstu=stu;
	return tstu;
}

TYPE Delete(TYPE *headstu, int *ptop, int m)	
{	
	// ？最后一个填充上去 

	// ？在父函数判断 m<top 等合法检查 
	TYPE tstu;
	//tstu={-1, "error", -1};
	tstu=headstu[m-1];
	if( *ptop>m ) // *ptop!=m
		headstu[m-1]=headstu[(*ptop)-1];
	(*ptop)--;
	return tstu;
	
	// 做了一些合并 
	/*
	// 原 
	if( *ptop==m )
	{
		(*ptop)--;
		return headstu[(*ptop)-1];	// *ptop==m 故 即是 return headstu[m-1]; // 与另一选择条件相同  
	}
	else
	{
		tstu=headstu[m-1];
		headstu[m-1]=headstu[(*ptop)-1];
		(*ptop)--;
		return tstu;
	}
	*/
}


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

void Clear()	// 清空/初始化 
{
	system("cls");
	
	printf("1 : Add\t\t");
	printf("2 : Read\n");
	
	printf("3 : Change\t");
	printf("4 : Delete\n");
	
	printf("5 : Load\t");
	printf("6 : Save\n");
	
	printf("7 : Pritop\t"); 
	printf("8 : Clear\n");
	
	printf("9 : Empty\t");
	printf("O : Exit\n");
}



// 待 
// 在完成后添加一些提示词 
// 输入合法判断 

int main()
{
	//printf("%d\n", sizeof(TYPE));
	
	TYPE stud[MAX_SIZE];
	int top=0;
	
	int flag; 
	TYPE tstu;
	char ch;
	int m;
	int i;
	Clear(); // Clear 兼容 输出菜单 
	
	do
	{
		printf("Enter flag : ");
		scanf("%d", &flag);
		switch(flag)
		{
			case 1:		// Add
			{
				Add(stud, &top, Sca());
				break;
			}
			
			case 2:		// Read
			{
				printf("输入序号 : ");
				scanf("%d", &m);
				if(m>=0)
					Pri(stud[m-1]);
				else
					PriAll(stud, top);
				break;
			}
				
			case 3:		// Change
			{
				
				printf("输入序号 : ");
				scanf("%d", &m);
				Change(stud+(m-1), Sca());
				break;	
			}
			
			case 4:		// Delete
			{
				printf("输入序号 : ");
				scanf("%d", &m);
				Delete(stud, &top, m);
				break;
			}
				
			case 5:		// Load
			{
				top=Load(stud);
				printf("载入完成\n");
				break;
			}
			
			case 6:		// Save
			{
			printf("保存完成\n"); 
				Save(stud, top);
				break;
			}
				
			case 7:		// pritop
			{
				printf("top : %d\n", top);
			}
			
			case 8:		// Clear
			{
				Clear();
				break;
			}
					
			case 9:		// Empty
			{
				Empty();
				break;	
			}
				
			case 0:		// Exit
			{ 
				printf("退出\n");
				return 0; 
			} 
			
			default:
			{
				printf("error enter\n");
			}
		}
	}while(flag!=0);

	return 0;
}

