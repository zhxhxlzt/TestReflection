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

	META_FUNCTION_NO_ARGS_WITH_RETURN(GetObjectName, std::string)
	{
		return "Hello";
	}
};

