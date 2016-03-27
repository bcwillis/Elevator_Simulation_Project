#include "building.h"
#include <queue>

// initializes a building.
building::building()
{
  _nflr0_floor1 = 0;
  _nflr1_floor2 = 0;
  _nflr2_floor3 = 0;
  _nflr3_floor4 = 0;
  _nflr4_floor5 = 0;
  _nflr5_floor6 = 0;
  _nflr6_floor7 = 0;
  _nflr7_floor8 = 0;
  _nflr8_floor9 = 0;
  _nflr9_floor10 = 0;
  _nflr10_floor11 = 0;
  _nflr11_floor12 = 0;
  _Na = 0;
  _n = 0;
}

// pushes a passenger onto the floor, witha destination and arrival time.
void building::insert(const int & _floor_in, const int & _destination_floor, const double & _time_of_arrival)
{
  _Na++;
  _n++;
  switch(_floor_in)
    {
    case 0:
      _nflr0_floor1++;
      _TA_0_floor_1.push(_time_of_arrival);
      _DES_0_floor_1.push(_destination_floor);
      break;
    case 1:
      _nflr1_floor2++;
      _TA_1_floor_2.push(_time_of_arrival);
      _DES_1_floor_2.push(_destination_floor);
      break;
    case 2:
      _nflr2_floor3++;
      _TA_2_floor_3.push(_time_of_arrival);
      _DES_2_floor_3.push(_destination_floor);
      break;
    case 3:
      _nflr3_floor4++;
      _TA_3_floor_4.push(_time_of_arrival);
      _DES_3_floor_4.push(_destination_floor);
      break;
    case 4:
      _nflr4_floor5++;
      _TA_4_floor_5.push(_time_of_arrival);
      _DES_4_floor_5.push(_destination_floor);
      break;
    case 5:
      _nflr5_floor6++;
      _TA_5_floor_6.push(_time_of_arrival);
      _DES_5_floor_6.push(_destination_floor);
      break;
    case 6:
      _nflr6_floor7++;
      _TA_6_floor_7.push(_time_of_arrival);
      _DES_6_floor_7.push(_destination_floor);
      break;
    case 7:
      _nflr7_floor8++;
      _TA_7_floor_8.push(_time_of_arrival);
      _DES_7_floor_8.push(_destination_floor);
      break;
    case 8:
      _nflr8_floor9++;
      _TA_8_floor_9.push(_time_of_arrival);
      _DES_8_floor_9.push(_destination_floor);
      break;
    case 9:
      _nflr9_floor10++;
      _TA_9_floor_10.push(_time_of_arrival);
      _DES_9_floor_10.push(_destination_floor);
      break;
    case 10:
      _nflr10_floor11++;
      _TA_10_floor_11.push(_time_of_arrival);
      _DES_10_floor_11.push(_destination_floor);
      break;
    case 11:
      _nflr11_floor12++;
      _TA_11_floor_12.push(_time_of_arrival);
      _DES_11_floor_12.push(_destination_floor);
      break;
    }
}


// returns the number of people waiting outside the elevator
int building::_n_on_floor_arg(const int & _floor_in)
{
  switch(_floor_in){
    case 0:
      return _nflr0_floor1;
    case 1:
      return _nflr1_floor2;
    case 2:
      return _nflr2_floor3;
    case 3:
      return _nflr3_floor4;
    case 4:
      return _nflr4_floor5;
    case 5:
      return _nflr5_floor6;
    case 6:
      return _nflr6_floor7;
    case 7:
      return _nflr7_floor8;
    case 8:
      return _nflr8_floor9;
    case 9:
      return _nflr9_floor10;
    case 10:
      return _nflr10_floor11;
    case 11:
      return _nflr11_floor12;
    default:
      return 0;
    }
}

//returns time of arrival
// removes front of queue
double building::pop_ta(const int & _floor_in)
{
  double returnx = 0.0;
  switch(_floor_in){
    case 0:
      _nflr0_floor1--;
      returnx = _TA_0_floor_1.front();
      _TA_0_floor_1.pop();
      break;
    case 1:
      _nflr1_floor2--;
      returnx = _TA_1_floor_2.front();
      _TA_1_floor_2.pop();
      break;
    case 2:
      _nflr2_floor3--;
      returnx = _TA_2_floor_3.front();
      _TA_2_floor_3.pop();
      break;
    case 3:
      _nflr3_floor4--;
      returnx = _TA_3_floor_4.front();
      _TA_3_floor_4.pop();
      break;
    case 4:
      _nflr4_floor5--;
      returnx = _TA_4_floor_5.front();
      _TA_4_floor_5.pop();
      break;
    case 5:
      _nflr5_floor6--;
      returnx = _TA_5_floor_6.front();
      _TA_5_floor_6.pop();
      break;
    case 6:
      _nflr6_floor7--;
      returnx = _TA_6_floor_7.front();
      _TA_6_floor_7.pop();
      break;
    case 7:
      _nflr7_floor8--;
      returnx = _TA_7_floor_8.front();
      _TA_7_floor_8.pop();
      break;
    case 8:
      _nflr8_floor9--;
      returnx = _TA_8_floor_9.front();
      _TA_8_floor_9.pop();
      break;
    case 9:
      _nflr9_floor10--;
      returnx = _TA_9_floor_10.front();
      _TA_9_floor_10.pop();
      break;
    case 10:
      _nflr10_floor11--;
      _TA_10_floor_11.front();
      _TA_10_floor_11.pop();
      break;
    case 11:
      _nflr11_floor12--;
      returnx = _TA_11_floor_12.front();
      _TA_11_floor_12.pop();
      break;
    default:
      returnx = 0.0;
      break;
    }
  return returnx;
}

  int building::n_stored()
  {
    return _n;
  }

// returns destination floor
int building::pop_DF(const int & _floor_in)
{
  _n--;
  double returny = 0;
  switch(_floor_in){
    case 0:
      returny = _DES_0_floor_1.front();
      _DES_0_floor_1.pop();
      break;
    case 1:
      returny = _DES_1_floor_2.front();
      _DES_1_floor_2.pop();
      break;
    case 2:
      returny = _DES_2_floor_3.front();
      _DES_2_floor_3.pop();
      break;
    case 3:
      returny = _DES_3_floor_4.front();
      _DES_3_floor_4.pop();
      break;
    case 4:
      returny = _DES_4_floor_5.front();
      _DES_4_floor_5.pop();
      break;
    case 5:
      returny = _DES_5_floor_6.front();
      _DES_5_floor_6.pop();
      break;
    case 6:
      returny = _DES_6_floor_7.front();
      _DES_6_floor_7.pop();
      break;
    case 7:
      returny = _DES_7_floor_8.front();
      _DES_7_floor_8.pop();
      break;
    case 8:
      returny = _DES_8_floor_9.front();
      _DES_8_floor_9.pop();
      break;
    case 9:
      returny = _DES_9_floor_10.front();
      _DES_9_floor_10.pop();
      break;
    case 10:
      returny = _DES_10_floor_11.front();
      _DES_10_floor_11.pop();
      break;
    case 11:
      returny = _DES_11_floor_12.front();
      _DES_11_floor_12.pop();
      break;
    default:
      returny = 0;
      break;
    }
  return returny;
}


building::~building()
{
  while(_Na != 0 ){
      _Na--;
      _TA_0_floor_1.pop();
      _TA_1_floor_2.pop();
      _TA_2_floor_3.pop();
      _TA_3_floor_4.pop();
      _TA_4_floor_5.pop();
      _TA_5_floor_6.pop();
      _TA_6_floor_7.pop();
      _TA_7_floor_8.pop();
      _TA_8_floor_9.pop();
      _TA_9_floor_10.pop();
      _TA_10_floor_11.pop();
      _TA_11_floor_12.pop();
      _DES_0_floor_1.pop();
      _DES_1_floor_2.pop();
      _DES_2_floor_3.pop();
      _DES_3_floor_4.pop();
      _DES_4_floor_5.pop();
      _DES_5_floor_6.pop();
      _DES_6_floor_7.pop();
      _DES_7_floor_8.pop();
      _DES_8_floor_9.pop();
      _DES_9_floor_10.pop();
      _DES_10_floor_11.pop();
      _DES_11_floor_12.pop();
    }
}

