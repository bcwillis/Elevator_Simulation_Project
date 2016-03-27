#include <iostream>
#include "building.h"

using namespace std;

int main()
{
  building B;

  B.insert(0,1,0.15);
  B.insert(1,2,.17);
  B.insert(0,1,.2);



  cout<<"Number on floor 0: "<<B._n_on_floor_arg(0)<<endl;

  system("pause");

  cout<<"B.pop_ta(0)"<<B.pop_ta(0)<<endl;
  cout<<"B.pop_DF(0)"<<B.pop_DF(0)<<endl;
  cout<<"Number on floor 0: "<<B._n_on_floor_arg(0)<<endl;
  cout<<"number stored" << B.n_stored() << endl;

  cout<<"B.pop_ta(0)"<<B.pop_ta(0)<<endl;
  cout<<"B.pop_DF(0)"<<B.pop_DF(0)<<endl;
  cout<<"number stored" << B.n_stored() << endl;

  cout<<"Number on floor 0: "<<B._n_on_floor_arg(0)<<endl;
  cout<<"number stored" << B.n_stored() << endl;

  cout<<"B.pop_ta(1)"<<B.pop_ta(1)<<endl;
  cout<<"B.pop_DF(1)"<<B.pop_DF(1)<<endl;
  cout<<"number stored" << B.n_stored() << endl;

  cout<<"Number on floor 1: "<<B._n_on_floor_arg(1)<<endl;

  system("pause");
  B.~building();

}
