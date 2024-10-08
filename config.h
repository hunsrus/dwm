/* See LICENSE file for copyright and license details. */

/* appearance */

#define FONT_SIZE "10"
#define SCRIPTS_PATH "/home/gabriel/.scripts"
#define SCREENSHOTS_PATH "/home/gabriel/Imágenes/Capturas de pantalla"
#define ROFI_THEME_PATH "/home/gabriel/.config/rofi/launchers/type-1/style-3.rasi" 

static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int gappx     = 10;       /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "SfProDisplay:style=semibold:size="FONT_SIZE, "SfMono Nerd Font:size="FONT_SIZE };
static const char dmenufont[]       = "SfProDisplay:style=semibold:size="FONT_SIZE;
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#eeeeee";	//#bbbbbb
static const char col_gray4[]       = "#2c2c2c";
static const char col_cyan[]        = "#63b1bc";	//#46acb8
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       1 << 8,            0,           -1 },
	{ "firefox",  NULL,       NULL,       0,		    0,           -1 },
	{ "spotify_launcher", NULL, NULL,     1 << 9,       0,           -1 },
	{ "gnome-calendar", NULL, NULL,		  0,	        1,           -1 },
	// figuras de matlab
	{ NULL, 	  NULL, 	"Figure",	  0,	        1,           -1 },
	{ NULL, 	  NULL, 	"Plot",		  0,	        1,           -1 },
	{ NULL, 	  NULL, 	"whisper",	  0,	        1,           -1 },
	// ventana flotante de descarga de teams
	{ NULL, 	  NULL, "Notificación de Microsoft Teams",		  0,	        1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *screenlock[]  = { "slock", NULL };
static const char *killwindow[]  = { "xkill", NULL };
static const char *filexcmd[]  = { "nautilus", NULL };
static const char *taskmanager[]  = { "st", "btop", NULL };
static const char *dmenupower[] = {SCRIPTS_PATH"/dmenu-power", "-launcher", "rofi", "-theme", ROFI_THEME_PATH,NULL};
static const char *dmenuwebsearch[] = {SCRIPTS_PATH"/dmenu_websearch.sh", NULL};
static const char *dmenubookmarks[] = {SCRIPTS_PATH"/bmks", "rofi", "-theme", ROFI_THEME_PATH, NULL};
static const char *dmenucalculator[] = {SCRIPTS_PATH"/dmenu-calculator", NULL};
static const char *dmenunotifications[] = {SCRIPTS_PATH"/dmenu-notifications", NULL};
static const char *dmenuscreenshot[] = {SCRIPTS_PATH"/dmenu-screenshot", SCREENSHOTS_PATH, NULL};
static const char *dmenumonitors[] = {SCRIPTS_PATH"/dmenu-mons", "-launcher", "rofi", "-theme", ROFI_THEME_PATH, NULL};
static const char *dmenugpt[] = {SCRIPTS_PATH"/dmenu-gpt", NULL};
static const char *dmenutranslate[] = {SCRIPTS_PATH"/dmenu-translate", NULL};
static const char *dmenubluetooth[] = {SCRIPTS_PATH"/dmenu-bluetooth", "-launcher", "rofi", "-theme", ROFI_THEME_PATH,NULL};
static const char *nautfacultad[] = {"nautilus", "/media/DATOS/Facultad/Ingeniería Electrónica", NULL};
static const char *calendar[] = {"gnome-calendar", NULL};
//static const char *applauncher[] = {"rofi", "-show", "drun", NULL};
static const char *applauncher[] = {"/home/gabriel/.config/rofi/launchers/type-1/launcher.sh", NULL};
static const char *appviewer[] = {"rofi", "-show", "window", "-theme", ROFI_THEME_PATH, NULL};
static const char *togglepolybar[] = {"polybar-msg", "cmd", "toggle", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,						XK_g,	   spawn,          {.v = dmenugpt} },
	{ MODKEY|ShiftMask,				XK_t,	   spawn,          {.v = dmenutranslate} },
	{ MODKEY|ShiftMask,				XK_b,	   spawn,          {.v = dmenubluetooth} },
	{ MODKEY,						XK_a,	   spawn,          {.v = applauncher} },
	{ MODKEY|ShiftMask,				XK_a,	   spawn,          {.v = appviewer} },
	{ MODKEY|ShiftMask,				XK_x,	   spawn,          {.v = killwindow} },
	{ MODKEY,    					XK_Escape, spawn,          {.v = screenlock} },
	{ MODKEY,    					XK_c,      spawn,          {.v = calendar} },
	{ MODKEY|ShiftMask,    			XK_f,      spawn,          {.v = nautfacultad} },
	{ MODKEY|ShiftMask,    			XK_m,      spawn,          {.v = dmenumonitors} },
	{ MODKEY|ShiftMask,    			XK_w,      spawn,          {.v = dmenubookmarks} },
	{ MODKEY,             			XK_w,      spawn,          {.v = dmenuwebsearch} },
	{ MODKEY|ShiftMask,    			XK_c,      spawn,          {.v = dmenucalculator} },
	{ MODKEY, 	   					XK_n,      spawn,          {.v = dmenunotifications} },
	{ MODKEY|ShiftMask,    			XK_s,      spawn,          {.v = dmenuscreenshot} },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = dmenupower} },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,             			XK_e,	   spawn,          {.v = filexcmd } },
	{ ControlMask|ShiftMask,		XK_Escape, spawn,          {.v = taskmanager } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_b,      spawn,		   {.v = togglepolybar} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,			            XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY,                       XK_minus, scratchpad_show, {0} },
    { MODKEY|ShiftMask,             XK_minus, scratchpad_hide, {0} },
    { MODKEY,                       XK_equal,scratchpad_remove,{0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

