
class replace{
public:
	void ReplaceBlank(char* string, int length);
	//void replace::ReplaceBlank(char* string,int length);
};

//void replace::ReplaceBlank(char* string, int length)
/*void replace::ReplaceBlank(char* string,int length)
{
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
	    ++originalLength;
		if (string[i] == ' ')
		{
			++numberOfBlank;
		}
		++i;
	}

	int newLength = originalLength + 2 * numberOfBlank;
	if (newLength == length)
	{
		return;
	}
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		indexOfOriginal--;
	}
}*/

void replace::ReplaceBlank(char* string, int length)
{
	if (string == nullptr || length <= 0)
	{
		return;
	}
	int numberOfLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++numberOfLength;
		if (string[i] == ' ')
		{
			++numberOfBlank;
		}
		++i;
	}

	int NewLength = numberOfLength + 2 * numberOfBlank;
	int indexOfOriginal = numberOfLength;
	int indexOfNew = NewLength;
	if (indexOfNew == length)
	{
		return;
	}
	while (indexOfOriginal >= 0 &&string[indexOfNew] != string[indexOfOriginal])
	//while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';   //a[i--]Ïàµ±ÓÚa[i],i=i-1;
		}
		else
			string[indexOfNew--] = string[indexOfOriginal];
		indexOfOriginal--;
	}
}