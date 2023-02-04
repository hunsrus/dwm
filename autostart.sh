#!/bin/bash
picom -b --config /home/gabriel/.config/picom/picom.conf
dwmblocks &
feh --bg-scale /home/gabriel/Imágenes/Fondos\ de\ escritorio/gradiente_bn.png &
/usr/lib/kdeconnectd &
dunst &
xbindkeys
