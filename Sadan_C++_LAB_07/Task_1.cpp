#include <iostream>

float calculateRunRate(int runs , float overs);
int main(){
    int runs = 0;
    float overs= 0.0;

    std::cout<<"Enter total runs scored: "<<std::endl;
    std::cin>>runs;

    std::cout<<"Enter overs bowled: "<<std::endl;
    std::cin>>overs;

    std::cout<<"\033[34mCurrent\033[0m Run Rate = \033[31m"<<calculateRunRate(runs, overs)<<"\033[0m runs \033[34mper over\033[0m";

}

float calculateRunRate(int runs , float overs){
    return runs / overs;
}