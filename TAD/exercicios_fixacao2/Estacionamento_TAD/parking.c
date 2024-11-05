#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct parking{
    int *parkingSpaces;
    int ocuppiedSpaces;
    int totalCapacity;
};

typedef struct parking* T_Parking;

T_Parking createParking(int capacity);
bool enterParking(T_Parking parking, int carPlate);
int exitParking(T_Parking parking);
void showParking(T_Parking parking);
void destroyParking(T_Parking parking);

//Client code
int main(){

    int carPlate;
    T_Parking garage;

    garage = createParking(5);
    //NÃO PODE FAZER ISSO, É UMA QUEBRA DE TAD
    //garage->ocuppiedSpaces = 0;

    carPlate = 1234;
    printf("Entrou %d -> %s\n",carPlate,enterParking(garage,carPlate)?"Sim":"Não");

    carPlate = 2345;
    printf("Entrou %d -> %s\n",carPlate,enterParking(garage,carPlate)?"Sim":"Não");

    carPlate = 3456;
    printf("Entrou %d -> %s\n",carPlate,enterParking(garage,carPlate)?"Sim":"Não");

    carPlate = 4567;
    printf("Entrou %d -> %s\n",carPlate,enterParking(garage,carPlate)?"Sim":"Não");

    carPlate = 5678;
    printf("Entrou %d -> %s\n",carPlate,enterParking(garage,carPlate)?"Sim":"Não");

    carPlate = 6789;
    printf("Entrou %d -> %s\n",carPlate,enterParking(garage,carPlate)?"Sim":"Não");

    showParking(garage);

    printf("Saiu: %d\n",exitParking(garage));
    printf("Saiu: %d\n",exitParking(garage));
    printf("Saiu: %d\n",exitParking(garage));

    showParking(garage);

    carPlate = 1234;
    printf("Entrou %d -> %s\n",carPlate,enterParking(garage,carPlate)?"Sim":"Não");

    showParking(garage);

    destroyParking(garage);

    return 0;
}

T_Parking createParking(int capacity){
    T_Parking parkingPtr =  NULL;

    if(capacity>0){
        parkingPtr = malloc(sizeof(struct parking));

        if(parkingPtr != NULL){
            parkingPtr->totalCapacity = capacity;
            parkingPtr->ocuppiedSpaces = 0;

            parkingPtr->parkingSpaces = malloc(sizeof(int)*capacity);

            if(parkingPtr->parkingSpaces == NULL){
                free(parkingPtr);
                parkingPtr = NULL;
            }
        }

    }

    return parkingPtr;
}

bool enterParking(T_Parking parking, int carPlate){
    bool result = false;
    
    if(parking!=NULL){
        if(parking->ocuppiedSpaces < parking->totalCapacity){
            parking->parkingSpaces[parking->ocuppiedSpaces] = carPlate;
            parking->ocuppiedSpaces += 1;
            result = true;
        }
    }

    return result;
}

int exitParking(T_Parking parking){
    int carPlate = -1;

    if(parking != NULL){
        if(parking->ocuppiedSpaces>0){
            carPlate = parking->parkingSpaces[0];
            for(int i=0;i<parking->ocuppiedSpaces-1;i++){
                parking->parkingSpaces[i] = parking->parkingSpaces[i+1];
            }
            parking->ocuppiedSpaces -= 1;
        }
    }

    return carPlate;
}
void showParking(T_Parking parking){
    if(parking==NULL){
        printf("Estacionamento inválido.\n");
    }else{
        printf("Estacionamento: \n");
        for(int i=0;i<parking->ocuppiedSpaces;i++){
            printf("\t-:%04d\n",parking->parkingSpaces[i]);
        }
    }
}
void destroyParking(T_Parking parking){
    free(parking->parkingSpaces);
    free(parking);
}
