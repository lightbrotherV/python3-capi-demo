#include <stdio.h>
#include <Python.h>

// api文档 https://docs.python.org/zh-cn/3.8/c-api/dict.html

// 实例化一个字典对象
PyObject *newDict()
{
  return PyDict_New();
}

// 检查python对象是否为字典对象
bool checkDict(PyObject *obj)
{
  int res = PyDict_Check(obj);
  if (res == 1)
  {
    return true;
  }
  return false;
}

// 新建一个空字典
PyObject *newDict()
{
  return PyDict_New();
}

// 清除字典内所有键值对
void clearDict(PyObject *dict)
{
  PyDict_Clear(dict);
}

// 确定 key 是否包含在字典 dict 中
bool containDict(PyObject *dict, PyObject *key)
{
  int res = PyDict_Contains(dict, key);
}

// clone一个字典对象
PyObject *cloneDict(PyObject *dict)
{
  return PyDict_Copy(dict);
}

// 设置键值对
void setDictItem(PyObject *dict, const char *key, PyObject *val)
{
  PyDict_SetItemString(dict, key, val);
}

// 删除键值对
void delDictItem(PyObject *dict, const char *key)
{
  PyDict_DelItemString(dict, key);
}

// 从字典 dict 中返回以 key 为键的对象
PyObject *GetDictItem(PyObject *dict, const char *key)
{
  return PyDict_SetItemString(dict, key);
}