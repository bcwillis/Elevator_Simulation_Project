#include <iostream>
#include <elevator.h>

using namespace std;

int main()
{
  double _CT=0.0;
  Elevator E;
  _CT=.15;
  E.time(_CT);
  cout<<endl;
  cout<< "E.targeted_floor()" <<E.targeted_floor()<<endl;
  cout<<"E.current_floor()"<<E.current_floor()<<endl;
  cout<<"E.get_Ex_time()"<<"E.get_In_time()"<<E.get_In_time()<<endl;
  cout<<E.get_Ex_time()<<endl;
  cout<<E.get_Ar_time()<<endl;
  cout<<E.get_De_time()<<endl;
  cout<<endl;
  E.push(.15,1);
  cout<<E._flr_ct(0)<<endl;
  cout<<E._flr_ct(1)<<endl;
  cout<<E._flr_ct(2)<<endl;
  cout<<E._flr_ct(3)<<endl;
  cout<<E._flr_ct(4)<<endl;
  cout<<E._flr_ct(5)<<endl;
  cout<<E._flr_ct(6)<<endl;
  cout<<E._flr_ct(7)<<endl;
  cout<<E._flr_ct(8)<<endl;
  cout<<E._flr_ct(9)<<endl;
  cout<<E._flr_ct(10)<<endl;
  cout<<E._flr_ct(11)<<endl;

  E.push(0.2,1);
  cout<<endl;
  _CT+=.2667;
  cout<<E._flr_ct(0)<<endl;
  cout<<E._flr_ct(1)<<endl;
  cout<<E._flr_ct(2)<<endl;
  cout<<E._flr_ct(3)<<endl;
  cout<<E._flr_ct(4)<<endl;
  cout<<E._flr_ct(5)<<endl;
  cout<<E._flr_ct(6)<<endl;
  cout<<E._flr_ct(7)<<endl;
  cout<<E._flr_ct(8)<<endl;
  cout<<E._flr_ct(9)<<endl;
  cout<<E._flr_ct(10)<<endl;
  cout<<E._flr_ct(11)<<endl;
  E.target_floor(1);
  cout<< "E.NDeparture_Time()  : " << E.Next_Departure_Time() << endl;
  E.time(_CT);
  _CT+=.3417;
  E.time(_CT);
  cout<<endl;
  cout<<E.targeted_floor()<<endl;
  cout<<E.current_floor()<<endl;
  cout<<E.get_In_time()<<endl;
  cout<<E.get_Ex_time()<<endl;
  cout<<E.get_Ar_time()<<endl;
  cout<<E.get_De_time()<<endl;
  cout<<endl;
  cout<<endl;
  cout<<E.get_n()<<endl;
  cout<<E.pop_ta(E.current_floor())<<endl;
  cout<<E.pop_tb(E.current_floor())<<endl;

  cout << "E.get_n() : "<< E.get_n() << endl;

  cout<<E._flr_ct(E.current_floor())<<endl;
  cout<<endl;
  cout<<E.get_n()<<endl;

  cout << "E.get_n() : "<< E.get_n() << endl;

  cout<<E.pop_ta(E.current_floor())<<endl;
  cout<<E.pop_tb(E.current_floor())<<endl;
  cout<<E._flr_ct(E.current_floor())<<endl;
  cout << "E.get_n() : "<< E.get_n() << endl;
  cout<<endl;
  E.push(0.17,2);
  cout<<E._flr_ct(2)<<endl;
  _CT+=.2667;
  cout << E.current_floor()<<endl;
  E.time(_CT);

  cout<< "E.Next_Departure_Time()  : " << E.Next_Departure_Time() << endl;
  cout<<endl;
  cout<<E.targeted_floor()<<endl;
  cout<<E.current_floor()<<endl;
  cout<<E.get_In_time()<<endl;
  cout<<E.get_Ex_time()<<endl;
  cout<<E.get_Ar_time()<<endl;
  cout<<E.get_De_time()<<endl;
  cout<<endl;
  cout << E.current_floor()<<endl;
  E.push(1.75,2);

  E.time(_CT);
  cout<< "E.Next_Departure_Time()  : " << E.Next_Departure_Time() << endl;
  _CT+= 0.24;
  E.time(_CT);

  cout<< "E.Next_Departure_Time()  : " << E.Next_Departure_Time() << endl;

  cout<<E._flr_ct(2)<<endl;
  cout << E.current_floor()<<endl;


  cout<< "E.Next_Departure_Time()  : " << E.Next_Departure_Time() << endl;

  _CT=4.125;
  E.time(_CT);
  cout<<endl;
  cout<<E.targeted_floor()<<endl;
  cout<<E.current_floor()<<endl;
  cout<<E.get_In_time()<<endl;
  cout<<E.get_Ex_time()<<endl;
  cout<<E.get_Ar_time()<<endl;
  cout<<E.get_De_time()<<endl;

  system("pause");


  return 0;
}
