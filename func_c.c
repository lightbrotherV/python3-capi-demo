#include <stdio.h>
#include <Python.h>

// api文档：https://stackoverflow.com/questions/29301824/what-is-the-pyclass-new-equivalent-in-python-3
// https://www.oreilly.com/library/view/python-cookbook/0596001673/ch16s06.html
// https://www.coder.work/article/3289809

char *reprint(PyObject *obj)
{
  PyObject *repr = PyObject_Repr(obj);
  PyObject *str = PyUnicode_AsEncodedString(repr, "utf-8", "~E~");
  char *bytes = PyBytes_AS_STRING(str);
  Py_XDECREF(repr);
  Py_XDECREF(str);
  return bytes;
}

static PyObject *test_class_add(PyObject *self, PyObject *args)
{
  
  PyObject *nameObj = PyObject_GetAttrString(self, "name");
  printf("input name: %s\n", reprint(nameObj));

  // ---
  int res = 123;
  printf("input i: %d\n", res);
  res++;
  return (PyObject *)Py_BuildValue("i", res);
}

// bool checkFunc(PyObject *func)
// {
//   int res = PyMethod_Check(func);
//   if (res != 1)
//   {
//     return false;
//   }
//   return true;
// }

int main()
{

  // 初始化Python虚拟机
  Py_Initialize();
  // 判断Python虚拟机是否成功
  if (Py_IsInitialized() == 0)
  {
    printf("fal to initialize Python\n");
    return -1;
  }

  printf("server run\n");
  // 导入模块
  PyRun_SimpleString("import sys");
  PyRun_SimpleString("sys.path.append('./')");
  // PyObject* pModule = PyImport_ImportModule("test-c");
  // PyObject* pDict = PyModule_GetDict(pModule);
  // PyObject* pFunHi = PyDict_GetItemString(pDict, "on_info");
  // PyObject *serverModule = PyImport_ImportModule("test_class");
  // PyObject *serverDict = PyModule_GetDict(serverModule);
  // PyObject *serverClass = PyDict_GetItemString(serverDict, "Test");
  // PyObject *instanceServer = PyObject_CallObject(serverClass, NULL);

  char *ml_name = "add";
  char *name = "testClass";

  // 新建类
  PyObject *testClassDict = PyDict_New();
  PyObject *testClass = PyObject_CallFunctionObjArgs((PyObject *)&PyType_Type, PyUnicode_FromString("Test"), PyTuple_New(0), testClassDict, NULL);
  PyMethodDef add_func_def = {ml_name, (PyCFunction)test_class_add, METH_NOARGS, ""};
  PyObject *func = PyCFunction_New(&add_func_def, testClass);
  PyObject_SetAttrString(testClass, ml_name, func);
  PyObject_SetAttrString(testClass, "name", PyUnicode_FromString(name));
  PyObject *res = PyObject_CallFunction(func, NULL, NULL);
  int addRes;
  PyArg_Parse(res, "i", &addRes);
  printf("res int: %d\n", addRes);
  // PyMethod_New();
  // 退出Python虚拟机
  Py_Finalize();
  return 0;
}
