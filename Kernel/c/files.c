#include <files.h>
#include <video.h>
#include <keyboard.h>

uint64_t fwrite(uint64_t fd, char *buffer, uint64_t maxBytes) {
	int result = 0;
	if(fd < MIN_FD || fd > MAX_FD) return -1;
	int i;
	switch(fd) {
		case STDOUT:
			result = 0;
			for(i = 0; buffer[i] != 0 && i < maxBytes; i++) {
				ncPrintChar(buffer[i]);
				result++;
			}
			break;
		case STDERR:
			result = 0;
			for(i = 0; buffer[i] != 0 && i < maxBytes; i++) {
				ncPrintColorChar(buffer[i], (char) 0x04);
				result++;
			}
			break;
		case KEYBOARD:
			fwrite(STDERR, "Can't write to keyboard.", 24);
			return 0;
			break;
		case SPEAKER:
			ncPrint("Speaker not implemented yet.");
			break;
	}
	return result;
}

uint64_t fread(uint64_t fd, char *buffer, uint64_t maxBytes) {
	fwrite(STDERR, "FREAD not implemented yet, lel", 50);
	return getPressedKey();
	return -1;
}