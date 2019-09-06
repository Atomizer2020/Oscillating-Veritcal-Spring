//
// Created by AJAX on 5/1/2019.
//

#include "DiffEq.h"

DiffEq::DiffEq() { //Default Constructor
}

double DiffEq::force(double &m, double &b, double &k) { //Setting mass, damping, spring constant & quadratic component
    _m = m;
    _b = b;
    _k = k;
    _r = (b * b) - 4 * m * k;
}
void DiffEq::formula() { //Printing initial equation to solve
    vector <string> output = {"(",")", "y''", "+","(" ,")", "y'+","(" ,")", "y", " = 0"};

    for (int i = 0; i < output.size(); i++){
        cout << output.at(i);
        if (i == 0){
            cout << _m;
        }
        if (i == 4){
            cout << _b;
        }
        if (i == 7){
            cout << _k;
        }
    }
}

int DiffEq::constants(int &c1, int &c2) { //Setting constants to the function/equation
    _c1 = c1;
    _c2 = c2;
}

void DiffEq::generalEquation() { //Printing general function/equation
    vector<string> regEqn = {"y(t)", "=", "c1", "*", "e^(", "*", "t", ")", "+", "c2", "*", "e^(", "*", "t", ")"};
    vector<string> oscEqn = {"y(t)", "=", "e^(", "*t)", "(", "c1*", "cos(", "t)", "+", "c2*", "sin(", "t)", ")"};
    cout << endl;
    setL(_r);
    if (_r > 0) { //Testing for overdamped
        for (int i = 0; i < regEqn.size(); i++) {
            cout << regEqn.at(i);
            if (i == 4) {
                cout << getL1();
            }
            if (i == 11) {
                cout << getL2();
            }
        }
    } else if (_r < 0) { //Testing if underdamped
        for (int i = 0; i < oscEqn.size(); i++) {
            cout << oscEqn.at(i);
            if (i == 2) {
                cout << getL1();
            }
            if (i == 6 || i == 10) {
                cout << getL2();
            }
        }
    } else if (_r == 0) { //Testing if critically damped
        for (int i = 0; i < regEqn.size(); i++) {
            cout << regEqn.at(i);
            if (i == 4) {
                cout << getL1();
            }
            if (i == 9) {
                cout << "*t";
            }
            if (i == 11) {
                cout << getL2();
            }
        }
    }
    cout << endl;
}
void DiffEq::overview() { //Brief overview of what the function will do
    if (_b == 0){
        cout << "The function is undamped. The spring will oscillate at a constant rate." << endl;
    } else if (_r > 0){
        cout << "The function is over-damped. The spring will decay with no oscillation." << endl;
    } else if (_r == 0){
        cout <<"The function critically damped. The spring will rapidly decay with no oscillation." << endl;
    } else if (_r < 0){
        cout <<"The function is under-damped. The spring will decay with oscillation." << endl;
    }
}

void DiffEq::particularSolution() { //Printing Particular solution of the function/equation
    vector<string> regEqn = {"y(t)", "=", "(", ")", "*", "e^(", "*", "t", ")", "+", "(", ")", "*", "e^(", "*", "t",
                             ")"};
    vector<string> oscEqn = {"y(t)", "=", "e^(", "t)", "(", "(", ")", "cos(", "t)", "+", "(", ")", "sin(", "t)", ")"};
    cout << endl;
    if (_r > 0) { //Setting overdamped equation
        for (int i = 0; i < regEqn.size(); i++) {
            cout << regEqn.at(i);
            if (i == 5) {
                cout << _lambda1;
            }
            if (i == 13) {
                cout << _lambda2;
            }
            if (i == 2) {
                cout << _c1;
            }
            if (i == 10) {
                cout << _c2;
            }
        }
    } else if (_r < 0) { //Setting underdamped equation
        for (int i = 0; i < oscEqn.size(); i++) {
            cout << oscEqn.at(i);
            if (i == 2) {
                cout << _lambda1;
            }
            if (i == 7 || i == 12) {
                cout << _lambda2;
            }
            if (i == 5) {
                cout << _c1;
            }
            if (i == 10) {
                cout << _c2;
            }
        }
    } else if (_r == 0) { //Setting critically damped equation
        for (int i = 0; i < regEqn.size(); i++) {
            cout << regEqn.at(i);
            if (i == 5) {
                cout << _lambda1;
            }
            if (i == 13) {
                cout << _lambda2;
            }
            if (i == 2) {
                cout << _c1;
            }
            if (i == 10) {
                cout << _c2;
                cout << "t";

            }
        }
    }
    cout << endl;

}

double DiffEq::solution(int &t) { //Finding the initial position of the function/equation
    double soln;

    if (_r > 0) {
        soln = (_c1 * pow(e, (_lambda1 * t))) + (_c2 * pow(e, (_lambda2 * t)));
    }
    if (_r < 0) {
        soln = (pow(e, (_lambda1 * t))) * ((_c1 * cos(_lambda2 * t * PI / 180)) + (_c2 * sin(_lambda2 * t * PI / 180)));
    }
    if (_r == 0) {
        soln = (_c1 * pow(e, (_lambda1 * t))) + (_c2 * t * pow(e, (_lambda2 * t)));
    }
    if (t == 0) {
        cout << "y(0)=" << soln << endl;
    }
    return soln;
}


int DiffEq::getC1() {
    return _c1;
};

int DiffEq::getC2() {
    return _c2;
};

double DiffEq::getR() {
    return _r;
}

void DiffEq::setL(double &_r) { //setting the decay/growth/oscillation coefficients
    if (_r > 0) { //function is decaying with no oscillation
        _lambda1 = (-_b + sqrt(_r)) / (2 * _m);
        _lambda2 = (-_b - sqrt(_r)) / (2 * _m);
    } else if (_r < 0) { //function is decaying with oscillation
        _lambda1 = (-_b) / (2 * _m);
        _lambda2 = (sqrt(-_r)) / (2 * _m);
    } else if (_r == 0) { // //function is decaying with no oscillation
        _lambda1 = (-_b) / 2 * _m;
        _lambda2 = _lambda1;
    }
}


double DiffEq::getL1() {
    return _lambda1;
}

double DiffEq::getL2() {
    return _lambda2;
}
void DiffEq::setShape(int &y) { //Sets the criteria for the mass-object

    if (y >= 640){
        y = 640 - (2*50);
    }
    _square.setRadius(50);
    _square.setPosition((320-50), (y-50));
    _square.setFillColor(Color::Magenta);
}
CircleShape DiffEq::getShape() {
    return _square;
}