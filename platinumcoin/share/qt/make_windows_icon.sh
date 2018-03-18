#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/platinumcoin.png
ICON_DST=../../src/qt/res/icons/platinumcoin.ico
convert ${ICON_SRC} -resize 16x16 platinumcoin-16.png
convert ${ICON_SRC} -resize 32x32 platinumcoin-32.png
convert ${ICON_SRC} -resize 48x48 platinumcoin-48.png
convert platinumcoin-16.png platinumcoin-32.png platinumcoin-48.png ${ICON_DST}

