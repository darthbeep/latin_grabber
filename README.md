# latin_grabber

Gets the definition and possibly type of word from wiktionary

To run, just clone and type python latin.py [args]

For example

`$ python latin.py amo amare`

Gives

```
        amo:
                I love
                I am fond of, like
                I am under obligation to; I am obliged to
                (with infinitive) to enjoy, be accustomed
        amare:
                present active infinitive of amō
                                I love
                                I am fond of, like
                                I am under obligation to; I am obliged to
                                (with infinitive) to enjoy, be accustomed
                second-person singular present passive imperative of amō
                second-person singular present passive indicative of amō
```

Meant for python3 and requires the modules bs4 and urllib3
