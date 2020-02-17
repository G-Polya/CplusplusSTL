
# 1.4 반복자
- 반복자는 포인터와 비슷하게 동작하는 클래스 템플릿 타입의 객체
- 반복자 iter이 유효객체를 가리킨다 >> *iter로 반복자 iter를 역참조해서 객체에 대한 참조를 얻을 수 있음
- 첫번째 원소를 가리키는 begin 반복자, 마지막 원소를 가리키는 end반복자(순차열에서 마지막 원소에서 하나 더 지나친 위치를 가리킴)

~~~
#include <numeric>
#include <iostream>
#include <iterator>

using namespace std;


int main()
{
    cout << "값은 공백으로 구분해서 입력하세요. 종료하려면 Ctrl+Z를 입력하세요" << endl;

    return 0;
}

~~~

