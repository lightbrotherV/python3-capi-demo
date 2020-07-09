#include <stdio.h>
#include <Python.h>

// 设置导入模块路径本地
void setLocalPath()
{
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append('./')");
}

// 导入模块
PyObject *importModule(char *moduleName)
{
  return PyImport_ImportModule(moduleName);
}

// 获取模块字典
PyObject *getModuleDict(PyObject *module)
{
  return PyModule_GetDict(module);
}