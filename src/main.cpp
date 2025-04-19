#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "Book.h"
#include "FixedPricePolicy.h"
#include "DiscountPricePolicy.h"
#include "Library.h"
using namespace std;

string getCurrentDate() {
    time_t now = time(nullptr);       // 현재 시간을 초 단위로 얻기
    tm localTime = {};                
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&localTime, &now);     // 윈도우: 스레드 안전 버전
#else
    localtime_r(&now, &localTime);     // 리눅스/유닉스: 스레드 안전 버전
#endif

    ostringstream oss;
    oss << put_time(&localTime, "%Y-%m-%d"); // yyyy-mm-dd 형태로 출력
    return oss.str();
}

int main() {
    cout << "오늘 날짜: " << getCurrentDate() << endl;
    return 0;
}
