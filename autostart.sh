#!/bin/bash
picom -b --config /home/gabriel/.config/picom/picom-jonaburg.conf --experimental-backends
dwmblocks &
feh --bg-scale '/home/gabriel/Imágenes/Wallpapers/fabrizio-conti-sK7own3aaw-unsplash.jpg' &
/usr/lib/kdeconnectd &
dunst &
rclone --vfs-cache-mode writes mount onedrive: ~/OneDrive &
rclone --vfs-cache-mode writes mount googledrive: ~/Drive &
rclone --vfs-cache-mode writes mount mega: ~/Mega &
xbindkeys
