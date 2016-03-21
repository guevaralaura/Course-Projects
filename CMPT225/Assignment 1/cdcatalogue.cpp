#include "cdcatalogue.h"
#include <string>
#include <iostream>


void CDCatalogue::CopyArray(const CDCatalogue& cat)
{
    int i;
    
    
    maxsize = cat.maxsize;
    numcds = cat.numcds;
    CD* cd_copy = new CD[maxsize];
    
    for(i=0;i<numcds;i++)
        cd_copy[i] = cat.cds[i];
    
    cds = cd_copy;
}


// Default constructor
// Creates an empty CDCatalogue with default array size (4)
CDCatalogue::CDCatalogue()
{
    maxsize = 4;
    numcds = 0;
    cds = new CD[maxsize];    //cds array is allocated for space of 4 CD objects
}


// Copy constructor
// Creates a new CDCatalogue object,
// performs a deep copy of the cat parameter's fields
CDCatalogue::CDCatalogue(const CDCatalogue& cat)
{
    
    maxsize = cat.maxsize; //copies maxsize
    numcds = cat.numcds; //copies numcds
    CD* cd_copy = new CD[maxsize]; //cds array is allocated for space of maxsize objects
    int i; //initalizer for forloop
    
    for(i=0;i<numcds;i++)
        cd_copy[i] = cat.cds[i]; //copies elements of cds from cat into new array
    
    cds = cd_copy; //sets CD catalogues cds attribute to new deep copied array
}


// Destructor
// Releases all memory allocated to private pointer members
CDCatalogue::~CDCatalogue()
{
    maxsize = 0; //these 2 steps are not really neccisary but I included it anyways. Sets their values to 0
    numcds = 0;
    delete[] cds; //frees up memory of cds array
}




// Insert - performs a set insertion with the CD catalogue
// Inserts CD and returns true if CD is not already in the catalogue
// Does not insert and returns false if a CD with a matching artist and album name
//   already exists in the registry
// If the array is already filled before the insertion occurs, then
//   first create a new dynamic array double the size of the old array,
//   copy all CD objects from old array to new array,
//   deallocate memory associated with the old array,
//   and insert the new CD and return true.
// POST:  catalogue contains CD
// PARAM: disc = item to be inserted, its fields should not be empty string
// NOTE:  since overloaded assignment operator has not been defined,
//          "insertion" will mean updating all fields of the CD at the appropriate index
bool CDCatalogue::Insert(CD disc)
{

    int i; //initializer
    
    for(i=0;i<numcds;i++)
    {
        if( (disc.GetArtist()==cds[i].GetArtist()) && (disc.GetAlbum()==cds[i].GetAlbum()) )
            return false; //if statement checks to see if artist and album are already in catalogue, if found returns false
    }
    
    
    if(numcds==maxsize)
    {
        CD* new_cd_array = new CD[maxsize*2]; //allocates 2x maxsize for new cd array
        for(i=0;i<numcds;i++)
            new_cd_array[i] = cds[i]; //copies all CDs from cds to new cd array
        
        maxsize = maxsize*2; //doubles maxsize
        delete[] cds; //frees memory from old cd array of current object
        cds = new_cd_array; //objects cd array is now equal to the new cd array
    }
    
    cds[numcds] = disc; //inserts disk at last index
    numcds++; //increases number of cds in cdcatalogue
    
    
    
    return true;
}



// Remove - performs a set removal with the CD catalogue
// Removes a CD with all matching parameters if one exists in the catalogue
// Returns false if a CD with the same parameters does not exist in the catalogue
// POST:  catalogue does not contain CD
// PARAM: disc = item to be removed, its fields should not be empty string
// NOTE:  "removal" if successful will be done by updating the parameters of the
// CD at the appropriate index using the parameters of the CD in
// the last valid index of the collection; then decrements count and returns true;
bool CDCatalogue::Remove(CD disc)
{
    int i; //initializer
    
    if(numcds==0){      //just in case it was empty already
        return false;
    }
    
    for(i=0;i<numcds;i++)
    {
        //looks if artist and albumname match existing cd in catalogue
        if( (disc.GetArtist()==cds[i].GetArtist()) && (disc.GetAlbum()==cds[i].GetAlbum()) )
        {
            cds[i] = cds[numcds-1]; //replaces found cd with cd at last index
            numcds--; //reduces numcds count by 1
            return true; //quits function and returns true
        }
    }

    return false; //returns false if disc is not found in cds array
    
    //not sure if we should erase last index at cds array, I really don't think it matters because you shouldn't be able to access it.
}



// Locates the array index of a CD with matching parameters
// Returns -1 if no CD with matching parameters exists in the catalogue
// PARAM: disc = item to be located, its fields should not be empty string
int CDCatalogue::Find(CD disc) const
{

    int i; //initializer
    
    if(numcds==0){
        return -1;
    }
    
    for(i=0;i<numcds;i++)
    {
        //looks if artist and albumname match existing cd in catalogue
        if( (disc.GetArtist()==cds[i].GetArtist()) && (disc.GetAlbum()==cds[i].GetAlbum()) )
            return i; //returns the index of the CD
    }

    return -1;
}




// Removes all CDs from the catalogue with artist matching the provided argument
    // Returns false if there are not matching CDs or input is empty string,
    //   otherwise returns true if at least one CD is removed
    // Remaining items may appear in the array in any order, with the requirement that
    //   there are no "empty" spaces in the array (i.e. an array with 5 items must occupy indices 0-4)
    // POST:  catalogue contains no instances of CDs with the supplied artist name
    // PARAM: dontlikeanymore = name of artist whose CDs should be removed from the catalogue
bool CDCatalogue::Boycott(string dontlikeanymore)
{
	CD* cd_copy = new CD[maxsize]; //cds array is allocated for space of maxsize objects
    int new_numcds = 0; //amount of cds in cd_copy array
	int i; //initializer    

    if(numcds==0){
        return false;
    }

	if(dontlikeanymore=="") 	//checks if input was empty and returns false if it was
		return false;	
    
    for(i=0;i<numcds;i++)
    {
        if(dontlikeanymore != cds[i].GetArtist())
        {
            // copies cds that dont have the same artist name as dontlikeanymore into new array called
            cd_copy[i] = cds[i];
            new_numcds++;
            std::cout << "\nincreases new_numcds to "<< new_numcds << endl;
        }
            
    }

    if(new_numcds!=numcds)
    {
        delete[] cds; //frees memory for cds array
        cds=cd_copy; //sets cds to copy cd array
        numcds = new_numcds; //sets numcds to new amount of cds in array
        return true; //ends program
    }
	
	return false; //there were no changes in the array, meaning dontlikeanymore was not found for any cd
}

int CDCatalogue::Count() const
{
	return numcds; //self explanatory
}



// Returns the set union of this and cat
// POST: union contains CD of this and cat, with no duplicate CDs (both parameters matching).
CDCatalogue CDCatalogue::Join(const CDCatalogue& cat) const
{
    
    int i; //initializer
    CDCatalogue new_cd_cat(cat); //copies CDcatalogue cat

    
    for(i=0;i<numcds;i++)        //goes through all elements of this CDcatalogue
        new_cd_cat.Insert(cds[i]);       //calls insert function on new CDcatalogue, only adds if no
                                        //copies of cd's exist and increases size when neccissary
    
    return new_cd_cat;          //returns new CDcatalogue cat1
    
    
}



// Returns the set intersection of this and cat
// POST: intersection contains CDs in both this and cat (both parameters matching).
CDCatalogue CDCatalogue::Common(const CDCatalogue& cat) const
{
    
    int i, j; //initializers
    
    CDCatalogue new_cd_cat; //creates new CDcatalogue
    
    for(i=0;i<numcds;i++) //goes through cds in this
    {
        for(j=0;j<cat.numcds;j++) //goes through cds in cat
        {
             //if cds match each other from both CD classes
            if( (cat.cds[j].GetArtist()==cds[i].GetArtist()) && (cat.cds[j].GetAlbum()==cds[i].GetAlbum()) )
            {
                new_cd_cat.Insert(cds[i]);  //inserts cd into new CDcatalogue
                break;                   //ends 'cat' for loop because cd match was found
            }
        }

    }
    
    
    return new_cd_cat;                      //returns new CDcatalogue
    
}


// Returns the set difference of this and cat
// CDs in both catalogues must have a full set of matching parameters
//   for a CD to be removed in the split.
// POST: difference contains CDs in this but not also in cat
CDCatalogue CDCatalogue::Split(const CDCatalogue& cat) const
{
    int i, j; //initializers
    bool exists;
    
    CDCatalogue new_cd_cat; //creates new CDcatalogue
    
    for(i=0;i<numcds;i++) //goes through cds in this
    {
        exists = false; //'exists' starts off false and turns true if match is found
        
        for(j=0;j<cat.numcds;j++) //goes through cds in cat
        {
            //if cds match each other from both CD classes
            if( (cat.cds[j].GetArtist()==cds[i].GetArtist()) && (cat.cds[j].GetAlbum()==cds[i].GetAlbum()) )
            {
                exists = true;              //'exists' changes to true when a match is found
                break;                   //ends 'cat' for loop when a match is found
            }
        }
        
        if(!exists)
            new_cd_cat.Insert(cds[i]);
        
    }
    
    
    return new_cd_cat;                      //returns new CDcatalogue
}


