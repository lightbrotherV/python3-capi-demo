#include <stdio.h>
#include <Python.h>

char* pyObj2string(PyObject *obj) {
    PyObject* repr = PyObject_Repr(obj);
    PyObject* str = PyUnicode_AsEncodedString(repr,"utf-8","~E~");
    char *bytes = PyBytes_AS_STRING(str);
    Py_XDECREF(repr);
    Py_XDECREF(str);
    return bytes;
}