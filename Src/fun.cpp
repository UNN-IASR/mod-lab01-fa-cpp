// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cstring>
#include <ctype.h>
#include <string>
#include <cmath>
#include <stdio.h>

unsigned int faStr1(const char* str) {
	int q = 0;
	bool f = false;
	int i = 0;
	bool s = true;
	while (str[i] == ' ' && str[i] != '\0') {
		i++;
	}
	while (str[i] != '\0') {
		if (str[i] != ' ' && f == false) {
			f = true;
			int k = i;
			while (str[k] != ' ') {
				if (isdigit(str[k])) {
					s = false;
					k++;
				}
				k++;
			}
			if (s == true) {
				q++;
			}
		} else {
			if (str[i] == ' ') {
				f = false;
				s = true;
			}
		}
		i++;
	}
	return q;
}
unsigned int faStr2(const char* str) {
	int bword = 0;
	int simv = 0;
	bool f = false;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			f = true;
		} else {
			simv++;
		}
		if (str[i] != ' ' && i == strlen(str) - 1) {
			bword++;
		}
		if (f == true) {
			if (i != 0) {
				if (str[i - 1] != ' ') {
					bword++;
				}
			}
			f = false;
		}
	}	return  round(simv / bword);
}
unsigned int faStr3(const char* str) {
	bool slovo = false;
	unsigned int a = 0;
	int i;

	for (i = 0; i < strlen(str); i++) {
		if (slovo &&(i == strlen(str) - 1 || str[i] == ' ')) {
			a++;
			slovo = false;
		} else {
            if (str[i] != ' ' && !islower(str[i]) && !slovo) {
			if (i == 0 || str[i - 1] == ' ') {
				slovo = true;
			}
		} else {
            if (slovo && !islower(str[i])) {
			slovo = false;
		}
	}

	return a;
}
