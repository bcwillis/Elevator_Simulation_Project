#include "elevator.h"
#include <queue>

// Pre:   none
// Post:  Declares a new elevator
Elevator::Elevator()
{
  _Cf = 0 ;
  _Nb = 0;
  _n = 0;
  _target=0;
  _t = 0.0;
  _T_external=0.0;
  _T_ARRIVAL = 0.0;
  _T_DEPARTURE = BOARDING_TIME;
  _moving = false;
  _direction = true;    // ((corresponds to up))
  _df0_n = 0;
  _df1_n = 0;
  _df2_n = 0;
  _df3_n = 0;
  _df4_n = 0;
  _df5_n = 0;
  _df6_n = 0;
  _df7_n = 0;
  _df8_n = 0;
  _df9_n = 0;
  _df10_n = 0;
  _df11_n = 0;
}

double Elevator::get_Ex_time()
{
  return _T_external;
}

double Elevator::get_In_time()
{
  return _t;
}

double Elevator::get_Ar_time()
{
  return _T_ARRIVAL;
}

double Elevator::get_De_time()
{
  return _T_DEPARTURE;
}


void Elevator::s_Ex_time(const double & _t_in)
{
  _T_external = _t_in;
}

void Elevator::s_In_time(const double & _t_in)
{
  _t = _t_in;
}

void Elevator::s_Ar_time(const double & _t_in)
{
  _T_ARRIVAL = _t_in;
}

void Elevator::s_De_time(const double & _t_in)
{
  _T_DEPARTURE = _t_in;
}

void Elevator::FORCE(const int & _CF_FOR)
{
  _Cf = _CF_FOR;
}

double Elevator::_Next_arrival_time()
{
  {
    if(_t>_T_ARRIVAL){
        return 10000.0;
      }
    else
      {
        return _T_ARRIVAL;
      }
  }
}

double Elevator::Next_Departure_Time()
{
  if(_t > _T_DEPARTURE){
      return 100000.0;
    }
  else
    {
      return _T_DEPARTURE;
    }
}

double Elevator::_Last_departure_time()
{
  return _t;
}

// Pre:   none
// Post:  sets external time to _t_in
//        sets conditionally appropreate:
//              double:
//                   _t  (internal time)
//                   _T_ARRIVAL
//                   _T_DEPARTURE
//
//              bool:
//                   _TxS
//                   _moving
//

void Elevator::time(const double & _t_in)
{
  _T_external = _t_in;
  if(_t_in>_T_ARRIVAL)
    {
     _t = _t_in;
    }
}

//////////////////////////////////////////////////

// Pre:   _t >= _ta
// Post:  sets _target floor to _target_floor
void Elevator::target_floor(const int & _target_floor_in)
{
  if(!_TxS)
    {
      _target = _target_floor_in;
      if(_Cf > _target){
          _T_ARRIVAL = _t + (_Cf - _target)*TRAVEL_RATE;
          _T_DEPARTURE = _T_ARRIVAL + BOARDING_TIME;
          _direction = false;
        }
      else
        {
          _T_ARRIVAL = _t + (_target - _Cf)*TRAVEL_RATE;
          _T_DEPARTURE = _T_ARRIVAL + BOARDING_TIME;
          _direction = true;
        }
    }
}

// pre: none
// post: returns true when the elevator is full.
bool Elevator::full()
{
  if(_n == CAPACITY)
    {
      return true;
    }
  else
    {
      return false;
    }
}

int Elevator::targeted_floor()
{
  return _target;
}

// pre: none
// post: returns true when the elevator is empty.
bool Elevator::empty()
{
  if(_n==0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

//Pre: none.
//Post: returns current time.
double Elevator::get_time()
{
  return _t;
}

bool Elevator::get_direction()
{
  if(_target<_Cf)
    {
      return false;
    }
  else
    {
      if(_target > _Cf)
        {
          return true;
        }
      else
        {
          return _direction;
        }
    }
}


int Elevator::current_floor()
{
  return _Cf;
}

// Pre:   none
// Post:  change direction (( Only allowed when _Velocity == 0 ))
void Elevator::change_direction()
{
  if(!_moving)
    {
      _direction = !_direction;
    }
}

int Elevator::_flr_ct(int flr)
{
  switch(flr){
    case 0:
      return _df0_n;
    case 1:
      return _df1_n;
    case 2:
      return _df2_n;
    case 3:
      return _df3_n;
    case 4:
      return _df4_n;
    case 5:
      return _df5_n;
    case 6:
      return _df6_n;
    case 7:
      return _df7_n;
    case 8:
      return _df8_n;
    case 9:
      return _df9_n;
    case 10:
      return _df10_n;
    case 11:
      return _df11_n;
    default:
      return 0;
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pre:   none
// Post:  unloads a time of arrival for the current floor. (unloading at destination:: NEED TO SET _td to _CT + (2.25)/60)
//        decrements the floor's respective counter.
///        NEED TO CHECK FLOOR COUNT BEFORE CALLING THE POP SEQUENCE IN MAIN
double Elevator::pop_ta(int _CF_in)
{
  double double_x = 0.0;

  switch(_CF_in){
    case 0:
      _df0_n--;
      double_x = _F0a_ta_to_Floor1.front();
      _F0a_ta_to_Floor1.pop();
      break;
    case 1:
      _df1_n--;
      double_x = _F1a_ta_to_Floor2.front();
      _F1a_ta_to_Floor2.pop();
      break;
    case 2:
      _df2_n--;
      double_x = _F2a_ta_to_Floor3.front();
      _F2a_ta_to_Floor3.pop();
      break;
    case 3:
      _df3_n--;
      double_x = _F3a_ta_to_Floor4.front();
      _F3a_ta_to_Floor4.pop();
      break;
    case 4:
      _df4_n--;
      double_x = _F4a_ta_to_Floor5.front();
      _F4a_ta_to_Floor5.pop();
      break;
    case 5:
      _df5_n--;
      double_x = _F5a_ta_to_Floor6.front();
      _F5a_ta_to_Floor6.pop();
      break;
    case 6:
      _df6_n--;
      double_x = _F6a_ta_to_Floor7.front();
      _F6a_ta_to_Floor7.pop();
      break;
    case 7:
      _df7_n--;
      double_x = _F7a_ta_to_Floor8.front();
      _F7a_ta_to_Floor8.pop();
      break;
    case 8:
      _df8_n--;
      double_x = _F8a_ta_to_Floor9.front();
      _F8a_ta_to_Floor9.pop();
      break;
    case 9:
      _df9_n--;
      double_x = _F9a_ta_to_Floor10.front();
      _F9a_ta_to_Floor10.pop();
      break;
    case 10:
      _df10_n--;
      double_x = _F10a_ta_to_Floor11.front();
      _F10a_ta_to_Floor11.pop();
      break;
    case 11:
      _df11_n--;
      double_x = _F11a_ta_to_Floor12.front();
      _F11a_ta_to_Floor12.pop();
      break;
    }
  return double_x;
}

// Pre:   none
// Post:  unloads a time of boarding for the current floor.
//        decrements the elvators cargo counter.
double Elevator::pop_tb(int _CF_in)
{
  double double_x = 0.0;
  _n--;
  switch(_CF_in)
    {
    case 0:
      double_x = _F0b_tb_to_Floor1.front();
      _F0b_tb_to_Floor1.pop();
      break;
    case 1:
      double_x = _F1b_tb_to_Floor2.front();
      _F1b_tb_to_Floor2.pop();
      break;
    case 2:
      double_x = _F2b_tb_to_Floor3.front();
      _F2b_tb_to_Floor3.pop();
      break;
    case 3:
      double_x = _F3b_tb_to_Floor4.front();
      _F3b_tb_to_Floor4.pop();
      break;
    case 4:
      double_x = _F4b_tb_to_Floor5.front();
      _F4b_tb_to_Floor5.pop();
      break;
    case 5:
      double_x = _F5b_tb_to_Floor6.front();
      _F5b_tb_to_Floor6.pop();
      break;
    case 6:
      double_x = _F6b_tb_to_Floor7.front();
      _F6b_tb_to_Floor7.pop();
      break;
    case 7:
      double_x = _F7b_tb_to_Floor8.front();
      _F7b_tb_to_Floor8.pop();
      break;
    case 8:
      double_x = _F8b_tb_to_Floor9.front();
      _F8b_tb_to_Floor9.pop();
      break;
    case 9:
      double_x = _F9a_ta_to_Floor10.front();
      _F9b_tb_to_Floor10.pop();
      break;
    case 10:
      double_x = _F10b_tb_to_Floor11.front();
      _F10b_tb_to_Floor11.pop();
      break;
    case 11:
      double_x = _F11b_tb_to_Floor12.front();
      _F11b_tb_to_Floor12.pop();
      break;
    }
  return double_x;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Pre: none
// Post:  loads a passenger into the elevator ((into the correct queue))
/// Overfilling the elevator needs to be handled in main.
void Elevator::push(const double & _time_of_arrival_in, const int & _destination_floor_in)
{
  switch(_destination_floor_in)
    {
    case 0:
      _Nb++;
      _n++;
      _df0_n++;
      _F0a_ta_to_Floor1.push(_time_of_arrival_in);
      _F0b_tb_to_Floor1.push(_t);
      break;
    case 1:
      _Nb++;
      _n++;
      _df1_n++;
      _F1a_ta_to_Floor2.push(_time_of_arrival_in);
      _F1b_tb_to_Floor2.push(_t);
      break;
    case 2:
      _Nb++;
      _n++;
      _df2_n++;
      _F2a_ta_to_Floor3.push(_time_of_arrival_in);
      _F2b_tb_to_Floor3.push(_t);
      break;
    case 3:
      _Nb++;
      _n++;
      _df3_n++;
      _F3a_ta_to_Floor4.push(_time_of_arrival_in);
      _F3b_tb_to_Floor4.push(_t);
      break;
    case 4:
      _Nb++;
      _n++;
      _df4_n++;
      _F4a_ta_to_Floor5.push(_time_of_arrival_in);
      _F4b_tb_to_Floor5.push(_t);
      break;
    case 5:
      _Nb++;
      _n++;
      _df5_n++;
      _F5a_ta_to_Floor6.push(_time_of_arrival_in);
      _F5b_tb_to_Floor6.push(_t);
      break;
    case 6:
      _Nb++;
      _n++;
      _df6_n++;
      _F6a_ta_to_Floor7.push(_time_of_arrival_in);
      _F6b_tb_to_Floor7.push(_t);
      break;
    case 7:
      _Nb++;
      _n++;
      _df7_n++;
      _F7a_ta_to_Floor8.push(_time_of_arrival_in);
      _F7b_tb_to_Floor8.push(_t);
      break;
    case 8:
      _Nb++;
      _n++;
      _df8_n++;
      _F8a_ta_to_Floor9.push(_time_of_arrival_in);
      _F8b_tb_to_Floor9.push(_t);
      break;
    case 9:
      _Nb++;
      _n++;
      _df9_n++;
      _F9a_ta_to_Floor10.push(_time_of_arrival_in);
      _F9b_tb_to_Floor10.push(_t);
      break;
    case 10:
      _n++;
      _Nb++;
      _df10_n++;
      _F10a_ta_to_Floor11.push(_time_of_arrival_in);
      _F10b_tb_to_Floor11.push(_t);
      break;
    case 11:
      _Nb++;
      _n++;
      _df11_n++;
      _F11a_ta_to_Floor12.push(_time_of_arrival_in);
      _F11b_tb_to_Floor12.push(_t);
      break;
    }
}

int Elevator::get_n()
{
  return _n;
}

int Elevator::get_Nb()
{
  return _Nb;
}

// Pre: none
// Post:  Terminates the elevator
Elevator::~Elevator()
{
  while(_n!=0)
    {
      _F0a_ta_to_Floor1.pop();
      _F0b_tb_to_Floor1.pop();
      _F1a_ta_to_Floor2.pop();
      _F1b_tb_to_Floor2.pop();
      _F2a_ta_to_Floor3.pop();
      _F2b_tb_to_Floor3.pop();
      _F3a_ta_to_Floor4.pop();
      _F3b_tb_to_Floor4.pop();
      _F4a_ta_to_Floor5.pop();
      _F4b_tb_to_Floor5.pop();
      _F5a_ta_to_Floor6.pop();
      _F5b_tb_to_Floor6.pop();
      _F6a_ta_to_Floor7.pop();
      _F6b_tb_to_Floor7.pop();
      _F7a_ta_to_Floor8.pop();
      _F7b_tb_to_Floor8.pop();
      _F8a_ta_to_Floor9.pop();
      _F8b_tb_to_Floor9.pop();
      _F9a_ta_to_Floor10.pop();
      _F9b_tb_to_Floor10.pop();
      _F10a_ta_to_Floor11.pop();
      _F10b_tb_to_Floor11.pop();
      _F11a_ta_to_Floor12.pop();
      _F11b_tb_to_Floor12.pop();
      _n--;
    }

  _Cf = 0;
  _target = 0;
  _TxS = false;

}
