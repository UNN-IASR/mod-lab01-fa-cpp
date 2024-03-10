// Copyright 2022 UNN-IASR

#include "fun.h"

unsigned int faStr1(const char* str) {
	
	unsigned int counter = 0, i=0;
	bool isword = false, cont_digit = false;
	while (str[i]) 
	{
		if (!isword && str[i] != ' ') 
		{
			isword = true;
		}
		if (isword && str[i] == ' ') 
		{
			isword = false;
			if (!cont_digit) counter++;
			cont_digit = false;
		}
		if (str[i] >= '0' && str[i] <= '9')cont_digit = true;
		i++;
	}
	return counter;
}

unsigned int faStr2(const char* str) { 
	unsigned int counter = 0, i = 0;
	bool isword = false, right_word = false;
	while (str[i])
	{
		if (!isword && str[i] != ' ')
		{
			isword = true;
			if(str[i]>='A'&&str[i]<='Z')right_word = true;
		}
		else if (isword && str[i] == ' ')
		{
			isword = false;
			if (right_word) counter++;
			right_word = false;
		}
		else if (str[i] < 'a' || str[i] > 'z')right_word = false;
		i++;
	}
	return counter;
}

unsigned int faStr3(const char* str) {
	unsigned int counter = 0, i = 0, sum=0,avg;
	bool isword = false;
	while (str[i])
	{
		if (!isword && str[i] != ' ')
		{
			isword = true;
		}
		if (isword && str[i] == ' ')
		{
			isword = false;
			counter++;
		}
		else if (isword)sum++;
		i++;
	}
	if(sum % counter>=0.5*counter)avg = sum/counter+1;
	else avg = sum / counter;
	return avg;
}
