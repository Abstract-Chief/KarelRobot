# TODO

## Todo

### Version Info

* provide version info some way
    * in credits?
    * `--version` / `-v` ?

### Refactoring the Export

* move `internals.c` to `core.c`
* create module for exports only
    * distinguish different export modes to at least separate functions (JSON, YAML, text, XML, ...)


### NCurses alternatives

-   move from ncurses to s-lang
    -   avoid usage of movek() function for Karel's movement because of ncurses move() function
    -   or maybe termbox (but no support for windows :-( http://code.google.com/p/termbox/
-   SDL support for GUI
    -   more interesting ;)


### Support for CI

* make the tests pass first before delivery/deployment


### Environment variable for world file

* don't need to recompile every time, when the same algorithm is used for different world
* benefit for testing purposes


## Done

### `_error_shut_off()` update

* make it with variable length arguments
    * as the `printf()`
* use it always for shut off. not only when Karel is initialized and runnig (in GUI mode)


### Internationalization

-   gettext support for error messages
-   done in 2019.1


### Karel and Super Karel

- karel should contain only the basic vocabulary:

    * `turn_on()`
    * `turn_off()`
    * `move()` or `step()`
    * `turn_left()`
    * `pick_beeper()`
    * `put_beeper()`

- karel should be equipped with following basic sensors:

    * `front_is_clear()`
    * `facing_north()`
    * `beepers_present()`
    * `beepers_in_bag()`

-   super karel extension
    -   "batteries included" Karel

- done in 2019.1


### Naming Conventions

* rewrite from Java/C++ style to C style
* done in 2019.1
