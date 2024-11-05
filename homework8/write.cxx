#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>
#include "myclass.h"

void write(){

    const Int_t nEvents = 1000;

    TFile* file = new TFile("tree_file.root", "RECREATE");

    TTree* tree = new TTree("tree", "A tree with cusome class objects");

    myclass* obj = new myclass();
    tree->Branch("homework8", &obj);

for (Int_t i{0}; i<nEvents; i++){ 
    obj-> px = gRandom->Gaus(0,.02);
    obj-> py = gRandom->Gaus(0,.02);
    obj-> pz = gRandom->Gaus(0,.02);

    obj-> GetMagnitude();

    tree->Fill();
    }

tree->Write();
delete obj;
file->Close();
delete file;
}