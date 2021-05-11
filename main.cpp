#include <iostream>
#include <string>
#include <vector>
#include "Scale.h"

using namespace std;

// {Note::FFlat, "F-flat"},


using namespace std;

int main(){
    Algerian scale(Note::C);

    for(int i = 0; i < scale.size(); i++){
        cout << "Note: " << scale.getNote_toString(i) << endl;
    }

    return 0;
}
