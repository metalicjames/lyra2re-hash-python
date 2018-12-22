#include <Python.h>

#include "Lyra2RE.h"

static PyObject *lyra2re3_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    lyra2re3_hash((char *)PyBytes_AsString((PyObject*) input), output);
#else
    lyra2re3_hash((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef Lyra2RE3Methods[] = {
    { "getPoWHash", lyra2re3_getpowhash, METH_VARARGS, "Returns the proof of work hash using Lyra2REv3 hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef Lyra2RE3Module = {
    PyModuleDef_HEAD_INIT,
    "lyra2re3_hash",
    "...",
    -1,
    Lyra2RE3Methods
};

PyMODINIT_FUNC PyInit_lyra2re3_hash(void) {
    return PyModule_Create(&Lyra2RE3Module);
}

#else

PyMODINIT_FUNC initlyra2re3_hash(void) {
    (void) Py_InitModule("lyra2re3_hash", Lyra2RE3Methods);
}
#endif
