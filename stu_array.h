// Add, Delete, Change Functions


void Add(TYPE *headstu, int *ptop, TYPE stu)
{
	headstu[(*ptop)++]=stu;
}


TYPE Delete(TYPE *headstu, int *ptop, int m)	
{	
	// ？最后一个填充上去 
	TYPE tstu;
	tstu=headstu[m-1];
	if( *ptop>m )
		headstu[m-1]=headstu[(*ptop)-1];
	(*ptop)--;
	return tstu;
	
}


TYPE Change(TYPE *pstu, TYPE stu)
{
	TYPE tstu=*pstu;
	*pstu=stu;
	return tstu;
}

