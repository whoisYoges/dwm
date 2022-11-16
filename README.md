### My Build of DWM:

### Applied Patches
- [alwayscenter](https://dwm.suckless.org/patches/alwayscenter/): This patch places all the floating windows in the centere of screen, like the center patch, but without a rule.

- [fullgaps](https://dwm.suckless.org/patches/fullgaps/): This patch adds gaps between client windows.

- [scratchpads](https://dwm.suckless.org/patches/scratchpads/): This patch enables multiple scratchpads, each with one asigned window.

- [swallow](https://dwm.suckless.org/patches/swallow/): This patch adds "window swallowing" to dwm. Example, when you open a gui application from terminal, it hides the terminal in background, leaving that application only without splitting terminal and that application; terminal can be accessed back after closing the gui application.

- [notitle](https://dwm.suckless.org/patches/notitle/): This patch hides your window's titles in dwm-bar.

- [barpadding](https://dwm.suckless.org/patches/barpadding/): This patch adds variables for verticle and horizontal space between the statusbar and the edge of the screen.

- [attachabove](https://dwm.suckless.org/patches/attachabove/): Make new clients attach above the selected client, instead of always becoming the new master.

- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/): This patch prevents dwm from drawing tags with no clients (i.e. vacant) on the bar.

- [monoclesymbol](https://dwm.suckless.org/patches/monoclesymbol/): This patch always display the the monocle-symbol as defined in config.h if the monocle-layout is activated. Do not display the number of open clients in the current tag.

### Requirements/Dependencies
In order to build dwm you need the Xlib header files.

- libxcb
- Xlib-libxcb
- xcb-res
- libxinerama
- libx11
- Comic Sans Ms font (If you want to use another font edit in the configuration)
- font-awesome (for iconic tags in dwm-bar)
- [libxft-bgra](https://aur.archlinux.org/packages/libxft-bgra) (for colored emoji support)

### Features
- applied alacritty as default scratchpad terminal (MODKEY+x, MODKEY+c, MODKEY+v)
- applied deadbeef as scratchpad audio/music player (Super+a)
- applied geany as scratchpad note taking application (Super+t)
- applied keepassxc as scratchpad password manager (Super+p)
- applied swallow feature for alacritty terminal
- default font: Comic Sans MS
- Iconic tags symbols
- Removed clickability from the bar

### Configuration and installation
Edit config.mk to match your local setup (dwm is installed into the /usr/local namespace by default).

The configuration of dwm is done copying [config.def.h](config.def.h) to `config.h`, editing it and then (re)compiling the source code.
