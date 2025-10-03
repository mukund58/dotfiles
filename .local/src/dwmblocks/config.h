//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {

/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
  {"",  "netspeed",  1,  16},
  {"",  "memory",  1,  16}, 
  {"",  "sb-cpu",  1,  16},
  {"",  "volume", 1,  10},
  {"",  "clock",  60, 1},
  {"",  "battery",  1, 10},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
