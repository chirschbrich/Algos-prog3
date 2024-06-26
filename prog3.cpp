#include <vector>
#include "stuff3.h"

// you should modify the code for this one
// you can also change the parameters. 
// If you do that. make sure you change that for the call from Decision1()
pair<bool, Stuff3> DecisionRecur1(vector<Stuff3>& vec)
{
   /*
   divide vector into smaller vectors by passing in n/2 recursively
   find what is true and compare it with the layer up
      if nothing is true then dont
   keep going up checking to see if the number is in the vector more than half the time
   */
  // check if empty first
  if(vec.empty()) {
   return make_pair(false, Stuff3());
  }

   // Base case - two elements, compare them and return
   if (vec.size() == 2) {
      if (vec[0] == vec[1]) {
         return make_pair(true, vec[0]);
      } else {
         return make_pair(false, Stuff3());
      }
   }

   // Base case - one element, return true with that element
   if (vec.size() == 1) {
      return make_pair(true, vec[0]);
   }

   int partition = vec.size() / 2;
   vector<Stuff3> left;
   vector<Stuff3> right;
   for (int i = 0; i < vec.size(); i++){
      if (i < partition) {
         left.push_back(vec[i]);
      }
      else {
         right.push_back(vec[i]);
      }
   }

   pair<bool, Stuff3> leftResult = DecisionRecur1(left);
   pair<bool, Stuff3> rightResult  = DecisionRecur1(right); 

   //check if obj appears > 50% of the time in vec
   if (leftResult.first){ //check for solution in left half
      int count = 0;
      for (size_t i = 0; i < vec.size(); i++){
         if (leftResult.second == vec[i])
            count++;
      }

      if (count > vec.size()/2) {
         return leftResult;
      }
   }
   if (rightResult.first) { //check for solution in right half
      int count = 0;
      for (size_t i = 0; i < vec.size(); i++){
         if (rightResult.second == vec[i])
            count++;
      }

      if (count > vec.size()/2) {
         return rightResult;
      }
   }
   return make_pair(false, Stuff3()); //no solution
}

pair<bool, Stuff3> Decision1(vector<Stuff3>& vec) {
   return DecisionRecur1(vec);
}

// you should modify the code for this one
// you can also change the parameters. 
// If you do that. make sure you change that for the call from Decision2()
pair<bool, Stuff3> DecisionRecur2(vector<Stuff3>& vec, int start, Stuff3 stuff, int count)
{
   //need base cases for odd and even vector sizes
   if (start >= vec.size()) {
      if (count == 0) {
         if (vec.size() % 2 != 0) //if it is odd, find edge case where no pairs occur but last num is deciding factor
            stuff = vec[vec.size() - 1];
         else
            return make_pair(false, Stuff3()); //no solution
      }

      int numTimes = 0;
      for (size_t i = 0; i < vec.size(); i++){
         if (stuff == vec[i])
            numTimes++;
      }

      if (numTimes > vec.size()/2) {
         return make_pair(true, stuff);
      }

      return make_pair(false, Stuff3());
   }

   if (vec[start - 1] == vec[start] && vec[start] == stuff) { //matching pair found == previous pair, increment count
      return DecisionRecur2(vec, start + 2, stuff, count + 1);
   }
   else if (vec[start - 1] == vec[start] && !(vec[start] == stuff)) { // matching pair found != previous pair (could be first matching pair found)
      if (count == 0) { //first unique pair found
         return DecisionRecur2(vec, start + 2, vec[start], count + 1); //first matching pair found
      }
      return DecisionRecur2(vec, start + 2, stuff, count - 1); //found matching pair != previous pair
   }

   return DecisionRecur2(vec, start + 2, stuff, count); //no matching pair found, move on to next call
}

pair<bool, Stuff3> Decision2(vector<Stuff3>& vec)
{
   // you can change this line if you decide to change the parameters for DecisionRecur2
   return DecisionRecur2(vec, 1, Stuff3(false, 0, 0, 0), 0);
}
