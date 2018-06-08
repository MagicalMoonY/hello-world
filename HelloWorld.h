#ifndef _HELLO_WORLD_
#define _HELLO_WORLD_
class HelloWorld {
 public:
  void hello(){
   cout << "hello world" << endl;
  }
};
#endif
int main(){
    HelloWorld d;
    d.hello();
    return 0;
}
