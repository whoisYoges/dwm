/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 4;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 12;       /* vertical padding of bar */
static const int sidepad            = 12;       /* horizontal padding of bar */
static const char *fonts[]          = { "Comic Sans MS:size=12" };

static const char normbg[]			= "#242424";
static const char normfg[]			= "#08FF08";
static const char normborder[]      = "#133333";
static const char selbg[]			= "#222222";
static const char selfg[]			= "#FFFF00";
static const char selborder[]		= "#1338F0";

static const char *colors[][3]      = {
	/*               fg			bg			border   */
	[SchemeNorm] = { normfg,	normbg,		normborder},
	[SchemeSel]  = { selfg,		selbg,		selborder  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;

const char *spcmd1[] = {"alacritty", "--class", "spterm1", "-o", "window.dimensions.lines=15", "-o", "window.dimensions.columns=60", NULL };
const char *spcmd2[] = {"alacritty", "--class", "spterm2", "-o", "window.dimensions.lines=15", "-o", "window.dimensions.columns=60", NULL };
const char *spcmd3[] = {"alacritty", "--class", "spterm3", "-o", "window.dimensions.lines=15", "-o", "window.dimensions.columns=60", NULL };
const char *spcmd4[] = {"keepassxc", NULL }; //password manager
const char *spcmd5[] = {"deadbeef", NULL }; //music player
const char *spcmd6[] = {"geany", NULL }; //todo and instant notes
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm1",     spcmd1},
	{"spterm2",     spcmd2},
	{"spterm3",     spcmd3},
    {"keepassxc",   spcmd4},
    {"deadbeef",    spcmd5},
    {"geany",		spcmd6},
};

/* tagging */
static const char *tags[] = { "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */

	/* class     	instance	title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Alacritty",	NULL,		NULL,           0,         0,          1,           0,        -1 },
	{ NULL,			NULL,		"Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
	{ NULL,			"spterm1",	NULL,		   	SPTAG(0),  1,		   0, 			0,		  -1 },
	{ NULL,			"spterm2",	NULL,		   	SPTAG(1),  1,		   0, 			0,		  -1 },
	{ NULL,			"spterm3",	NULL,		   	SPTAG(2),  1,		   0, 			0,		  -1 },
    { NULL,         "keepassxc", NULL,          SPTAG(3),  1,          0,           0,        -1 },
    { NULL,         "deadbeef", NULL,           SPTAG(4),  1,          0,           0,        -1 },
    { NULL,         "geany",	NULL,           SPTAG(5),  1,          0,           0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.53; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* Key Bindings */
static Key keys[] = {
	/* modifier                     key        function        argument */
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
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -4 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +4 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
    
    /* Scratchpads */
	{ MODKEY,            			XK_x,  	   togglescratch,  {.ui = 0 } },
	{ MODKEY,            			XK_c,  	   togglescratch,  {.ui = 1 } },
	{ MODKEY,            			XK_v,  	   togglescratch,  {.ui = 2 } },
    { Mod4Mask,                     XK_p,      togglescratch,  {.ui = 3 } },
    { Mod4Mask,                     XK_a,      togglescratch,  {.ui = 4 } },
    { Mod4Mask,                     XK_t,      togglescratch,  {.ui = 5 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} },
};
