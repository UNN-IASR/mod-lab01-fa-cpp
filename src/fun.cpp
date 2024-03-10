#include <cctype>


unsigned int faStr1(const char* str)
{
	int i;
	bool invWord = false; //булевая переменная, определяющая, допустимое ли слово или нет 
	bool word = false; //булевая переменная, определяющая, находимся ли мы в слове в данный момент
	int WnD = 0; //Количество слов, в которых не содержутся цифры
	while (str[i]) {
		char value = str[i];
		if (value == ' ') {
			invWord = false;
			word = false;
		}
		else {
			word = true;
			if (isdigit(value)&&!invWord) {
				invWord = true;
				WnD++;
			}
		};
		i++;
	}
	return WnD;
}
