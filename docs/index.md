## travis

[travis tutorial](https://docs.travis-ci.com/user/tutorial/)

## CMake

[cmake tutorial](https://cmake.org/cmake-tutorial/)

Add include directories to a target.

[target_include_directories](https://cmake.org/cmake/help/v3.0/command/target_include_directories.html)

The BUILD_INTERFACE and INSTALL_INTERFACE generator expressions can be used to describe separate 
usage requirements based on the usage location. Relative paths are allowed within the 
INSTALL_INTERFACE expression and are interpreted relative to the installation prefix. For example:

[generator expressions](https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html#manual:cmake-generator-expressions(7))

$<BUILD_INTERFACE:...>
Content of ... when the property is exported using export(), or when the target is used by another target in the same buildsystem. 
Expands to the empty string otherwise.

$<INSTALL_INTERFACE:...>
Content of ... when the property is exported using install(EXPORT), and empty otherwise.
