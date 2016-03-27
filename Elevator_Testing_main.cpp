#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <random>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include "building.h"
#include "elevator.h"
#include "data.h"


#define _Max_Ta 740.0
#define dInfty   120000.0

using namespace std;
int tempflr = 0;
queue<int> external;
queue<int> internal1;
queue<int> internal2;

//////////////////////////////////////////////////////////////////////////////////
int fcfs1(Elevator _E1, Elevator _E2, building _b, queue<int> internal, queue<int> internal2)
{
  if(external.empty())
    {
      return 0;
    }

  else if ((_E1.empty() == true))
    {
      if(_b._n_on_floor_arg(external.front() == 0))
        {
          external.pop();
        }

      int edummy = external.front();
      external.pop();
      return edummy;
    }

  else if (_E1.empty() == false)
    {
      int idummy = internal.front();
      internal.pop();
      return idummy;
    }
}


int fcfs2(Elevator _E1, Elevator _E2, building _b, queue<int> internal, queue<int> internal2)
{
  if(external.front() == NULL)
    {
      return 0;
    }

  else if (_E2.empty())
    {
      if(_b._n_on_floor_arg(external.front() == 0))
        {
          external.pop();
        }

      int edummy = external.front();
      external.pop();
      return edummy;
    }

  else if (_E2.empty() == false)
    {
      int idummy = internal2.front();
      internal2.pop();
      return idummy;
    }
}


int greatest1(Elevator _E1, Elevator _E2, building _b, queue<int> internal, queue<int> internal2)
{
  int greatest = 0;
  int greatest_flr = 0;

  if (external.front() == NULL)
    return 0;

  else if (_E1.empty() == true)
    {
      for(int i = 0; i < 12 ;i++)
        {
          if(_b._n_on_floor_arg(i) > greatest)
            {
              greatest = _b._n_on_floor_arg(i);
              greatest_flr = i;
            }
        }
      return greatest_flr;
    }

  else if (_E1.empty() == false)
    {
      int idummy = internal.front();		// make dummy variable public?
      internal.pop();
      return idummy;
    }
}


int greatest2(Elevator _E1, Elevator _E2, building _b, queue<int> internal, queue<int> internal2)
{
  int greatest = 0;
  int greatest_flr = 0;
  if (external.front() == NULL)
    return 0;
  else if (_E2.empty() == true)
    {
      for(int i = 0; i < 12 ;i++)
        {
          if(_b._n_on_floor_arg(i) > greatest)
            {
              greatest = _b._n_on_floor_arg(i);
              greatest_flr = i;
            }
        }
      return greatest_flr;
    }
  else if (_E2.empty() == false)
    {
      int idummy = internal2.front();		// make dummy variable public?
      internal2.pop();
      return idummy;
    }
}

int random(Elevator _E1, Elevator _E2, building _b, queue<int> internal, queue<int> internal2)
{
  int u = (int)(12*((float) rand()/ RAND_MAX));
};
///////////////////////////////////////////////////////////////////////////////////////


int _minEvent(double _tai, double _e1ta, double _e2ta, double _e1td, double _e2td)
{
  double dummy = min(_tai, min(_e1ta, min(_e2ta, min(_e1td, _e2td))));
  if (dummy == _tai) return 0;
  if (dummy == _e1ta) return 1;
  if (dummy == _e2ta) return 2;
  if (dummy == _e1td) return 3;
  if (dummy == _e2td) return 4;
};

int ND = 0;

int main()
{
  double _CT = 0.0
      , _ta = 0.0
      ;

  ///////////////////////////////////////////////////////
  std::random_device IAT;
  std::mt19937 gen(IAT());
  gen.seed(static_cast<long double>(time(0)));
  std::exponential_distribution<double> X(5.0);
  ///////////////////////////////////////////////////////

  ///////////////////////////////////////////////////////
  std::random_device SrvT;
  std::mt19937 gen2(SrvT());
  gen.seed(static_cast<long double>(time(0)));
  std::exponential_distribution<double> Y(11.0);
  //////////////////////////////////////////////////////



  //  std::queue<double> _time_of_arrival_queue;
  //  std::queue<int> _floors_of_arrival;
  building B;
  Elevator E1;
  Elevator E2;
  data D;


  // TIMING MASKS
  double E1TA
      ,  E2TA
      ,  E1TD
      ,  E2TD
      ;


  int disembarking = 0
      , embarking = 0;


  E1TA = E1._Next_arrival_time();
  E2TA = E2._Next_arrival_time();
  E1TD = E2.Next_Departure_Time();
  E2TD = E2.Next_Departure_Time();

  //  E1.FORCE(0);
  int K = 0;
  // START LOOP...   ================================================================================
  system("pause");
  while(_CT < _Max_Ta)
    {
      //      if(E1.full()&&E1._flr_ct(E1.current_floor())>0){while(E1._flr_ct(E1.current_floor())>0){E1.pop_ta(E1.current_floor()); E1.pop_tb(E1.current_floor()); ND++;}};
      //      if(E2.full()&&E2._flr_ct(E2.current_floor())>0){while(E2._flr_ct(E2.current_floor())>0){E2.pop_ta(E2.current_floor()); E2.pop_tb(E2.current_floor()); ND++;}};
      while(K!=51){
          switch( _minEvent( _ta, E1TA, E2TA, E1TD, E2TD ) )
            {
            case 0:   // _ta is min.
              cout  << "case 0" << endl;
              cout<<E1.Next_Departure_Time()<<endl;
              cout<<E2.Next_Departure_Time()<<endl;
              _CT = _ta;
              //////////  >>>>>> Arrival Phase <<<<<<< /////////////////////////////////////////////////
              _ta = X(gen) +_CT;
              int j = rand()%11 + 1;
              B.insert( 0, j, _ta );
              external.push(0);
              D.vector_push_n_a(_CT);
              _ta = _CT + 0.3*BOARDING_TIME; //replace with distribution later
              break;

            case 1: // E1.TA
              cout  << "case 1" << endl;
              _CT = E1._Next_arrival_time() +0.001;
              E1.time(_CT+0.0001);
              //          E2.time(_CT);
              //E2.FORCE(E2.targeted_floor);
              //              if(E1._flr_ct(E1.current_floor())>0){
              disembarking = E1._flr_ct(E1.current_floor());
              while(disembarking > 0)
                {
                  D.vector_push_n_d(E1.pop_ta(E1.current_floor()),E1.pop_tb(E1.current_floor()),_CT,E1.current_floor());
                  cout << _CT << endl;
                  cout << E1.current_floor() << endl;
                  disembarking--;
                  ND++;
                  cout<<"disembarked"<<endl;
                };
              E1TA=dInfty;
              break;

            case 2:
              cout  << "case 2" << endl;
              _CT = E2._Next_arrival_time() +0.001;
              E2.time(_CT+0.001);
              //          E2.time(_CT);
              //E2.FORCE(E2.targeted_floor);
              //              if(E2._flr_ct(E2.current_floor())>0){
              disembarking = E2._flr_ct(E2.current_floor());
              while(disembarking > 0)
                {
                  D.vector_push_n_d(E2.pop_ta(E2.current_floor()),E2.pop_tb(E2.current_floor()),_CT,E2.current_floor());
                  cout << _CT << endl;
                  cout << E2.current_floor() << endl;
                  cout<<"disembarked"<<endl;
                  disembarking--;
                  ND++;
                };
              E2TA = dInfty;
              break;


            case 3:
              cout  << "case 3" << endl;
              cout<<E1.Next_Departure_Time()<<endl;
              //E1.TD
              _CT = E1.Next_Departure_Time();
              cout << "E1TD:  " << E1TD << endl;
              cout << "E1.TD:  " << E1.Next_Departure_Time() << endl;
              E1.time(_CT+0.002);
              //<<<<  Loop Boarding Phase >>>>>
              embarking = B._n_on_floor_arg(E1.current_floor());
              if(embarking > (12 - E1.get_n())){
                  embarking = 12 - E1.get_n();
                };
              while(embarking > 0)
                {
                  tempflr = B.pop_DF(E1.current_floor());
                  internal1.push(tempflr);
                  E1.push(B.pop_ta(E1.current_floor()), tempflr );
                  D.vector_push_n_b(_CT);
                  embarking--;
                };


              cout <<" E1.CF : " << E1.current_floor() << endl;
              if( E1.current_floor() != 0)
                {
                  E1.target_floor(0);
                }
              else
                {
                  E1.target_floor(2);
                }


              cout<<"E1TA :  "<<E1TA<<endl;
              cout<<"E1TD :  "<<E1TD<<endl;
              E1TA = E1._Next_arrival_time();
              E1TD = E1.Next_Departure_Time();
              cout<<"E1TA :  "<<E1TA<<endl;
              cout<<"E1TD :  "<<E1TD<<endl;
              break;


            case 4:
              cout  << "case 4" << endl;
              cout<<E2.Next_Departure_Time()<<endl;
              //E2.TD
              _CT = E2.Next_Departure_Time();
              E2.time(_CT+0.0004);
              //              E2.FORCE(E2.targeted_floor());
              //              E2.time(_CT);
              //<<<<  Loop Boarding Phase >>>>>
              // embarking = # of people trying to get onto elevator
              embarking = B._n_on_floor_arg(E2.current_floor());
              if(embarking > (12 - E2.get_n())){
                  embarking = 12 - E2.get_n();
                };
              while(embarking > 0)
                {
                  tempflr = B.pop_DF(E2.current_floor());
                  internal2.push(tempflr);
                  E2.push(B.pop_ta(E2.current_floor()), tempflr);
                  D.vector_push_n_b(_CT);
                  embarking--;
                };
              cout <<" E2.CF : " << E2.current_floor() << endl;
              if( E2.current_floor() != 0)
                {
                  E2.target_floor(0);
                }
              else
                {
                  E2.target_floor(2);
                }
              E2TA = E2._Next_arrival_time();
              E2TD = E2.Next_Departure_Time();
              break;
            }
          K++;
        }




      /////////////////////////////////////////////////////
      // Status printout:
      /////////////////////////////////////////////////////
      system("pause");
      cout << "ELEVATOR DIAGNOSTICS : " << endl << endl;
      //      system("pause");
      cout  << " _CT : " << _CT << endl;
      cout << " E1.get_time() " << E1.get_time() << endl;
      cout << " E2.get_time() " << E2.get_time() << endl;
      cout << " E1.get_direction() " << E1.get_direction() << endl;
      cout << " E2.get_direction() " << E2.get_direction() << endl;
      cout << " E1.current_floor() " << E1.current_floor() << endl;
      cout << " E2.current_floor() " << E2.current_floor() << endl;
      cout << " E1.get_Nb() :" << E1.get_Nb() << endl;
      cout << " E2.get_Nb() :" << E2.get_Nb() << endl;
      cout <<  "E1._flr_ct(2) : " << E1._flr_ct(2) << endl;
      cout <<  "E2._flr_ct(2) : " << E2._flr_ct(2) << endl;
      cout << " E1.Next_Departure_Time() :" << E1.Next_Departure_Time() << endl;
      cout << " E2.Next_Departure_Time() :" << E2.Next_Departure_Time() << endl;
      cout << " B._n_on_floor_arg(E1.current_floor()) : " << B._n_on_floor_arg(E1.current_floor()) << endl;
      cout << " B._n_on_floor_arg(E2.current_floor()) : " << B._n_on_floor_arg(E2.current_floor()) << endl;
      cout << "D.arrivals(_CT)" << D.arrivals(_CT) << endl;
      cout << "D.ndep()" << ND << endl;
      system("pause");
      K=0;
    }






  system("pause");
  E1.~Elevator();
  E2.~Elevator();
  D.~data();
  B.~building();


  //  cout << " E1.| :" << E1.| << endl;
  //  cout << " E2.| :" << E2.| << endl;
  //  cout  << " _CT : " << _CT << endl;
  //  cout  << " E1.current_floor() : "<< E1.current_floor() << endl;
  //  cout  << " E2.current_floor() : " << E2.current_floor() << endl;
  //  cout << " E1.get_time() " << E1.get_time() << endl;
  //  cout << " E2.get_time() " << E2.get_time() << endl;
  //  cout << " E1.get_direction() " << E1.get_direction() << endl;
  //  cout << " E2.get_direction() " << E2.get_direction() << endl;
  //  cout << " E1.current_floor() " << E1.current_floor() << endl;
  //  cout << " E2.current_floor() " << E2.current_floor() << endl;
  //  cout << " E1.get_Nb() :" << E1.get_Nb() << endl;
  //  cout << " E2.get_Nb() :" << E2.get_Nb() << endl;
  //  cout << " E1.Next_Departure_Time() :" << E1.Next_Departure_Time() << endl;
  //  cout << " E2.Next_Departure_Time() :" << E2.Next_Departure_Time() << endl;




  return 0;


}
