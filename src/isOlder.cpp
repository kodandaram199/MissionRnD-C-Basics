/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int compare(char *, char *, int, int);
int validityCheck(char *, char *);

int isOlder(char *dob1, char *dob2) {
	int age;
	if ((age = validityCheck(dob1, dob2)) == -1)
	{
		return age;
	}
	if ((age = compare(dob1, dob2, 6, 4)) == 0)
	{
		if ((age = compare(dob1, dob2, 3, 2)) == 0)
		{
			if ((age = compare(dob1, dob2, 0, 2)) == 0)
			{
				return 0;
			}
			return age;
		}
		return age;

	}
	return age;

}
int compare(char *dob1, char*dob2, int start, int len)
{
	int i = start;
	while (i <= (start + len - 1))
	{
		int asciiValueOfStr1 = (int)dob1[i];
		int asciiValueOfStr2 = (int)dob2[i];
		if (asciiValueOfStr1 >= 48 && asciiValueOfStr1 <= 57 && asciiValueOfStr2 >= 48 && asciiValueOfStr2 <= 57)
		{
			if (asciiValueOfStr1 == asciiValueOfStr2)
			{
				if (i != (start + len - 1))
					i++;
				else
					return 0;
			}

			else if (asciiValueOfStr1 > asciiValueOfStr2)
				return 2;
			else if (asciiValueOfStr1 < asciiValueOfStr2)
				return 1;
		}
		else
			break;
	}
	if (i != (start + len - 1))
		return -1;

}

int validityCheck(char *dob1, char *dob2)
{
	/*For validating the lenghts of strings.*/
	int i = 0, len1 = 0, len2 = 0;
	while (dob1[i] != '\0') {
		i++;
	}
	len1 = i;
	i = 0;
	while (dob2[i] != '\0') {
		i++;
	}
	len2 = i;
	i = 0;
	if (len1 != 10 || len2 != 10)
	{
		return -1;
	}

	/*validating character '-' and digits 0-9*/

	while (dob1[i] != '\0')
	{
		int asciiValueOfStr1 = (int)dob1[i];
		int asciiValueOfStr2 = (int)dob2[i];
		if (i == 2 || i == 5)
		{
			if (asciiValueOfStr1 != 45 || asciiValueOfStr2 != 45)
				return -1;
			else
				i++;
		}
		else
		{
			if (asciiValueOfStr1 >= 48 && asciiValueOfStr1 <= 57 && asciiValueOfStr2 >= 48 && asciiValueOfStr2 <= 57)
				i++;
			else
				return -1;
		}

	}
	/*validating year*/
	int year1 = ((int)(dob1[8] - 48) * 10 + (int)(dob1[9] - 48)) % 4;
	int year2 = ((int)(dob1[8] - 48) * 10 + (int)(dob1[9] - 48)) % 4;
	if (year1 == 0)
	{
		if (((int)(dob1[3] - 48) * 10 + (int)(dob1[4] - 48)) == 2)
		{
			if (((int)(dob1[0] - 48) * 10 + (int)(dob1[1] - 48)) >29)
				return -1;
		}
	}
	else
	{
		if (((int)(dob1[3] - 48) * 10 + (int)(dob1[4] - 48)) == 2)
		{
			if (((int)(dob1[0] - 48) * 10 + (int)(dob1[1] - 48)) >28)
				return -1;
		}
	}
	if (year2 == 0)
	{
		if (((int)(dob1[3] - 48) * 10 + (int)(dob1[4] - 48)) == 2)
		{
			if (((int)(dob1[0] - 48) * 10 + (int)(dob1[1] - 48)) >29)
				return -1;
		}
	}
	else
	{
		if (((int)(dob1[3] - 48) * 10 + (int)(dob1[4] - 48)) == 2)
		{
			if (((int)(dob1[0] - 48) * 10 + (int)(dob1[1] - 48)) >28)
				return -1;
		}
	}
	if (((int)(dob1[3] - 48) * 10 + (int)(dob1[4] - 48)) > 12)
	{
		return -1;
	}
	if (((int)(dob1[0] - 48) * 10 + (int)(dob1[1] - 48)) > 31)
		return -1;
	else
		return 0;


}