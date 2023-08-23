#include <iostream>
#include <vector>
#include <functional>
#include <regex>	// regular expression
#include <thread>
#include <mutex>
#include <future>

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
//				std::weak_ptr<> p = resource;
//
//	정규 표현식	
//		동시성
//			Thread
//				Deadlock
//			
//			Asynchronous Function(비동기 함수)	
//				
//
//	Process												Thread
//	앱이 실행되어 (Runtime) 메모리에 등록된 상태		한 프로세스 내에서 실행되는 여러 흐름
//	자신의 정보를 context에 저장						공유 메모리 사용
//	OS가 제어											프로세스가 제어
//	Context-Switching									Deadlock
// 
// 
//	Deadlock			//교착상태
// 	critical Section	//임계구역
// 	Mutual Exclusion	//상호배제
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

//class Warrior
//{
//public:
//	int mHealth;
//	int mAttack;
//
//	Warrior(int h, int a) : mHealth{ h }, mAttack{ a }
//	{
//
//	}
//};
//
//int main()
//{
//	Warrior* p = new Warrior(100, 10);
//
//	p->mAttack = 10;
//	(*p).mAttack = 10;
//
//	delete p;
//
//	std::unique_ptr<Warrior> spWarrior = std::make_unique<Warrior>(100, 20);
//
//	//spWarrior.		//unique ptr
//	//spWarrior->		//spWarrior
//
//	std::cout << spWarrior->mAttack << std::endl;
//
//	spWarrior.release();	// delete p;
//	spWarrior.reset();		// delete p; p = nullptr;
//	  
//	Warrior* ptr = spWarrior.get(); // 일반 포인터
//}

//class Image
//{	
//};
//
//class Demon
//{
//public:
//	int mHealth;
//	int mAttack;
//
//	std::shared_ptr<Image> mspImage;
//
//	Demon(int h, int a, std::shared_ptr<Image> spImage) : mHealth{ h }, mAttack{ a }, mspImage{ spImage }
//	{
//
//	}
//};
//
//int main()
//{
//	std::shared_ptr<Image> spImage = std::make_shared<Image>();
//	{
//		std::unique_ptr<Demon> spDemon = std::make_unique<Demon>(100, 10, spIamage);
//		{
//			std::unique_ptr<Demon> spDemon2 = std::make_unique<Demon>(100, 10, spIamage);
//		}
//	}
//}

//void F(int a, char b)
//{
//}
//
//using namespace std::placeholders;
//
//int main()
//{
//	F(1, 'a');
//	F('a', 1);
//
//	auto functor1 = std::bind(F, _1, _2);
//	functor1(1, 'a');
//
//	auto functor2 = std::bind(F, _2, _1);
//	functor2('a', 1);
//
//	auto functor3 = std::bind(F, 10, _1);
//	functor3('f');
//}

//int main()
//{
//	std::cout << "이메일 : ";
//	std::string email;
//	std::cin >> email;
//
//	// 입력한 이메일이 올바른 메일 주소인가?
//	//(\w+[\w\.]*)	@	(\w+[\w\.]*)\.([A-Za-z]+)  \w = 단어가 여러개 올 수 있음
//	//std::regex pattern("(\\w+[\\w\\.]*)@(\\w+[\\w\\.]*)\\.([A-Za-z]+)");
//	std::regex pattern(R"(\w+[\w\.]*)@(\w+[\w\.]*)\.([A-Za-z]+)");
//	if (std::regex_match(email, pattern))
//	{
//		std::cout << " 올바른 메일 주소 " << std::endl;
//	}
//	else
//	{
//		std::cout << " 잘못된 메일 주소 " << std::endl;
//	}
//}

//std::mutex gMutex;
//
//void PlayMovie()
//{
//	for (int i = 0; i < 1000; i++)
//	{
//		gMutex.lock();
//		std::cout << "PlayMovie : " << i << std::endl;
//		gMutex.unlock();
//	}
//}
//void Download()
//{
//	for (int repeat = 0; repeat < 10; repeat++)
//	{
//		for (char i = 33; i < 125;i++)
//		{
//			gMutex.lock();
//			std::cout << "Download : " << i << std::endl;
//			gMutex.unlock();
//		}
//	}
//}
//
//int main()
//{
//	std::thread job1(PlayMovie);
//	std::thread job2(Download);
//
//	job1.join();
//	job2.join();
//
//	std::cout << "모든 작업이 끝났습니다." << std::endl;
//}
//
//int main()
//{
//	std::future<void> job1 = std::async(PlayMovie);
//	std::future<void> job2 = std::async(Download);
//
//	std::cout << "모든 작업이 끝났습니다." << std::endl;
//}


// C++ 20 사천왕(big four)
// concept. range, coroutine, module

//concept = template의 요구사항을 간단히 알려줌
//range = 

//#include <header>
//- 중복
//- 순서에 영향
//- 하나만 사용할 수 없음
//
//#import iostream.cout
