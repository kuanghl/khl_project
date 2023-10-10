#include "pybind11/pybind11.h"
#include "pybind11/numpy.h"
#include "pybind11/stl.h"
#include "pytest.h"

namespace py = pybind11;

PYBIND11_MODULE(pytest, m)
{
    /* optional module docstring */ 
    m.doc() = "pybind11 example plugin";

    /* variable description */
    // enum
    py::enum_<tErrorCode>(m, "tErrorCode")
        .value("Success", tErrorCode::Success)
        .value("Error1", tErrorCode::Error1)
        .value("Error2", tErrorCode::Error2)
        .value("Error_Res", tErrorCode::Error_Res)
        .export_values();


    /* expose add function, and add keyword arguments and default arguments */
    m.def("add", &add_simple, "A function which adds two numbers.", py::arg("i")=1, py::arg("j")=2);

    m.def("add_pointer", 
        [](int i, int j, py::array_t<int> result){
            py::buffer_info info = result.request();
            return add_int_pointer(i, j, static_cast<int *>(info.ptr));
        }, "add_int_pointer"
    );

}