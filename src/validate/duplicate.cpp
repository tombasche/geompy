#include "../../include/validate/duplicate.h"

void coordsFromTuple(PyObject * t, double *coords) {
    double x = PyFloat_AsDouble(PyTuple_GetItem(t, 0));
    double y = PyFloat_AsDouble(PyTuple_GetItem(t, 1));
    coords[0] = x;
    coords[1] = y;
}

bool isDuplicateVertex(PyObject * inputArgs, int indexF, int indexN) {
    double coordsFirst [2];
    PyObject * coord = PyList_GetItem(inputArgs, indexF);
    coordsFromTuple(coord, coordsFirst);

    double coordsNext [2];
    PyObject * coordN = PyList_GetItem(inputArgs, indexN);
    coordsFromTuple(coordN, coordsNext);

    if (coordsFirst[0] == coordsNext[0] && coordsFirst[1] == coordsNext[1]) {
        return true;
    }
    return false;
}

PyObject * lineStringHasDuplicateVertex(PyObject * self, PyObject * args)
{
    PyObject * input;

    if (!PyArg_ParseTuple(args, "O", &input)) {
        return NULL;
    }

    long lineLength = PyList_Size(input);

    if (lineLength == 2) {
        if (isDuplicateVertex(input, 0, 1)) {
            Py_RETURN_TRUE;
        }
        Py_RETURN_FALSE;
    }

    for (int i = 1; i < lineLength - 1; i++) {
        if (isDuplicateVertex(input, i, i + 1)) {
            Py_RETURN_TRUE;
        }
    }

    Py_RETURN_FALSE;
}

