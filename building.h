/// Building Class   //////////////////////////////////////////////////////

#ifndef building_H
#define building_H

#include <queue>

class building
{
public:
  building();

  // pre: none. well. someone has to be on floor n for anything to happen, so we should probanly check if there's anyone on the floor before wea actually call this function when we implement it, since thete's no crash-the-program saftey net thingy...
  // post: if there is someone on the floor, it returns the time of arrival value for that person,
  //       else, I'm not exactly sure, probably returns an extraneous address value which the compiler uses as the end() ptr for the particular queue which corresponds to the current floor...
  double pop_ta( const int & _floor_in );


  //pre:
  // post : tells us how many
  int n_stored();


  //
  int pop_DF( const int & _floor_in );

  // pre: none
  // post: pushes arrival time into the  floor (( corresponding to _floor_in )'s queue...
  //       increments _Na
  //       increments _n_FLOOR_"x"
  void insert(const int & _floor_in, const int & _dest_floor, const double & _ta_in);

  //pre: none
  // post : returns the number of people waing on the floor: "_floor_in"
  int _n_on_floor_arg(const int & _floor_in);


  /**
    when popping on floor "floor#" (value == flr# -1)
type_temp = *(_QUEUE_NAME_"flr#"_floor_"floor#".end()-1)
                      _DES_0_floor_1.pop();]
                      return type_temp();
                     */
  ~building();





private:

  // number of people who have arrived.
  int _Na
  ,   _n;


  // number of people on floor x.
  int _nflr0_floor1
  ,   _nflr1_floor2
  ,   _nflr2_floor3
  ,   _nflr3_floor4
  ,   _nflr4_floor5
  ,   _nflr5_floor6
  ,   _nflr6_floor7
  ,   _nflr7_floor8
  ,   _nflr8_floor9
  ,   _nflr9_floor10
  ,   _nflr10_floor11
  ,   _nflr11_floor12
  ;

  std::queue<double>  _TA_0_floor_1
  ,                   _TA_1_floor_2
  ,                   _TA_2_floor_3
  ,                   _TA_3_floor_4
  ,                   _TA_4_floor_5
  ,                   _TA_5_floor_6
  ,                   _TA_6_floor_7
  ,                   _TA_7_floor_8
  ,                   _TA_8_floor_9
  ,                   _TA_9_floor_10
  ,                   _TA_10_floor_11
  ,                   _TA_11_floor_12
  ;

  std::queue<int>    _DES_0_floor_1
  ,                  _DES_1_floor_2
  ,                  _DES_2_floor_3
  ,                  _DES_3_floor_4
  ,                  _DES_4_floor_5
  ,                  _DES_5_floor_6
  ,                  _DES_6_floor_7
  ,                  _DES_7_floor_8
  ,                  _DES_8_floor_9
  ,                  _DES_9_floor_10
  ,                  _DES_10_floor_11
  ,                  _DES_11_floor_12
  ;
  ;

};

#endif // building_H

