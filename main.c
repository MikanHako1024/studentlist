#include <stdio.h>
#include <stdlib.h>
#include "stu_base.h"

#include "stu_io.h"
#include "stu_array.h"
#include "stu_sys.h"
#include "stu_file.h"


// ����������˳�� 

// ָ�뻹�����ݵ�ѡ�� 

void Pri(TYPE stu);
TYPE Sca();
void PriAll(TYPE *headstu, int top);
TYPE Change(TYPE *pstu, TYPE stu);
TYPE Delete(TYPE *headstu, int *ptop, int m);	
void Clear();
void Save(TYPE *stu, int top);
int Load(TYPE *stu);
void Empty();
void Add(TYPE *headstu, int *ptop, TYPE stu);

/*
TYPE 
{
	int sno;		// studentNo
	char name[12];	// studentName
	double score;	// studentScore
};
*/

/*	
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
*/


// �� 
// ����ɺ����һЩ��ʾ�� 
// ����Ϸ��ж� 

int main(int argc, char** argv)
{
	//printf("%d\n", sizeof(TYPE));
	//printf("%d\n", sizeof(num));
	//printf("%d\n", sizeof(name));
	//printf("%d\n", sizeof(score));
	
	int i;
	TYPE stud[MAX_SIZE];
	int top=0;
	
	
	
	int flag; 
	TYPE tstu;
	char ch;
	int m;
	
	Clear(); // Clear ���� ����˵� 
	
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
				printf("������� : ");
				scanf("%d", &m);
				if(m>=0)
					Pri(stud[m-1]);
				else
					PriAll(stud, top);
				break;
			}
				
			case 3:		// Change
			{
				
				printf("������� : ");
				scanf("%d", &m);
				Change(stud+(m-1), Sca());
				break;	
			}
			
			case 4:		// Delete
			{
				printf("������� : ");
				scanf("%d", &m);
				Delete(stud, &top, m);
				break;
			}
				
			case 5:		// Load
			{
				top=Load(stud);
				printf("�������\n");
				break;
			}
			
			case 6:		// Save
			{
			printf("�������\n"); 
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
				printf("1 : Empty array\n");
				printf("2 : Empty file\n");
				printf("Empty Way : ");
				scanf("%d", &flag);
				if(flag==1)
				{
					top=0;
					printf("���������\n");
				}
				else if(flag==2)
				{
					Empty();
					printf("������ļ�\n");
				}
				flag=9;
				break;	
			}
				
			case 0:		// Exit
			{ 
				printf("�˳�\n");
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

