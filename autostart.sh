#!/bin/bash
export PATH=$PATH:/home/gabriel/.spicetify:/home/gabriel/.scripts
picom -b --config /home/gabriel/.config/picom/picom-jonaburg.conf --experimental-backends
xrandr --output eDP-1 --mode 1366x768 &
#dwmblocks &
/home/gabriel/.config/polybar/launch.sh &
#feh --bg-scale '/home/gabriel/Imágenes/Wallpapers/fabrizio-conti-sK7own3aaw-unsplash.jpg' &
#feh --bg-scale '/home/gabriel/Imágenes/Wallpapers/clouds-dwm.png' &
#feh --bg-scale '/home/gabriel/Imágenes/Wallpapers/gris.jpg' &
#feh --bg-scale '/home/gabriel/Imágenes/Wallpapers/222222.png' &
feh --bg-scale '/home/gabriel/Imágenes/Wallpapers/-zgH2-pop-dark.png' &
/usr/lib/kdeconnectd &
dunst &
sxhkd &
rclone --vfs-cache-mode writes mount onedrive: ~/OneDrive &
rclone --vfs-cache-mode writes mount googledrive: ~/Drive &
rclone --vfs-cache-mode writes mount mega: ~/Mega &
xbindkeys &
