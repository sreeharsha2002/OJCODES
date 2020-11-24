#include<stdlib.h>
#include<assert.h>
#include<iostream>
using namespace std;

int main(){
    int t, leftrange, rightrange, guessed, is_guess_correct;
    cin >> t;
    // assert statements make sure the condition given in them is satisfied
    // it's not required, but it is a good practice.
    // Since this is interactive question, I would suggest you to write the assert queries in your codes
    // based on the constraints of the question so that it makes it easier for you to debug
    assert(t > 0);
    assert(t <= 10);
    while(t--){
        cin >> leftrange >> rightrange;
        guessed = rightrange;
        assert(leftrange <= rightrange);
        for(int i = leftrange; i <= rightrange; i++){
            cout << "MY " << i << endl; fflush(NULL);
            cin >> is_guess_correct;
            if(is_guess_correct){
                guessed = i;
                break;
            }
        }
        cout << "YOUR " << guessed << endl;
    }
    return 0;
}
