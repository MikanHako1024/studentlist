#include <stdio.h>

#include "base.h"

TYPE Change(TYPE *pstu, TYPE stu)
{
	TYPE tstu=*pstu;
	*pstu=stu;
	return tstu;
}

