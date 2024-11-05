#ifndef __MYCLASS_H__
#define __MYCLASS_H__

#include <TObject.h>
#include <cmath>

class myclass : public TObject {
public:
    // Constructors and Destructor
    myclass();                    // Default constructor
    myclass(Int_t variable);      // Parameterized constructor
    virtual ~myclass();           // Destructor

 
    Double_t GetMagnitude() const;

    Double_t px;
    Double_t py;
    Double_t pz;

private:
    ClassDef(myclass, 1);
};

#endif // __MYCLASS_H__
