#include <iostream>
#include <vector>
#include <cctype>
#include "datamodel.h"
using namespace std;

vector<Product> allproducts = {
  Product(1,"apple",26),
Product(2,"mango",16),
Product(3,"guava",36),
Product(4,"banana",56),
Product(5,"strawberry",29),
Product(6,"pineaaple",20)
};


Product* chooseProduct(){
  //Display the list of Products
  string productlist;
  cout << "Available Products" << endl;
  for(auto product:allproducts){
    productlist.append(product.getdisplayname());
    }
    cout << productlist << endl;
    cout << "-------------------" << endl;
    string choice;
    cin >> choice;
    for(int i=0;i<allproducts.size();i++){
      if(allproducts[i].getShortName() == choice){
        return &allproducts[i];
      }
    }
    cout << "Product not found" << endl;
    return NULL;
}

bool checkout(Cart &cart){
  if(cart.isEmpty()){
    return false;
  }
  int total = cart.getTotal();
  cout << "Pay in Cash : ";
  int paid;
  cin >> paid;
  if(paid>=total){
    cout << "Change : " << paid-total << endl;
    cout << "Thank you for Shopping!";
    return true;
  }else{
    cout << "Not enough Cash" << endl;
    return false;
  }
}
int main() {
  char action;
  Cart cart;
  
  while(true){
    cout<< "Select an action - (a)add item , (v) view cart,(c) checkout" << endl; 
    cin >> action;
    if(action=='a'){
      // Add to cart
      Product *product= chooseProduct();
      if(product!=NULL){
        cout << "Added to the cart " << product->getdisplayname() << endl;
        cart.addProduct(*product);
      }
    }else if(action=='v'){
      // View the cart
      cout << "----------------" << endl;
      cout << cart.viewCart();
      cout << "----------------" << endl;
    }else{
      // Checkout
      cart.viewCart();
      if(checkout(cart)){
        break;
      }
    }
  }
  return 0;
}