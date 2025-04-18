#pragma once
#include<iostream>
#include<string>
using namespace std;

class BookPricePolicy
{
public:
	virtual double calculatePrice(double basePrice) const = 0;
	virtual BookPricePolicy* clone() const = 0;
	virtual string getPolicyType() const = 0;
	virtual ~BookPricePolicy() = default;
};

