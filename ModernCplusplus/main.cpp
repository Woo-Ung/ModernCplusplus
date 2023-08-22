#include <iostream>
#include <vector>

//template<class T>
//void swap(T&& a, T&& b)
//{
//	T tmp(a) = std::move(a);
//	a = std::move(b);
//	b = std::move(a);
//}
//
//template <typename T>
//void myTemplate(T&& x)
//{
//	f(std::forward(x));
//}
//
//int main()
//{
//	[=]() mutable throw () -> int
//		{
//			//body
//		};
//
//	std::vector<std::string> v;
//	std::string str = "example";
//
//	v.push_back(std::move(str));
//}




//enum Flags
//{
//	none =0,
//	slow = 1,
//	poison =2,
//	bleed =3,
//	paralyse =4
//};
//
// constexpr int operator | (Flags f1, Flags f2)
//{
//	return Flags(f1 | f2);
//}
//
//int main()
//{
//	//constexpr (constant expression)
//
//
//	Flags myStatus{};
//
//	switch (myStatus)
//	{
//	case slow | paralyse:
//		break;
//	}
//}

//int main()
//{
//	auto x = 1;
//
//	decltype(x + 1.1f) y = x;
//
//	std::cout << y << std::endl;
//}

//C++11 Class
//
//MyClass(const MyClass&)	//복사 생성자
//MyClass(MyClass&&)			//이동 생성자
//
//MyClass & operator=(const MyClass&)	//복사 대입 연산자
//MyClass & operator=(MyClass&&)		//이동 대입 연산자
//
//대리 생성자 (delegating constructor)
//MyClass() : MyClass(1,1)

//enum class Flags : char
//{
//	slow,
//	poison
//};
//
//int main()
//{
//	Flags f;
//
//	f = Flags::slow;
//
//	switch (f)
//	{
//	case Flags::slow:
//			break;
//
//	case Flags::poison:
//		break;
//	}
//}
//
//template <typename T1, typename T2>
//auto Add(T1 x, T2 y) -> decltype(x + y)	// suffix return type
//{
//	return x + y;
//}
//
//int main()
//{
//	// Raw String Literal
//	std::string str1 = R"( "'\'" )";  //()안에 문자가 *그대로* 출력됨
//
//
//	std::cout << str1 << std::endl;
//}

//template<typename T>
//T Sum(T first)
//{
//	return first;
//}
//
//template<typename T, typename ... Args>
//T Sum(T first, Args... args)
//{
//	return first + Sum(args...);
//}
//
//using namespace std::string_literals;
//
//int main()
//{
//	std::cout << Sum(1, 2, 3) << std::endl;
//	std::cout << Sum("a"s, "b"s, "c"s) << std::endl;
//}

// C++ 17
//template<typename ... Args>
//auto Sum(Args... args)
//{
//	return (args + ...);
//}
//
//using namespace std::string_literals;
//
//int main()
//{
//	std::cout << Sum(1, 2, 3) << std::endl;
//	std::cout << Sum("a"s, "b"s, "c"s) << std::endl;
//}


//C++11 STL
//	스마트 포인터
//		알아서 메모리 관리
//		onwership
//			std::unique_ptr
//			std::shared_ptr
//			std::weak_ptr
//
//	정규 표현식
//
//


//int main()
//{
//	std::unique_ptr<int> p{ new int };
//	// C++14
//
//	std::unique_ptr<int> p2 = std::make_unique<int>();
//
//	*p = 1;
//
//	std::cout << *p << std::endl;
//}

class Warrior
{
public:
	int mHealth;
	int mAttack;

	Warrior(int h, int a) : mHealth{ h }, mAttack{ a }
	{

	}
};

int main()
{
	Warrior* p = new Warrior(100, 10);

	p->mAttack = 10;
	(*p).mAttack = 10;

	delete p;

	std::unique_ptr<Warrior> spWarrior = std::make_unique<Warrior>(100, 20);

	//spWarrior.		//unique ptr
	//spWarrior->		//spWarrior

	std::cout << spWarrior->mAttack << std::endl;

	spWarrior.release();	// delete p;
	spWarrior.reset();		// delete p; p = nullptr;
	  
	Warrior* ptr = spWarrior.get(); // 일반 포인터
}