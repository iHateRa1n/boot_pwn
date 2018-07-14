/*
boot_pwn / StallionX - iBoot Exploit like thing
Thanks winocm for multi_kloader!
This will take an iBEC and an iBSS, and load it on startup.
If you want, you can dual boot; and put the iBEC and iBSS into this program, and it will make it untethered!
:)

CREDITS:
winocm - multi_kloader/ios-kexec-utils

iH8Ra1n, 2018
*/

#include <stdio.h>
#include <stdlib.h>

int do_it() {
	/*
	boot_pwn / StallionX code
	boot_pwn / StallionX is an iBoot Exploit like thing; that can run an arbitrary iBSS & iBEC on iOS.
	No 64-bit... yet. :(
	*/
	printf("[*] running boot_pwn / StallionX! \n");
	system("if mv iBEC /iBEC; then\n\tprintf\nelse\n\techo \"[!] no iBEC\"\nfi");
	system("if mv iBSS /iBSS; then\n\tprintf\nelse\n\techo \"[!] no iBSS\"\nfi");
	printf("[*] done with setup. ready to pwn! :D\n");
	printf("[*] installing boot code! \n");
	system("mv /usr/libexec/CrashHousekeeping /usr/libexec/CrashHouseKeeping2");
	system("cp -R exec /usr/libexec/CrashHousekeeping; chmod 4777 /usr/libexec/CrashHousekeeping");
	printf("[*] pwnd! rebooting, say goodbye to iOS! \n");
	system("reboot");
};

int main() {
	printf("iSec boot_pwn / StallionX 0.0.0 alpha\n");
	if (getuid() != 0) {
		// not root :.(
		printf("[!] no root\n");
		return 1;
	};
	if (getuid() == 0) {
		// we're root, so it'll work.
		do_it();
	};
	return 0;
};
