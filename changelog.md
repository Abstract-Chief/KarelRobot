# Changelog

## 2019.1 (30th july 2019)

* changelog added to the project ;)
* signal for `CTRL+C` is correctly handled and execution is terminated
* bug with length of command name is fixed
* coding style changed from CamelCase to snake_style
* library has been divided to two parts
    * `karel.h` - only the basics commands and limited set of sensors
    * `superkarel.h` - _batteries included karel_, all the sensors are available
* documentation was updated
* all internal variables and functions (private) have `_` prefix
* input file parses is much more sensitive to errors
* function `get_step_delay()` was removed
* initial support for tests
    * for some sensors only from `karel.h` and `superkarel.h`
* initial support for internationalization (i18n)
    * all the strings are currently enclosed in the `_()` macro
    * translations are in the `po/` directory
    * basic `.pot` file is extracted
* if `NULL` is given instead of `path` in the function `turn_on()`, then world file is read from `stdin`
* huge refactoring
* some _CMake_ cleanup