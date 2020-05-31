#include "Python.h"

void coordsFromTuple(PyObject * t, double *coords);
bool isDuplicateVertex(PyObject * inputArgs, int indexF, int indexN);

static PyObject * lineStringHasDuplicateVertex(PyObject * self, PyObject * args);