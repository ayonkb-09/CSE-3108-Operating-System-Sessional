#include <bits/stdc++.h>
using namespace std;

int main()
{
    int frames, pages;

    cout << "Enter the number of frames: ";
    cin >> frames;

    cout << "Enter the number of pages in the incoming stream: ";
    cin >> pages;
 
    int incomingStream[pages];

    cout << "Enter the page reference string:";
    for(int i = 0; i < pages; i++) {
        cin >> incomingStream[i];
    }

    int temp[frames];
    int pageFaults = 0;
    int position = 0;

   
    for(int i=0;i<frames;i++) {
        temp[i]=-1;
    }

    cout<<endl<<"Incoming Frame1 Frame2 Frame3"<<endl;


    for(int i=0;i<pages;i++) {
        bool found=false;

        for(int j=0;j<frames;j++) {
            if(temp[j]==incomingStream[i]) {
                found=true;
                break;
            }
        }

        if(!found) {
            temp[position] = incomingStream[i];
            position = (position + 1) % frames;
            pageFaults++;
        }

        cout << incomingStream[i] << "        ";
        for(int j = 0; j < frames; j++) {
            if(temp[j] != -1)
                cout << temp[j] << "        ";
            else
                cout << "-        ";
        }
        cout << endl;
    }
    int hits=pages-pageFaults;
    float hitpercent=(hits*100.0f)/pages;
    float misspercent=(pageFaults*100.0f)/pages;


    cout <<endl<<"Total Page Faults:   " << pageFaults;
    cout << endl<<"Total Hits:   " << pages - pageFaults <<endl;
    cout<<setprecision(3);
    cout<< "Hit percentage:"<<hitpercent<<"%"<<endl;
    cout<< "Miss percentage:"<<misspercent<<"%"<<endl;

    return 0;
}
