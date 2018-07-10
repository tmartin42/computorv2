#include <iostream>
#include "AVar.hpp"
#include "Rational.hpp"
#include "Matrix.hpp"

int main (void) {

    Rational lol =  Rational(2);
   Rational kek =  Rational(3);
  
/*
   std::vector< std::vector<Variable> > vec;

    Variable myints1[] = {Variable(2), Variable(5), Variable(6)};
    Variable myints2[] = {Variable(3),Variable(3), Variable(9)};

    std::vector<Variable> vec1;
    vec1.push_back(Variable(2.0));
    vec1.push_back(Variable(5));
  //  vec1.push_back(Variable(6));
    std::vector<Variable>  vec2;
    vec2.push_back(Variable(3));
    vec2.push_back(Variable(3));
    //vec2.push_back(Variable(9));
    vec.push_back(vec1);
    vec.push_back(vec2);
   Variable mat = Variable(vec);



   std::vector< std::vector<Variable> > vecb;

    std::vector<Variable> vec3;
    vec3.push_back(Variable(9));
    vec3.push_back(Variable(4));
    vec3.push_back(Variable(6));
    std::vector<Variable>  vec4;
    vec4.push_back(Variable(7.5));
    vec4.push_back(Variable(1));
    vec4.push_back(Variable(4));
    vecb.push_back(vec3);
    vecb.push_back(vec4);
   Variable matt = Variable(vecb);
*/

   std::vector< std::vector<Rational> > vec;

    Rational myints1[] = {Rational(2), Rational(5), Rational(6)};
    Rational myints2[] = {Rational(3),Rational(3), Rational(9)};

    std::vector<Rational> vec1;
    vec1.push_back(Rational(1));
    vec1.push_back(Rational(2));
  //  vec1.push_back(Variable(6));
    std::vector<Rational>  vec2;
    vec2.push_back(Rational(45));
    vec2.push_back(Rational(22));
    //vec2.push_back(Variable(9));
    vec.push_back(vec1);
    vec.push_back(vec2);
   Matrix mat = Matrix(vec);



   std::vector< std::vector<Rational> > vecb;

    std::vector<Rational> vec3;
    vec3.push_back(Rational(99));
    vec3.push_back(Rational(42));
    vec3.push_back(Rational(12));
    std::vector<Rational>  vec4;
    vec4.push_back(Rational(30));
    vec4.push_back(Rational(21));
    vec4.push_back(Rational(10));
    vecb.push_back(vec3);
    vecb.push_back(vec4);
    Matrix matt = Matrix(vecb);
//   std::cout << std::endl;

  try {
    mat.display();
  } catch (std::exception e) {
    std::cout << "error" << std::endl;
  }
  //  (lol - kek).display();

    //(mat + lol).display();
  //  res1->display();
    //AVar *res2 = (*lol - *kek * *kek);
   // res2->display();
    return (0);
}