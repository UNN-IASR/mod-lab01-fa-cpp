// Copyright 2022 UNN-IASR
#include "fun.h"
unsigned int faStr1(const char* str) {
    if (str == "") {
	    return 0;
	}
    bool startworld = false;
	int count_worlds = 0;
    for (const char* p = str; *p; p++) {
        if (*p != ' ') {
            startworld = true;
            if ('0' <= *p && *p <= '9') {
                startworld = false;
                while (*p != ' ') {
                    p++;
                }
            }
        } else {
            if (startworld) {
                startworld = false;
                count_worlds++;
            }
        }
    } if (startworld) {
         startworld = false;
         count_worlds++;
    }
    return count_worlds;
}


unsigned int faStr2(const char* str) {
	if (str == "") {
		return 0;
	}
	bool startworld = false;
	int count_worlds = 0;
	for (const char* p = str; *p; p++) {
		if (*p != ' ') {
			if (*p >= 'A' && *p <= 'Z') {
				if (!startworld){
					startworld = true;
				} else {
					startworld = false;
					while (*p != ' ' && *p != 0) {
						p++;
					}
				}
			} else {
				if (*p >= 'a' && *p <= 'z') {
					if (!startworld){
						while (*p != ' ' && *p != 0) {
							p++;
						}
					}

				}
				else {
					startworld = false;
				}

			} if ('0' <= *p && *p <= '9') {
				startworld = false;
				while (*p != ' ' && *p != 0) {
					p++;
				}
			}

		} else { 
			if (startworld) {
				startworld = false;
				count_worlds++;
			}
		}

	} if (startworld) {
		startworld = false;
		count_worlds++;
	}
	return count_worlds;
}


unsigned int faStr3(const char* str) {
	int count_worlds = 0, countSymbol = 0;
	if (str == "") {
		return 0;
	}
	bool startworld = false;
	for (const char* p = str; *p; p++) {
		if (*p != ' ') {
			startworld = true;
			countSymbol++;
			if ('0' <= *p && *p <= '9') {
				startworld = false;
				while (*p != ' ' && *p != 0) {
					p++;
				}
			}

		} else {
			if (startworld) {
				startworld = false;
				count_worlds++;
			}
		}

	} if (startworld) {
	    startworld = false;
		count_worlds++;
	}
	int mediumLength = countSymbol / count_worlds;
	return mediumLength;
}
