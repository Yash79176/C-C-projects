#include<bits/stdc++.h>
#include<fstream>
using namespace std;

//First we create a class called Shopping which will then include sub classes,
// We will declare some variables used in supermarket like name, code, price etc.
class shopping{
    private:
        int productCode;
        string productName;
        float productPrice;
        float anyDiscount;

    public:
        void menu();
        void administrator();
        void customer();
        void add();
        void edit();
        void replaceProduct();
        void removeProduct();
        void listOfProducts();
        void getReceipt();
};
void shopping :: menu(){
    m:
    int choice;
    string id;
    string password;
    int option;
    int OTP;

    cout<<"\t\t\t_______________________\n";
    cout<<"\t\t\t                       \n";
    cout<<"\t\t\t Welcome to Supermarket\n";
    cout<<"\t\t\t                       \n";
    cout<<"\t\t\t  Select one:          \n";
    cout<<"\t\t\t  (1) administrator    \n";
    cout<<"\t\t\t  (1) customer         \n";
    cout<<"\t\t\t  (1) Exit             \n";
    cout<<"\t\t\t                       \n";
    cin>>choice;

    switch(choice){
        case 1:{
            cout<<"Enter the unique login id_passowrd for the administrator:\n";
            cout<<"id: ";
            cin>>id;
            cout<<"password: ";
            cin>>password;

            if(id=="superMarket@gmail.com" && password=="sumar@123"){
                administrator();
            }
            else{
                cout<<"Invalid Id or password, try again\n";
                cout<<"if forgot password enter 1 else 2";
                cin>>option;

                switch(option){
                    case 1:
                        cout<<"Enter your Id:";
                        cin>>id;
                        cout<<"Enter OTP sent to this id";
                        cin>>OTP;
                        cout<<"the administrator Id_Password has been sent to the mail\n";

                    case 2:
                        cout<<"Enter the unique login id_passowrd for the administrator:\n";
                        cout<<"id: ";
                        cin>>id;
                        cout<<"password: ";
                        cin>>password;
                }
            }
            break;
        }
        case 2:{
            customer();
        }
        case 3:{
            exit(0);
        }
        default:{
            cout<<"Please select from given optionsn";
        }
    }
    goto m;
}

void shopping :: administrator(){
    m:
    int choice;
    //Here we will create a menu in whcih there will be different options
    cout<<"\t\t\t\t\t\t\t Administrator Menu:\n";
    cout<<"\t\t\t\t\t __(1) Add the product__\n";
    cout<<"\t\t\t\t\t __(2) Replace the product__\n";
    cout<<"\t\t\t\t\t __(3) Remove the product__\n";
    cout<<"\t\t\t\t\t __(1) Back to main menu__\n";
    cout<<"Please Enter your choice:";
    cin>>choice;

    switch(choice){
        case 1: {
            add();
            break;
        }
        case 2: {
            replaceProduct();
            break;
        }
        case 3: {
            removeProduct();
            break;
        }
        case 4: {
            menu();
            break;
        }
        default:
            cout<<"Invalid choice\n";
    }
    goto m;   
}

void shopping:: customer(){
    m:
    int choice;
    cout<<"\t\t\t\tCustomer:\n";
    cout<<"\t\t\t___________\n";
    cout<<"\t\t\tplease select:\n";
    cout<<"\t\t\t(1) Buy product\n";
    cout<<"\t\t\t(2) Go Back:\n";
    cout<<"\t\t\t\t\t\t\t\t:\n";
    cin>>choice;

    switch(choice){
        case 1:
            getReceipt();
            break;

        case 2:
            menu();

        default:
            cout<<"Invalid choice\n";
    }
    goto m;
}

void shopping:: add(){
    // We will use file_handling operation to add products in the menu
    m:
    fstream data;
    int c;
    int token;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t Add new product\n";
    cout<<"\n\t\t Enter product code:\n";
    cin>>productCode;
    cout<<"\n\t\t Enter product name:\n";
    cin>>productName;
    cout<<"\n\t\t Enter product price:\n";
    cin>>productPrice;
    cout<<"\n\t\t Enter product discount:\n";
    cin>>anyDiscount;

    // Here we will add a file and store all the product details,

    data.open("ProductBase.txt", ios:: in);
    if(!data){
        data.open("productBase.txt", ios::app|ios::out);
        data<<" "<<productCode<<" "<<productName<<" "<<productPrice<<" "<<anyDiscount<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;  // Reading from the file
        // Here we are initilaiing the file, after which 
        // we'll use a while loop to iterate through the file.
        while(!data.eof()){
            if(c == productCode) token++;
            data>>c>>n>>p>>d;
        }
        data.close();
    }
        if(token==1) // gives away the info of a productCode being already present in the menu 
        goto m;
        else{
            data.open("productBase.txt", ios::app|ios::out);
            data<<" "<<productCode<<" "<<productName<<" "<<productPrice<<" "<<anyDiscount<<"\n";
            data.close();
        }
        cout<<"\n\n\t\t Record Inserted\n";
}

void shopping:: replaceProduct(){
    fstream productData1, productData2;
    //Declare some variables
    int key;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Modify the product\n";
    cout<<"\t\t\t Enter the product code: ";
    cin>>key;

    productData1.open("ProductBase.txt", ios::in);
    if(!productData1) cout<<"\n\t Product doesn't exist!\n";
    else{
        productData2.open("ProductBase2.txt", ios::app|ios::out);
        productData1>>productCode>>productName>>productPrice>>anyDiscount;
        while(!productData1.eof()){
            if(key == productCode){
                cout<<"\n\t\t product new code :";
                cin>>c;
                cout<<"\n\t\t product name :";
                cin>>n;
                cout<<"\n\t\t product price :";
                cin>>p;
                cout<<"\n\t\t product discount :";
                cin>>d;
                productData2<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else{
                productData2<<" "<<productCode<<" "<<productName<<" "<<productPrice<<" "<<anyDiscount<<"\n";
            }
            productData1.close();
            productData2.close();

            remove("ProductBase.txt");
            rename("productBase2.txt", "ProductBase.txt");

            if(token == 0) cout<<"\n\n\t Record not found!\n";
        }
    }
}

void shopping:: removeProduct(){
    fstream ProductData1, ProductData2;
    int key;
    int token = 0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Enter product: ";
    cin>>key;
    ProductData1.open("ProductBase.txt", ios::in);
    if(!ProductData1){
        cout<<"File doesn't exist";
    }
    else{
        ProductData2.open("ProductBase2.txt", ios::app|ios::out);
        ProductData1>>productCode>>productName>>productPrice>>anyDiscount;
        while(!ProductData1.eof()){
            if(productCode == key){
                cout<<"\n\t Product deleted successfully!\n";
                token ++;
            }
            else{
                ProductData2<<" "<<productCode<<" "<<productName<<" "<<productPrice<<" "<<anyDiscount<<"\n";
            }
            ProductData1>>productCode>>productName>>productPrice>>anyDiscount;
        }
        ProductData1.close();
        ProductData2.close();
        remove("ProductBase.txt");
        rename("ProductBase.txt","ProductBase2.txt");

        if(token == 0) cout<<"\n\t Record not found.\n";
    }
}

void shopping:: listOfProducts(){
    fstream ProductData1, ProductData2;
    ProductData1.open("ProductBase.txt", ios::in);
    cout<<"\n\n\t_________________________________\n";
    cout<<"Sr No.\t\t Name \t\t Price\n";
    cout<<"\n\n\t_________________________________\n";
    ProductData1>>productCode>>productName>>productPrice>>anyDiscount;
    while(!ProductData1.eof()){
        cout<<productCode<<" "<<productName<<" "<<productPrice<<" "<<anyDiscount<<"\n";
        ProductData1>>productCode>>productName>>productPrice>>anyDiscount;
    }
    ProductData1.close();
}
void shopping :: getReceipt(){
    // Here we declare arrays because we've to store multiple product keys, and multiple products
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    int arrquantity[100];
    char choice;
    int c = 0;
    float amount = 0;
    float Discount = 0;
    int total = 0;

    cout<<"\n\t\t\tReceipt:\n";
    data.open("ProductBase.txt, ios::in");
    if(!data){
        cout<<"\n\t\tEmpty database";
    }
    else{
        data.close();

        listOfProducts();
        cout<<" \n\n\t________________\n";
        cout<<"Please place the order\n";
        cout<<" \n\n\t________________\n";
        do{
            cout<<"\tEnter Product code:";
            cin>>arrc[c];
            cout<<"\n\tEnter the product quantity: ";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c] == arrc[i]){
                    cout<<"\nDuplicate product code, please enother another one.\n";
                    goto m;
                }
            }
            c++;
            cout<<"\n Do you want more products? ";
            cin>>choice;
        }
        while(choice == 'c');

        cout<<"\n\n\t\t____________RECEIPT___________\n";
        cout<<"\nProductNo. \t product Name\t product quantity \t price \tAmount \t DiscountedAmount\n";
        
        for(int i=0;i<c;i++){
            data.open("ProductBase.txt", ios::in);
            data>>productCode>>productName>>productPrice>>anyDiscount;
            while(!data.eof()){
               // inside this while loop we'll check if we are matching
               // if code enter by the user is matching with the code stored in file
               if(productCode ==  arrc[i]){
                amount = productPrice * arrq[i];
                Discount = amount-(amount * Discount)/100;
                total += Discount;
                cout<<"\n"<<productCode<<"\t\t"<<productName<<"\t\t"<<productPrice<<"\t\t"<<amount<<"\t\t"<<anyDiscount<<"\n";
               }
                data>>productCode>>productName>>productPrice>>anyDiscount;
            }
        }
            data.close();
    }
        cout<<"\n\n___________________";
        cout<<"\n Total Amount = "<<total;   
}
int main(){
    shopping s;
    s.menu();
return 0;
}