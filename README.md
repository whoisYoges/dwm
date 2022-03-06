### My Build of DWM:

### Applied Patches
- [alwayscenter](https://dwm.suckless.org/patches/alwayscenter/)
- [fullgaps](https://dwm.suckless.org/patches/fullgaps/)
- [scratchpads](https://dwm.suckless.org/patches/scratchpads/)
- [swallow](https://dwm.suckless.org/patches/swallow/)
- [notitle](https://dwm.suckless.org/patches/notitle/)
- [barpadding](https://dwm.suckless.org/patches/barpadding/)

### Requirements
In order to build dwm you need the Xlib header files.

### Features
- applied alacritty as default scratchpad terminal (MODKEY+x)
- applied swallow feature for alacritty terminal
- default font: Comic Sans MS

### Configuration and installation
Edit config.mk to match your local setup (dwm is installed into the /usr/local namespace by default).

The configuration of dwm is done in [config.h](config.h) and then (re)compiling the source code.

### *Note: If you apply any other patched in it, it will be applied to config.def.h, but my custom settings are applied to config.h. So If you need all my patches + settings and want to apply your patch backup config.def.h and replace config.def.h with config.h.*
