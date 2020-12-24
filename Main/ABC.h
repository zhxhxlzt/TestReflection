#pragma once
#include "Object.h"

class ABCD : public Object
{
	META_OBJECT(ABCD, Object)
	{
		REGISTER_FUNC(Init);
	}

public:
	META_VOID_FUNC_P(Init, { int a; int b; int c; })
	{
		a = args.a;
		b = args.b;
		c = args.c;
	}


private:
	int a, b, c;
	
};