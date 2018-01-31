#include <iostream>

template < int n>
class Repeat : public Repeat <n-1>
{
public:
	Repeat()
	{
		std::cout<<n<<" ";
	}
};

template <>
class Repeat <0>
{
public:
	Repeat()
	{
		std::cout<<0;
	}
};

int main()
{
        Repeat<100> r;
}
