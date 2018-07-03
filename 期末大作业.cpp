#include<iostream> 
#include<vector>//vector是一种顺序容器，事实上和数组差不多，但它比数组更优越。
#include<stdlib.h>
using namespace std;
class Unit_ALL{
	public:
		virtual void trans(double) = 0;//定义纯虚函数 
		virtual bool find(string,string) = 0;
};
class Base:public  Unit_ALL {
	public:
		Base();
		virtual bool find(string _string1,string _string2);
		virtual void trans(double num);
	private:
		int mark;
		int now;
		int next;
		vector<string> length_measurement;	//长度 
		vector<double> length_number;
		vector<string> time_measurement;//时间 
		vector<double> time_number;
		vector<string> quality_measurement;//质量
		vector<double> quality_number;
		vector<string> temperature_measurement;//温度
		vector<double> temperature_number;	
};
bool Show(){//输入提示以及选择单位类型
	int choice = 0;
	printf("%-12s%-12s%-12s%-12s\n\n", "1.length","2.time","3.quality","4.temperature");
	cout <<"Please enter the number of the unit that you want to convert:"<<endl;
	cin >>choice; 
	if(choice == 1){
		printf("%-12s%-12s%-12s%-12s\n\n","mm","m","cm","nm","km");
		return true;
	}
	else if(choice == 2){
		printf("%-12s%-12s%-12s%-12s%-12s\n\n", "ms","s","min","h","d");
		return true;		
	}
	else if(choice == 3){
		printf("-12s%-12s%-12s%-12s\n", "mg","g","kg","t");
		return true;		
	}
	else if(choice == 4){
		printf("%-12s%-12s%-12s%-12s\n%-12s\n", "℃","℉","K","Re","R");
		return true;
	}
	else{
		cout<<"invalid input!"<<endl;
		return false;		
	}
}
Base::Base(){
	mark = 0;
	now = next = 100;
	length_measurement.push_back ("mm"); length_measurement.push_back ("cm");length_measurement.push_back ("km"); length_measurement.push_back ("m");length_measurement.push_back ("nm"); 
	length_number.push_back (0.001); length_number.push_back (0.01); length_number.push_back (1000); length_number.push_back (1);length_number.push_back (0.000000001);
	time_measurement.push_back ("ms"); time_measurement.push_back ("s"); time_measurement.push_back ("min"); time_measurement.push_back ("h"); time_measurement.push_back ("d");
    time_number.push_back (1.0/60); time_number.push_back (1); time_number.push_back (60); time_number.push_back (3600);time_number.push_back (216000); 
	quality_measurement.push_back ("mg");quality_measurement.push_back ("g"); quality_measurement.push_back ("kg");	quality_measurement.push_back ("t"); 
	quality_number.push_back (1000);quality_number.push_back (1); quality_number.push_back (0.001);	quality_number.push_back (0.000001);  
	temperature_measurement.push_back ("℃"); temperature_measurement.push_back ("℉"); temperature_measurement.push_back ("K");temperature_measurement.push_back ("Re"); temperature_measurement.push_back ("R");
    temperature_number.push_back (1); temperature_number.push_back (33.8); temperature_number.push_back (274.15);temperature_number.push_back (0.8); temperature_number.push_back (493.47);	
}
void Base:: trans(double num){
	if(now == next){
		cout<<num;
		return;
	}
	vector<double>::iterator _iterator1,_iterator2;
	if(mark == 1){
		_iterator1 = now+length_number.begin();
		_iterator2 = next+length_number.begin();
		cout<<"Conversion result："<<num*(*_iterator1)/(*_iterator2)<<endl<<endl; 
	}
	else if(mark == 2){
		_iterator1 = now + time_number.begin();
		_iterator2 = next + time_number.begin();
		cout<<"Conversion result："<<num*(*_iterator1)/(*_iterator2)<<endl<<endl; 				
	}
	else if(mark == 3){
		_iterator1 = now + quality_number.begin();
		_iterator2 = next + quality_number.begin();
		cout<<"Conversion result："<<num*(*_iterator1)/(*_iterator2)<<endl<<endl; 				
	}
	else if(mark == 4){
		_iterator1 = now + temperature_number.begin();
		_iterator2 = next + temperature_number.begin();
		cout<<"Conversion result："<<num*(*_iterator2)/(*_iterator1)<<endl<<endl; 				
	}
	else{
		cout<<"Error!"<<endl;
    }
}
bool Base :: find(string _string1,string _string2){
	vector<string>::iterator _iterator1,_iterator2;//迭代器(Iterator)模式
	for(_iterator1 = length_measurement.begin();_iterator1 != length_measurement.end(); _iterator1++){
		if(_string1 == *_iterator1){
			for(_iterator2 = length_measurement.begin();_iterator2 != length_measurement.end();_iterator2++){
				if(_string2 == *_iterator2){
					mark = 1;
					now = _iterator1 - length_measurement.begin();
					next = _iterator2 - length_measurement.begin();
					return true;
				}
			}
		}
	}
	for(_iterator1 = time_measurement.begin();_iterator1 != time_measurement.end();_iterator1++){
		if(_string1 == *_iterator1){
			for(_iterator2 = time_measurement.begin();_iterator2 != time_measurement.end();_iterator2++){
				if(_string2 == *_iterator2){
					mark = 2;
					now = _iterator1 - time_measurement.begin();
					next = _iterator2 - time_measurement.begin();
					return true;
				}
			}
		}
	}
	for(_iterator1 = quality_measurement.begin();_iterator1 != quality_measurement.end();_iterator1++){
		if(_string1 == *_iterator1){
			for(_iterator2 = quality_measurement.begin();_iterator2 != quality_measurement.end();_iterator2++){
				if(_string2 == *_iterator2){
					mark = 3;
					now = _iterator1 - quality_measurement.begin();
					next = _iterator2 - quality_measurement.begin();
					return true;
				}
			}
		}
	}
	for(_iterator1 = temperature_measurement.begin();_iterator1 != temperature_measurement.end();_iterator1++){
		if(_string1 == *_iterator1){
			for(_iterator2 = temperature_measurement.begin();_iterator2 != temperature_measurement.end();_iterator2++){
				if(_string2 == *_iterator2){
					mark = 4;
					now = _iterator1 - temperature_measurement.begin();
					next = _iterator2 - temperature_measurement.begin();
					return true;
				}
			}
		}
	}
	if(!mark) return false;
}
int main(){
	cout << "the codes' purpose is to accomplish the function of Unit Convertor" << endl;
	cout << "the author is yangmingyue"<<endl;
	cout << "the teacher is Dashark"<<endl<<endl;
	double num;//原单位的数值 
	string begin,end;//原单位与想转换的单位 
	bool win,choose;//false = 0 ,true = 1;
	int all_times;
	cout<<"Please enter the number of times you want to convert"<<endl;
	cin >> all_times; 
	for(int kkk = 0;kkk < all_times;kkk++){
		choose=Show();
    	while(!choose){
    		cout<<"\nplease enter a number1-4";
	    	system("pause");
	    	choose=Show();
    	}
    	cout << "Please enter the normal range, the original unit and the unit you want to convert, separated by spaces. "
    	"(please use the corresponding English in the hint to indicate the unit)."<<endl; 
    	cout << "Examples (for example in length)：" << endl;
    	cout << "1 cm m" << endl; 
     	while(cin >> num >> begin >> end){
        	Base obj1;
        	win=obj1.find(begin,end);
        	if(win)
        	obj1.trans(num);
	        else{
		        Base obj2;
		        win = obj2.find(begin,end);
		        if(!win) cout <<"Error!"<<endl;
		        else obj2.trans(num);
	        }
	        break;
		}
	}
	return 0;
}
