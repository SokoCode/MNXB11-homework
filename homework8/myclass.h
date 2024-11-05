#ifndef __MYCLASS_H__
#define __MYCLASS_H__

class your_class : public TObject {
    public:
        your_class(); // default constructor
        your_class(Int_t variable); // some other constructor
        virtual ~your_class(); // destructor

    private:
        // some private members

    ClassDef(your_class, 1); // your_class
};


#endif // __MYCLASS_H__