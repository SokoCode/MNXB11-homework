#include <TFile.h>
#include <TTree.h>
#include <TH2F.h>
#include "myclass.h"

void read(){

    TFile* file =new TFile("tree_file.root", "READ");
    TTree* tree = (TTree*)file->Get("tree");

    myclass* obj = new myclass();

    tree->SetBranchAddress("homework8", &obj);

    TH2F* h2 = new TH2F("h2", "px vs py;px;py", 100, -0.1, 0.1, 100, -0.1, 0.1);

    Int_t nEntries = tree->GetEntries();
    
    for (Int_t i=0; i < nEntries; i++){
        tree->GetEntry(i);
        h2->Fill(obj->px, obj->py);
    }

    h2->Draw("COLZ");

    tree->Draw("px*py:pz", "obj->GetMagnitude() > 0.05");

    delete h2;
    delete obj;
    file->Close();
    delete file;
}