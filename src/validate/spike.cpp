#include "../../include/validate/spike.h"


float newPrecision(double n, double i) {
    return floor(pow(10,i)*n)/pow(10,i);
}

PyObject * coordsHasSpike(PyObject * self, PyObject * args, PyObject * keywds) {
    PyObject * coordArgs;
    double angle = 0.05;
    double roundPrecision = 8;
    static char *kwlist[] = {"coords", "angle", "round_precision", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O|dd", kwlist, &coordArgs, &angle, &roundPrecision))
        return NULL;

    long lineLength = PyList_Size(coordArgs);
    if (lineLength < 3) { Py_RETURN_FALSE; }

    // Don't mark as a spike if there's a duplicate vertex
    for (int i = 0; i < lineLength - 1; i++) {
        if (isDuplicateVertex(coordArgs, i, i + 1)) {
            Py_RETURN_FALSE;
        }
    }

    double coordsFirst [2];
    PyObject * coord1 = PyList_GetItem(coordArgs, 0);
    coordsFromTuple(coord1, coordsFirst);

    double coordsSecond [2];
    PyObject * coord2 = PyList_GetItem(coordArgs, 1);
    coordsFromTuple(coord2, coordsSecond);

    double coordsThird [2];
    PyObject * coord3 = PyList_GetItem(coordArgs, 2);
    coordsFromTuple(coord3, coordsThird);

    double vector_0_0 = coordsFirst[0] - coordsSecond[0];
    double vector_0_1 = coordsFirst[1] - coordsSecond[1];

    double vector_1_0 = coordsThird[0] - coordsSecond[0];
    double vector_1_1 = coordsThird[1] - coordsSecond[1];

    double term_a = sqrt(pow(vector_0_0, 2) + pow(vector_0_1,2));
    double term_b = sqrt(pow(vector_1_0, 2) + pow(vector_1_1, 2));
    double denom = term_a * term_b;

    if (denom == 0) {
        PyErr_SetObject(PyExc_ZeroDivisionError, PyLong_FromDouble(denom));
        return NULL;
    }

    double dotProduct = (vector_0_0 * vector_1_0) + (vector_0_1 * vector_1_1);
    double value = dotProduct / denom;
    if (value < -1) { value = -1;}
    if (value > 1) { value = 1;}

    if (newPrecision(acos(value), roundPrecision) <= angle) { Py_RETURN_TRUE;}

    Py_RETURN_FALSE;
}