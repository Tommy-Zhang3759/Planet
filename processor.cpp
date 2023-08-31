#include<iostream>
#include<cmath>
#include<vector>
//#define mapSizeX ((((unsigned long long)(1)<<16)-1))
//#define mapSizeY ((((unsigned long long)(1)<<16)-1))
#define mapSizeX ((((unsigned long long)(1)<<4)-1)) // 1
#define mapSizeY ((((unsigned long long)(1)<<4)-1)) // 1
#define timeStep (3600) // s
#define G (6.67e21) //N*km^2/(10^20kg)
#define Pi (acos(-1))
#define planetNumber (8)
using namespace std;
struct Gravity{
    double quantity = 99;
    double direction = 999999;// rad
};


struct Planet{
    string name = "";
    long long distanceFromTheSun = 5906400000;//  km
    double mapX = 0, mapY = 0;// km
    double mass = 0;// 10^20 kg
    double vDire = 0;// rad
    int vQuantitmap = 0;// km/s
    double planetGravitmapYProcesserQ(double mapX, double mapY){
        return G*this->mass/(((this->mapX - mapX)*(this->mapX - mapX)+(this->mapY - mapY)*(this->mapY - mapY)));// N/10^20kg
    }
    double planetGravitmapYProcesserD(double mapX, double mapY){
        double dir = atan((mapY - this->mapY)/(mapX - this->mapX));
        //cout<<dir<<' ';
        if (mapY < this->mapY || mapY == this->mapY && mapX < this->mapX){
            return dir + Pi;
        }else{
            return dir;
        }
    }
    Gravity planetGravityProcesser(double mapx, double mapy){
        Gravity* a = new Gravity;
        a->direction = this->planetGravitmapYProcesserD(mapx, mapy);
        a->quantity = this->planetGravitmapYProcesserQ(mapx, mapy);
        return *a;
    }
    double gravityEnv[3][3] = {};
};

vector<Planet> planets(planetNumber);

void vectorAdding(){

}

void gravityLoader(){
    int adapter[3] = {-1, 0, 1};
    vector<Planet>::iterator it1;       
    vector<Planet>::iterator it2;
    vector<Planet> planets_nextStep(planetNumber);
    for(it1 = planets.begin(); it1 != planets.end();){
        for(int i = 0; i < 3; i++){
            for(int j = 0; i < 3; i++){
                for(it2 = planets.begin(); it2 != planets.end();){
                    //vector adding;
                }
            }
        }
    }
}

void fresh(){
    int t = 0;
    int graD = 0;
    int graQ = 0;
    vector<Planet>::iterator it;
    vector<Planet> planets_nextStep(planetNumber);
    for(it = planets.begin(); it != planets.end();){
        while(t != timeStep){
            if((*it).vDire > 0 && (*it).vDire > Pi/2){
                
            }else if((*it).vDire > 0 && (*it).vDire > Pi/2){

            }else if((*it).vDire > 0 && (*it).vDire > Pi/2){

            }else if((*it).vDire > 0 && (*it).vDire > Pi/2){

            }
        }
    }
}

int main(){
    Planet *sun = new Planet;
    sun->mass = 1988500;
    /*for(int i = 0;i < mapSizeX/2; i++){
        for(int j = 0;j < mapSizeY/2; j++){
            //cout<<sun->planetGravityProcesserQ(i,j)<<' ';
        }
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
    for(int i = 0;i < mapSizeX/2; i++){
        for(int j = 0;j < mapSizeY/2; j++){
            cout<<sun->planetGravityProcesserD(i,j)<<endl;
        }
        cout<<endl;
    }*/

    //static Gravity (*gravity)[mapSizeY] = new Gravity[mapSizeX][mapSizeY];
    //auto gravity = new Gravity[mapSizeX][mapSizeY];
    //cout<<"end"<<endl<<endl<<gravity[9][9].quantity<<endl;
    
    //delete []gravity;
    cout<<"done";
    return 0;
}
