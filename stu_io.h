// Pri, PriAll, Sca Functiones


void Pri(TYPE stu)
{
	printf("����ѧ��ѧ�� : %d\n", stu.sno);
	printf("����ѧ������ : %s\n", stu.name);
	printf("����ѧ���ɼ� : %.2lf\n", stu.score);
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
	printf("����ѧ��ѧ�� : ");
	scanf("%d", &stu.sno);
	printf("����ѧ������ : ");
	scanf("%s", stu.name);
	printf("����ѧ���ɼ� : ");
	scanf("%lf", &stu.score);
	return stu;
}
