#include <stdio.h>

#include "base.h"

TYPE Delete(TYPE *headstu, int *ptop, int m)	
{	
	// �����һ�������ȥ 
	TYPE tstu;
	tstu=headstu[m-1];
	if( *ptop>m )
		headstu[m-1]=headstu[(*ptop)-1];
	(*ptop)--;
	return tstu;
	
}

