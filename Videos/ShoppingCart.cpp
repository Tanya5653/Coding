#include<iostream>
#include "cart.h"
#include<vector>
using namespace std;

vector<Product> allProducts ={
    Product(1,"apple",26 ),
    Product( 3,"mango", 16 ),
    Product( 2,"guava",36 ),
    Product( 5,"banana",56 ),
    Product( 4,"strawberry",29 ),
    Product( 6,"pineapple",20 ),
};

Product* chooseProduct(){
    string productList;
    cout<<"Available products:"<<endl;

    for(auto product : allProducts){
        productList.append(product.DisplayProduct());
    }
    cout<< productList<<endl; 
    cout<<"----------------"<<endl;
    string choice;
    cin>>choice;

    for(int i=0;i<allProducts.size();i++){
          if(allProducts[i].getShortName()==choice){
            return &allProducts[i];
          }
    }
    cout<<"Product not found"<<endl;
    return NULL;

}

bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    int Total = cart.getTotal();
    cout<<"Pay in Cash.";
    int paid;
    cin>>paid;

    if(paid>=Total){
        cout<<"Change:"<<paid-Total<<endl;
        cout<<"ThankYou for Shopping..";
        return true;
    }
    else{
        cout<<"NOT enough cash.";
        return false;
    }
}

int main(){
    char action;
    Cart cart;
    while(true){
        cout<<"Select an action - (a)dd item, (v)iew item , (c)heckout"<<endl;
        cin>>action;

        if(action=='a'){
            //view all products + choose product + add to the cart
            Product * product = chooseProduct();
            if(product!=NULL){
                cout<<" Added to the cart: "<<product->DisplayProduct()<<endl;
                cart.addProduct(*product);
            }
        }
        else if(action =='v'){
            //view the cart
            cout<<"-------------"<<endl;
            cout<< cart.viewCart()<<endl;
            cout<<"-------------"<<endl;
        }
        else{
            //checkout
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }
    return 0;
}

// int main(){

// Product p(1,"pomogrenate",30);
// cout<<p.DisplayProduct()<<endl;

// Item fruit(p,4);
// cout<< fruit.getPrice()<<endl;
// cout<< fruit.getItemInfo()<<endl;
// return 0;
// }