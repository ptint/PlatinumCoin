
Debian
====================
This directory contains files used to package platinumcoind/platinumcoin-qt
for Debian-based Linux systems. If you compile platinumcoind/platinumcoin-qt yourself, there are some useful files here.

## platinumcoin: URI support ##


platinumcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install platinumcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your platinumcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/platinumcoin128.png` to `/usr/share/pixmaps`

platinumcoin-qt.protocol (KDE)

