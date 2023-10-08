#include "pybind11/pybind11.h"
#include "pybind11/stl.h"
#include "pytest.h"

namespace py = pybind11;

int add111(int i, int j){
    return (i+j);
}

PYBIND11_MODULE(pytest, m)
{
    /* optional module docstring */ 
    m.doc() = "pybind11 example plugin";

    /* variable description */


    /* expose add function, and add keyword arguments and default arguments */
    m.def("add", &add111, "A function which adds two numbers.", py::arg("i")=1, py::arg("j")=2);
}