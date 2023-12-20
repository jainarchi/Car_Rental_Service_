#include <iostream>         
#include <ctime>
using namespace std;                                               



class Dur_Rent {
   public:
         int days;
           string brandName;
           int charge ;
           bool forbook;
    
    public :
        
   void duration(){
            cout<<"Enter number of days you require the Car rental service : ";
            cin >>days;
            cout<< endl;
   }
    
   
  void rental_charge(){
            
     if(brandName == "Maruthi" || brandName == "Hyundai" ||brandName == "BMW" || brandName ==  "Jaguar" ||brandName == "Buggati" ||brandName == "Roll-Royce"){  
         
         
             if(brandName == "Maruthi" || brandName == "Hyundai"){
                  charge = days*3000;
       
                  cout<< brandName <<" Rental charge for " << days<< " days :  Rs. "<< days*3000<<"/-"<<endl<<endl;
          
             }
       
             else if(brandName == "BMW" || brandName ==  "Jaguar"){
               charge= days*5000;
          
               cout<< brandName<<" Rental charge for " << days << " days :  Rs. "<< days*5000 <<"/-"<< endl<<endl;
         
               }
       
             else if(brandName == "Buggati" ||brandName == "Roll-Royce"){
               charge= days*10000;
           
               cout<< brandName <<" Rental charge for "<< days <<" days :  Rs. "<< days*10000 << "/-"<<endl<<endl;
           
              }
              
              cout<<"For booking our Car Rental Service(1 for Yes, 0 for No):";
              cin>>forbook;
              if(forbook==1){
                  cout<<"Yes"<<endl<<endl;
                  cout<<"*Please proceed with the rental process."<<endl;
                  
              }
              else if(forbook==0){cout<<"No"<< endl;
              }
              cout<<"---------------------------------------------------------->>"<<endl;
     } 
   
    else{
     cout<< "wrong entered";
       }
       
  }
  
    
};


class SelectCar : public Dur_Rent{
    
//   protected:
//       string brandName;
      
  public:
    
   void display_brand(){
       cout<<"\t<<Car Brand List>>"<< endl;
    
       cout<< "* Maruthi--------------------(Rs.3000/day)" << endl << "* Hyundai--------------------(Rs.3000/day)"<< endl <<"* BMW------------------------(Rs.5000/day)" <<endl<< "* Jaguar---------------------(Rs.5000/day)"<<endl<< "* Buggati--------------------(Rs.10000/day)"<<endl<< "* Roll-Royce-----------------(Rs.10000/day)"<< endl<< endl;
       
       selected_brand();
   }
    
    void selected_brand(){
        cout<<"Enter Selected Car brand name :"<< endl;
        cin>> brandName;
        
        if (brandName == "Maruthi" || brandName == "Hyundai" ||brandName ==  "BMW"|| brandName == "Jaguar" || brandName == "Buggati" ||brandName ==  "Roll-Royce"){
            cout<< endl<< endl;
            duration();
            rental_charge();
            
        }
        else{
            cout<< "Sorry, we do not have "<< brandName<< " cars available"<< endl<<endl;
        }
        
    }
    
};

class Customer {
public:
    string fullname;
    int age;
    string country;
    bool hasLicense;
    string phoneNumber;
    
    public:
    void getDetails() {
        cout << "Enter your full name: "<< endl;
        cin.ignore();
        getline(cin,fullname);
        
        cout << "Enter your age: "<< endl;
        cin >> age;
       
        
        cout << " Enter your Country: "<<endl;
        cin >> country;
       
        
        cout << "Do you have a valid driving license? (1 for Yes, 0 for No): ";
        cin >> hasLicense;
        if(hasLicense==1){cout<<"Yes"<< endl;}
        else if(hasLicense==0){cout<<"No" << endl; }
        
       cout<<"Enter your Phone Number : ";
       cin>>phoneNumber;
       
       if(phoneNumber.length()!=10){
           cout<<"Invalid phone number! Please enter valid phone number."<<endl;
       }
    
    }
};

class Reservation : public Customer, public Dur_Rent{
    string address;
    // protected:
    // string fullname;
    // int age;
    // string country;
    // bool hasLicense;
     
public:
    
       
    void confirmation_detail(){
       
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"Name -"<< fullname <<" "<<endl<<"Age - "<< age <<endl<<"Country - "<<country<< endl<<"Phone No.- "<<phoneNumber<<endl<<endl;
        
        cout<<"Car - "<<brandName <<endl<<"No of days - "<<days<<endl<<"Rental charge - Rs."<< charge<<"/-" <<endl<<endl;
        
        cout<<"Enter your address : ";
        cin.ignore();
        getline(cin,address);
        cout<<"The car will arrive at your given address: "<<address<<endl;
        
    }
    void print(){
        cout<<"\nYour Reservation has been Confirmed."<< endl;
        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);
          // Display current date
   cout << "Current Date: " << localTime->tm_mday << '/' << 1 + localTime->tm_mon << '/' << 1900 + localTime->tm_year << endl;
    
    // Display current time
    cout << "Current Time: " << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << endl;
    
    
        cout<<"The car will be provided within 1 hour. "<<endl<<endl;
        
        cout << "The car will be returned back to service after "<<days<<" days of reservation time and date"<<endl;
        
        cout<<"Thank you for choosing Our Car retal service."<< endl<<"-------------------------------------------------------------";
    }
    
    
};


int main() {
cout<<"Welcome To Car Rental Services\n\n";
bool confirm;
 SelectCar sc;
 sc.display_brand();
   
        if(sc.forbook==1) { 
            
            Customer customer;
           customer.getDetails();

 if (!customer.hasLicense || customer.country != "India" || customer.age < 18 || customer.phoneNumber.length() !=10) {
        cout<<endl<< "Oops! "<<customer.fullname<< ", you are not eligible to rent our car." << endl<<endl<<"Please read terms and conditions to rent the Car of our Company: "<<endl;
        cout<<"* Our services availble in India.\n* You must be Above 18 years of age."<<endl;
       cout<<"* Enter valid information. \n* You must have valid License of India.\n ";
         }
     else {

        cout <<"Congratulations! "<<customer.fullname<<", you are eligible to rent our car. "<< endl;
        cout<<"Do you confirm a car rental service (1 for yes , 0 for No) : ";
        
        cin>>confirm;
        
        if(confirm==1){
           cout<<"Yes"<<endl;
          Reservation r;

        r.fullname = customer.fullname;
        r.age =customer.age;
        r.country = customer.country;
        r.phoneNumber = customer.phoneNumber;
        
         r.brandName = sc.brandName;
         r.charge = sc.charge;
          r.days = sc.days;
          
        r.confirmation_detail();
        r.print();
           
       }
          
      }
    }
    


	return 0;
}