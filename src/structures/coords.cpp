#pragma once

void coordsFromTuple(PyObject * t, double *coords) {
    double x = PyFloat_AsDouble(PyTuple_GetItem(t, 0));
    double y = PyFloat_AsDouble(PyTuple_GetItem(t, 1));
    coords[0] = x;
    coords[1] = y;
}