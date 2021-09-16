#include <iostream>
using namespace std;
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

void mini_max(int x[3][3]);
void print(int x[3][3]);
bool checker(int n,int x[3][3]);
bool full_checker(int x[3][3]);
int main(){
    int c;
    int x[3][3]={{0,0,0},
                {0,0,0},
                {0,0,0}};
    print(x);
    while(1){
        
        if(full_checker(x)==1){
            cout<<COLOR_MAGENTA "The End" COLOR_RESET;
            break;
        }
        cout<<COLOR_MAGENTA "Player X Please Enter number:\n" COLOR_RESET;
        cin>>c;
        switch (c)
        {
        case 0:
            x[0][0]=1;
            break;
        case 1:
            x[0][1]=1;
            break;
        case 2:
            x[0][2]=1;
            break;
        case 3:
            x[1][0]=1;
            break;
        case 4:
            x[1][1]=1;
            break;
        case 5:
            x[1][2]=1;
            break;
        case 6:
            x[2][0]=1;
            break;
        case 7:
            x[2][1]=1;
            break;
        case 8:
            x[2][2]=1;
            break;
        
        default:
            cout<<COLOR_MAGENTA "WRONG NUMBER!" COLOR_RESET;
            break;
        }
        print(x);
        cout<<"-----------------------"<<endl;
        /*if(full_checker){
            break;
        }*/
        if(checker(1,x) || checker(2,x)){
            if(checker(1,x)){
            cout<<COLOR_MAGENTA "Player X wins" COLOR_RESET;
            }
            break;
        }
        if(full_checker(x)==1){
            cout<<COLOR_MAGENTA "The End" COLOR_RESET;
            break;
        }
        cout<<COLOR_MAGENTA "Player O Plays:\n\n" COLOR_RESET;
        
        mini_max(x);
        if(checker(1,x) || checker(2,x)){
            break;
        }
    }

    
}
void print(int x[3][3]){
   
    int c=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x[i][j]==0){
                cout<<COLOR_BLUE "| " COLOR_RESET<<COLOR_GREEN <<c<< COLOR_RESET<<COLOR_BLUE " |" COLOR_RESET;
            }else if(x[i][j]==1){
                cout<<COLOR_BLUE "| " COLOR_RESET<<COLOR_RED "X" COLOR_RESET<<COLOR_BLUE " |" COLOR_RESET;
            }else if(x[i][j]==2){
                cout<<COLOR_BLUE "| " COLOR_RESET<<COLOR_YELLOW "O" COLOR_RESET<<COLOR_BLUE " |" COLOR_RESET;
            }
            c++;

        }
        cout<<COLOR_BLUE "\n---------------\n" COLOR_RESET;
    }
}
bool checker(int n,int x[3][3]){
    if((x[0][0]==n && x[1][1]==n && x[2][2]==n)
        || (x[0][2]==n && x[1][1]==n && x[2][0]==n)
        || (x[0][0]==n && x[0][1]==n && x[0][2]==n)
        || (x[1][0]==n && x[1][1]==n && x[1][2]==n)
        || (x[2][0]==n && x[2][1]==n && x[2][2]==n)
        || (x[0][0]==n && x[1][0]==n && x[2][0]==n)
        || (x[0][1]==n && x[1][1]==n && x[2][1]==n)
        || (x[0][2]==n && x[1][2]==n && x[2][2]==n)){
        return 1;
    }
    else{
        return 0;
    }
}
bool full_checker(int x[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x[i][j]==0){
                
                return 0;
                    
            }
        }
    }
    return 1;
  
}
void mini_max(int x[3][3]){
    int flag=0;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(x[i][j]==0){
                x[i][j]=2;
                if(checker(2,x)){
                    flag=1;
                    
                }
                if(flag==1){
                    break;
                }else{
                    x[i][j]=0; 
                }
            }
            
        }
        if(flag==1){
            
            break;
        }
    }
    if(flag==0){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(x[i][j]==0){
                    x[i][j]=1;
                
                    if(checker(1,x)){
                        x[i][j]=2;
                        flag=1;
                        
                    }
                    if(flag==1){
                        break;
                    }else{
                        x[i][j]=0; 
                    }
                }
                
                
            }
            if(flag==1){
                break;
            }
        }
        if(flag==0){
            while(1){
                int i=rand()%3;
                int j=rand()%3;
                if(x[i][j]==0){
                    x[i][j]=2;
                    break;
                }
            }

            flag=1;

        }
        
    }
    
   
    if(flag==1){
        print(x);
        if(checker(1,x)){
            cout<<COLOR_MAGENTA "Player X wins" COLOR_RESET;
        }else if(checker(2,x)){
            cout<<COLOR_MAGENTA"Player O wins";
        }
    }
    
    
}