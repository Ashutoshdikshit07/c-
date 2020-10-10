#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

std::vector<std::string> readRecordFromFile(std::string file_name,std::string search_term);

int main()
{
    string search_term,filename;
   
    cout<<"enter file name"<<endl; // enter file name
    cin>>filename;

    cout<<"enter search word"<<endl;   // enter words
    cin>>search_term;

    std::vector<std::string> data= readRecordFromFile(filename,search_term); //calls the readRecord function

    return 0;
}


std::vector<std::string> readRecordFromFile(std::string file_name,std::string search_term)
{
    std::vector<std::string>records;
    std:: ifstream file;
    file.open(file_name);       //opens file

    bool found_record =false;   //initially value is defined false

    std::string field_one;      
    std::string field_two;

    while(getline(file,field_one,',') && !found_record)  //it gets the 1st field from the file
    {
        getline(file,field_two,'\n');   
        if(field_one==search_term)          //if it finds the match bool value is turned to true
        {
            found_record = true;
            records.push_back("yes");
            records.push_back(field_two);
        }
    
    } 
    if(!found_record)
    {
        cout<<"no";
    }

    std::cout<<records[0]<<" "<< records[1];
    return records;

}




































/*int main()
{
    char word[100],wordfile[100];
    fstream fin;
    fin.open("EnglishDictionary.csv", ios::in);
    cout<<"enter a word to search in the file";
    cin>>word;

    vector<string> row;
    string line, word ,temp;
    while(fin >> temp){
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,', ')){
            row.push_back(word);
            wordfile=row[0];
            if(wordfile==word)
            {
                cout<<"yes";
            }
        }
    }
}*/