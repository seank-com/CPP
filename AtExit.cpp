//////////////////////////////////////////////////////////////////////
// I read an article on Dr. Doobs (http://drdobbs.com/cpp/184403758)
// about the same time I was reading up on the new features in C++11
// (http://msdn.microsoft.com/en-us/library/dd293599.aspx) and had
// this great idea to bring two good ideas together to make something
// awesome.
//

#include <iostream>
#include <functional>

class AtExit
{
   bool _dismissed;
   std::function<void (void)> _func;
public:
  AtExit(std::function<void (void)> func)
    : _func(func)
    , _dismissed(false)
  {
  }

  ~AtExit()
  {
    if (!_dismissed)
    {
      _func();
    }
  }

  void Dimiss() throw()
  {
    _dismissed = true;
  }
};

void Success(int& a, int& b)
{
  int olda = a;
  AtExit guard([&a, olda] ()
  {
    a = olda;
  });

  a = 5;
  b = 5;

  guard.Dimiss();
}

void Fail(int& a, int& b)
{
  int olda = a;
  AtExit guard([&a, olda] ()
  {
    a = olda;
  });

  a = 7;
  return;
  b = 7;

  guard.Dimiss();
}

int main()
{
  int a = 1;
  int b = 1;

  std::cout << "a = " << a << std::endl << "b = " << b << std::endl;

  Success(a, b);

  std::cout << "a = " << a << std::endl << "b = " << b << std::endl;

  Fail(a, b);

  std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
}
