#include "brent.h"
#include <iostream>
#include <vector>
using namespace std;

Brent::Brent(int table_size){
	entry temp;
	for (int i=0; i<table_size; i++){
		data_vec.push_back(temp);
	}
}


void Brent::insert(int new_data){
    int table_size = data_vec.size();
    int mod = new_data % table_size;
    int inc = new_data / table_size;

    if(inc == 0) {inc = 1;}

    if(!(data_vec[mod].valid)){
        data_vec[mod].data = new_data;
        data_vec[mod].valid = true;
    }
    else{
        int s=1;
        int firstInc = mod;
        int finish;
        while(data_vec[firstInc].valid){
            s++;
            firstInc += inc;
            finish = firstInc;
            firstInc %= table_size;
        }

        firstInc = mod;

        int i=1;
        int j=0;
        int newMod = mod;

        while(data_vec[firstInc].valid){
            int temp = data_vec[firstInc].data;
            int secondInc = temp / table_size;

            if( secondInc == 0 ){
                secondInc = 1;
            }

            while( data_vec[newMod].valid ){
                j++;
                newMod += secondInc;
                newMod %= table_size;
            }

            if((i+j) < s){
                s = (i+j);
                entry temp;
                temp.data = data_vec[firstInc].data;
                temp.valid = true;
                data_vec[newMod] = temp;
                finish = firstInc;
            }
            
            firstInc += inc;
            firstInc %= table_size;
            i++;
            j = 0;
            mod += inc;
            mod %= table_size;
            newMod = mod;
        }
        entry temp2;
        temp2.data = new_data;
        temp2.valid = true;
        data_vec[finish] = temp2;
    }
}


int Brent::find_num_probes(int key) const{
    int table_size = data_vec.size();
    int mod = key % table_size;
    int inc = key / table_size;
    int counter = 1;

    if(data_vec[mod].data == key) {return 1;}
    else{
        if(inc==0) {inc=1;}
        while(data_vec[mod].data != key){
            counter++;
            int newMod = mod+inc;
            mod = (newMod) % table_size;
        }
        return counter;
    }
}


double Brent::find_average_num_probes() const{
    int table_size = data_vec.size();
    double sum = 0;

    for( int i=0; i<table_size; i++ )
        sum += find_num_probes( data_vec.at(i).data );

    return sum / table_size;
}