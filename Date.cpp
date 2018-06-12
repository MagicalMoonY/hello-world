class Date {
public:
  Date(int y, int m, int d)
  {
     cout<<“12356749235253426865629856262846”<<endl;
  };
  ~Date(){
      cout << "结构"<<endl;
  };

  void nextDay();
  void previousDay();
  bool equal(Date other);
  void show();
private:
  int year;
  int month;
  int day;
};
void nextDay(){
    day++;
}
void previousDay(){
  day--;
}
bool equal(Date other){
    if(day == 30){
        return 1;
    }
  return 0;
}
void show(){
    cout << day << endl;
}
int main() {
  Date today(2012,12,20);
  Date day(2012,12,20);
  day.show();
  for(int i=0;i<30;i++)
    day.nextDay();
  day.show();
  for(int i=0;i<30;i++)
    day.previousDay();
  day.show();
  if(day.equal(today))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
