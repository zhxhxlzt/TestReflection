#pragma once
#include "STD.h"





struct MetaObjectInfo;
namespace
{
	std::map<std::string, MetaObjectInfo*> s_meta_info;
}




struct MetaObjectInfo
{
	using FunctionTypeNoArgs = std::function<void(void*)>;
	std::string class_name;
	std::string base_class_name;

	std::map<std::string, FunctionTypeNoArgs> no_args_func_map;
};




#define META_OBJECT(DeriveClassType, BaseClassType)	\
public:	\
	using ClassType = DeriveClassType;	\
	static MetaObjectInfo* GetMetaObjectInfo() { static MetaObjectInfo info{ #DeriveClassType, #BaseClassType }; return &info; }	\
	virtual const std::string& GetRealClassName() const { static const std::string real_class_name = #DeriveClassType; return real_class_name;}	\
	DeriveClassType() {	\
		static bool meta_inited = false; \
		if (!meta_inited) {	\
			s_meta_info[GetRealClassName()] = GetMetaObjectInfo();	\
			RegisterAllMethod();	\
			meta_inited = true;	\
		}	\
	}	\
private:	\
	static void RegisterAllMethod()


#define META_FUNCTION_NO_ARGS(FuncName)	\
static void RegisterMetaFunction ## FuncName()	{	\
	auto f = [](void* vobj)	{ static_cast<ClassType*>(vobj)->FuncName(); };	\
	GetMetaObjectInfo()->no_args_func_map[#FuncName] = f;	\
}	\
void FuncName()

#define REGISTER_METHOD(FuncName) RegisterMetaFunction ## FuncName()
	

template<typename D, typename B>
bool IsBaseClassOf(const D& d, const B& b)
{
	auto it = s_meta_info.find(d.GetRealClassName());
	auto base_class_name = b.GetRealClassName();
	while (it != s_meta_info.end())
	{
		auto meta_info = it->second;
		if (meta_info->base_class_name == base_class_name)
		{
			return true;
		}
		it = s_meta_info.find(meta_info->base_class_name);
	}
	return false;
}

class A
{
	META_OBJECT(A, None);
	void Say()
	{
		printf("Hello");
	}
	
	META_FUNCTION_NO_ARGS(Hello)
	{
		
	}
	
};



#define GOGOGO(...)