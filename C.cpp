#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef struct{
	int a;
	int b;
	char D;
}Carro;

size_t N,M,C;

void direccion(Carro &);
Carro crear(int, int, char);
void printl(vector<Carro> &);
void colision_vertical(vector<Carro> &);
void colision_horizontal(vector<Carro> &);
size_t ASV_simulation(vector<Carro> &);

int main () {

	vector<Carro> simulacion;
    //*
    //N=5;M=6;C=7; //INPUT 1
    N=2;M=2;C=3; //INPUT 2 y 3
    //N=2;M=2;C=4; //VETICAL
    //*/

	/*
	cin>>N>>M>>C;
    size_t A,B;
    char D;
    for(size_t i=0; i<C; i++){
        cin>>A>>B>>D;
        simulacion.push_back(crear(A,B,D));
    }
    //*/
    /* INPUT 1
    simulacion.push_back(crear(2,2,'O'));
    simulacion.push_back(crear(3,2,'N'));
    simulacion.push_back(crear(4,2,'N'));
    simulacion.push_back(crear(4,5,'N'));
    simulacion.push_back(crear(2,6,'O'));
    simulacion.push_back(crear(5,5,'L'));
    simulacion.push_back(crear(2,4,'O'));
    //*/
    /* INPUT 2
    simulacion.push_back(crear(1,1,'L'));
    simulacion.push_back(crear(1,2,'O'));
    simulacion.push_back(crear(2,2,'N'));
    //*/
    //* INPUT 3
    simulacion.push_back(crear(1,1,'L'));
    simulacion.push_back(crear(1,2,'O'));
    simulacion.push_back(crear(2,1,'N'));
    //*/
    /* INPUT CHOQUE VERTICAL
    simulacion.push_back(crear(1,2,'N'));
    simulacion.push_back(crear(2,2,'S'));
    simulacion.push_back(crear(1,1,'S'));
    simulacion.push_back(crear(2,1,'N'));
    //*/
    cout<<C-ASV_simulation(simulacion)<<endl;

	return 0;
}

size_t ASV_simulation(vector<Carro> &v){

    size_t vehiculos = N>M?N:M;
    size_t choques = 0;

    while(vehiculos>0){
        for(size_t i = 0;i<v.size();i++){
            for(size_t j=i+1; j<v.size();j++){
                if((v[i].D=='N' && v[j].D=='S' || v[i].D=='S' && v[j].D=='N') && (v[i].b==v[j].b) && (v[i].a==v[j].a-1)){
                    v[i].D='C';
                    vector<Carro>::iterator it = v.begin()+j;
                    v.erase(it);
                    choques+=2;
                    j--;
                }
                else if((v[i].D=='O' && v[j].D=='L' || v[i].D=='L' && v[j].D=='O') && (v[i].a==v[j].a) && (v[i].b==v[j].b-1)){
                    v[j].D='C';
                    vector<Carro>::iterator it = v.begin()+i;
                    v.erase(it);
                    choques+=2;
                    j--;
                }
                else if(v[i].a==v[j].a && v[i].b==v[j].b){
                    v[i].D='C';
                    vector<Carro>::iterator it = v.begin()+j;
                    v.erase(it);//CHECAR***
                    choques+=2;
                    if(v[i].D=='C'||v[j].D=='C'){
                        choques--;
                    }
                }
            }
            direccion(v[i]);
            if((v[i].a<1||v[i].a>N) || (v[i].b<1||v[i].b>M)){
                vector<Carro>::iterator it = v.begin()+i;
                v.erase(it);
            }
        }
        vehiculos--;
        //printl(v);
    }
    return choques;
}

void direccion(Carro &c){

    if('N'==c.D){
        c.a--;
    }
    else if('S'==c.D){
        c.a++;
    }
    else if('L'==c.D){
        c.b++;
    }
    else if('O'==c.D){
        c.b--;
    }
}

Carro crear(int a, int b, char d){
    Carro c;
    c.a=a;
    c.b=b;
    c.D=d;
    return c;
}

void printl(vector<Carro> &v){
    for(size_t i=0; i<v.size(); i++){
        cout<<v[i].a<<' '<<v[i].b<<v[i].D<<endl;
    }
    cout<<"---------------------------"<<endl;
}
