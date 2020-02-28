int max(int x, int y)
{
	return (x > y) ? x : y;
}
int min(int x, int y)
{
	return (x < y) ? x : y;
}


number::number(int iNumerator, int iDenominator)
{
	numerator = iNumerator;
	denominator = iDenominator;
}

number::number(int iNumerator)
{
	numerator = iNumerator;
	denominator = 1;
}

number::number()
{
	numerator = 1;
	denominator = 1;
}
number::number(const number& ss)
{
	numerator = ss.numerator;
	denominator = ss.denominator;
}
number number::Add(const number& C) {
	number dd;
	dd.numerator = numerator * C.denominator +
		denominator * C.numerator;
	dd.denominator = denominator * C.denominator;
	return dd;
}
number number::operator +(number& C)
{
	number dd;
	dd.numerator = numerator * C.denominator +
		denominator * C.numerator;
	dd.denominator = denominator * C.denominator;
	return dd;
}
number number::operator -(number& C)
{
	number dd;
	dd.numerator = numerator * C.denominator -
		denominator * C.numerator;
	dd.denominator = denominator * C.denominator;
	return dd;
}
number number::operator *(number& C)
{
	number dd;
	dd.numerator = numerator * C.numerator;
	dd.denominator = denominator * C.denominator;
	return dd;
}
number number::operator /(number& C)
{
	number dd;
	dd.numerator = denominator * C.denominator;
	dd.denominator = numerator * C.numerator;
	return dd;
}

bool number::operator==(const number& C) {
	bool res = 0;
	if (numerator == C.numerator && denominator == C.denominator) {
		res = 1;
	}
	else {
		res = 0;
	}
	return res;
}

void number::cancellation()
{
	int N;
	bool bReturn;
	do
	{
		N = min(abs(numerator), abs(denominator));
		int num = numerator;
		int den = denominator;
		bReturn = false;
		for (int i = N; i > 1; i--)
		{
			num = (numerator / i) * i;
			den = (denominator / i) * i;
			if (((numerator / i) * i == numerator) &&
				((denominator / i) * i == denominator))
			{
				numerator /= i;
				denominator /= i;
				bReturn = true;
				break;
			}
		}
	} while (bReturn);

	return;
}
void number::inPut() {
	cout << "Числетель = ";
	cin >> numerator;
back:
	cout << "Знаменатель = ";
	cin >> denominator;
	if (denominator == 0) {
		cout << "Знаменатель не может быть равен 0" << endl;
		goto back;
	}
}
void number::output() {
	cout << x;
	cout << y;
}