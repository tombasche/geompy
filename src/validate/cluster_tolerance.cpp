#include "Python.h"
#include <iostream>

#include "../structures/coords.cpp"
#include "../measure/measure.cpp"

static PyObject * hasClusterToleranceIssue(PyObject * self, PyObject * args) {
    PyObject * lineCoords;

    double tolerance = 0.025;

    if (!PyArg_ParseTuple(args, "O|d", &lineCoords, &tolerance)) {
        return NULL;
    }

    long lineLength = PyList_Size(lineCoords);

    PyObject * prev = NULL;
    for (int i = 0; i < lineLength; i++) {
        if (prev) {
            double coordsPrev [2];
            coordsFromTuple(prev, coordsPrev);

            double coords [2];
            PyObject * coord = PyList_GetItem(lineCoords, i);
            coordsFromTuple(coord, coords);
            float distance = metreDistance(coords[0], coords[1], coordsPrev[0], coordsPrev[1]);
            if (distance < tolerance)
                Py_RETURN_TRUE;
        }
        prev = PyList_GetItem(lineCoords, i);
    }


    Py_RETURN_FALSE;
}
