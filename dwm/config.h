#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }
#define BROWSER "firefox"
#define TERMINAL "st"
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const unsigned int barborderpx    = 3;  /* border pixel of bar */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 25;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 25;  /* vert inner gap between windows */
static const unsigned int gappoh         = 25;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 25;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 0;   /* 0 means bottom bar */
static const int bar_height              = 25;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = 0;  /* vertical padding of bar */
static const int sidepad                 = 0;  /* horizontal padding of bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]               = { "Terminus:size=11:style=Bold" };
static const char dmenufont[]            = "Terminus:size=11:style=Bold";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#ffffff"; //#fbf205
static char normbgcolor[]                = "#2e2e2e"; //#4d4d4d
static char normbordercolor[]            = "#2e2e2e"; //#da035e
static char normfloatcolor[]             = "#2e2e2e"; //#da035e
                                                             
static char selfgcolor[]                 = "#ffffff"; //#ffffff
static char selbgcolor[]                 = "#757ca6"; //#757ca6
static char selbordercolor[]             = "#da035e"; //#da035e
static char selfloatcolor[]              = "#da035e"; //#da035e
                                                             
static char titlenormfgcolor[]           = "#bbbbbb"; //#bbbbbb
static char titlenormbgcolor[]           = "#2e2e2e"; //#da0352
static char titlenormbordercolor[]       = "#da035e"; //#da035e
static char titlenormfloatcolor[]        = "#2e2e2e"; //#da035e
                                                             
static char titleselfgcolor[]            = "#fbf205"; //#fbf205
static char titleselbgcolor[]            = "#2e2e2e"; //#000000
static char titleselbordercolor[]        = "#da035e"; //#da035e
static char titleselfloatcolor[]         = "#da035e"; //#da035e
                                                             
static char tagsnormfgcolor[]            = "#f5ead2"; //#ffffff
static char tagsnormbgcolor[]            = "#2e2e2e"; //#000000
static char tagsnormbordercolor[]        = "#da035e"; //#000000
static char tagsnormfloatcolor[]         = "#da035e"; //#da035e
                                                             
static char tagsselfgcolor[]             = "#fbf305"; //#fbf305
static char tagsselbgcolor[]             = "#2e2e2e"; //#000000
static char tagsselbordercolor[]         = "#da035e"; //#da035e
static char tagsselfloatcolor[]          = "#ff8eaf"; //#ff8eaf
                                                             
static char hidnormfgcolor[]             = "#da035e"; //#da035e
static char hidselfgcolor[]              = "#227799"; //#227799
static char hidnormbgcolor[]             = "#2e2e2e"; //#4d4d4d
static char hidselbgcolor[]              = "#2e2e2e"; //#4d4d4d
                                                             
static char urgfgcolor[]                 = "#da035e"; //#ffffff
static char urgbgcolor[]                 = "#2e2e2e"; //#4d4d4d
static char urgbordercolor[]             = "#227799"; //#227799
static char urgfloatcolor[]              = "#da035e"; //#da035e

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "sppulse", "-g", "80x20", "-e", "pulsemixer", NULL };
static Sp scratchpads[] = {
   /* name          cmd  */
   {"spterm",      spcmd1},
   {"sppulse", spcmd2},
};

static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

static const Rule rules[] = {
{ "St",     NULL,     NULL,  NULL,    0,      0,      1,     0,     -1 },
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Firefox", .tags = 1 << 7)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
	RULE(.instance = "sppulse", .tags = SPTAG(1), .isfloating = 1)
};

static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_status,            NULL,                    "status" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,                    "awesomebar" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "TTT",      bstack },
	{ "|M|",      centeredmaster },
	{ "[M]",      monocle },
	{ "===",      bstackhoriz },
	{ ">M>",      centeredfloatingmaster },
	{ "|||",      col },
	{ "(@)",      spiral },
	{ "[\\]",     dwindle },
	{ "HHH",      grid },
	{ "---",      horizgrid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_s,     ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_w,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_e,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = -1 } },

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>

static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_slash,      spawn,                  	{.v = dmenucmd } },
	{ MODKEY,                       XK_Return,     spawn,                  	{.v = termcmd } },
	{ MODKEY|ShiftMask,		XK_slash,      spawn,		       	SHCMD("~/.local/bin/dmenuscript.sh") },
	{ MODKEY|ShiftMask,		XK_backslash,  spawn,		       	SHCMD("~/.local/bin/dmenuunicode.sh") },
	{ MODKEY|ShiftMask,		XK_m,  spawn,		       		SHCMD("~/.local/bin/math.sh") },
	{ MODKEY,			XK_backslash,  spawn,		       	SHCMD("~/.local/bin/sd.sh") },
	{ MODKEY|ControlMask,		XK_backslash,  spawn,			SHCMD("~/.local/bin/thsd.sh") },
	{ MODKEY|ShiftMask,		XK_h,  	       spawn,		       	SHCMD("dunstctl history-pop") },
	{ MODKEY|ControlMask, 		XK_comma,      spawn, 			SHCMD("playerctl -p spotify previous") },
	{ MODKEY|ControlMask, 		XK_period,     spawn, 			SHCMD("playerctl -p spotify next") },
	{ MODKEY|ControlMask,           XK_p,          spawn, 			SHCMD("playerctl -p spotify play-pause") },
	{ MODKEY,                       XK_b,          togglebar,              	{0} },
	STACKKEYS(MODKEY,                              focus)
	STACKKEYS(MODKEY|ShiftMask,                    push)
  	{ MODKEY,	        	XK_bracketleft,   cyclelayout,         {.i = -1 } },
  	{ MODKEY,                       XK_bracketright,     cyclelayout,      {.i = +1 } },
//	{ MODKEY, XK_w, spawn, SHCMD("qutebrowser --qt-flag disable-gpu") },
  	{ MODKEY,			XK_w,	       spawn,		       {.v = (const char*[]){ BROWSER, NULL } } },
	{ MODKEY,                       XK_o,          incnmaster,             {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY,                       XK_space,      zoom,                   {0} },
	{ MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	//{ MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	//{ MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	//{ MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	//{ MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	//{ MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	//{ MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	//{ MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	//{ MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	//{ MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	//{ MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	//{ MODKEY|ControlMask,           XK_0,          togglegaps,             {0} },
	//{ MODKEY|ControlMask|ShiftMask, XK_0,          defaultgaps,            {0} },
	{ MODKEY, 			XK_e, 	       spawn, 		       SHCMD("thunar") },
	{ MODKEY|ShiftMask,             XK_Tab,        view,                   {0} },
	{ MODKEY,                       XK_g,          shiftview,              { .i = -1 } },
	{ MODKEY,                       XK_semicolon,  shiftview,              { .i = +1 } },
	{ MODKEY,                       XK_q,          killclient,             {0} },
	{ MODKEY,             		XK_i,          spawn,          SHCMD("dunstctl close-all") },
	//{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	//{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_t,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                       XK_c,          setlayout,              {.v = &layouts[3]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[4]} },
	{ MODKEY,                       XK_n,         setlayout,              {.v = &layouts[5]} },
	{ MODKEY,                       XK_F7,         setlayout,              {.v = &layouts[6]} },
	{ MODKEY,                       XK_s,         setlayout,              {.v = &layouts[7]} },
	{ MODKEY,                       XK_F6,          setlayout,              {.v = &layouts[9]} },
	{ MODKEY,                       XK_F5,         setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_f,         togglefloating,         {0} },
        { MODKEY, XK_p, togglescratch, {.ui = 1 } },
	{ MODKEY,                       XK_grave,      togglescratch,          {.ui = 0 } },
	{ MODKEY|ControlMask,           XK_grave,      setscratch,             {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_grave,      removescratch,          {.ui = 0 } },
	{ MODKEY,                       XK_f,          togglefullscr,          {0} },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~SPTAGMASK } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
{ MODKEY|ControlMask, XK_f, spawn, SHCMD("maim --hidecursor -i $(xdotool getactivewindow) ~/Pictures/window-$(date +%Y%m%d-%H%M%S).png && notify-send 'Window screenshot saved'") },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
//  { 0,				XK_Print,	spawn,		SHCMD("flameshot gui") },
//	{ 0, XK_Print, spawn, SHCMD("maim -s ~/downloads/screenshot-$(date +%Y%m%d-%H%M%S).png") },
{ 0, XK_Print, spawn, SHCMD("maim -s --hidecursor ~/downloads/screenshot-$(date +%Y%m%d-%H%M%S).png") },
  { 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%- && wpctl set-volume @DEFAULT_AUDIO_SINK@ 3%+; kill -44 $(pidof dwmblocks)") },
  { 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%+ && wpctl set-volume @DEFAULT_AUDIO_SINK@ 3%-; kill -44 $(pidof dwmblocks)") },
	{ 0, XF86XK_AudioMicMute,	spawn,		SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

