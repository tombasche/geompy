# geompy
Python wrapper around C++ geometry operations

# Installation
`python3 setup.py install`


# Usage
```
>>> from geompy import line_string_has_duplicate_vertex
>>> line_string_has_duplicate_vertex([(1,1), (1,1)])
>>> True
```

# TODO

* Documentation for functions
* Better error handling (different data types passed in etc.)
* Porting of repair functions and tests
* Add a 'Why this?' section and do some performance testing :D 