# Table of content:
- [Applied Patches](#applied-patches)
- [Features](#features)
- [Dependencies](#dependencies)
- [Configuration](#configuration)
- [Installation](#installation)

![Preview_Image](preview.jpg)

### Applied Patches
- [alwayscenter](https://dwm.suckless.org/patches/alwayscenter/): This patch places all the floating windows in the centere of screen, like the center patch, but without a rule.

- [attachabove](https://dwm.suckless.org/patches/attachabove/): Make new clients attach above the selected client, instead of always becoming the new master.

- [barpadding](https://dwm.suckless.org/patches/barpadding/): This patch adds variables for verticle and horizontal space between the statusbar and the edge of the screen.

- [fullgaps](https://dwm.suckless.org/patches/fullgaps/): This patch adds gaps between client windows.

- [hide vacant tags](https://dwm.suckless.org/patches/hide_vacant_tags/): This patch prevents dwm from drawing tags with no clients (i.e. vacant) on the bar.

- [monoclesymbol](https://dwm.suckless.org/patches/monoclesymbol/): This patch always display the the monocle-symbol as defined in config.h if the monocle-layout is activated. Do not display the number of open clients in the current tag.

- [notitle](https://dwm.suckless.org/patches/notitle/): This patch hides your window's titles in dwm-bar.

- [restartsig](https://dwm.suckless.org/patches/restartsig/): This patch allows user to restart dwm via Mod+CTRL+SHIFT+Q or by `kill -HUP dwmpid`.

- [scratchpads](https://dwm.suckless.org/patches/scratchpads/): This patch enables multiple scratchpads, each with one asigned window.

- [swallow](https://dwm.suckless.org/patches/swallow/): This patch adds "window swallowing" to dwm. Example, when you open a gui application from terminal, it hides the terminal in background, leaving that application only without splitting terminal and that application; terminal can be accessed back after closing the gui application.

- [rotatetags](https://dwm.suckless.org/patches/rotatetags/): This patch provides the ability to rotate the tagset left / right. It implements a new function rotatetags which modifies the current tagset.

### Features
- applied alacritty as default scratchpad terminal (`Mod+x`, `Mod+c`, `Mod+v`)
- applied keepassxc as scratchpad password manager (`Super+p`)
- applied swallow feature for alacritty terminal
- Removed clickability from the bar
- Reconfigured `Mod+button1` to move window and `Mod+Shift+button1` to resize window. (Earlier both were done by `Mod+button1`)
- Added `Mod+r` to move window and `Mod+Shift+r` to resize window using mouse/touchpad.
- `Mod+shift+Left` and `Mod+shift+Right` to change the tags/worksapces.

### Dependencies

- [freetype2](https://archlinux.org/packages/extra/x86_64/freetype2/)
- [libxcb](https://archlinux.org/packages/extra/x86_64/libxcb/)
- [libxinerama](https://archlinux.org/packages/extra/x86_64/libxinerama/)
- [libx11](https://archlinux.org/packages/extra/x86_64/libx11/)
- [libxft](https://archlinux.org/packages/extra/x86_64/libxft/)
- Fonts:
    - [Comic Sans MS](ComicSansMS/ComicSansMS.ttf)
    - [Font Awesome 6 Free Solid](Font-Awesome/fa-solid-900.ttf)

### Configuration
Edit config.mk to match your local setup (dwm is installed into the /usr/local namespace by default).

The configuration of dwm is done copying [config.def.h](config.def.h) to `config.h`, editing it and then (re)compiling the source code.

### Installation

1. Install all the required [dependencies](#dependencies).

2. Copy required fonts to fonts directory.

```
sudo cp -r ComicSansMS /usr/share/fonts/
sudo cp -r Font-Awesome /usr/share/fonts/
```

3. Install dwm.

```
sudo make install
```

**If you want my bar and setup, checkout my [dotfiles](https://github.com/whoisyoges/dotfiles).**
