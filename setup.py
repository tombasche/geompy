from distutils.core import setup, Extension

c_module = Extension("geompy", sources=["src/validate/validate.cpp"])

setup(
    name="geompy",
    version="1.0",
    description="Module to perform performant actions on geometry",
    ext_modules=[c_module],
)