//--------------Header Files------------
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdio.h>

//---------------Variables-------------
using namespace std;
unsigned int times,p_age,P_ID,p_bedno,p_vacsintim,List_no;
int choise4;
int Date_in[3];
int packets[5]={1,2,3,4,5};
int cho[3]={1,2,3};
float tot;
float Bread=60.00;
float String_Hoppers=40.00;
float pittu=55.00;
float Rice=80.00;
float roti=40.00;
float *bread;
float *S_hopper;
float *PITTU;
float *Ric;
float *Roti;
float Categ[5];
char choice,choice3;
char op[4]={1,2,3,4};
string p_NID,p_name,p_neig,city,province,gender,p_Vacsin_type,p_address,p_Vacsin,r_tellno,p_tellno;
string Username="Admin";
string Password="1234";

//------Function To Get Patient Basic Details------
void patientdata(unsigned int P_ID,unsigned int List_no,unsigned int p_bedno,string p_name,unsigned int p_age,string p_address,string city,string province,string p_NID,string p_tellno,string r_tellno,string p_neig,string p_Vacsin,unsigned int p_vacsintim,string p_Vacsin_type)
{
  int Date_in[3];
  cout<<"\nEnter Patient List Number ::> ";
  cin>>List_no;

    for(int i=0;i<times;i++)
    {
    cout<<"\nPatient ID                ::> ";
    cin>>P_ID;
    cout<<"Enter Patient Bed Number  ::> ";
     cin>>p_bedno;
    cout<<"\t\t\t  BD"<<p_bedno<<endl;
    cout<<"\nEnter Patient Name:>"<<endl;
    cout<<"\tEnter Name(with Initials)  :>";
     cin.ignore();
     getline(cin,p_name);
     input5:
    cout<<"\nEnter Patient Age          :>";
        while(!(cin>>p_age))
        {
         cout<<"\nPlease..Input Valid Details!"<<endl;
         cin.clear();
         cin.ignore(100, '\n');
        }
        if(p_age<=0||p_age>=120)
        {
         cout<<"Please..Enter Valid Details.!"<<endl;
         goto input5;
        }
        else{
            cout<<"Patient Age                :> "<<p_age<<"Years Old"<<endl;
        }
    cin.ignore();
    cout<<"\nEnter Address:>"<<endl;
    cout<<"\tAddress            :>";
     getline(cin,p_address);
    cout<<"\nEnter City                 :>";
     cin>>city;
    cout<<"Enter Province             :>";
     cin>>province;

     input13:
  //  cout<<"Patient National Id";
  //  cout<<" 1.Old ID"<<endl;
 //   cout<<" 2.New ID"<<endl;
 //   cout<<"Select ID Type:> ";
//    cin>>choise4;

//    switch(choise4){
  //    case
    cout<<"\nEnter Patient National ID  :>";
     while(!(cin>>p_NID))
        {
         cout<<"\nPlease..Input Valid Details!"<<endl;
         cin.clear();
         cin.ignore(10, '\n');
        }
    if(p_NID.length()>=10 && p_NID.length()<11)
    {
     cout<<"Patient National ID Number   :>"<<p_NID;
    }
    else
    {
     cout<<"Invalid ID Number..Plase Enter valid Details."<<endl;
     goto input13;
    }
     input6:
    cout<<"\nEnter Patient Mobile Number:>";
       while(!(cin>>p_tellno))
        {
         cout<<"\nPlease..Input Valid Details!"<<endl;
         cin.clear();
         cin.ignore(10, '\n');
        }
    if(p_tellno.length()>=10 && p_tellno.length()<11)
    {
     cout<<"Patient Mobile Number   :>"<<p_tellno;
    }
    else
    {
     cout<<"Invalid Phone Number..Plase Enter valid Details."<<endl;
     goto input6;
    }
    cin.ignore();
    gen:
    cout<<"\nEnter Patient Gender     :>";
     cin>>gender;
     if(gender=="Male"||gender=="male"||gender=="Female"||gender=="female"||gender=="MALE"||gender=="FEMALE"||gender=="other"||gender=="Other"||gender=="OTHER"){
     cout<<"\nPatient Gender          :>"<<gender<<endl;
     }
     else{
        cout<<"Please Enter Valid Details."<<endl;
        goto gen;
     }
    cout<<"\nEnter 1 Relative of the Patient:>";
     cin.ignore();
     getline(cin,p_neig);

     input12:
     cout<<"\nEnter Patient Relative Mobile Number:>";
    while(!(cin>>r_tellno))
        {
         cout<<"\nPlease..Input Valid Details!"<<endl;
         cin.clear();
         cin.ignore(10, '\n');
        }
     if(r_tellno.length()>=10 && r_tellno.length()<11)
    {
     cout<<"Patient Mobile Number   :>"<<r_tellno;
    }
    else
    {
     cout<<"Invalid Phone Number..Plase Enter valid Details."<<endl;
     goto input12;
    }

     cout<<"\nEnter Data Of Patient Was Admited:>"<<endl;
       cout<<"Date => ";
       cin>>Date_in[0];
       if(Date_in[0]>31){
        cout<<"\nEnter Wrong Date"<<endl;
       }
        cout<<"Mounth => ";
        cin>>Date_in[1];
        if(Date_in[1]>12){
        cout<<"\nEnter Wrong Date"<<endl;
       }
        cout<<"Year => ";
       cin>>Date_in[2];
    input7:
    cout<<"\nIs The Patient  get Vacsin ?:"<<endl;
    cout<<"\nEnter 'Yes' Or 'No'\n[ YES ]\n[ NO  ]"<<endl;
    cout<<"\nYour Answer => ";
     cin>>p_Vacsin;
     if(p_Vacsin=="yes"||p_Vacsin=="YES"||p_Vacsin=="Yes")
     {
       cout<<"\nVacsin Status::> YES"<<endl;
       cout<<"\nVacsination Times::> ";
       cin>>p_vacsintim;
       cout<<"\nEnter What Vacsin Type Patient Get::> ";
       cin.ignore();
       getline(cin,p_Vacsin_type);
     }
    else if (p_Vacsin=="No"||p_Vacsin=="NO"||p_Vacsin=="no")
    {
    cout<<"\nVacsin Status::> NO"<<endl;
    }
    else
    {
     cout << "\nYou Enter wrong input"<<endl;
    goto input7;
    }
    cout<<endl;
   //-------------Writing To text File------
    ofstream write;
    write.open("Patient.txt",ios::app);
    write<<"ID :"<<"A-PID"<<P_ID<<endl;
    write<<"---------------------~Patient Details~-------------------"<<endl;
    write<<"-------------"<<endl;
    write<<"+ Section A +"<<endl;
    write<<"-------------"<<endl;
    write<<"\nPatient List ==> "<<List_no<<endl;
    write<<"Patient Bed NO ==> "<<"BD"<<p_bedno<<endl<<endl;
    write<<"Patient  Name          : "<<p_name<<endl;
    write<<"Patient Age            : "<<p_age<<"Years Old "<<endl;
    write<<"Patient Full Address   : "<<p_address<<endl;
    write<<"Patient City           : "<<city<<endl;
    write<<"Patient Province       : "<<province<<endl;
    write<<"Patient National-ID No : "<<p_NID<<endl;
    write<<"Patient Mobile No      : "<<p_tellno<<endl;
    write<<"Patient Gender         : "<<gender<<endl;
    write<<"Patient Relative       : "<<p_neig<<endl;
    write<<"Relative Mobile No     : "<<r_tellno<<endl<<endl;
    write<<"Patient Vacsination States : "<<p_Vacsin<<endl;
    write<<"Patient Vacsination Times  : "<<p_vacsintim<<endl;
    write<<"Patient Vacsin Type        : "<<p_Vacsin_type<<endl<<endl;
    write<<"Patient Admited Date       : "<<Date_in[0]<<"/"<<Date_in[1]<<"/"<<Date_in[2]<<endl;
    write<<"+++++++++++++++++++++++++++++A++++++++++++++++++++++++++++"<<endl<<endl;
    write.close();
    write.open("List_NO.txt",ios::app);
    write<<List_no;
    write.close();
    write.open("Pid.txt",ios::app);
    write<<P_ID;
    write.close();
    cout<<"\nRecord Save Complete....."<<endl;
    }
}

//-----------Function to print Bill A---------------
void bill_A(){

    ofstream write;
    write.open("Bill.txt",ios::app);
    write << "\n\t\t\t ------------Set A-------------------------\t"<<endl;
    write  << "\t\t\t|            ~Breakfast~                     |"<<endl;
    write  << "\t\t\t| Food Item : Bread                          |"<<endl;
    write  << "\t\t\t| Qunty     : "<<packets[1]<<"Packets        |"<<endl;
    write  << "\t\t\t| Price     : "<<Categ[0]<<"R.s              |"<<endl;
    write  << "\t\t\t|                                            |"<<endl;
    write  << "\t\t\t| Food Item : String Hoppers                 |"<<endl;
    write  << "\t\t\t| Qunty     : "<<packets[2]<<"Packets        |"<<endl;
    write  << "\t\t\t| Price     : "<<Categ[1]<<"R.s              |"<<endl;
    write  << "\t\t\t|                                            |"<<endl;
    write  << "\t\t\t| Food Item : Pittu                          |"<<endl;
    write  << "\t\t\t| Qunty     : "<<packets[3]<<"Packets        |"<<endl;
    write  << "\t\t\t| Price     : "<<Categ[2]<<"R.s              |"<<endl;
    write  << "\t\t\t|                                            |"<<endl;
    write  << "\t\t\t| Total Price : Rs."<<tot<<"                 |"<<endl;
    write  << "\t\t\t|                                            |"<<endl;
    write  << "\t\t\t| Covid-19                                   |"<<endl;
    write  << "\t\t\t| Qurantine Zone Division 03                 |"<<endl;
    write  << "\t\t\t| Section-A                                  |"<<endl;
    write  << "\t\t\t -------------------------------------------\t"<<endl;
    write  << "\t\t\t                                            "<<endl;
    write.close();
    cout<<"Bill Print Successfull..."<<endl;

}

//-----------Function to print Bill B---------------
void bill_B(){
  ofstream write;
  write.open("Bill.txt",ios::app);
  write << "\n\t\t\t -----------------SetB---------------------\t"<<endl;
  write  << "\t\t\t|                ~Lunch~                     |"<<endl;
  write  << "\t\t\t| Food Item : Rice And Curry                 |"<<endl;
  write  << "\t\t\t| Qunty     : "<<packets[4]<<"Packets        |"<<endl;
  write  << "\t\t\t| Price     : "<<Categ[3]<<"R.s              |"<<endl;
  write  << "\t\t\t|                                            |"<<endl;
  write  << "\t\t\t| Food Item : Bread                          |"<<endl;
  write  << "\t\t\t| Qunty     : "<<packets[1]<<"Packets        |"<<endl;
  write  << "\t\t\t| Price     : "<<Categ[0]<<"R.s              |"<<endl;
  write  << "\t\t\t|                                            |"<<endl;
  write  << "\t\t\t| Total Price : Rs."<<tot<<"                 |"<<endl;
  write  << "\t\t\t|                                            |"<<endl;
  write  << "\t\t\t| Covid-19                                   |"<<endl;
  write  << "\t\t\t| Qurantine Zone Division 03                 |"<<endl;
  write  << "\t\t\t| Section-A                                  |"<<endl;
  write  << "\t\t\t -----------------------------------------\t"<<endl;
  write  << "\t\t\t                                            "<<endl;
  write.close();
  cout<<"Bill Print Successfull..."<<endl;

}

//-----------Function to print Bill C---------------
void bill_C(){
    ofstream write;
    write.open("Bill.txt",ios::app);
    write << "\n\t\t\t -----------------SetC---------------------\t"<<endl;
    write  << "\t\t\t|                ~Dinner~                    |"<<endl;
    write  << "\t\t\t| Food Item : Rice And Curry                 |"<<endl;
    write  << "\t\t\t| Qunty     : "<<packets[4]<<"Packets        |"<<endl;
    write  << "\t\t\t| Price     : "<<Categ[3]<<"R.s              |"<<endl;
    write  << "\t\t\t|                                            |"<<endl;
    write  << "\t\t\t| Food Item : Bread                          |"<<endl;
    write  << "\t\t\t| Qunty     : "<<packets[5]<<"Packets        |"<<endl;
    write  << "\t\t\t| Price     : "<<Categ[4]<<"R.s              |"<<endl;
    write  << "\t\t\t|                                            |"<<endl;
    write  << "\t\t\t| Total Price : Rs."<<tot<<"                 |"<<endl;
    write  << "\t\t\t|                                            |"<<endl;
    write  << "\t\t\t| Covid-19                                   |"<<endl;
    write  << "\t\t\t| Qurantine Zone Division 03                 |"<<endl;
    write  << "\t\t\t| Section-A                                  |"<<endl;
    write  << "\t\t\t -------------------------------------------\t"<<endl;
    write  << "\t\t\t                                            "<<endl;
    write.close();
    cout<<"Bill Print Successfull..."<<endl;
}

//----------Function To Read and Display Patient Details-----------
void Read(){
 ifstream read;
 read.open("Patient.txt",ios::in);
  if(read.is_open()){
     string line;
      while(getline(read,line)){
        cout<<line<<endl;
      }
      read.close();
   }
}

//----------Function To Login-----------
void log(string Username,string Password){
login:
cout<<"\t\t\t\t\t                                           "<<endl;
cout<<"\t\t\t\t<=*##########################################*=>"<<endl;
cout<<"\t\t\t\t         COVID-19 Corantine Zone Division 03        "<<endl;
cout<<"\t\t\t\t<=*##########################################*=>"<<endl<<endl<<endl;
cout<<"\t\t\t\t\t<=*+++++++++++++++*=>"<<endl;
cout<<"\t\t\t\t\t<=*+  Section A  +*=>"<<endl;
cout<<"\t\t\t\t\t<=*+++++++++++++++*=>"<<endl<<endl;

//----------Login-----------
cout<<"\t\t\t\t\t+==========================+"<<endl;
cout<<"\t\t\t\t\t ========================   "<<endl;
cout<<"\t\t\t\t\t        System Login        "<<endl;
cout<<"\t\t\t\t\t ========================   "<<endl;
cout<<"\t\t\t\t\t+==========================+"<<endl;
cout<<"\n\t\t\t\t\tEnter Username : ";
cin>>Username;
cout<<"\n\t\t\t\t\tEnter Password : ";
cin>>Password;
   if(Username!="Admin"||Password!="1234")
   {
   cout<<"\n\t\t\t\tSorry.!...Access Denied.(Please Enter Correct Username And Password)"<<endl;
   system("PAUSE");
   system("cls");
   goto login;
  }
}

//-----------------------Main Programm---------------------------
int main(){
system("color 9e");
std::cout<<std::setprecision(2)<<std::fixed;
log(Username,Password);
        input1:
        system("cls");
        cout<<"\t\t\t\t\t                                           "<<endl;
        cout<<"\t\t\t\t<=*##########################################*=>"<<endl;
        cout<<"\t\t\t\t         COVID-19 Corantine Zone Division 03        "<<endl;
        cout<<"\t\t\t\t<=*##########################################*=>"<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t<=*+++++++++++++++*=>"<<endl;
       cout<<"\t\t\t\t\t<=*+  Section A  +*=>"<<endl;
       cout<<"\t\t\t\t\t<=*+++++++++++++++*=>"<<endl<<endl;
     cout<<"\t\t\t\t\t+==========================+"<<endl;
     cout<<"\t\t\t\t\t ========================"<<endl;
     cout<<"\t\t\t\t\t        Wellcome         "<<endl;
     cout<<"\t\t\t\t\t ========================"<<endl;
     cout<<"\t\t\t\t\t+==========================+"<<endl<<endl;
cout<<"\t\t\t\t\t\t<== MainMenu ==>"<<endl<<endl;
cout<<"\t\t\t\t\t[ (1)=> Food Oders For Patient   ]"<<endl;
cout<<"\t\t\t\t\t[ (2)=> Patient Details          ]"<<endl;
cout<<"\t\t\t\t\t[ (3)=> Exit                     ]"<<endl<<endl;
cout<<"\t\t\t\t\tEnter your option : ";
cin>>op[1];

system("cls");
switch(op[1]){
   case '1':
            Oder_M:
            cout << "\n\t\t\t -----------------------------------------------------------"<<endl;
			cout << "\t\t\t|                      FOOD-Menu                           |"<<endl;
			cout << "\t\t\t -----------------------------------------------------------"<<endl;
			cout <<  "\t\t\t---------------------FOOD Packets--------------------------"<<endl;
			cout << "\n\t\t\t ------------Set A----------\t ------------Set B----------"<<endl;
			cout << "\t\t\t|        Breakfast          |\t|           Lunch           |"<<endl;
			cout << "\t\t\t| 1 : Bread                 |\t| 1 : Rice And Curry        |"<<endl;
			cout << "\t\t\t| 2 : String Hoppers        |\t| 2 : Bread                 |"<<endl;
			cout << "\t\t\t| 3 : Pittu                 |\t|                           |"<<endl;
			cout << "\t\t\t ---------------------------\t ---------------------------"<<endl;

			cout << "\n\t\t\t ------------Set C----------\t"<<endl;
			cout << "\t\t\t|        Dinner                 |"<<endl;
			cout << "\t\t\t| 1 : Rice And Curry            |"<<endl;
			cout << "\t\t\t| 2 : Pol Roti                  |"<<endl;
			cout << "\t\t\t|                               |"<<endl;
			cout << "\t\t\t ---------------------------\t  "<<endl;

			cout << "\t\t\t ---------------------------\t  "<<endl;
			cout << "\n\t\t\tPress 'E' To Go-To Main Menu  "<<endl;
			cout << "\t\t\t ---------------------------\t  "<<endl;

			cho_sel:
			cout << "\n\t\t\tChoose Set : ";
			cin >> choice;

			    system("cls");
			  	switch(choice){
				case 'A' :
				case 'a' :
                   Oder:
                   cout << "\n\t\t\t ------------Set A----------\t"<<endl;
			       cout << "\t\t\t|        Breakfast          |"<<endl;
			       cout << "\t\t\t| 1 : Bread                 |"<<endl;
			       cout << "\t\t\t| 2 : String Hoppers        |"<<endl;
			       cout << "\t\t\t| 3 : Pittu                 |"<<endl;
			       cout << "\t\t\t ---------------------------\t"<<endl;
				    cout<<"\nEnter Food Number To Oder :> ";
				    cin>>cho[1];
				    switch(cho[1]){
				      case 1 :
                        cout<<"\n 1 : Bread"<<endl;
                        cout<<"\n Price For 1 Packet = Rs.60.00"<<endl;
                        p1:
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[1];
                        if(packets[1]<=0){
                            cout<<"Please enter Valid Input"<<endl;
                             system("PAUSE");
                             goto p1;
                        }
                        bread=&Bread;
                        Categ[0]=*bread*packets[1];
                        cout<<"\nPrice Is :> Rs."<<Categ[0]<<endl;
                        cout<<"\nPress 'Y' to Oder Another Breakfast And 'N' To Continue"<<endl;
                        cin>>choice3;
                          if(choice3=='Y'||choice3=='y'){
                            goto Oder;
                          }
                          else if (choice3=='N'||choice3=='n'){
                            tot=Categ[0]+Categ[1]+Categ[2];
                            cout<<"\nTotal Price :> Rs."<<tot<<endl;
                             bill_A();
                            system("PAUSE");
                            system("cls");
                            goto Oder_M;
                          }
                      break;

                       case 2 :
                        cout<<"\n 2 : String Hoppers"<<endl;
                        cout<<"\n Price For 1 Packet = Rs.40.00"<<endl;
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[2];
                         p2:
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[2];
                        if(packets[2]<=0){
                            cout<<"Please enter Valid Input"<<endl;
                             system("PAUSE");
                             goto p2;
                        }
                        S_hopper=&String_Hoppers;
                        Categ[1]=*S_hopper*packets[2];
                        cout<<"\Price Is :> Rs."<<Categ[1]<<endl;
                        cout<<"\nPress 'Y' to Oder Another Breakfast And 'N' To Continue"<<endl;
                        cin>>choice3;
                          if(choice3=='Y'||choice3=='y'){
                            goto Oder;
                          }
                          else if (choice3=='N'||choice3=='n'){
                            tot=Categ[0]+Categ[1]+Categ[2];
                            cout<<"\nTotal Price :> Rs."<<tot<<endl;
                             bill_A();
                            system("PAUSE");
                            system("cls");
                            goto Oder_M;
                          }
                     break;

                       case 3 :
                        cout<<"\n 3 : Pittu"<<endl;
                        cout<<"\n Price For 1 Packet = Rs.55.00"<<endl;
                        cout<<"How Much Packet You Want :> ";
                        cin>>packets[3];
                         p3:
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[3];
                        if(packets[3]<=0){
                            cout<<"Please enter Valid Input"<<endl;
                             system("PAUSE");
                             goto p3;
                        }
                        PITTU=&pittu;
                        Categ[2]=*PITTU*packets[3];
                        cout<<"Price Is :> Rs."<<Categ[2]<<endl;
                        cout<<"\nPress 'Y' to Oder Another Breakfast And 'N' To Continue"<<endl;
                        cin>>choice3;
                          if(choice3=='Y'||choice3=='y'){
                            goto Oder;
                          }
                          else if (choice3=='N'||choice3=='n'){
                            tot=Categ[0]+Categ[1]+Categ[2];
                            cout<<"Total Price :> Rs."<<tot<<endl;
                            bill_A();
                            system("PAUSE");
                            system("cls");
                            goto Oder_M;
                          }
                     break;

                     default :cout << "\n\t\t\tYou Enter wrong input"<<endl;
                     goto Oder;
                     break;
				    }
                break;

                case 'B' :
				case 'b' :
                   Oder_2:
                   cout << "\n\t\t\t ------------Set B----------\t"<<endl;
			       cout << "\t\t\t|        Lunch                 |"<<endl;
			       cout << "\t\t\t| 1 : Rice And Curry           |"<<endl;
			       cout << "\t\t\t| 2 : Bread                    |"<<endl;
			       cout << "\t\t\t -----------------------------\t"<<endl;
				    cout<<"\nEnter Food Number To Oder :> ";
				    cin>>cho[2];
				    switch(cho[2]){
				      case 1 :
                        cout<<"\n 1 : Rice And Curry"<<endl;
                        cout<<"\n Price For 1 Packet = Rs.80.00"<<endl;
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[4];
                         p4:
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[4];
                        if(packets[4]<=0){
                            cout<<"Please enter Valid Input"<<endl;
                             system("PAUSE");
                             goto p4;
                        }
                        Ric=&Rice;
                        Categ[3]=*Ric*packets[4];
                        cout<<"\nPrice Is :> Rs."<<Categ[3]<<endl;
                        cout<<"\nPress 'Y' to Oder Another Breakfast And 'N' To Continue"<<endl;
                        cin>>choice3;
                          if(choice3=='Y'||choice3=='y'){
                            goto Oder_2;
                          }
                          else if (choice3=='N'||choice3=='n'){
                            tot=Categ[3]+Categ[0];
                            cout<<"\nTotal Price :> Rs."<<tot<<endl;
                            bill_B();
                            system("PAUSE");
                            system("cls");
                            goto Oder_M;
                          }
                      break;

                       case 2 :
                        cout<<"\n 1 : Bread"<<endl;
                        cout<<"\n Price For 1 Packet = Rs.60.00"<<endl;
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[1];
                         p5:
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[1];
                        if(packets[1]<=0){
                            cout<<"Please enter Valid Input"<<endl;
                             system("PAUSE");
                             goto p5;
                        }
                        bread=&Bread;
                        Categ[0]=*bread*packets[1];
                        cout<<"\nPrice Is :> Rs."<<Categ[0]<<endl;
                        cout<<"\nPress 'Y' to Oder Another Breakfast And 'N' To Continue"<<endl;
                        cin>>choice3;
                          if(choice3=='Y'||choice3=='y'){
                            goto Oder;
                          }
                          else if (choice3=='N'||choice3=='n'){
                            tot=Categ[3]+Categ[0];
                            cout<<"\nTotal Price :> Rs."<<tot<<endl;
                            bill_B();
                            system("PAUSE");
                            system("cls");
                            goto Oder_M;
                            }
                     break;
                     default :cout << "\n\t\t\tYou Enter wrong input"<<endl;
                     goto Oder_2;
                     break;
				    }

                break;

                case 'C':
				case 'c' :
                   Oder_3:
                   cout << "\n\t\t\t ------------Set C----------\t"<<endl;
			       cout << "\t\t\t|            Dinner            |"<<endl;
			       cout << "\t\t\t| 1 : Rice And Curry           |"<<endl;
			       cout << "\t\t\t| 2 : Pol Roti                 |"<<endl;
			       cout << "\t\t\t -----------------------------\t"<<endl;
				    cout<<"\nEnter Food Number To Oder :> ";
				    cin>>cho[3];
				    switch(cho[3]){
				      case 1 :
                        cout<<"\n 1 : Rice And Curry"<<endl;
                        cout<<"\n Price For 1 Packet = Rs.80.00"<<endl;
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[4];
                         p6:
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[1];
                        if(packets[1]<=0){
                            cout<<"Please enter Valid Input"<<endl;
                             system("PAUSE");
                             goto p6;
                        }
                        Ric=&Rice;
                        Categ[3]=*Ric*packets[4];
                        cout<<"\nPrice Is :> Rs."<<Categ[3]<<endl;
                        cout<<"\nPress 'Y' to Oder Another Breakfast And 'N' To Continue"<<endl;
                        cin>>choice3;
                          if(choice3=='Y'||choice3=='y'){
                            goto Oder_3;
                          }
                          else if (choice3=='N'||choice3=='n'){
                            tot=Categ[3]+Categ[4];
                            cout<<"\nTotal Price :> Rs."<<tot<<endl;
                            bill_C();
                            system("PAUSE");
                            system("cls");
                            goto Oder_M;
                          }
                      break;

                       case 2 :
                        cout<<"\n 2 : Pol Roti"<<endl;
                        cout<<"\n Price For 1 Packet = Rs.40.00"<<endl;
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[5];
                         p7:
                        cout<<"\nHow Much Packet You Want :> ";
                        cin>>packets[5];
                        if(packets[5]<=0){
                            cout<<"Please enter Valid Input"<<endl;
                             system("PAUSE");
                             goto p7;
                        }
                        Roti=&roti;
                        Categ[4]=*Roti*packets[5];
                        cout<<"\nPrice Is :> Rs."<<Categ[4]<<endl;
                        cout<<"\nPress 'Y' to Oder Another Breakfast And 'N' To Continue"<<endl;
                        cin>>choice3;
                          if(choice3=='Y'||choice3=='y'){
                            goto Oder_3;
                          }
                          else if (choice3=='N'||choice3=='n'){
                            tot=Categ[3]+Categ[4];
                            cout<<"\nTotal Price :> Rs."<<tot<<endl;
                            bill_C();
                            system("PAUSE");
                            system("cls");
                            goto Oder_M;
                            }
                     break;
                     default :cout << "\n\t\t\tYou Enter wrong input"<<endl;
                     goto Oder_3;
                     break;
				    }

                break;

                case 'E' :
				case 'e' :
				    goto input1;
                break;

                default :cout << "\n\t\t\tYou Enter wrong input"<<endl;
                system("PAUSE");
                system("cls");
			    goto Oder_M;
                break;
			  	}
     break;

   case '2':input2:
            cout<<"\n\t\t\t\t\t[1:Add Patients Details     ]"<<endl;
            cout<<"\t\t\t\t\t[2:View Patients Details    ]"<<endl;
            cout<<"\t\t\t\t\t[3:Go To Main Menu          ]"<<endl<<endl;
            cout<<"\t\t\t\tEnter Option Number To Proceade -> ";
            cin>>op[2];

              system("cls");
              switch(op[2]){
                 case '1':input3:
                          cout<<"\nHow many patients you wish to Add:";
                          cin>>times;
                          if(times<0||times>40)
                            {
                            cout<<"\nPlease Enter Valid Number(Between 1 and 10)"<<endl;
                            goto input3;
                            }
                          else
                            {
                             patientdata(P_ID,List_no,p_bedno,p_name,p_age,p_address,city,province,p_NID,p_tellno,r_tellno,p_neig,p_Vacsin, p_vacsintim,p_Vacsin_type);
                             input4:
                             cout<<"\nPress '1' To Go previous Menu Or '2' To Go Main Menu\n[ 1.Yes ]\n[ 2.No  ]"<<endl;
                             cout<<"Enter Your Choise to Prosede => ";
                             cin>>op[3];
                             system("cls");
                             if(op[3]=='1')
                                {
                                 goto input2;
                                }
                             else if (op[3]=='2')
                                {
                                 goto input1;
                                }
                             else
                                {
                                 cout<<"\nYou Enter wrong input"<<endl;
                                 goto input4;
                                }
                            }
                 break;

                case '2':
                       Read();
                       input8:
                        cout<<"\nPress '1' To Go previous Menu Or '2' To Go Main Menu\n[ 1.Yes ]\n[ 2.No  ]"<<endl;
                        cout<<"Enter Your Choice to Continue => ";
                        cin>>op[4];
                         system("cls");
                        if(op[4]=='1')
                                {
                                 goto input2;
                                }
                             else if (op[4]=='2')
                                {
                                 goto input1;
                                }
                             else
                                {
                                 cout<<"\nYou Enter wrong input"<<endl;
                                 goto input8;
                                }
                 break;

                case '3':goto input1;
                 break;

                default :cout << "\n\t\t\tYou Enter wrong input"<<endl;
			    goto input2;
			     break;
               }
    system("cls");
    case '3':
            cout<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			cout<<"\n\n\n\n\n\n\t\t\t\t\t      ~*Thank You...Have a Nice Day*~  +\n";
			cout<<"\t\t\t\t+++--Created By H.M.S.B.Sameranayaka HNDIT Full time--+++"<<endl;
			cout<<"\n\n\n\n\n\n                                                     "<<endl;
			cout<<"\t\t\t\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
			system("PAUSE");
			exit(EXIT_SUCCESS);;
     break;

    default :cout << "\n\n\t\t\t\t~You Enter wrong input~"<<endl;
    system("PAUSE");
    system("cls");
    goto input1;
    break;
   }

return 0;
}
