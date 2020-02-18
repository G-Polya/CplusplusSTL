
# 1.4 반복자
- 반복자는 포인터와 비슷하게 동작하는 클래스 템플릿 타입의 객체
- 반복자 iter이 유효객체를 가리킨다 >> *iter로 반복자 iter를 역참조해서 객체에 대한 참조를 얻을 수 있음
- 첫번째 원소를 가리키는 begin 반복자, 마지막 원소를 가리키는 end반복자(순차열에서 마지막 원소에서 하나 더 지나친 위치를 가리킴)

## 1.4.1 반복자 얻기
- 전역함수 begin()과 end()는 일반적인 배열이나 문자열 객체를 인수로 받아도 동작하며 반복자를 얻는 단일방법을 제공

~~~
#include <numeric>
#include <iostream>
#include <iterator>

using namespace std;


int main()
{
	double data[] = { 2.5, 4.56, 53.5, 8.5 };
	cout << "배열 원소들:\n";
	for (auto iter = begin(data); iter != end(data); iter++)
	{
		cout << *iter << " ";
	}

	auto total = accumulate(begin(data), end(data), 0.0);
	cout << "\n배열 원소들의 합계: " << total << endl;

}

~~~
### ※accumulate() 함수는 두 인수로 지정된 범위에 있는 원소들의 합계를 반환한다. 세번쨰 인수는 합계에 사용할 초기값을 지정한다.

## 1.4.3 스트림 반복자
- istream_iterator<T>는 istream에서 타입 T의 객체들을 읽을 수 있는 입력반복자. istream은 파일스트림이나 표준입력스트림 cin이 될 수 있다.
- istream_iterator<T>의 인수없는 생성자는 스트림의 끝에 도달하면 일치하게 되는 end 반복자 객체를 생성

~~~
int main()
{
	cout << "값은 공백으로 구분해서 입력하세요. 종료하려면 Ctrl+Z를 입력하세요: " << endl;

	cout << "\nThe sum of the values you entered is "
		<< accumulate(istream_iterator<double>(cin), istream_iterator<double>(), 0.0)
		<< endl;

	return 0;
}


~~~

## 1.4.4 반복자 어댑터
- 역방향반복자(reverse_iterator), 삽입반복자(insert_iterator), 이동반복자(move_iterator)

### 1.4.4.1 역방향 반복자 reverse_iterator
- 역방향 반복자는 표준 반복자와 반대로 동작
- rbegin()는 첫번째원소에서 하나 더 앞, rend()은 마지막원소를 가리킨다
- reverse_iterator 객체는 내부 반복자를 반환하는 base() 멤버함수를 갖고 있다
- 내부반복자는 역방향반복자 riter가 가리키는 원소에서 오른쪽 한칸을 가리킨다

### 1.4.4.2 삽입 반복자 insert_iterator
- 삽입 반복자는 컨테이터의 어느 위치든 새 원소들을 범위로 추가할 수 있다.
- back_insert_iterator는 push_back()멤버 함수로 컨테이너의 끝에 새 원소를 추가한다. vector, list, deque 컨테이너가 push_back()을 멤버로 지원한다. 전역함수 back_inserter()
- front_insert_iterator는 push_front() 멤버 함수로 컨테이너의 앞에 새 원소를 추가한다. list, forward_deque 컨테이너가 push_forward()를 지원한다. 전역함수 forward_inserter()
-insert_iterator는 insert() 멤버가 있는 컨테이너에 새 원소를 추가한다. string헤더의 문자열클래스. 전역함수 inserter()

### 1.4.4.3 이동 반복자 move_iterator

# 1.5 반복자에 쓰이는 연산
- advance()는 첫번째 인수로 받은 반복자를 두번째 인수로 지정한 숫자만큼 증가시킨다.
~~~
int main()
{
	int data[] = { 1,2,3,4,5,6 };
	auto iter = std::begin(data);
	std::advance(iter, 3);
	cout << "네 번째 원소: " << *iter << endl;

	return 0;
}
~~~
- distance()는 두 반복자가 지정한 범위에 있는 원소들의 개수를 반환
~~~
int main()
{
	int data[] = { 1,2,3,4,5,6 };
	auto iter = std::begin(data);
	
	cout << "data에 있는 원소의 개수:" << distance(begin(data), end(data)) << endl;

	return 0;
}
~~~
- next()는 첫번째 인수로 받은 반복자를 두번쨰 인수로 지정한 숫자만큼 증가시킨 반복자를 반환
~~~
int main()
{
	int data[] = { 1,2,3,4,5,6 };
	auto iter = begin(data);
	auto fourth = next(iter, 3);
	cout << "첫번쨰 원소: " << *iter << " 그리고 네 번쨰 원소:" << *fourth << endl;
	
	return 0;
}
~~~
- prev()는 첫번째 인수로 받은 반복자를 두번쨰 인수로 지정한 숫자만큼 감소시킨 반복자를 반환

# 1.6 스마트 포인터
- 스마트 포인터는 자유공간에 할당된 메모리의 주소만 저장할 수 있다
- 원시포인터에서 하던 증가, 감소 같은 산술연산은 스마트 포인터에서 할 수없다
※ 자유 공간 : new/delete로 할당해제하는 동적 메모리 공간. heap : malloc/free로 할당하는 동적메모리공간
- 스마트 포인터를 사용하면 객체가 더는 필요하지 않을 때 객체에 할당된 메모리가 자동으로 해제된다
- memory헤더를 포함해야한다

## 1.6.1 unique_ptr<T> 포인터 사용하기
- unique_ptr<T> 객체는 주소 하나를 유일하게 저장. 주소가 가리키는 객체를 unique_ptr<T> 객체가 독점적으로 소유
- unique_ptr<T>객체가 소멸될 떄 해당객체도 같이 소멸.
- 스마트 포인터를 여러개 둘 필요가 없고 소유권을 하나로 정해두고 싶을 때 이러한 유형의 스마트포인터를 사용
~~~
unique_str<string> pname {new string{"Algermon}};
~~~
- unique_ptr<T> 객체를 생성하는 더 좋은 방법은 memory헤더에 정의된 mkae_unique<T>() 함수템플릿을 사용하는것
~~~
auto pname = make_unique<string>("Algernon");
~~~
- 원시 포인터와 마찬가지로 유니크 포인터를 역참조해서 객체에 접근할 수 있다.
~~~
cout<<*pname<<endl;
~~~
- 배열을 가리키는 unqiue_ptr<T> 객체도 생성할 수 있다
~~~
size_t len(10);
unique_ptr<int[]> pnumbers {new int[len]};

auto pnumbers = make_unique<int[]>(len);
~~~

- unique_ptr<T> 객체는 복제할 수 없으므로 함수에 값으로 전달할 수 없다. 참조에 의한 호출은 가능
- unique_ptr<T> 객체를 반환하는 건 가능
- unique_ptr<T> 객체를 이동하거나 원하는 위치에서 생성하는 방식으로 컨테이너에 저장만 할 수 있다.

- unique_ptr<T>에서 원시포인터 얻는 방법
~~~
auto unique_p = make_unique<string>(6, '*');
string pstr {unique_p.get()};
~~~


