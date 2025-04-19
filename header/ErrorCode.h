#pragma once
#include<string>
using namespace std;

enum class ErrorCode
{
	UNKNOWN, NOT_FOUND, DUPLICATE, LIMIT_EXCEEDED, AUTH_FAILED, OUT_OF_STOCK
};

inline string codeToString(ErrorCode code)
{
	switch (code)
	{
	case ErrorCode::UNKNOWN: return "UNKNOWN";
	case ErrorCode::NOT_FOUND: return "NOT_FOUND";
	case ErrorCode::DUPLICATE: return "DUPLICATE";
	case ErrorCode::LIMIT_EXCEEDED: return "LIMIT_EXCEEDED";
	case ErrorCode::AUTH_FAILED: return "AUTH_FAILED";
	case ErrorCode::OUT_OF_STOCK: return "OUT_OF_STOCK";
	default: return "UNDEFINED";
	}
}