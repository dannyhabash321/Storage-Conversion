// Author: Danny Habash
// Course: COSC 2425 
// Program Set 1 
// Comments: None 

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int main(){

    bool runAgain=true;
    float base10Size, base2Size;
    string unit;
    char runA;
    //stores corresponding units
    vector<string> unit2={"B", "KiB","MiB","GiB","TiB","PiB","EiB","ZiB"};
    vector<string> unit10={"B", "KB","MB","GB","TB","PB","EB","ZB"};
    unordered_map <string, int> map={ {"B", 1}, {"KB", 1},{"MB", 1}, {"GB", 1},{"TB", 1},{"PB", 1},{"EB", 1},{"ZB", 1}};
    
    while(runAgain){

        cout << "Enter the hard drive size: ";
        cin >> base10Size;
        cin >> unit;
        if(map.find(unit)==map.end()){
            cout<< "Provide correct Units in all caps!! Exitting program.";
            exit (1);
        }

        int unitIdx=0;
        //formula to convert units
        while(unit!=unit10[unitIdx]){
            base2Size = (base10Size*1000.0)/1024.0;
            base10Size=base2Size;
            unitIdx++;
        }
        //chooses the right units
        while(base2Size<1 && unitIdx >1){
            base2Size=base2Size*1024;
            unitIdx--;
        }
        //chooses the right units
        while(base2Size>1024 && unitIdx<unit2.size()-1 ){
            base2Size=base2Size/1024;
            unitIdx++;

        }

        cout << "The corresponding binary drive size: "<< base2Size<<" " << unit2[unitIdx]<<endl;

        cout << "Run again(Y/N): ";
        cin >> runA;
        
        //determines if running again
        if(tolower(runA)!='y') 
            runAgain=false;
    }
    



    return 0;
}
