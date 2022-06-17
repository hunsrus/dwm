dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X developed by the [suckless.org](https://suckless.org/) community. It manages windows in tiled, monocle and floating layouts. All of the layouts can be applied dynamically, optimising the environment for the application in use and the task performed.

This particular build includes the following patches:
- [autostart](https://dwm.suckless.org/patches/autostart/)
- [uselessgap](https://dwm.suckless.org/patches/uselessgap/)

Requirements
------------
In order to build dwm you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

In order to relaunch DWM if the binary changes instead of logging out, replace the above line with the execution of the following code:

    csum=""
    new_csum=$(sha1sum $(which dwm))
    while true
    do
        if [ "$csum" != "$new_csum" ]
        then
            csum=$new_csum
            dwm
        else
            exit 0
        fi
        new_csum=$(sha1sum $(which dwm))
        sleep 0.5
    done

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
