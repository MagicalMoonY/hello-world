#include<iostream>
using namespace std;
class HelloWorld{
  public:
  void hello()
  {
    printf("hello world");
  };
};
int main() {
  HelloWorld hw;
  hw.hello();
  return 0;
}
