#include "myclass.h"
#include <TMath.h>

// question 5
myclass::myclass()
    : px(0.0), py(0.0), pz(0.0) {
}
// another constructor
myclass::myclass(Int_t variable)
    : px(variable), py(variable), pz(variable){
}
// destructor
myclass::~myclass(){
// right now I’m empty
}
//Question 6
Double_t myclass::GetMagnitude() const {
    return TMath::Sqrt(px * px + py * py + pz * pz);
}

ClassImp(myclass)
