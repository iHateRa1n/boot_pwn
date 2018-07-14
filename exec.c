/*
exec.c - part of the StallionX toolkit
runs on startup with suid, by replacing /usr/libexec/CrashHousekeeping
enjoy untethers!

:D
*/

#include <stdlib.h>
#include <stdio.h>

int main() {
	system("/multi_kloader /iBSS /iBEC"); // boot me!
	return 0;
};
