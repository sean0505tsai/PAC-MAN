#include <fstream>
#include <iostream>
int main(void){
    std::ifstream ifs("maze00.map");
    int mapMatrix[34][28] = {0};
    for(int i=0; i<34; i++){
        for(int j = 0; j<28; j++){
            ifs>>mapMatrix[i][j];
        }
    }
    ifs.close();
    
    for(int i=0; i<34; i++){
        for(int j = 0; j<28; j++){
            std::cout<<mapMatrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
