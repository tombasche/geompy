#include "Python.h"
#include "validate/duplicate.cpp"

static PyMethodDef Methods[] = {
    { "line_string_has_duplicate_vertex", lineStringHasDuplicateVertex, METH_VARARGS},
    { NULL, NULL, 0, NULL}
};

static struct PyModuleDef module_definition = {
    PyModuleDef_HEAD_INIT,
    "geompy",
    "A Python module extension in C++ for geometry operations",
    -1,
    Methods
};

PyMODINIT_FUNC PyInit_geompy(void) {
    Py_Initialize();
    return PyModule_Create(&module_definition);
}