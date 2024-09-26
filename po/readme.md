# Howto

To extract messages from source files

```bash
xgettext --from-code=UTF-8 --keyword=_ --language=C --add-comments --sort-output -o po/karel.pot src/*.c
```

To init translation in Slovak language

```bash
mkdir sk/
msginit --input=karel.pot --locale=sk --output=sk/karel.po
```

Finally generate `.mo` file

```bash
msgfmt --output-file=po/sk/karel.mo po/sk/karel.po
```

## Resources

* http://www.labri.fr/perso/fleury/posts/programming/a-quick-gettext-tutorial.html
