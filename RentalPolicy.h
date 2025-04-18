#pragma once
#include<iostream>
using namespace std;

class CustomerProfile;

class RentalPolicy
{
public:
	virtual int maxBooks() const = 0;
	virtual int maxRentDuration() const = 0;
	virtual ~RentalPolicy() = default;

};

