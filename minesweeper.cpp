#include <iostream>
using namespace std;

enum sq{
    hid,rev,flag,mine
};

int main(){
    const int size=5;
    sq board[size][size];
    int m[size][size]={
        {0,0,1,0,0},
        {0,0,0,0,0},
        {0,1,0,1,0},
        {0,0,0,0,0},
        {1,0,0,0,0}
    };
    for (int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            board[i][j]=hid;
        }
    }

    bool gameover=false;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                              MINESWEEPER"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
    while(gameover==false){
        cout<<""<<endl;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(board[i][j]==hid)
                cout<<"[ ]";
                else if(board[i][j]==rev)
                cout<<"[O]";
                else if(board[i][j]==flag)
                cout<<"[F]";
                else if(board[i][j]==mine)
                cout<<"[X]";
            }
            cout<<endl;
        }
        int r,c,a;
        cout<<"Enter row(0 to 4): "<<endl;
        cin>>r;
        cout<<"Enter column(0 to 4): "<<endl;
        cin>>c;
        cout<<"To reveal press 1 and to flag press 2: "<<endl;
        cin>>a;

        if(r<0 || r>=size || c<0 || c>=size){
            cout<<"Invalid input!"<<endl;
            continue;
        }
        if (a==2)
        board[r][c]=flag;
        else if(a==1){
            if(m[r][c]==1){
                board[r][c]=mine;
                cout<<"Hit the mines. Game Over!"<<endl;
                gameover=true;
            }
            else {
                board[r][c]=rev;
                cout<<"Safe! Continue."<<endl;
            }
        }
    }
    cout <<"RESULT"<<endl;
    for(int i=0; i<size;i++){
        for(int j=0;j<size;j++){
            if(board[i][j]==mine)
            cout<<"[X]";
            else if(board[i][j]==1)
            cout<<"[*]";
            else 
            cout<<"[O]";
        }
        cout<<endl;
    }
}