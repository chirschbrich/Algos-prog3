#include <vector>
#include "stuff3.h"

// you should modify the code for this one
// you can also change the parameters. 
// If you do that. make sure you change that for the call from Decision1()
pair<bool, Stuff3> DecisionRecur1(vector<Stuff3>& vec)
{
   //need base cases for odd and even vector sizes

   /*
   divide vector into smaller vectors by passing in n/2 recursively
   find what is true and compare it with the layer up
      if nothing is true then dont
   keep going up checking to see if the number is in the vector more than half the time
   
   
   */
   
   Stuff3 s; //only creates a vector for compilation, will be deleted later
   pair<bool, Stuff3> p = make_pair(false, s); //pair that will be returned, replace perameters with answer
   return p;
}

pair<bool, Stuff3> Decision1(vector<Stuff3>& vec)
{
   // you can change this line if you decide to change the parameters for DecisionRecur1
   return DecisionRecur1(vec);
}

// you should modify the code for this one
// you can also change the parameters. 
// If you do that. make sure you change that for the call from Decision2()
pair<bool, Stuff3> DecisionRecur2(vector<Stuff3>& vec)
{
   //need base cases for odd and even vector sizes
   
   
   Stuff3 s; //only creates a vector for compilation, will be deleted later
   pair<bool, Stuff3> p = make_pair(true, s); //pair that will be returned, replace perameters with answer
   return p;
}

pair<bool, Stuff3> Decision2(vector<Stuff3>& vec)
{
   // you can change this line if you decide to change the parameters for DecisionRecur2
   return DecisionRecur2(vec);
}
