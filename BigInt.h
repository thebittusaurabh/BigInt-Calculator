#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInt {
private:
    string number;
    bool isNegative;

public:
    BigInt() : number("0"), isNegative(false) {}

    BigInt(string num) {
        if (num[0] == '-') {
            isNegative = true;
            number = num.substr(1);
        } else {
            isNegative = false;
            number = num;
        }
        reverse(number.begin(), number.end());
    }

    BigInt operator+(const BigInt& other) const {
        if (isNegative == other.isNegative) {
            string result = add(number, other.number);
            if (isNegative) {
                result += "-";
            }
            reverse(result.begin(), result.end());
            return BigInt(result);
        } else {
            if (isNegative) {
                return other - BigInt(number);
            } else {
                return *this - BigInt(other.number);
            }
        }
    }

    BigInt operator-(const BigInt& other) const {
        if (isNegative == other.isNegative) {
            if (abs_compare(number, other.number) >= 0) {
                string result = subtract(number, other.number);
                if (isNegative) {
                    result += "-";
                }
                reverse(result.begin(), result.end());
                return BigInt(result);
            } else {
                string result = subtract(other.number, number);
                if (!isNegative) {
                    result += "-";
                }
                reverse(result.begin(), result.end());
                return BigInt(result);
            }
        } else {
            return *this + BigInt((isNegative ? "-" : "") + other.number);
        }
    }

    friend ostream& operator<<(ostream& os, const BigInt& bi) {
        if (bi.isNegative) {
            os << "-";
        }
        for (int i = bi.number.size() - 1; i >= 0; i--) {
            os << bi.number[i];
        }
        return os;
    }

private:
    static string add(const string& a, const string& b) {
        string result;
        int carry = 0, sum = 0;
        size_t maxLength = max(a.size(), b.size());
        for (size_t i = 0; i < maxLength || carry; i++) {
            sum = carry;
            if (i < a.size()) {
                sum += a[i] - '0';
            }
            if (i < b.size()) {
                sum += b[i] - '0';
            }
            carry = sum / 10;
            result += (sum % 10) + '0';
        }
        return result;
    }

    static string subtract(const string& a, const string& b) {
        string result;
        int carry = 0, diff = 0;
        for (size_t i = 0; i < a.size(); i++) {
            diff = (a[i] - '0') - carry - (i < b.size() ? (b[i] - '0') : 0);
            carry = (diff < 0) ? 1 : 0;
            if (carry) {
                diff += 10;
            }
            result += diff + '0';
        }
        return result;
    }

    static int abs_compare(const string& a, const string& b) {
        if (a.size() != b.size()) {
            return a.size() - b.size();
        }
        return a.compare(b);
    }
};

#endif // BIGINT_H
