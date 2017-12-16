// Pri, PriAll, Sca Functiones


void Pri(TYPE stu)
{
	printf("输入学生学号 : %d\n", stu.sno);
	printf("输入学生姓名 : %s\n", stu.name);
	printf("输入学生成绩 : %.2lf\n", stu.score);
}


void PriAll(TYPE *headstu, int top)
{
	void Pri(TYPE stu);
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
