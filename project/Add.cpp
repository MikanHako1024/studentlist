#include <stdio.h>

#include "base.h"

void Add(TYPE *headstu, int *ptop, TYPE stu)
{
	headstu[(*ptop)++]=stu;
}
