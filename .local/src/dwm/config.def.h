/* ── Appearance ───────────────────────────── */
static const char *fonts[] = { "JetBrains Mono:size=12", "JoyPixels:pixelsize=12:antialias=true:autohint=true" };
static const char dmenufont[] = "JetBrains Mono:size=12";
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[]  = "#005577";
static const unsigned int borderpx  = 2;
static const unsigned int snap      = 32;
static const int showbar            = 1;
static const int topbar             = 1;

/* ── Tagging ──────────────────────────────── */
static const char *tags[] = { "", "", "", "", "", "" };

/* ── Rules ────────────────────────────────── */
static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   isterminal  noswallow  monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           0,          0,         -1 },
	{ "st",       NULL,       NULL,       0,            0,           1,          0,         -1 },
};

/* ── Layouts ──────────────────────────────── */
#include "grid.c"
#include "fibonacci.c"

static const float mfact     = 0.25; // Master area size factor
static const int nmaster     = 0.5; // Number of clients in master area
static const int resizehints = 0.75; // Resize hints for tiled windows

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },    // Floating
	{ "[M]",      monocle },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "HHH",      grid },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
};

/* ── Key Definitions ──────────────────────── */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* ── Commands ─────────────────────────────── */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", NULL };

/* ── Key Bindings ─────────────────────────── */
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,              		XK_equal,  zoom,  	   {.f = +1} },
	{ MODKEY,              		XK_minus,  zoom,     	   {.f = -1} },
	{ MODKEY,              		XK_o,      zoomreset, 	   {.f =  0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY,                       XK_s,      setlayout,      {.v = &layouts[7]} },
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
};
