#include<iostream>
#include<cmath>
#include<vector>
//#define mapSizeX ((((unsigned double)(1)<<16)-1))
//#define mapSizeY ((((unsigned double)(1)<<16)-1))
#define ll long long
#define mapSizeX (((1<<4)-1)) // block
#define mapSizeY (((1<<4)-1)) // block
double blockL = 100000; // m, 1000 as minimum
#define timeStep (3600) // s
#define G (6.67e21) //N*km^2/(10^20kg)
#define Pi (acos(-1))
#define planetNumber (8)
using namespace std;

double mid(double a, double b){
    return (a+b)/2;
}

struct vectorVar{
    double x = 0, y = 0;
};

struct vectorCalc{
    vectorVar addition(vectorVar a, vectorVar b){
        vectorVar c;
        c.x = a.x + b.x;
        c.y = a.y + b.y;
        return c;
    }

    vectorVar multiplicationP(vectorVar a, double b){
        vectorVar c;
        c.x = a.x * b;
        c.y = a.y * b;
        return c;
    }
};

struct Planet{
    string name = "";
    double x = 0;//  km
    double y = 0;
    double mass = 0;// *10^20kg
    vectorVar velocity;
    // vectorVar gravityField;  create it as a array if needed
};

vector<Planet> planets;

double pythagorasTheorem(double a, double b){
    return sqrt(10 * (log10(a)+log10(a)+log10(b)+log10(b)));
}

double distBetweenPoints(double x1, double y1, double x2, double y2){
    return pythagorasTheorem(abs(x1 - x2), abs(y1 - y2));
}

double mapTra(int i){
    return i * blockL;
}

void fresh(){
    vectorVar gravityField[mapSizeX][mapSizeY];
    for(int i = 0; i < mapSizeX; i++){ // grav field loader
        for(int j = 0; j < mapSizeY; j++){
            gravityField[i][j].x = 0;
            gravityField[i][j].y = 0;
            for(double k = 0; k < planets.size(); k++){
                double blockPX =  mapTra(i) + blockL / 2;
                double blockPY =  mapTra(j) + blockL / 2;
                double &x = planets[k].x;
                double &y = planets[k].y;
                double &m = planets[k].mass;
                double angle = atan((y - blockPY)/(x - blockPX));
                gravityField[i][j].x += (G * m / (distBetweenPoints(planets[k].x, planets[k].y, blockPX, blockPY))) * cos(angle);
                gravityField[i][j].y += (G * m / (distBetweenPoints(planets[k].x, planets[k].y, blockPX, blockPY))) * sin(angle);
            }
            cout<<sqrt(pow(gravityField[i][j].x, 2) + pow(gravityField[i][j].y, 2)) / 1e27<<"  ";
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
