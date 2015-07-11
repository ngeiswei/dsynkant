DSynkant
========

Description
-----------

DSynkant is a virtual synthesizer that emulates the Roland D-50/D-550.

Features
--------

It's rather barebone right now. There is no GUI, no presets, and no
sound! It only compiles on Linux but the code should easily be
portable to other platforms. It supports DSSI and VST.

Requirements
------------

- Boost (version 1.46 minimum) http://www.boost.org/
- DSSI SDK http://dssi.sourceforge.net/ (optional)
- VST SDK http://www.steinberg.net/en/company/developers.html (optional)

Compilation
-----------

```
mkdir build
cd build
cmake ..
make -j4
```
should work.

For VST support, download the VST SDK (tested with 3.6) and unzip it
directly under the project root directory.

Under GNU/Linux 64-bit, you may also need to comment out a bit of code
in

```
pluginterfaces/vst2.x/aeffect.h
```

like all definitions of VSTCALLBACK except
```
#define VSTCALLBACK
```

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

Acknowledgment
--------------

Thanks to:

* David Godevais for giving me his Roland D-550!
