#define Workshop1

#ifdef Workshop1

#include <iostream>
#include <string>

using namespace std;

string Int2Any(int x, int digitsNums) {
	string result;
	int ost;

	while (x > 0) {
		ost = x % digitsNums;
		result.push_back(ost + '0');
		x /= digitsNums;
	}

	reverse(result.begin(), result.end());

	return result;
}

void writeInt2Any(int x, int digitsNums) {
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
}

void writeAny2Int(string number, int digitsNums) {
	int result = 0, size = number.size(), 
		itD, stepin;

	for (int i = 0;i < size;i++) {
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
	int size = number.size();

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
	int size = number.size(), digit;
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

int main() {
	int mode, number, sys;
	string sNumber;
	while (true) {
		cout << "\nChoose option: \n"
			<< "1) Dec to any\n"
			<< "2) Any to dec\n"
			<< "3) Oct to Bin\n"
			<< "4) Hex to Bin\n"
			<< "> ";

		cin >> mode;

		switch (mode) {
		case 1:
			cout << "Number: ";
			cin >> number;
			cout << "System: ";
			cin >> sys;
			writeInt2Any(number, sys);
			break;
		case 2:
			cout << "Number: ";
			cin >> sNumber;
			cout << "System: ";
			cin >> sys;
			writeAny2Int(sNumber, sys);
			break;
		case 3:
			cout << "Number: ";
			cin >> sNumber;
			writeOct2Bin(sNumber);
			break;
		case 4:
			cout << "Number: ";
			cin >> sNumber;
			writeHex2Bin(sNumber);
			break;
		}
	}
	return 0;
}

#endif
