#include <stdio.h>
#include <Python.h>


char* reprint(PyObject *obj) {
    PyObject* repr = PyObject_Repr(obj);
    PyObject* str = PyUnicode_AsEncodedString(repr,"utf-8","~E~");
    char *bytes = PyBytes_AS_STRING(str);
    Py_XDECREF(repr);
    Py_XDECREF(str);
    return bytes;
}

int main() {
  
    // 初始化Python虚拟机
    Py_Initialize();
    // 判断Python虚拟机是否成功
    if (Py_IsInitialized() == 0){
        printf("fal to initialize Python\n");
        return -1;
    }
 
    printf("server start\n");
    // 导入模块
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./')");
    // PyObject* pModule = PyImport_ImportModule("test-c");
    // PyObject* pDict = PyModule_GetDict(pModule);
    // PyObject* pFunHi = PyDict_GetItemString(pDict, "on_info");
    PyObject* serverModule = PyImport_ImportModule("test_class");
    PyObject* serverDict = PyModule_GetDict(serverModule);
    PyObject* serverClass = PyDict_GetItemString(serverDict, "Test");
    PyObject* instanceServer = PyObject_CallObject(serverClass,NULL);
    PyObject* sname = PyUnicode_FromString("sname");
    PyObject* skey = PyUnicode_FromString("skey");
    PyObject* idparam = PyObject_GetAttrString(instanceServer, "name_1");
    char* bytes = reprint(idparam);
    printf("REPR: %s\n", bytes);
    PyObject_SetAttr(instanceServer, sname, skey);
    idparam = PyObject_GetAttrString(instanceServer, "sname");
    bytes = reprint(idparam);
    printf("REPR: %s\n", bytes);
    printf("server end\n");
    // 退出Python虚拟机
    Py_Finalize();
    return 0;
}