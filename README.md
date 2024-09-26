## Karel the Robot

Karel the robot is in general an educational programming language for beginners,
created by *Richard E. Pattis*. This is implementation of *Karel the Robot* for *C
programming language*.

For more information about Karel the robot visit the Wikipedia page at
http://en.wikipedia.org/wiki/Karel_(programming_language)

## Usage

There are two libraries included in this package:

* `karel.h` - the basic _Karel the Robot_ library with the essential commands and sensors; suitable for beginneris in programming
* `superkarel.h` - the extended version of _Karel the Robot_ library, when _Karel_ is fully equipped with all of the sensors and commands; suitable for problem solvers

To compile program with _karel.h_ library:

```bash
gcc program.c -o program -lkarel -lcurses
```

To compile program with _superkarel.h_ library:

```bash
gcc program.c -o program -lkarel -lcurses
```


## Dependencies

To compile the *Karel the Robot* library, you need to have a copy of the
*ncurses* library.

Please read the file `INSTALL.md` for installation instructions
and full list of dependencies.


## License

This app is under the *GPLv3*. You should have received a copy with it. Otherwise
or if you detect a breach of irs terms, please contact the author or the FSF.
Your freedom it's in play!


## Where to get more information

The homepage of the Karel the robot library is at
https://git.kpi.fei.tuke.sk/kpi/karel-the-robot
