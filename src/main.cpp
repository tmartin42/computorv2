#include <iostream>
#include "Variable.hpp"

int main (void) {

    Variable lol =  Variable(2);
   Variable kek =  Variable(3);

   std::vector< std::vector<Variable> > vec;

    Variable myints1[] = {Variable(2), Variable(5), Variable(6)};
    Variable myints2[] = {Variable(3),Variable(3), Variable(9)};

    std::vector<Variable> vec1;
    vec1.push_back(Variable(2.0));
    vec1.push_back(Variable(5));
    vec1.push_back(Variable(6));
    std::vector<Variable>  vec2;
    vec2.push_back(Variable(3));
    vec2.push_back(Variable(3));
    vec2.push_back(Variable(9));
    vec.push_back(vec1);
    vec.push_back(vec2);
   Variable mat = Variable(vec);

//   std::cout << std::endl;

    mat.display();
  //  (lol - kek).display();

    //(mat + lol).display();
  //  res1->display();
    //AVar *res2 = (*lol - *kek * *kek);
   // res2->display();
    return (0);
}