// Copyright 2022 UNN-IASR
#include "fun.h"
#include <ctype.h>
#include <cmath>
#include <iostream>
unsigned int faStr1(const char *str){
	bool inWord = false;
	int count = 0;
	int i = 0;
	bool digit = false;
	while (str[i]) {
		if (isdigit(str[i]) && digit == false){
			digit = true;
		}
		if (str[i] != ' ' && inWord == false){
			inWord = true;
			count++;
		} else if (str[i] == ' ' && inWord == true){
			if (digit == true){
				count--;
				digit = false;
			}
			inWord = false;
		}
		i++;
	}
	std::cout << count<<std::endl;
	return count;
}
unsigned int faStr2(const char* str){
	bool inWord = false; 
	int count = 0;
	int i = 0;
	bool Up = false;
	while (str[i]) {
		if (str[i] != ' ' && inWord == false && isupper(str[i])){
			inWord = true;
			count++;
		} else if (str[i] != ' ' && inWord == true && !islower(str[i]) && Up == false){
			Up = true;
		} else if (str[i] == ' ' && inWord == true){
			inWord = false;
			Up = false;
		}
		if (Up == true){
			 Up = false;
		 }
		i++;
	}
	std::cout << count << std::endl;
	return count;
}
unsigned int faStr3(const char* str){
	bool inWord = false;
	double count = 0;
	double str_len = 0;
	int i = 0;
	while (str[i]) {
		if (str[i] != ' ' && inWord == false){
			inWord = true;
			count++;
		}
		if (str[i] != ' ' && inWord == true){
			str_len++;
		} else if (str[i] == ' ' && inWord == true){
			inWord = false;
		}
		i++;
	}
	double average = round(str_len / count);
	std::cout << average << std::endl;
	return average;
}
