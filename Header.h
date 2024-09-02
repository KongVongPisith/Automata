#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <new>
using namespace std;
int sym;
///////////////////////////////////////////////////////////////(1)
struct NFA{
    string idNFA;
    string nameNFA;
    string usnameNFA;
    string stateNFA;
    string finalNFA;
    string symbolNFA;

    string newidNFA;
    string newnameNFA;
    string newusnameNFA;
    string newstateNFA;
    string newfinalNFA;
    string newsymbolNFA;
};NFA s;
//////////////////////////////////////////////////////////////(2)
struct DFA{
    string idDFA;
    string nameDFA;
    string usnameDFA;
    string stateDFA;
    string tripDFA;
    string finalDFA;
    string symbolDFA;

    string newidDFA;
    string newnameDFA;
    string newusnameDFA;
    string newstateDFA;
    string newfinalDFA;
    string newsymbolDFA;
};DFA df;
//////////////////////////////////////////////////////////////(3)
void color (int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void gotoxy(int x,int y){
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
////////////////////////////////////////////////////////////////(4)
void CountAndCancel();
void Login();
void Loading();
void DfaAndNfa();
void createNFA();
void head_all();
void displayNFA();
void TestStringNFA();
void diplayAll();
void deleteNFA();
void menuTESTSTRING();
void BackAndExitNFA();
void SaveAndInputNFA();
void inputAgain();
///////////////////////////////////////////////////////////////
void creadeDFA();
void TestStringDFA();
void diplayAllDFA();
void deleteDFA();
void head_all();
void displayTranDFA();
//////////////////
void SaveAndInputDFA();
void menuTESTSTRINGDFA();
void BackAndExitDFA();
///////////////////////////////////////////////////////////////
void CountAndCancel(){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int Set[] = {7,7,7};
    int counter =2;
    char key;
    while(1){
        gotoxy(33,15);
        SetConsoleTextAttribute(h,7);
        cout<<"...............................................";
        gotoxy(33,16);
        color(Set[0]);
        cout<<":                  COUNTINUE                  :";
        gotoxy(33,17);
        color(Set[1]);
        cout<<":                   CANCEL                    :";
        SetConsoleTextAttribute(h,7);
        gotoxy(33,18);
        cout<<"...............................................\n";

        key = _getch();
        if(key == 72 && (counter >=2 && counter <= 2)){
            counter=counter-1;
        }
        if(key == 80 && (counter >=1 && counter <= 1)){
            counter=counter+1;
        }
        if(key == '\r'){//carriage return
            if(counter == 1){
                system("cls");
                Loading();
                getch();
                system("cls");
            }
            if(counter == 2){
                system("cls");
                Login();
                getch();
                system("cls");
            }
        }
        Set[0] = 7;
        Set[1] = 7;

         if(counter == 1){
            Set[0] = 31;
        }if(counter == 2){
            Set[1] = 28;
        }
    }
        finish:
        system("cls");
}
void Login(){
    string username;
    string password;
while(1){
        gotoxy(33,3);
//        color(9);
//        cout<<"     ** WELCOME TO AUTOMATA AND ALGORITHM **\n";
        color(7);
        gotoxy(33,5);
        cout<<"               .................";
        gotoxy(33,6);
        cout<<"               :               :";
        gotoxy(50,6);
        color(9);
        cout<<"Login Account";
        color(7);
        gotoxy(33,7);
        cout<<"...............................................";
        gotoxy(33,8);
        cout<<":                                             :";
        gotoxy(33,9);
        cout<<":     Username:                               :";
        gotoxy(33,10);
        cout<<":     Password:                               :";
        gotoxy(33,11);
        cout<<":                                             :";
        gotoxy(33,12);
        cout<<":.............................................:";
        gotoxy(39,9);
        color(9);
        cout<<"Username: ";
        cin>>username;
        gotoxy(39,10);
        color(9);
        cout<<"Password: ";
        cin>>password;
        gotoxy(33,12);
        color(7);
        cout<<":.............................................:";

            if(username=="GroupB2"&& password=="2225"){
                gotoxy(33,13);
                cout<<":                                             :";
                color(2);
                gotoxy(49,13);
                cout<<"OKEY,IT'S CORRECT       ";
                color(7);
                gotoxy(33,14);
                cout<<"...............................................\n";
                CountAndCancel();
            }else if(username=="GroupB2" && password!="2225"){
                gotoxy(33,13);
                cout<<":                                             :";
                color(4);
                gotoxy(41,13);
                cout<<"NOT CORRECT PASSWORD,TRY AGAIN!!!";
                color(7);
                gotoxy(33,14);
                cout<<"...............................................\n";
                Login();
            }else if(username!="GroupB2" && password=="2225"){
                gotoxy(33,13);
                cout<<":                                             :";
                color(4);
                gotoxy(40,13);
                cout<<"NOT CORRECT USERNAME, TRY AGAIN!!!";
                color(7);
                gotoxy(33,14);
                cout<<"...............................................\n";
                Login();
            }else{
                gotoxy(33,13);
                cout<<":                                             :";
                color(4);
                gotoxy(45,13);
                cout<<"NOT CORRECT,TRY AGAIN!!!";
                color(7);
                gotoxy(33,14);
                cout<<"...............................................\n";
                Login();

            }
            system("paues");
        }
    }
void Loading(){
     color(7);
     cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t    loading......\n";
     char a=254, b=254;
     color(7);
     cout<<"\t\t\t\t\t\t    ";
     for (int i=0;i<=12;i++)
     cout<<a;
     color(10);
     cout<<"\r";
     color(10);
     cout<<"\t\t\t\t\t\t    ";
     for (int i=0;i<=12;i++){
     cout<<b;
     for (int j=0;j<1e8;j++); //You can also use sleep function instead of for loop
         Sleep(1);
     }
     color(7);
     system("cls");
     DfaAndNfa();
     getch();
     system("cls");
}
void DfaAndNfa(){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int Set[] = {7,7,7}; // DEFAULT COLORS
    int counter =2;
    char key;
    while(1){
        gotoxy(33,6);
        SetConsoleTextAttribute(h,4);
        cout<<"...................................................";
        gotoxy(33,7);
        cout<<":                    DFA & NFA                    :\n";
        gotoxy(33,8);
        cout<<"...................................................";
        gotoxy(33,9);
        SetConsoleTextAttribute(h,7);
        cout<<":                                                 :";
        gotoxy(33,10);
        color(Set[0]);
        cout<<":    1. CREATE NFA                                :";

        gotoxy(33,11);
        color(Set[1]);
        cout<<":    2. CREATE DFA                                :";

        gotoxy(33,12);
        color(Set[2]);
        cout<<":    3. EXIT                                      :";

        SetConsoleTextAttribute(h,7);
        gotoxy(33,13);
        cout<<"...................................................\n";

        key = _getch();
        if(key == 72 && (counter >=2 && counter <= 3)){
            counter=counter-1;
        }
        if(key == 80 && (counter >=1 && counter <= 2)){
            counter=counter+1;
        }
        if(key == '\r'){//carriage return
            if(counter == 1){
                system("cls");
                createNFA();
                system("cls");
                SaveAndInputNFA();
                getch();
                system("cls");
            }
            if(counter == 2){
                system("cls");
                creadeDFA();
                system("cls");
                SaveAndInputDFA();
                getch();
                system("cls");
            }
            if(counter == 3){
                system("cls");
                goto finish;
            }
        }
        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
         if(counter == 1){
            Set[0] = 31;
        }if(counter == 2){
            Set[1] = 31;
        }if(counter == 3){
            Set[2] = 28;
        }
    }
    finish:
    system("cls");
}
void menuTESTSTRING(){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); //set color
    int Set[] = {7,7,7,7,7,7,7}; // DEFAULT COLORS
    int counter =2;
    char key;
    while(1){
        gotoxy(33,7);
        SetConsoleTextAttribute(h,4);
        cout<<"...................................................";
        gotoxy(33,8);
        cout<<":                    MENU NFA                     :\n";
        gotoxy(33,9);
        cout<<"...................................................";
        gotoxy(33,10);
        SetConsoleTextAttribute(h,7);
        cout<<":                                                 :";
        gotoxy(33,11);
        color(Set[0]);
        cout<<":    1. TEST STRING NFA                           :";

        gotoxy(33,12);
        color(Set[1]);
        cout<<":    2. TRANSITION NFA                            :";

        gotoxy(33,13);
        color(Set[2]);
        cout<<":    3. VIEW ALL DATA  NFA                        :";

        gotoxy(33,14);
        color(Set[3]);
        cout<<":    4. DELETE DATA  NFA                          :";

        gotoxy(33,15);
        color(Set[4]);
        cout<<":    5. MINIMIZE                                  :";

        gotoxy(33,16);
        color(Set[5]);
        cout<<":    6. COUNTINE                                  :";

        gotoxy(33,17);
        color(Set[6]);
        cout<<":    7. EXIT                                      :";


        SetConsoleTextAttribute(h,7);
        gotoxy(33,18);
        cout<<"...................................................\n";

        key = _getch();
        if(key == 72 && (counter >=2 && counter <= 7)){
            counter=counter-1;
        }
        if(key == 80 && (counter >=1 && counter <= 6)){
            counter=counter+1;
        }
        if(key == '\r'){//carriage return
            if(counter == 1){
                system("cls");
                TestStringNFA();
                BackAndExitNFA();
                getch();
                system("cls");
            }
            if(counter == 2){
                system("cls");
                displayNFA();
                BackAndExitNFA();
                getch();
                system("cls");
            }
            if(counter == 3){
                system("cls");
                diplayAll();
                BackAndExitNFA();
                getch();
                system("cls");
            }
            if(counter == 4){
                system("cls");
                diplayAll();
                deleteNFA();
                BackAndExitNFA();
                getch();
                system("cls");
            }
            if(counter == 5){
                system("cls");
                BackAndExitNFA();
                getch();
                system("cls");
            }
            if(counter == 6){
                system("cls");
                DfaAndNfa();
                getch();
                system("cls");
            }
            if(counter == 7){
                system("cls");
                goto finish;
            }
        }
        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;
        Set[5] = 7;
        Set[6] = 7;
         if(counter == 1){
            Set[0] = 31;
            //Set[6] = 158;
        }if(counter == 2){
            Set[1] = 31;
            //Set[6] = 158;
        }if(counter == 3){
            Set[2] = 31;
            //Set[6] = 158;
        }if(counter == 4){
            Set[3] = 31;
           // Set[6] = 158;
        }if(counter == 5){
            Set[4] = 31;
           // Set[6] = 158;
        }if(counter == 6){
            Set[5] = 31;
           // Set[6] = 158;
        }if(counter == 7){
            Set[6] = 28;
           // Set[6] = 158;
        }
    }
        finish:
        system("cls");
}
void menuTESTSTRINGDFA(){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); //set color
    int Set[] = {7,7,7,7,7,7,7}; // DEFAULT COLORS
    int counter =2;
    char key;
    while(1){
        gotoxy(33,7);
        SetConsoleTextAttribute(h,4);
        cout<<"...................................................";
        gotoxy(33,8);
        cout<<":                    MENU DFA                     :\n";
        gotoxy(33,9);
        cout<<"...................................................";
        gotoxy(33,10);
        SetConsoleTextAttribute(h,7);
        cout<<":                                                 :";
        gotoxy(33,11);
        color(Set[0]);
        cout<<":    1. TEST STRING  DFA                          :";

        gotoxy(33,12);
        color(Set[1]);
        cout<<":    2. TRANSITION DFA                            :";

        gotoxy(33,13);
        color(Set[2]);
        cout<<":    3. VIEW ALL DATA DFA                         :";

        gotoxy(33,14);
        color(Set[3]);
        cout<<":    4. DELETE DATA  DFA                          :";

        gotoxy(33,15);
        color(Set[4]);
        cout<<":    5. MINIMIZE                                  :";

        gotoxy(33,16);
        color(Set[5]);
        cout<<":    6. COUNTINE                                  :";

        gotoxy(33,17);
        color(Set[6]);
        cout<<":    7. EXIT                                      :";


        SetConsoleTextAttribute(h,7);
        gotoxy(33,18);
        cout<<"...................................................\n";

        key = _getch();
        if(key == 72 && (counter >=2 && counter <= 7)){
            counter=counter-1;
        }
        if(key == 80 && (counter >=1 && counter <= 6)){
            counter=counter+1;
        }
        if(key == '\r'){//carriage return
            if(counter == 1){
                system("cls");
                TestStringDFA();
                BackAndExitDFA();
                getch();
                system("cls");
            }
            if(counter == 2){
                system("cls");
                displayTranDFA();
                BackAndExitDFA();
                getch();
                system("cls");
            }
            if(counter == 3){
                system("cls");
                diplayAllDFA();
                BackAndExitDFA();
                getch();
                system("cls");
            }
            if(counter == 4){
                system("cls");
                diplayAllDFA();
                deleteDFA();
                BackAndExitDFA();
                getch();
                system("cls");
            }
            if(counter == 5){
                system("cls");

                BackAndExitDFA();
                getch();
                system("cls");
            }
            if(counter == 6){
                system("cls");
                DfaAndNfa();
                getch();
                system("cls");
            }
            if(counter == 7){
                system("cls");
                goto finish;
            }
        }
        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        Set[3] = 7;
        Set[4] = 7;
        Set[5] = 7;
        Set[6] = 7;
         if(counter == 1){
            Set[0] = 31;
            //Set[6] = 158;
        }if(counter == 2){
            Set[1] = 31;
            //Set[6] = 158;
        }if(counter == 3){
            Set[2] = 31;
            //Set[6] = 158;
        }if(counter == 4){
            Set[3] = 31;
           // Set[6] = 158;
        }if(counter == 5){
            Set[4] = 31;
           // Set[6] = 158;
        }if(counter == 6){
            Set[5] = 31;
           // Set[6] = 158;
        }if(counter == 7){
            Set[6] = 28;
           // Set[6] = 158;
        }
    }
        finish:
        system("cls");
}
class Transition{
    public:
    string str;
    int cnt;
    string * list;
    void strTokenize() {
        comma ();
        char *cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());
        char *p = strtok(cstr, ",");
        int i = 0;
        list = new string[cnt];
        while (p != 0) {
            list[i] = p;
            i++;
            p = strtok(NULL, ",");
        }
    }
    void showList(){
        for (int i=0; i < cnt; i++)
            cout << list[i] << "  ";
    }
    private:

    void comma() {
        cnt = 1;
	size_t found = str.find(',');
        while (found != string::npos) {
            cnt++;
            found = str.find(',', found + 1);
    	}
     }

};
void BackAndExitNFA(){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); //set color
    int Set[] = {3,3,3}; // DEFAULT COLORS
    int counter =2;
    char key;
    while(1){
        gotoxy(45,20);
        SetConsoleTextAttribute(h,9);
        cout<<"...........................";
        gotoxy(45,21);
        color(Set[0]);
        cout<<":          BACK           :";
        gotoxy(45,22);
        color(Set[1]);
        cout<<":          EXIT           :";
        SetConsoleTextAttribute(h,9);
        gotoxy(45,23);
        cout<<"...........................\n";

        key = _getch();
        if(key == 72 && (counter >=2 && counter <= 2)){
            counter=counter-1;
        }
        if(key == 80 && (counter >=1 && counter <= 1)){
            counter=counter+1;
        }
        if(key == '\r'){//carriage return
            if(counter == 1){
                system("cls");
               menuTESTSTRING();
                getch();
                system("cls");
            }
            if(counter == 2){
                system("cls");
               goto finish;
            }
        }
        Set[0] = 3;
        Set[1] = 3;

         if(counter == 1){
            Set[0] = 158;
        }if(counter == 2){
            Set[1] = 156;
        }
    }
        finish:
        system("cls");
}
void BackAndExitDFA(){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); //set color
    int Set[] = {3,3,3}; // DEFAULT COLORS
    int counter =2;
    char key;
    while(1){
        gotoxy(45,20);
        SetConsoleTextAttribute(h,9);
        cout<<"...........................";
        gotoxy(45,21);
        color(Set[0]);
        cout<<":          BACK           :";
        gotoxy(45,22);
        color(Set[1]);
        cout<<":          EXIT           :";
        SetConsoleTextAttribute(h,9);
        gotoxy(45,23);
        cout<<"...........................\n";

        key = _getch();
        if(key == 72 && (counter >=2 && counter <= 2)){
            counter=counter-1;
        }
        if(key == 80 && (counter >=1 && counter <= 1)){
            counter=counter+1;
        }
        if(key == '\r'){//carriage return
            if(counter == 1){
                system("cls");
                menuTESTSTRINGDFA();
                getch();
                system("cls");
            }
            if(counter == 2){
                system("cls");
               goto finish;
            }
        }
        Set[0] = 3;
        Set[1] = 3;

         if(counter == 1){
            Set[0] = 158;
        }if(counter == 2){
            Set[1] = 156;
        }
    }
        finish:
        system("cls");
}
void SaveAndInputNFA(){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); //set color
    int Set[] = {3,3,3}; // DEFAULT COLORS
    int counter =2;
    char key;
    while(1){
        gotoxy(45,10);
        SetConsoleTextAttribute(h,2);
        cout<<"INPUT COMPLETED,CON OR NOT? ";
        gotoxy(45,11);
        SetConsoleTextAttribute(h,9);
        cout<<"...........................";
        gotoxy(45,12);
        color(Set[0]);
        cout<<":        CONTINUE         :";
        gotoxy(45,13);
        color(Set[1]);
        cout<<":       INPUT AGAIN       :";
        SetConsoleTextAttribute(h,9);
        gotoxy(45,14);
        cout<<"...........................\n";

        key = _getch();
        if(key == 72 && (counter >=2 && counter <= 2)){
            counter=counter-1;
        }
        if(key == 80 && (counter >=1 && counter <= 1)){
            counter=counter+1;
        }
        if(key == '\r'){//carriage return
            if(counter == 1){
                system("cls");
                menuTESTSTRING();
                getch();
                system("cls");
            }
            if(counter == 2){
                system("cls");
                createNFA();
                getch();
                system("cls");
            }
        }
        Set[0] = 3;
        Set[1] = 3;
         if(counter == 1){
            Set[0] = 158;
        }if(counter == 2){
            Set[1] = 156;
        }
    }
    finish:
    system("cls");
}
void SaveAndInputDFA(){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); //set color
    int Set[] = {3,3,3}; // DEFAULT COLORS
    int counter =2;
    char key;
    while(1){
        gotoxy(45,10);
        SetConsoleTextAttribute(h,2);
        cout<<"INPUT COMPLETED,CON OR NOT? ";
        gotoxy(45,11);
        SetConsoleTextAttribute(h,9);
        cout<<"...........................";
        gotoxy(45,12);
        color(Set[0]);
        cout<<":        CONTINUE         :";
        gotoxy(45,13);
        color(Set[1]);
        cout<<":       INPUT AGAIN       :";
        SetConsoleTextAttribute(h,9);
        gotoxy(45,14);
        cout<<"...........................\n";

        key = _getch();
        if(key == 72 && (counter >=2 && counter <= 2)){
            counter=counter-1;
        }
        if(key == 80 && (counter >=1 && counter <= 1)){
            counter=counter+1;
        }
        if(key == '\r'){//carriage return
            if(counter == 1){
                system("cls");
                menuTESTSTRINGDFA();
                getch();
                system("cls");
            }
            if(counter == 2){
                system("cls");
                creadeDFA();
                getch();
                system("cls");
            }
        }
        Set[0] = 3;
        Set[1] = 3;
         if(counter == 1){
            Set[0] = 158;
        }if(counter == 2){
            Set[1] = 156;
        }
    }
    finish:
    system("cls");
}
//////////////////////////////////////////////////////////////////////////////////////////////////(6)
Transition **trans;
    string *states, *final, str, input,temp[100],current[100],**transitionV2,*trap,tmp;
    char  *alf,id[100],name[100], tempV2;
    int nots,nos, nofs, noa, i, j, k, x, y, z, f, flag, cnt, temp_last, curr_last,couter=0,transition=0,currentV2;
//////////////////////////////////////////////////////////////////////////////////////////////////(6)


//////////////////////////////////////////////////////////////////////////////////////////////////(7)
//    string *states, *final, *trap, **transitionV2,input, tmp;
//    char *alf, temp,id[100],name[100];
//    int nos, nots, nofs, noa, i, j, current, flag;
//////////////////////////////////////////////////////////////////////////////////////////////////(7)
void createNFA(){
    fstream NFA;
    NFA.open("DataNFA.txt", ios::app);
    color(4);
    cout<<"\n\t\t\t\t...................................................\n";
    cout<<"\t\t\t\t:                   CREATE NFA                    :\n";
    cout<<"\t\t\t\t...................................................\n";
    color(7);
    cout<<"\n\t\t\t\tEnter file name:\n";
    color(2);
    cout<<"\t\t\t\t> ";
    cin>>name;
    color(7);
    cout<<"\t\t\t\tEnter ID:\n";
    color(2);
    cout<<"\t\t\t\t> ";
    cin>>id;
    color(7);
    cout<<"\t\t\t\tEnter the total number of states:";
    cin>>nos;
    states = new string[nos];

    NFA<<id<<"\t\t"<<name<<"\t\t";
    cout<<"\t\t\t\tEnter the states (enter the start state first)\n";
    for (i = 0; i < nos; i++){
        color(2);
        cout<<("\t\t\t\t> ");
        cin>>states[i];
        NFA<<states[i];
    }
    color(7);
    cout<<"\t\t\t\tEnter the number of final states :";
    cin>>nofs;
    final = new string[nofs];
	cout<<"\t\t\t\tEnter the final states\n";
    NFA<<"\t\t\t";
    for (i = 0; i<nofs; i++){
        color(2);
        cout<<("\t\t\t\t> ");
        cin>>final[i];
        NFA<<final[i];
    }
    color(7);
    cout<<"\t\t\t\tEnter the number of symbols in the alphabet : ";
    cin>>noa;
    alf = new char[noa];
    cout<<"\t\t\t\tEnter the symbols for the alphabet:\n";
    NFA<<"\t\t";
    for (i = 0; i < noa; i++){
        color(2);
        cout<<("\t\t\t\t> ");
        cin>>alf[i];
          NFA<<alf[i];
    }
    NFA<<endl;

    color(7);
    trans = new Transition*[nos];
    for (j = 0; j < nos; j++){
          trans[j] = new Transition[noa];
    }
    cout<<"\t\t\t\tEnter the transition for the given states:\n";
    for (i = 0; i < nos; i++){
    color(7);
	cout<<"\n\t\t\t\tFor state: ";
    color(2);
	cout << states[i] << endl;
        for (j = 0; j < noa; j++){
            color(7);
       	    cout << "\t\t\t\tOn input symbol ";
            color(2);
       	    cout << alf[j];
            color(7);
       	    cout << " to state: ";
            color(2);
            cin >> trans[i][j].str;
            trans[i][j].strTokenize();

        }
    }
    NFA.close();
}
////////////////////////////////////////////////////////////////(7)
void displayNFA(){
    color(7);
    cout<<"\n\n\n\t\t\t\tThe transition table you entered is :\n";
    cout<<"\n\t\t\t\tstate\t";
    for (i=0; i<noa; i++){
        color(10);
        cout<<alf[i]<<"   ";
    }
    for (i=0; i<nos; i++){
    color(10);
    cout<<endl<<"\t\t\t\t"<<states[i] << "\t";
        for (j=0;j<noa;j++){
            color(4);
            trans[i][j].showList();"\t";
        }
    }
    color(7);
    cout<<"\n\n\t\t\t\tThe symbol is:( ";
    for (i=0; i<noa; i++){
        couter++;
        color(4);
        if(couter<noa){
        cout<<alf[i]<<" , ";
        }else{
        cout<<alf[i];
        color(7);
        cout<<" ).";
        }
    }
    couter=couter-noa;
    color(7);
    cout<<"\n\t\t\t\tThe State is :( ";
    for (i=0; i<nos; i++){
        couter++;
        color(4);
        if(couter<nos){
        cout<<states[i]<<" , ";
        }else{
        cout<<states[i];
        color(7);
        cout<<" ).";
        }
    }
    color(7);
    couter=couter-nos;
    cout<<"\n\t\t\t\tThe final is :( ";
    for (i=0; i<nofs; i++){
        couter++;
        color(4);
        if(couter<nofs){
        cout<<final[i]<<" , ";
        }else{
        cout<<final[i];
        color(7);
        cout<<" ).";
        }
    }
    couter=couter-nofs;
}
////////////////////////////////////////////////////////////////(8)
void TestStringNFA(){
while(true){
            color(7);
            cout<< "\n\n\t\t\t\tEnter the input string : ";
            cin >> input;
            if (input == "exit"){
                 menuTESTSTRING();
            }
            curr_last = 0;
            current[curr_last] = states[0];
            for (i=0; i<input.length(); i++){
                for (j = 0; j<noa; j++){
                    if (alf[j] == input[i])
                        break;
                }
                    temp_last = 0;
                for (k = 0; k <= curr_last; k++){
                        if (current[k] == "t")
                    for (x = 0; x < nos; x++)
                            if (states[x] == current[k])
                                break;
                        cnt = trans[x][j].cnt;
                        for (y = 0; y < cnt; y++){
                            str = trans[x][j].list[y];
                            flag = 0;
                            for (z = 0; z < temp_last; z++){
                                if (str == "t"){
                                    flag = 1;
                                    break;
                                }
                                if (temp[z] == str){
                                    flag = 1;
                                    break;
                                }
                            }
                            if (flag == 0){
                                temp[temp_last++] = str;
                            }
                        }
                    }
                    for (y = 0; y <= temp_last; y++){
                         current[y] = temp[y];
                    }
                    curr_last = temp_last - 1;
            }
            f = 0;
        for (i = 0; i <= curr_last; i++){
            for(j = 0; j < nofs; j++){
                if(final[j] == current[i]){
                    f = 1;
                }
            }
        }
        if (f==1){
             color(2);
            cout<<"\n\t\t\t\t>>>>The string has been accepted<<<<";
        }
        else if (f==0){
            color(4);
            cout<<"\n\t\t\t\t>>>>The string has been rejected<<<<";
        }
     }
}
void head_allV2(){
    color(2);
    gotoxy(20,5);
    cout<<".................................................................................";
    gotoxy(20,6);
    cout<<":    ID";
    gotoxy(32,6);
    cout<<":   NAME";
    gotoxy(48,6);
    cout<<":   N.O.STATE";
    gotoxy(68,6);
    cout<<":   N.O.F.STATE";
    gotoxy(88,6);
    cout<<":   SYMBOL  :"<<endl;
    gotoxy(20,7);
    cout<<".................................................................................";
    color(7);
}
////////////////////////////////////////////////////////////////(9)
void diplayAll(){
    fstream inNFA;
    inNFA.open("DataNFA.txt",ios::in);
    inNFA>>s.idNFA;
    inNFA>>s.nameNFA;
    inNFA>>s.stateNFA;
    inNFA>>s.finalNFA;
    inNFA>>s.symbolNFA;
    gotoxy(12,7);
    head_allV2();
int i=0;
while(!inNFA.eof()){
    gotoxy(20,8+i);
    cout<<":    "<<s.idNFA;
    gotoxy(32,8+i);
    cout<<":   "<<s.nameNFA;
    gotoxy(48,8+i);
    cout<<":   "<<s.stateNFA;
    gotoxy(68,8+i);
    cout<<":    "<<s.finalNFA;
    gotoxy(88,8+i);
    cout<<":    "<<s.symbolNFA<<endl;
    gotoxy(100,8+i);
    cout<<":";
    i++;
    inNFA>>s.idNFA;
    inNFA>>s.nameNFA;
    inNFA>>s.stateNFA;
    inNFA>>s.finalNFA;
    inNFA>>s.symbolNFA;
    };
    gotoxy(20,9+i-1);
    cout<<".................................................................................";
    inNFA.close();
}
////////////////////////////////////////////////////////////////(10)
void deleteNFA(){
    string d;
    int counterNFA=0;
    fstream inNFA1;
    fstream DeletNFA;
    inNFA1.open("DataNFA.txt",ios::in);
    DeletNFA.open("new1.txt",ios::out);
    inNFA1>>s.idNFA;
    inNFA1>>s.nameNFA;
    inNFA1>>s.stateNFA;
    inNFA1>>s.finalNFA;
    inNFA1>>s.symbolNFA;
    cout<<"\n\t\t\t\t\t\tDelete data by id:";
    cin>>d;
    if(d=="exit"|| d=="EXIT"){
        cout<<"\n\t\t\t\t\tNo delete";

    }
//    if(s.idNFA==d){
//        color(2);
//        cout<<"\n\t\t\t\t\tdelete";
//        color(7);
//    }else{
//        color(4);
//        cout<<"\n\t\t\t\t\tNo delete";
//        color(7);
//    }
    while(!inNFA1.eof()){
        if(s.idNFA!=d){
            color(4);
            cout<<"\n\t\t\t\tNo delete";
            color(7);
            DeletNFA<<s.idNFA<<"\t\t"<<s.nameNFA<<"\t\t"<<s.stateNFA<<"\t\t\t"<<s.finalNFA<<"\t\t"<<s.symbolNFA<<endl;
//            counterNFA=1;
        }else{
            color(2);
            cout<<"\n\t\t\t\tdeleted";
            color(7);
        }
        inNFA1>>s.idNFA;
        inNFA1>>s.nameNFA;
        inNFA1>>s.stateNFA;
        inNFA1>>s.finalNFA;
        inNFA1>>s.symbolNFA;
    }
    inNFA1.close();
    DeletNFA.close();
    if(remove("DataNFA.txt")!=0){
        cout<<"\t\t\t\t\t\tFile not remove.\n";
    }else{
        cout<<"\t\t\t\t\t\tFile removed.\n";
    }
    if(rename("new1.txt","DataNFA.txt")!=0){
        cout<<"\t\t\t\t\t\tfile no rename.\n";
    }else{
        cout<<"\t\t\t\t\t\tfile  renamed.\n";
    }
    ////////////////////////////////////////////////////////Delete in File
}
void edit(){
    string c;
    fstream inNFA2;
    fstream Edit;
    inNFA2.open("DataNFA.txt",ios::in);
    Edit.open("new1.txt",ios::out);
    inNFA2>>s.newidNFA;
    inNFA2>>s.newnameNFA;
    inNFA2>>s.newstateNFA;
    inNFA2>>s.newfinalNFA;
    inNFA2>>s.newsymbolNFA;
    cout<<" Enter id:";
    cin>>c;
    while(!inNFA2.eof()){
        if(s.newidNFA==c){
            Edit<<s.newidNFA<<"\t\t"<<s.newnameNFA<<"\t\t"<<s.newstateNFA<<"\t\t\t"<<s.newfinalNFA<<"\t\t"<<s.newsymbolNFA<<endl;
        }else{
        cout<<"\n\tEnter new file name:\n";
        color(2);
        cout<<"\t>";
        cin>>s.newnameNFA;
        color(7);
        cout<<"\tEnter new ID:\n";
        color(2);
        cout<<"\t>";
        cin>>s.newidNFA;
        color(7);
        cout<<"\tEnter the total number of states:";
        cin>>nos;
        states = new string[nos];

        Edit<<s.newidNFA<<"\t\t"<<s.newnameNFA<<"\t\t";
        states[0]=s.newstateNFA[0];
        cout<<"\tEnter the states (enter the start state first)\n";
        for (i = 0; i < nos; i++){
            color(2);
            cout<<("\t> ");
            cin>>states[i];
            states[i]=s.newstateNFA[i];
            Edit<<s.newstateNFA[i];
        }
        color(7);
        cout<<"\tEnter the number of final states :";
        cin>>nofs;
        final = new string[nofs];
        cout<<"\tEnter the final states\n";
        final[0]=s.newfinalNFA[0];
         Edit<<"\t\t\t";
        for (i = 0; i<nofs;i++){
            color(2);
            cout<<("\t> ");
            cin>>final[i];
            final[i]=s.newfinalNFA[i];
            Edit<<s.newfinalNFA[i];
        }
        color(7);
        cout<<"\tEnter the number of symbols in the alphabet : ";
        cin>>noa;
        alf= new char[noa];
        alf[0]=s.symbolNFA[0];
        cout<<"\tEnter the symbols for the alphabet:\n";
        Edit<<"\t\t";
        for (i = 0; i < noa; i++){
            color(2);
            cout<<("\t> ");
            cin>>alf[i];
            alf[i]=s.newsymbolNFA[i];
            Edit<<s.newsymbolNFA[i];
        }
        Edit<<endl;
        inNFA2>>s.newidNFA;
        inNFA2>>s.newnameNFA;
        inNFA2>>s.newstateNFA;
        inNFA2>>s.newfinalNFA;
        inNFA2>>s.newsymbolNFA;
    };
    inNFA2.close();
    Edit.close();
    if(remove("DataNFA.txt")!=0){
        cout<<"\n\tFile not remove";
    }else{
        cout<<"\n\tFile removed";
    }
    if(rename("new1.txt","DataNFA.txt")!=0){
        cout<<"\nfile no rename";
    }else{
        cout<<"\nfile  renamed\n";
    }
  }
}
void inputAgain(){////////////////////////////////////////////////////////Delete in File
    int counterAgain=0;
    fstream inAgain;
    fstream DeletAgain;
    inAgain.open("DataNFA.txt",ios::in);
    DeletAgain.open("new1.txt",ios::out);
    inAgain>>s.idNFA;
    inAgain>>s.nameNFA;
    inAgain>>s.stateNFA;
    inAgain>>s.finalNFA;
    inAgain>>s.symbolNFA;
    ////////////////////////////////////////////////////////Delete in File
    while(!inAgain.eof()){
        if(s.idNFA==s.idNFA){
            DeletAgain<<s.idNFA<<"\t\t"<<s.nameNFA<<"\t\t"<<s.stateNFA<<"\t\t\t"<<s.finalNFA<<"\t\t"<<s.symbolNFA<<endl;
             counterAgain=1;
        }else{

             counterAgain=0;
        }
        inAgain>>s.idNFA;
        inAgain>>s.nameNFA;
        inAgain>>s.stateNFA;
        inAgain>>s.finalNFA;
        inAgain>>s.symbolNFA;
    }
    if(counterAgain==0){
//        color(2);
//        cout<<"\n\t\t\t\tdelete";
    }else{
//        color(4);
//        cout<<"\n\t\t\t\tNo delete";
    }
    inAgain.close();
    DeletAgain.close();
    if(remove("DataNFA.txt")!=0){
        cout<<"\n\t\t\t\tFile not remove";
    }else{
        cout<<"\n\t\t\t\tFile removed";
    }
    if(rename("new1.txt","DataNFA.txt")!=0){
        cout<<"\n\t\t\t\tfile no rename";
    }else{
        cout<<"\n\t\t\t\tfile  renamed\n";
    }

}
//////////////////////////////////////////////////////////////////////////////////createDFA
void creadeDFA(){
    fstream DFA;
    DFA.open("DataDFA.txt",ios::app);
    color(4);
    cout<<"\n\t\t\t\t...................................................\n";
    cout<<"\t\t\t\t:                   CREATE DFA                    :\n";
    cout<<"\t\t\t\t...................................................\n";
    color(7);
    cout<<"\n\t\t\t\tEnter file name:\n";
    color(2);
    cout<<"\t\t\t\t> ";
    cin>>name;
    color(7);
    cout<<"\t\t\t\tEnter ID:\n";
    color(2);
    cout<<"\t\t\t\t> ";
    cin>>id;
    DFA<<id<<"\t\t"<<name<<"\t\t";
    color(7);
    cout<<"\t\t\t\tEnter the number of states:";
    cin>>nos;
    states = new string[nos];
    for (i = 0; i < nos; i++){
        color(2);
        cout<<"\t\t\t\t> ";
        cin>>states[i];
        DFA<<states[i];
    }
    color(7);
    cout<<"\t\t\t\tnumber of final states:";
    cin>>nofs;
    final = new string[nofs];
    DFA<<"\t\t\t";
    for (i = 0; i < nofs; i++){
        color(2);
        cout<<"\t\t\t\t> ";
        cin>>final[i];
        DFA<<final[i];
    }
    color(7);
    cout<<"\t\t\t\tEnter the trap states:";
    cin>>nots;
    trap = new string[nots];
    DFA<<"\t\t";
    if(nots==0){
        DFA<<"0";
    }else{
        for (i=0; i<nots; i++){
            color(2);
            cout<<"\t\t\t\t> ";
            cin>>trap[i];
            DFA<<trap[i];
        }
    }
    color(7);
    cout<< "\t\t\t\tEnter the symbol for the DFA:";
    cin>>noa;
    alf = new char[noa+1];
    DFA<<"\t\t";
    for(i = 0; i < noa; i++){
        color(2);
        cout<<"\t\t\t\t> ";
        cin>>alf[i];
        DFA<<alf[i];
    }
    DFA<<endl;
    transitionV2 = new string *[nos];
    for(i = 0; i < nos; i++){
         transitionV2[i] = new string[noa];
    }
    color(7);
    cout<<"\t\t\t\tEnter the transition for the given states:";
    for(i = 0; i < nos; i++) {
        cout<<"\n\t\t\t\tFor state:";
        color(2);
        cout<<states[i]<< endl;
        color(7);
        for(j = 0; j < noa; j++) {
            cout<<"\t\t\t\tOn input ";
            color(2);
            cout<<alf[j];
            color(7);
            cout<<" to state : ";
            color(2);
            cin>>transitionV2[i][j];
            color(7);
        }
    }
}
void displayTranDFA(){
    color(7);
    int couterDFA=0;
    cout<<"\n\n\n\t\t\t\tThe transition table you entered is :\n";
    cout<<"\t\t\t\tstate\t";
    for(i = 0; i<noa; i++){
        color(2);
        cout<<alf[i]<< "\t";
    }
    for(i = 0; i < nos; i++) {
        color(2);
        cout<<endl<<"\t\t\t\t"<<states[i]<<"\t";
        for(j=0; j<noa; j++){
            color(4);
            cout<<transitionV2[i][j]<<"\t";
        }
    }
    color(7);
    cout<<"\n\n\t\t\t\tThe symbol is:( ";
    for (i=0; i<noa; i++){
        couterDFA++;
        color(4);
        if(couterDFA<noa){
        cout<<alf[i]<<" , ";
        }else{
        cout<<alf[i];
        color(7);
        cout<<" ).";
        }
    }
    couterDFA=couterDFA-noa;
    color(7);
    cout<<"\n\t\t\t\tThe State is :( ";
    for (i=0; i<nos; i++){
        couterDFA++;
        color(4);
        if(couterDFA<nos){
        cout<<states[i]<<" , ";
        }else{
        cout<<states[i];
        color(7);
        cout<<" ).";
        }
    }
    color(7);
    couterDFA=couterDFA-nos;
    cout<<"\n\t\t\t\tThe final is :( ";
    for (i=0; i<nofs; i++){
        couterDFA++;
        color(4);
        if(couterDFA<nofs){
        cout<<final[i]<<" , ";
        }else{
        cout<<final[i];
        color(7);
        cout<<" ).";
        }
    }
    couterDFA=couterDFA-nofs;
}
void TestStringDFA(){
    while (true){
    currentV2 = 0, flag = 0;
    color(7);
    cout<<"\n\t\t\t\tEnter the input string : ";
    cin>>input;
  if(input.compare("exit") == 0){
           menuTESTSTRINGDFA();
  }
  for(i = 0; i < input.length(); i++){
            tempV2 = input.at(i);
      for(j = 0; j < noa; j++) {
          if (alf[j] == tempV2) {
              break;
          }
      }
            tmp = transitionV2[currentV2][j];
      for(int k = 0; k < nos; k++){
          if(states[k].compare(tmp) == 0) {
               currentV2 = k;
               break;
           }
       }
      for(j = 0; j < nots; j++){
          if (states[currentV2].compare(trap[j]) == 0) {
              flag = 1;
          }
      }
    }
    if(flag == 1){
            color(4);
            cout<<"\t\t\t\t>>>>The input string has been rejected<<<<";
    }
    for(i = 0; i < nofs; i++){
       if(states[currentV2].compare(final[i]) == 0) {
           color(2);
            cout<<"\t\t\t\t>>>>The string has been accepted<<<<";
                flag = 1;
        }
    }
    if(flag == 0){
            color(4);
            cout<<"\t\t\t\t>>>>The string has been rejected<<<<";
      }
  }
}
void head_all(){
    color(2);
    gotoxy(12,5);
    cout<<".....................................................................................................";
    gotoxy(12,6);
    cout<<":    ID";
    gotoxy(24,6);
    cout<<":   NAME";
    gotoxy(40,6);
    cout<<":   N.O.STATE";
    gotoxy(60,6);
    cout<<":   TRIP STATE";
    gotoxy(80,6);
    cout<<":   N.O.F.STATE";
    gotoxy(100,6);
    cout<<":   SYMBOL  :"<<endl;
    gotoxy(12,7);
    cout<<".....................................................................................................";
    color(7);
}
void diplayAllDFA(){
    fstream inDFA;
    inDFA.open("DataDFA.txt",ios::in);
    inDFA>>df.idDFA;
    inDFA>>df.nameDFA;
    inDFA>>df.stateDFA;
    inDFA>>df.tripDFA;
    inDFA>>df.finalDFA;
    inDFA>>df.symbolDFA;
    head_all();
int i=0;
while(!inDFA.eof()){
    gotoxy(12,8+i);
    cout<<":    "<<df.idDFA;
    gotoxy(24,8+i);
    cout<<":    "<<df.nameDFA;
    gotoxy(40,8+i);
    cout<<":  "<<df.stateDFA;
    gotoxy(60,8+i);
    cout<<":   "<<df.tripDFA;
    gotoxy(80,8+i);
    cout<<":   "<<df.finalDFA;
    gotoxy(100,8+i);
    cout<<":   "<<df.symbolDFA<<endl;
    gotoxy(112,8+i);
    cout<<":";
    i++;
    inDFA>>df.idDFA;
    inDFA>>df.nameDFA;
    inDFA>>df.stateDFA;
    inDFA>>df.tripDFA;
    inDFA>>df.finalDFA;
    inDFA>>df.symbolDFA;
    };
    gotoxy(12,9+i-1);
    cout<<".....................................................................................................";
    inDFA.close();
}
void deleteDFA(){
    string d;
    int counterDFA=0;
    fstream inDFA1;
    fstream DeletDFA;
    inDFA1.open("DataDFA.txt",ios::in);
    DeletDFA.open("newDFA.txt",ios::out);
    inDFA1>>df.idDFA;
    inDFA1>>df.nameDFA;
    inDFA1>>df.stateDFA;
    inDFA1>>df.tripDFA;
    inDFA1>>df.finalDFA;
    inDFA1>>df.symbolDFA;
    cout<<"\n\t\t\t\t\t\tDelete data by id:";
    cin>>d;
    if(d=="exit"|| d=="EXIT"){
        cout<<"\n\t\t\t\t\t\tExit No delete";
    }
    int c=0;
//    if(df.idDFA==d){
//        color(2);
//        cout<<"\n\t\t\t\t\t\tdelete";
//        color(7);
//        c=1;
//    }
//    if(c==0){
//        color(4);
//        cout<<"\n\t\t\t\t\t\tNo delete";
//        color(7);
//    }
    while(!inDFA1.eof()){
        if(df.idDFA!=d){
            color(4);
            cout<<"\n\t\t\t\t\t\tNo delete";
            DeletDFA<<df.idDFA<<"\t\t"<<df.nameDFA<<"\t\t"<<df.stateDFA<<"\t\t\t"<<df.tripDFA<<"\t\t"<<df.finalDFA<<"\t\t"<<df.symbolDFA<<endl;
            color(7);
        }else{
          color(2);
          cout<<"\n\t\t\t\t\t\tdeleted";
          color(7);
        }
        inDFA1>>df.idDFA;
        inDFA1>>df.nameDFA;
        inDFA1>>df.stateDFA;
        inDFA1>>df.tripDFA;
        inDFA1>>df.finalDFA;
        inDFA1>>df.symbolDFA;
    }
    inDFA1.close();
    DeletDFA.close();
    if(remove("DataDFA.txt")!=0){
        cout<<"\n\t\t\t\t\t\tFile not remove";
    }else{
        cout<<"\n\t\t\t\t\t\tFile removed";
    }
    if(rename("newDFA.txt","DataDFA.txt")!=0){
        cout<<"\n\t\t\t\t\t\tfile no rename";
    }else{
        cout<<"\n\t\t\t\t\t\tfile renamed\n";
    }
}
