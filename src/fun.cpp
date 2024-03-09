// Copyright 2022 UNN-IASR
#include "fun.h"

unsigned int faStr1(const char *str) {
	bool inWord = false;
	bool wordInvalidated = false;
	int i = 0;
	unsigned int count = 0;
	while (str[i] != '\0') {
		if (inWord) {
			if (str[i] >= '0' && str[i] <= '9') wordInvalidated = true;
			if (str[i] == ' ' || str[i] == '\n') {
				if (wordInvalidated) count--;
				inWord = false;
				wordInvalidated = false;
			}
		}
		else {
			if (str[i] != ' ' && str[i] != '\n' && (str[i] < '0' || str[i] > '9')) {
				count++;
				inWord = true;
			}
		}
		i++;
	}
    return count;
}

unsigned int faStr2(const char *str) {
	bool inWord = false;
	bool wordInvalidated = false;
	int i = 0;
	unsigned int count = 0;
	while (str[i] != '\0') {
		if (inWord) {
			if (str[i] < 'a' || str[i] > 'z') wordInvalidated = true;
			if (str[i] == ' ' || str[i] == '\n') {
				if (wordInvalidated) count--;
				inWord = false;
				wordInvalidated = false;
			}
		}
		else {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				count++;
				inWord = true;
			}
		}
		i++;
	}
    return count;
}

unsigned int faStr3(const char *str) {
	bool inWord = false;
	int i = 0;
	unsigned int count = 0;
	float sum = 0;
	while (str[i] != '\0') {
		if (inWord) {
			if (str[i] == ' ' || str[i] == '\n') {
				inWord = false;
			}
			else sum++;
		}
		else {
			if (str[i] != ' ' && str[i] != '\n') {
				count++;
				sum++;
				inWord = true;
			}
		}
		i++;
	}
    return count ? (unsigned int)(sum / count) + ((float)(sum / count) - (unsigned int)(sum / count) > 0.5f) : 0;
}
