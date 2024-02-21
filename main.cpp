#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isValidCreditCard(const string& cardNumber) {
	int sum = 0;
	bool alternate = false;

	// Read digits left to right
	for (int i = cardNumber.length() - 1; i >= 0; --i) {
		int digit = cardNumber[i] - '0'; // Convert character to integer

		// Double every other digit
		if (alternate) {
			digit *= 2;

			// if doubling results in a two digit number, add those two
			if (digit > 9) {
				digit = digit % 10 + 1;
			}
		}

		sum += digit;
		alternate = !alternate; // Switch flag for next iteration
	}

	// CCN is valid if the sum is divisible by 10
	return (sum % 10 == 0);
}

int main() {
	string cardNumber;

	// Input CC number 
	cout << "Enter your credit card number: ";
	cin >> cardNumber;

	// Remove everything but integers from the input
	cardNumber.erase(remove_if(cardNumber.begin(), cardNumber.end(), [](char c) { return !std::isdigit(c); }), cardNumber.end());

	// Check validity and display output
	if (isValidCreditCard(cardNumber)) {
		cout << "The credit card number in valid." << endl;
	}
	else {
		cout << "The credit card number is not valid. " << endl;
	}

	return 0;
}