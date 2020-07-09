#include <stdio.h>
#include <Python.h>

// api 文档： https://docs.python.org/zh-cn/3.8/c-api/method.html

// 创建一个函数对象
// funcFlag: METH_NOARGS:无参数， 
//           METH_VARARGS|METH_KEYWORDS :同时拥有匿名参数和关键字参数
PyObject *createFunc(const char *name, PyCFunction funcPointer, int funcFlag, const char *funcDoc)
{
  PyMethodDef add_func_def = {name, (PyCFunction)funcPointer, funcFlag, funcDoc};
  PyObject *func = PyCFunction_New(&add_func_def, NULL);
  return func;
}