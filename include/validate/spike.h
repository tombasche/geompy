#include <math.h>
#include "Python.h"

float newPrecision(double n, double i);

static PyObject * coordsHasSpike(PyObject * self, PyObject * args, PyObject * keywds);