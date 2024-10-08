void bubble(){

    int  continua, aux;

    do{
        continua = 0;
        for(int i=0;i<TAM-1;i++){
            if(v[i]>v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua=1;
            }
        }
    }while(continua!=0);
}
void selection(){

}
void insert(){

}
void merge(){

}
void quick(){
    
}