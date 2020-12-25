#define PY_SSIZE_T_CLEAN
#include <Python.h>

void InitPy()
{
	Py_Initialize();
}