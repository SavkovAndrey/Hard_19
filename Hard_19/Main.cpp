#include <iostream>
#include <string>

using namespace std;

void mostRecent(char* text, char* word);
int Counter(char *text, char *temp, int i);

int main()
{
	setlocale(LC_ALL, "RU");

	cout << "¬ведите текст: \n";
	char text[1000]{};
	char word[1000]{};
	
	cin.getline(text, 999);

	mostRecent(text, word);

	cout << "\nсамое часто встречающеес€ слово в тексте:  ";
	for (int i = 0; word[i] != '\0'; i++)
	{
	word[i] = toupper(word[i]);
	}
	cout << word << endl;

	system("pause");
	return 0;
}

void mostRecent(char* text, char* word)
{
	char temp[1000]{ '\0' };
	int j = 0;
	int count = 0;
	int max_count = 0;

	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] != ' ' && text[i] != '.' && text[i] != ',' && text[i] != '!' && text[i] != '?' && text[i] != ':')
		{
			temp[j] = text[i];
			j++;
		}
		else
		{
			count = Counter(text, temp, i);
			if (count > max_count)
			{
				max_count = count;
				for(int k = 0; k < j; k++)
				word[k] = temp[k];
			}
			j = 0;
			char temp[1000]{ '\0' };
		}
	}
}

int Counter(char* text, char* temp, int i)
{
	char buff[1000]{ '\0' };
	int k = 0;
	int count = 0;


	for (i; text[i] != '\0'; i++)
	{
		if (text[i] != ' ' && text[i] != '.' && text[i] != ',' && text[i] != '!' && text[i] != '?' && text[i] != ':')
		{
			buff[k] = text[i];
			k++;
		}
		else
		{
			if (strcmp(buff, temp) == 0)
			{
				count++;
			}
			k = 0;
			char buff[1000]{ '\0' };
		}
	}
	return count;
}