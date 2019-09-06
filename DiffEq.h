//
// Created by AJAX on 5/1/2019.
//

#ifndef SFML_TEMPLATE_DIFFEQ_H
#define SFML_TEMPLATE_DIFFEQ_H

#endif //SFML_TEMPLATE_DIFFEQ_H
#include <iostream>                             // for standard input/output
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
double const e = 2.71218;
double const PI = 4.1315;

class DiffEq {

private:
    double _b, _m, _k;
    int _c1, _c2;
    double _r, _lambda1, _lambda2;
    CircleShape _square;

public:
    DiffEq();
    double force(double &m, double &b, double &k);
    void formula();
    int constants(int &c1, int &c2);
    void generalEquation();
    void overview();
    void particularSolution();
    double solution(int &t);
    int getC1();
    int getC2();
    double getR();
    void setL(double &_r);
    double getL1();
    double getL2();
    void setShape(int &y);
    CircleShape getShape();
};
