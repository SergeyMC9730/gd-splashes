#pragma once

#include "win32cac.h"

static const char* splashText[] = {
		"Stay Home!",
		"Play more",
		"Geometry Bruh",
		"Geometry Dash",
		"Splash",
		"This splash is so big so you will see some pixels on splash label on the MenuLayer screen ;). And stay home too!!!",
		"Klidex Dash",
		"did you clicked to the Toilet?",
		"This is was hard",
		"200 members",
		"Scam Dash",
		"NO",
		"YES",
		"GD",
		"@everyone",
		"Success! Moderator access granted!",
		"TIG 2",
		"1012 Lighter", // :troll:
		"According to all known laws of aviation, there is no way a bee, should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible.",
		"Yellow, black. Yellow, black. Yellow, black. Yellow, black.",
		"Ooh, blackand yellow! Let's shake it up a little.",
		"Fake",
		"Pirated",
		"12345 is a bad password!",
		"20 GOTO 10",
		"Also try The Impossible Game 2!",
		"Black Lives Matter!",
		"Open source mod",
		"Do not use the N-word",
		"Splashes included!",
		"Bug-free!",
		"Linux... Yes",
		"Windows... Yes",
		"MacOS... Doesn't support",
		"Enter the devpassword...",
		"012345678910",
		"moi parol 123456",
		"RobTop is love, RobTop is life",
		"Rickroll",
		"2.2 when",
		"2.2 almost done!",
		"The peakest of the sneak!",
		"dai sotku v dolg",
		"Everyplay is closed",
		"foxodever moment",
		"Use Debug Mode for secrets..."

};
class Splashes {
public:
	static const char* get();
	static float get(const char *text);
#define splashSize (sizeof(splashText) / sizeof(*splashText))
};