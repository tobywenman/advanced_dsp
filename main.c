#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

uint_fast8_t data[] = {0,0,0,0,1,1,0,1,1,1,0,0,1,0,0,0}; 

uint_fast8_t risingEdgeDetector(uint_fast8_t data[], bool start, size_t len){
    bool lowFound = false;

    if (start){
        for (uint_fast8_t i=0; i<len; i++){
            if (data[i] == 0){
                if (!lowFound){
                    lowFound = true;
                }
            }
            else{
                if (lowFound){
                    return i;
                }
            }
        }
    }
    else{
        for (uint_fast8_t i=len; i>=0; i--){
            if (data[i] == 0){
                if (!lowFound){
                    lowFound = true;
                }
            }
            else{
                if (lowFound){
                    return i;
                }
            }
        }
    }
}

int main(){
    printf("%i\n",risingEdgeDetector(data,true,16));
    return 0;
}

