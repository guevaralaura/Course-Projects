#include "cdcatalogue.cpp"
#include <iostream>





int main(){
    
    
    CDCatalogue first;
    CDCatalogue last;

    first.Insert(CD("KISS", "inCommon 1"));
    first.Insert(CD("KISS", "inCommon 2"));
    first.Insert(CD("Bang", "Different first 1"));
    first.Insert(CD("Bang", "Different first 2"));
    
    /*
    last.Insert(CD("KISS", "inCommon 1"));
    last.Insert(CD("KISS", "inCommon 2"));
    last.Insert(CD("Hello", "Different last 1"));
    last.Insert(CD("Hello", "Different last 2"));
    */
    
    int i;
    
    for(i=0;i<first.numcds;i++)
    {
        std::cout << first.cds[i].GetArtist() << " ";
        std::cout << first.cds[i].GetAlbum() << std::endl;
    }
    
    std::cout << endl;
    
    for(i=0;i<last.numcds;i++)
    {
        std::cout << last.cds[i].GetArtist() << " ";
        std::cout << last.cds[i].GetAlbum() << std::endl;
    }
    
    std::cout << endl << "Now inserting Super CdCatalogue" << endl << endl;
    
    CDCatalogue tester = last.Common(first);
    
    for(i=0;i<tester.numcds;i++)
    {
        std::cout << tester.cds[i].GetArtist() << " ";
        std::cout << tester.cds[i].GetAlbum() << std::endl;
    }
    
    
    std::cout << endl;
    
    
    return 0;
    
    
}