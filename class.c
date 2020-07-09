#include <stdio.h>
#include <Python.h>

// api 文档  https://docs.python.org/zh-cn/3.8/c-api/object.html

// 新建一个class
PyObject *createClass(char *className, PyObject *classDict)
{
  if (classDict == null)
  {
    classDict = PyDict_New();
  }
  PyObject *pClassBases = PyTuple_New(0); // An empty tuple for bases is equivalent to `(object,)`
  return PyObject_CallFunctionObjArgs((PyObject *)&PyType_Type, className, pClassBases, classDict, NULL);
}

// 根据class实例化一个对象
PyObject *newClass(PyObject *_class)
{
  return PyObject_CallObject(_class, NULL);
}

// 设置对象属性
void setAttr(PyObject *classInstance, char *attrName, PyObject *attrValue)
{
  PyObject_SetAttrString(classInstance, attrName, attrValue);
}

// 获取对象属性, 不存在返回null
PyObject *getAttr(PyObject *classInstance, char *attrName)
{
  return PyObject_GetAttrString(classInstance, attrName)
}

// 判断对象是否存在属性
bool hasAttr(PyObject *classInstance, char *attrName)
{
  int res = PyObject_HasAttrString(classInstance, attrName) if (res == 1)
  {
    return true;
  }
  return false;
}
