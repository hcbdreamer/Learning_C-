
class findrepeat{
public:
	bool Find(int** num, int rows, int columns, int length);
	//bool Find(int* num, int rows, int columns, int length);

};

bool findrepeat::Find(int** num, int rows, int columns, int number)
{
	
	int row = 0;
	int column = columns - 1;
	while (column >= 0 && row < rows)
	{
		if (num[row][column] == number)
		{
			return true;
		}
		else if (num[row][column]>number)
		{
			column--;
		}
		else
		{
			row++;
		}
	}
	return false;
}

/*bool findrepeat::Find(int* num, int rows, int columns, int number)
{
	if (num != nullptr&&rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (column >= 0 && row < rows)
		{
			if (num[row*columns + column] == number)
			{
				return true;
			}
			else if (num[row*columns + column]>number)
			{
				column--;
			}
			else
			{
				row++;
			}
		}
	}
	return false;
}*/