#include "Python.h"
#include "validate/duplicate.cpp"
#include "validate/spike.cpp"
#include "validate/cluster_tolerance.cpp"

static PyMethodDef Methods[] = {
    { "line_string_has_duplicate_vertex", lineStringHasDuplicateVertex, METH_VARARGS, "Check a line string for duplicate points"},
    { "coords_has_spike", (PyCFunction)coordsHasSpike, METH_VARARGS | METH_KEYWORDS, "Check for a spike within a set of coordinates"},
    { "line_string_has_cluster_tolerance", hasClusterToleranceIssue, METH_VARARGS | METH_KEYWORDS, "Check for a points within the cluster tolerance"},
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