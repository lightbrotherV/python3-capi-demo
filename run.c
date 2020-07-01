#include <stdio.h>
#include <Python.h>

bool start() {
  // 初始化Python虚拟机
    Py_Initialize();
    // 判断Python虚拟机是否启动成功
    if (Py_IsInitialized() == 0){
        return false;
    }
}

void end() {
  // 退出Python虚拟机(须先成功启动python虚拟机)
    Py_Finalize();
}