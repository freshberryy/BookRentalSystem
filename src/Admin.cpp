#include "Admin.h"

Admin::Admin(string name, UserCredential credential):User(name, credential) {}


void Admin::displayMenu() const
{
    cout << "\n관리자 메뉴\n";
    cout << "----------------------------\n";
    cout << "  1. 도서 등록\n";
    cout << "  2. 도서 삭제\n";
    cout << "  3. 전체 도서 목록 보기\n";
    cout << "  4. 사용자 목록 조회\n";
    cout << "  5. 재고 확인 및 수정\n";
    cout << "  0. 로그아웃\n";
    cout << "----------------------------\n";
    cout << ">> 번호를 선택하세요: ";

}

bool Admin::isAdmin() const
{
    return 1;
}

