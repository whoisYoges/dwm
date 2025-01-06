/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "0xProto Nerd Font:size=11", "CaskaydiaCove NF:size=11", "Symbols Nerd Font:size=9" };

/* Color Scheme - Light */
static const char light_normbg[]          = "#fbf1c7";
static const char light_normfg[]          = "#3c3836";
static const char light_normborder[]      = "#d5c4a1";
static const char light_selbg[]           = "#fbf1c7";
static const char light_selfg[]           = "#b8bb26";
static const char light_selborder[]       = "#b8bb26";

/* Color Scheme - Dark */
static const char dark_normbg[]          = "#282828";
static const char dark_normfg[]          = "#ebdbb2";
static const char dark_normborder[]      = "#7c6f64";
static const char dark_selbg[]           = "#282828";
static const char dark_selfg[]           = "#98971a";
static const char dark_selborder[]       = "#98971a";

static const char *colors[][SchemeN][3] = {
		/*               fg         bg         border   */
	{ /* dark */
		[SchemeNorm] = { dark_normfg,    dark_normbg,     dark_normborder},
		[SchemeSel]  = { dark_selfg,     dark_selbg,      dark_selborder  },
	},
	{ /* light */
		[SchemeNorm] = { light_normfg,    light_normbg,     light_normborder},
		[SchemeSel]  = { light_selfg,     light_selbg,      light_selborder  },
	},
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"kitty", "--name", "spterm", "--class", "spterm", "--title", "spterm", NULL };
const char *spcmd2[] = {"keepassxc", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"keepassxc",   spcmd2},
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "ghostty", NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ "kitty",   NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
	{ NULL,     "spterm",  "spterm",       SPTAG(0),  1,          1,           1,        -1 },
	{ NULL,     "keepassxc", NULL,         SPTAG(1),  1,          0,           0,        -1 },
	{ "Bitwarden", NULL,     NULL,         0,         1,          0,           0,        -1 },
	{ "Pavucontrol", NULL,   NULL,         0,         1,          0,           0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.52; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",        tile },    /* first entry is default */
	{ "",        NULL },    /* no layout function means floating behavior */
	{ "",        monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD("ghostty") },
	{ Mod4Mask,             		XK_b,      spawn,          SHCMD("librewolf -P") },
	{ Mod4Mask,             		XK_s,      spawn,          SHCMD("brave") },
	{ Mod4Mask,             		XK_f,      spawn,          SHCMD("pcmanfm") },
	{ Mod4Mask,             		XK_m,      spawn,          SHCMD("thunderbird") },
	{ Mod4Mask,             		XK_l,      spawn,          SHCMD("slock") },
	{ 0,              XF86XK_MonBrightnessUp,  spawn,          SHCMD("brillo -A 1 && pkill -RTMIN+5 dwmblocks") },
	{ 0,             XF86XK_MonBrightnessDown, spawn,          SHCMD("brillo -U 1 && pkill -RTMIN+5 dwmblocks") },
	{ 0,              XF86XK_AudioLowerVolume, spawn,          SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%- && pkill -RTMIN+6 dwmblocks") },
	{ 0,              XF86XK_AudioRaiseVolume, spawn,          SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+ && pkill -RTMIN+6 dwmblocks") },
	{ 0,                	 XF86XK_AudioMute, spawn,          SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle && pkill -RTMIN+6 dwmblocks") },
	{ ControlMask,    XF86XK_AudioLowerVolume, spawn,          SHCMD("wpctl set-volume @DEFAULT_AUDIO_SOURCE@ 5%- && pkill -RTMIN+7 dwmblocks") },
	{ ControlMask,    XF86XK_AudioRaiseVolume, spawn,          SHCMD("wpctl set-volume @DEFAULT_AUDIO_SOURCE@ 5%+ && pkill -RTMIN+7 dwmblocks") },
	{ ControlMask,           XF86XK_AudioMute, spawn,          SHCMD("wpctl set-mute @DEFAULT_AUDIO_SOURCE@ toggle && pkill -RTMIN+7 dwmblocks") },
	{ 0,                            XK_Print,  spawn,          SHCMD("import -window root ~/Castor/Pictures/Screenshots/screenshot-$(date +'%Y-%m-%d:%H-%M-%S').png && notify-send 'Screenshot Taken'") },
	{ ShiftMask,                    XK_Print,  spawn,          SHCMD("flameshot gui") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
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
	{ MODKEY|ShiftMask,             XK_Left,   rotatetags,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,  rotatetags,     {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY,            			XK_x,  	   togglescratch,  {.ui = 0 } },
	{ Mod4Mask,            			XK_p,	   togglescratch,  {.ui = 1 } },
	{ MODKEY,                       XK_r,      movemouse,      {0} },
	{ MODKEY|ShiftMask,             XK_r,      resizemouse,    {0} },
	{ MODKEY,                       XK_s,      setscheme,      {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {1} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,       MODKEY|ShiftMask, Button1,        resizemouse,    {0} },
};

