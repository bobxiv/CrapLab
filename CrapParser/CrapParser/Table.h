//Para almacenar Nombre Variable - Valor Variable
#include <map>

//Mapa con los 1)nombres de variable 2)valores de variables
//Lista de doubles
std::map<std::string,double> VarList_D;
//Lista de Vector de Doubles
std::map<std::string,Store::Vector<double>> VarList_VD;
//Lista de Matrix de Doubles
std::map<std::string,Store::Matrix<double>> VarList_MD;

bool not_print;