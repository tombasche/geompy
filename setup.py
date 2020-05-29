from distutils.core import setup, Extension

MODULE_BASE = "src"

c_module = Extension("geompy", sources=[
    f"{MODULE_BASE}/main.cpp",
])

setup(
    name="geompy",
    version="1.0",
    description="Module to perform performant actions on geometry",
    ext_modules=[c_module],
)