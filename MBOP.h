#include <iostream>
#include <string>

using namespace std;

const int maxCells = 16;

string Int2Any(int x, int digitsNums) {
	string result;
	int ost;

	while (x > 0) {
		ost = x % digitsNums;
		result.push_back(ost + '0');
		x /= digitsNums;
	}

	if (result.empty()) result = "0";

	reverse(result.begin(), result.end());

	return result;
}

string writeInt2Any(int x, int digitsNums) {
	string result;
	int ost;
	cout << "  /" << digitsNums << '\n';

	while (x > 0) {
		ost = x % digitsNums;
		cout << x << " | " << ost << '\n';
		result.push_back(ost + '0');
		x /= digitsNums;
	}

	reverse(result.begin(), result.end());

	cout << result << '\n';
	return result;
}

int Any2Int(string number, int digitsNums) {
	int result = 0, size = (int)number.size(),
		itD, stepin;

	for (int i = 0; i < size; i++) {
		itD = (int)number[i] - (int)'0';
		stepin = size - i - 1;

		result += pow(digitsNums, stepin) * itD;
	}

	return result;
}

void writeAny2Int(string number, int digitsNums) {
	int result = 0, size = (int)number.size(),
		itD, stepin;

	for (int i = 0; i < size; i++) {
		itD = (int)number[i] - (int)'0';
		stepin = size - i - 1;
		cout << itD << " * " << digitsNums << "^" << stepin;

		if (i != size - 1) cout << " + ";
		else cout << " = ";

		result += pow(digitsNums, stepin) * itD;
	}

	cout << result << '\n';
}

void writeOct2Bin(string number) {
	string part;
	int size = (int)number.size();

	cout << number << " = ";

	for (int i = 0; i < size; i++) {
		part = Int2Any(number[i] - '0', 2);

		part = string(3 - part.size(), '0').append(part);

		cout << part;

		if (i != size - 1) cout << '|';
	}
}

void writeHex2Bin(string number) {
	string part;
	int size = (int)number.size(), digit;
	char digitChar;

	cout << number << " = ";

	for (int i = 0; i < size; i++) {
		digitChar = number[i];
		switch (digitChar) {
		case 'A':
			digit = 10;
			break;
		case 'B':
			digit = 11;
			break;
		case 'C':
			digit = 12;
			break;
		case 'D':
			digit = 13;
			break;
		case 'E':
			digit = 14;
			break;
		case 'F':
			digit = 15;
			break;
		default:
			digit = digitChar - '0';
		}

		part = Int2Any(digit, 2);

		part = string(4 - part.size(), '0').append(part);

		cout << part;

		if (i != size - 1) cout << '|';
	}
}

string BinSum(string n1, string n2) {
	int carry = 0, n1Size = (int)n1.length(), n2Size = (int)n2.length();
	string result;

	string paddedN1 = string(maxCells - n1Size, '0') + n1;
	string paddedN2 = string(maxCells - n2Size, '0') + n2;

	for (int i = maxCells - 1; i >= 0; --i) {
		int bitSum = (paddedN1[i] - '0') + (paddedN2[i] - '0') + carry;
		result.insert(result.begin(), '0' + bitSum % 2);
		carry = bitSum / 2;
	}

	if (carry > 0) {
		result.insert(result.begin(), '0' + carry);
	}

	return string(result.end() - maxCells, result.end());
}

void writeSM(int x) {
	if (x < 0) {
		cout << "1|";
	}
	else {
		cout << "0|";
	}
	cout << Int2Any(abs(x), 2) << '\n';
}

string C1(int x) {
	string bits = Int2Any(abs(x), 2);
	bits = string(16 - bits.size(), '0') + bits;
	if (x < 0) {
		int n = bits.size();
		for (int i = 0; i < n; i++) {
			if (bits[i] == '0') bits[i] = '1';
			else bits[i] = '0';
		}

		if (bits[0] == '0') bits = "1" + bits;
	}
	return string(bits.begin(), bits.begin() + maxCells);
}

string writeC1(int x) {
	string bits = writeInt2Any(abs(x), 2);
	cout << (int)log2(abs(x)) + 1 << " signs\n";
	bits = string(maxCells - bits.size(), '0') + bits;
	if (x < 0) {
		cout << bits << " -> ";
		int n = bits.size();
		for (int i = 0; i < n; i++) {
			if (bits[i] == '0') bits[i] = '1';
			else bits[i] = '0';
		}

		if (bits[0] == '0') bits = "1" + bits;
	}
	cout << "C1 result: " << bits << '\n';
	return string(bits.begin(), bits.begin() + maxCells);
}

string C2(int x) {
	if (x < 0) {
		return BinSum(C1(x), "1");
	}
	else {
		return C1(x);
	}
}

string writeC2(int x) {
	string result;
	if (x < 0) {
		result = BinSum(writeC1(x), "1");
	}
	else {
		result = writeC1(x);
	}
	cout << "C2 result: " << result << '\n';
	return result;
}

string float2Bin(float x) {
	string result = Int2Any((int)x, 2) + ",";
	x -= (int)x;
	while (x != (int)x) {
		x *= 2.0;
		result.push_back(((int)x % 2) + '0');
	}
	return result;
}

string writefloat2Bin(float x) {
	int actual;
	string result = writeInt2Any((int)x, 2) + ",";
	x -= (int)x;
	cout << "\n  *2\n";
	while (x != (int)x) {
		x *= 2.0;
		actual = (int)x % 2;
		cout << actual << " | " << x - (int)x << '\n';
		result.push_back(((int)x % 2) + '0');
	}
	cout << '\n' << result << '\n';

	return result;
}

float Bin2float(string number) {
	float result = 0;
	int size = (int)number.size(),
		itD, stepin, j = 1;

	while (number[j] != '.') {
		j++;
	}

	for (int i = 0; i < size; i++) {
		if (i != j) {
			itD = (int)number[i] - (int)'0';
			stepin = j - i;

			result += pow(2, stepin) * itD;
		}
	}

	return result;
}

float writeBin2float(string number) {
	float result = 0;
	int size = (int)number.size(),
		itD, stepin, j = 1;

	while (number[j] != '.') {
		j++;
	}

	for (int i = 0; i < size; i++) {
		if (i != j) {
			itD = (int)number[i] - (int)'0';
			stepin = j - i;

			cout << itD << " * " << 2 << "^" << stepin;

			if (i != size - 1) cout << " + ";
			else cout << " = ";

			result += pow(2, stepin) * itD;
		}
	}

	cout << result << '\n';

	return result;
}