// Bryan_Willis_Elevator_Class

///  Elevator Class  //////////////////////////////////////////////////////

#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <queue>

#define CAPACITY 12
#define INF 40000000
#define BOARDING_TIME 0.1667
#define TRAVEL_RATE 0.075

class Elevator
{
public:

  // Pre:   none
  // Post:  Declares a new elevator
  Elevator();

  int targeted_floor();

  // pre: none
  // post: returns true when the elevator is full.
  bool full();

  // pre: none
  // post: returns true when the elevator is full.
  //       (( This is really only used for algorithm purposes. ))
  bool get_direction();

  // pre: none
  // post: returns true when the elevator is empty.
  bool empty();

  // pre: none
  // post: returns the NUMBER of PASSENGER going to the corresponding FLOOR "flr"
  int _flr_ct(int flr);

  //Pre: none.
  //Post: returns current time.
  double get_time();

  // Pre: none
  // Post: Retunr current floor of the elevator
  int current_floor();

  // Pre:   none
  // Post:  SETS TIME current time to _t_in
  void time(const double & _t_in);
  void FORCE( const int & _CF_FOR );

  // Pre: none
  // Post: gets departure time
  double _Last_departure_time();

  // Pre: none
  // Post: gets scheduled arrival time. (( In main, when we are implementing our algorithms, if we want the elevator to be interuptable, we need to handle loss of destination conditions));
  double _Next_arrival_time();
  double Next_Departure_Time();

  // Pre:   none
  // Post:  sets _target floor to _target_floor
  void target_floor(const int & _target_floor);
  //  bool target_floor_tstng_(const int & _target_floor);

  // Pre:   none
  // Post:  change direction (( Only allowed when _Velocity == 0 ))
  void change_direction();

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  /**
    intended for use as: (( Let X1, X2 be "elevators", Y be a "Building/structure" ))
    Data.insert(_X1.pop_ta(), _X1.pop_tb, main::_CT);
  */

  // Pre:   none
  // Post:  unloads a time of arrival for the current floor. (unloading at destination, sets _td to _CT + (2.25)/60)
  double pop_ta(int _CF_in);

  // Pre:   none
  // Post:  unloads a time of boarding for the current floor.
  double pop_tb(int _CF_in);

  int get_n();


  //pre: none
  // post:
  //  returns _T_external;
  //  retunrs _t;
  //  returns _T_ARRIVAL;
  //  returns _T_DEPARTURE;
  double get_Ex_time();
  double get_In_time();
  double get_Ar_time();
  double get_De_time();

  //pre: none
  // post modifies external time, internal time, arrival time departure time
  void s_Ex_time(const double & _t_in);
  void s_In_time(const double & _t_in);
  void s_Ar_time(const double & _t_in);
  void s_De_time(const double & _t_in);


  // Pre: none
  // Post: returns the number of passengers that have boarded the elevator at some time up until this point.
  int get_Nb();

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // Pre: none
  // Post:  loads a passenger into the elevator
  void push(const double & _time_of_arrival_in, const int & _destination_floor_in);

  // Pre: none
  // Post:  Terminates the elevator
  ~Elevator();


private:

  // Number boarded on elevator.
  int _Nb;

  double _t                                                           // time ( current time )
  ,      _T_external
  ,      _T_ARRIVAL
  ,      _T_DEPARTURE
  ;

  bool  _moving
  ;

  int _Cf;
  int  _target                                                  // targeted destination floor.
  //                                                                      "So target is like your destination floor for the elevator"
  //                                                                             WHEN WE UPDATE CURRENT FLOOR, WE ALSO NEED TO UPDATE TIME.
  ,      _n // cargo                                                        number of passengers onboard
  ,      _df0_n // cargo to flr 0
  ,      _df1_n // cargo to flr 1
  ,      _df2_n // cargo to flr 2
  ,      _df3_n // cargo to flr 3
  ,      _df4_n // cargo to flr 4
  ,      _df5_n // cargo to flr 5
  ,      _df6_n // cargo to flr 6
  ,      _df7_n // cargo to flr 7
  ,      _df8_n // cargo to flr 8
  ,      _df9_n // cargo to flr 9
  ,      _df10_n // cargo to flr 10
  ,      _df11_n // cargo to flr 11
  ;


  bool _direction                                                 // true if the elevator is going up.
  ,    _TxS         // Target_Floor_Set
  ;


  // Time of (a)_ARRIVAL storage
  std::queue<double>                _F0a_ta_to_Floor1
  ,                                 _F1a_ta_to_Floor2
  ,                                 _F2a_ta_to_Floor3
  ,                                 _F3a_ta_to_Floor4
  ,                                 _F4a_ta_to_Floor5
  ,                                 _F5a_ta_to_Floor6
  ,                                 _F6a_ta_to_Floor7
  ,                                 _F7a_ta_to_Floor8
  ,                                 _F8a_ta_to_Floor9
  ,                                 _F9a_ta_to_Floor10
  ,                                 _F10a_ta_to_Floor11
  ,                                 _F11a_ta_to_Floor12
  ;

  // Time of (b)_BOARDING storage
  std::queue<double>                _F0b_tb_to_Floor1
  ,                                 _F1b_tb_to_Floor2
  ,                                 _F2b_tb_to_Floor3
  ,                                 _F3b_tb_to_Floor4
  ,                                 _F4b_tb_to_Floor5
  ,                                 _F5b_tb_to_Floor6
  ,                                 _F6b_tb_to_Floor7
  ,                                 _F7b_tb_to_Floor8
  ,                                 _F8b_tb_to_Floor9
  ,                                 _F9b_tb_to_Floor10
  ,                                 _F10b_tb_to_Floor11
  ,                                 _F11b_tb_to_Floor12
  ;
};


#endif // ELEVATOR_H
