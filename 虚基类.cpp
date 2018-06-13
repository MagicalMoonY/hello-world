#include<iostream>
using namespace std;
//虚基类由关键字virtual标识，格式 class 派生类名 ：virtual 继承方式 基类名 。虚基类的目的是为了解决菱形结构出现的二义性问题 
class Furniture{//声明公共基类 ，构造菱形结构，用于解决多继承问题中的多个基类有相同成员，在组建一个更为抽象的基类后，可以减少冗余数据（原本的数据可能需要初始化两次，现在只需要一次） 
	public:
		Furniture(float w);
		void SetWeight(float w);
		float GetWeight();
	protected:
		float weight;
}; 
class Bed:virtual public Furniture{//将公共基类定义为虚基类 
	public:
		Bed(float w):Furniture(w){//一级派生类构造函数，负责初始化公共基类的数据成员 
			
		} 
		void Sleep(void) const;
};
class Sofa:virtual public Furniture{
	public:
		Sofa(float w):Furniture(w){
			
		}
		void WatchTV(void) const;
};
class SofaBed : public Sofa,public Bed{
	public:
		SofaBed(float w):Furniture(w),Sofa(w),Bed(w){//派生类构造函数的参数用来初始化3个基类的数据成员 
			
		}
		void FoldOut(void);
};
Furniture :: Furniture(float w){
	weight = w;
}
void Furniture :: SetWeight(float w){
	weight = w;
	cout << "此家具重"<<weight<<"千克" << endl; 
}
float Furniture :: GetWeight(){
	return weight;
}
void Bed :: Sleep(void) const{
    cout << "开始睡觉"<<endl;
}
void Sofa :: WatchTV(void) const{
    cout << "正在看电视"<< endl; 
}
void SofaBed :: FoldOut(void){
	cout << "可以折叠和打开"<<endl;
} 
int main(){
	SofaBed sb(50.5);
	sb.SetWeight(51.9);
	sb.WatchTV() ;
	sb.FoldOut() ;
	sb.Sleep() ; 
	return 0;
}

