#pragma once
#include "MetaObject.h"




class Object
{
	META_OBJECT(Object, None);
};

class Box : public Object
{
	META_OBJECT(Box, Object);
public:
	META_VOID_FUNC_P(SetProperty, { int length; int width; int height; }) {
		length = args.length;
		width = args.width;
		height = args.height;
	}

	META_FUNC(GetScaledVolumn, int, int, scale) {
		return length * width * height * scale;
	}

	META_FUNC_VOID(GetVolumn, int) {
		return length * width * height;
	}

	META_VOID_FUNC_VOID(Clear) {
		length = width = height = 0;
	}

private:
	int length;
	int width;
	int height;

};
