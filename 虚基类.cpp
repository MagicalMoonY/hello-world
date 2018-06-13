#include<iostream>
using namespace std;
//������ɹؼ���virtual��ʶ����ʽ class �������� ��virtual �̳з�ʽ ������ ��������Ŀ����Ϊ�˽�����νṹ���ֵĶ��������� 
class Furniture{//������������ ���������νṹ�����ڽ����̳������еĶ����������ͬ��Ա�����齨һ����Ϊ����Ļ���󣬿��Լ����������ݣ�ԭ�������ݿ�����Ҫ��ʼ�����Σ�����ֻ��Ҫһ�Σ� 
	public:
		Furniture(float w);
		void SetWeight(float w);
		float GetWeight();
	protected:
		float weight;
}; 
class Bed:virtual public Furniture{//���������ඨ��Ϊ����� 
	public:
		Bed(float w):Furniture(w){//һ�������๹�캯���������ʼ��������������ݳ�Ա 
			
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
		SofaBed(float w):Furniture(w),Sofa(w),Bed(w){//�����๹�캯���Ĳ���������ʼ��3����������ݳ�Ա 
			
		}
		void FoldOut(void);
};
Furniture :: Furniture(float w){
	weight = w;
}
void Furniture :: SetWeight(float w){
	weight = w;
	cout << "�˼Ҿ���"<<weight<<"ǧ��" << endl; 
}
float Furniture :: GetWeight(){
	return weight;
}
void Bed :: Sleep(void) const{
    cout << "��ʼ˯��"<<endl;
}
void Sofa :: WatchTV(void) const{
    cout << "���ڿ�����"<< endl; 
}
void SofaBed :: FoldOut(void){
	cout << "�����۵��ʹ�"<<endl;
} 
int main(){
	SofaBed sb(50.5);
	sb.SetWeight(51.9);
	sb.WatchTV() ;
	sb.FoldOut() ;
	sb.Sleep() ; 
	return 0;
}

