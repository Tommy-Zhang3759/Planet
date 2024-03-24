#include<iostream>
#include<cmath>
#include<vector>
//#define mapSizeX ((((unsigned double)(1)<<16)-1))
//#define mapSizeY ((((unsigned double)(1)<<16)-1))
#define ll long long
#define mapSizeX (8192) // blocks
#define mapSizeY (8192) // blocks
double blockL = 1000; // km, 1000 as minimum
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

vectorVar gravityField[mapSizeX][mapSizeY];

struct Planet{
    string name = "";
    double x = 0;//  km
    double y = 0;
    double mass = 0;// *10^20kg
    vectorVar velocity;
    // vectorVar gravityField;  create it as a array if needed
};

vector<Planet> planets;

double inline gFieldM(double x1, double y1, double x2, double y2){
    return pow(log10(abs(x1 - x2))+log10(abs(x1 - x2)), 10)+pow(log10(abs(y1 - y2))+log10(abs(y1 - y2)), 10);
}

double mapTra(int i){
    return i * blockL;
}

int griTra(double a){
    return a / blockL;
}

double gf[mapSizeX][mapSizeY];

void fresh(){
    for(int i = 0; i < mapSizeX; i++){ // grav field loader
        for(int j = 0; j < mapSizeY; j++){
            gravityField[i][j].x = 0;
            gravityField[i][j].y = 0;
            double blockPX =  mapTra(i) + blockL / 2;
            double blockPY =  mapTra(j) + blockL / 2;
            for(int k = 0; k < planets.size(); k++){
                double &x = planets[k].x;
                double &y = planets[k].y;
                double &m = planets[k].mass;
                double angle = atan((y - blockPY)/(x - blockPX));
                gravityField[i][j].x += (G * m / (gFieldM(x, y, blockPX, blockPY))) * cos(angle);
                gravityField[i][j].y += (G * m / (gFieldM(x, y, blockPX, blockPY))) * sin(angle);
                gf[i][j] += (G * m / (gFieldM(x, y, blockPX, blockPY)));
            }
            cout<<blockPX<<','<<blockPY<<','<<gf[i][j]<<','\
            <<sqrt(pow(gravityField[i][j].x,2)+pow(gravityField[i][j].y,2))<<','\
            <<gravityField[i][j].x<<','<<gravityField[i][j].y<<endl;
        }
        // cout<<endl;
    }
    for(int k = 0; k < planets.size(); k++){
        Planet &p = planets[k];
        int x = p.x, y = p.y;
        p.x += p.velocity.x*timeStep+0.5*gravityField[griTra(x)][griTra(y)].x*pow(timeStep, 2);
        p.y += p.velocity.y*timeStep+0.5*gravityField[griTra(x)][griTra(y)].y*pow(timeStep, 2);
    }
    
}

int main(){
    freopen("field.out", "w", stdout);
    Planet *sun = new Planet;
    sun->mass = 1000;
    sun->name = "Sun";
    sun->x = 100000/2;
    sun->y = 100000/2;
    planets.push_back(*sun);

    Planet *earth = new Planet;
    earth->mass = 1000;
    earth->name = "Earth";
    earth->x = 1000000/2;
    earth->y = 1000000/2;
    planets.push_back(*earth);

    for(int i = 0; i < 100; i++){
        fresh();
    }    
    // cout<<"done"<<endl;

    return 0;
}
