#pragma once
#include "MetaObject.h"

class Object
{
	META_OBJECT(Object, None)
	{
		REGISTER_METHOD(Nice);
	};
	
public:
	META_FUNCTION_NO_ARGS(Nice)
	{
		printf("Nice!");
	}
	
};

