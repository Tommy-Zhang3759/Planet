#include<iostream>
#include<cmath>
#include<vector>
//#define mapSizeX ((((unsigned long long)(1)<<16)-1))
//#define mapSizeY ((((unsigned long long)(1)<<16)-1))
#define mapSizeX ((((long long)(1)<<4)-1)) // block
#define mapSizeY ((((long long)(1)<<4)-1)) // block
long long blockL = 100000; // m
#define timeStep (3600) // s
#define G (6.67e21) //N*km^2/(10^20kg)
#define Pi (acos(-1))
#define planetNumber (8)
using namespace std;

long long mid(long long a, long long b){
    return (a+b)/2;
}

struct vectorVar{
    long long x = 0, y = 0;
};

struct vectorCalc{
    vectorVar addition(vectorVar a, vectorVar b){
        vectorVar c;
        c.x = a.x + b.x;
        c.y = a.y + b.y;
        return c;
    }

    vectorVar multiplicationP(vectorVar a, long long b){
        vectorVar c;
        c.x = a.x * b;
        c.y = a.y * b;
    }
};

struct Planet{
    string name = "";
    long long x = 0;//  km
    long long y = 0;
    double mass = 0;// *10^20kg
    vectorVar velocity;
    // vectorVar gravityField;  create it as a array if needed
};

vector<Planet> planets;

double pythagorasTheorem(double a, double b){
    return sqrt(10 * (log10(a)+log10(a)+log10(b)+log10(b)));
}

void fresh(){
    vectorVar gravityField[mapSizeX][mapSizeY];

    for(long long i = 0; i < mapSizeX; i++){ // grav field loader
        for(long long j = 0; j < mapSizeY; j++){
            gravityField[i][j].x = 0;
            gravityField[i][j].y = 0;
            for(long long k = 0; k < planets.size(); k++){
                long long &x = planets[k].x;
                long long &y = planets[k].y;
                double &m = planets[k].mass;
                double angle = atan((double)(x)/(double)(y));
                gravityField[i][j].x += (G * m / (pow(x, 2) + pow(y, 2))) * cos(angle);
                gravityField[i][j].y += (G * m / (pow(x, 2) + pow(y, 2))) * sin(angle);
            }
            cout<<sqrt(pow(gravityField[i][j].x, 2) + pow(gravityField[i][j].y, 2))<<"  ";
        }
        cout<<endl;
    }

}

int main(){
    Planet *sun = new Planet;
    sun->mass = 1988500;
    sun->name = "sum";
    planets.push_back(*sun);
    cout<<"done"<<endl;
    fresh();
    return 0;
}
