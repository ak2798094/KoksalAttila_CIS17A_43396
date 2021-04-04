#include <iostream>
#include <iomanip>

using namespace std;

struct MovieInfo {
    string movName;
    char *dirName;
    unsigned short yrRlsd;
    unsigned short runTime;
};

int main() {

    MovieInfo *mveInfo;
    int nMovies;

    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)."<<endl;
    cin>>nMovies;

    mveInfo=new MovieInfo[nMovies];

    for (int mvees=0;mvees<nMovies;mvees++) {
        cin.ignore();
        getline(cin,mveInfo[mvees].movName);
        int size=81;
        mveInfo[mvees].dirName=new char[size];
        cin.getline(mveInfo[mvees].dirName,size - 1);
        cin>>mveInfo[mvees].yrRlsd;
        cin>>mveInfo[mvees].runTime;

        cout<<left<<endl;
        cout<<setw(11)<<"Title:"<<mveInfo[mvees].movName<<endl;
        cout<<setw(11)<<"Director:"<<mveInfo[mvees].dirName<<endl;
        cout<<setw(11)<<"Year:"<<mveInfo[mvees].yrRlsd<<endl;
        cout<<setw(11)<<"Length:"<<mveInfo[mvees].runTime<<endl;
    }

    for (int mvees=0;mvees<nMovies;mvees++) {
        delete [] mveInfo[mvees].dirName;
    }
    delete [] mveInfo;

    return 0;
}
