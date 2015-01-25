DSynkant
========

Description
-----------

DSynkant is a virtual synthesizer that emulates the Roland
D50/D550. So far it only supports DSSI but is being developed in a way
that should easily support other softsynth API like VST.

Requirement
-----------

- DSSI

Compilation
-----------

```
mkdir build
cd build
cmake ..
make -j4
```
should work. If not maybe you have to install DSSI first.

Contribution
------------

It is largely incomplete, if you want to help you are more than
welcome. In particular, I don't own a Roland D-50, so if you own one,
I can definitely find helpful tasks for you.

### Coding standard:
Patches (pull requests) that do not meet the coding standard will not
be accepted.

1. Indentation: smart-tab, see
   http://www.emacswiki.org/emacs/SmartTabs for Emacs and
   http://www.vim.org/scripts/script.php?script_id=231 for Vim.
2. 80 columns max per line.

Bugs
----

Unknown. Please create an issue if you find some.

Author
------

Nil Geisweiller
