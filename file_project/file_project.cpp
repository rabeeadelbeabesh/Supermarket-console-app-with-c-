#include "stdafx.h";
#include<fstream>
#include<iostream>
#include<String>
#include<conio.h>
using namespace std;
bool tchek_sre(string s)
{
	int t = 0;
	
	for (int i = 0; i < s.size(); i++)
	{ 
		for (int j = 97; j <= 122; j++)
		{
			if (isdigit(s[i]) )
				return false;
		}
		
		
	}

	return true;
}

class department{
private:
	int dep_id;
	string dep_Name;
public:
	department(){
		dep_id = 0;
		dep_Name = "";
	}
	void add_department(int q) {

		dep_id = q;
		do{
			cout << "enter the department name-> ";
			cin >> dep_Name;
		} while (!tchek_sre(dep_Name));
	}
	void show_info() {
		cout << "the department id is=" << dep_id << "\n";
		cout << "the department Name is=" << dep_Name << "\n";
	}
	int depp_id() { return dep_id; }
	string depp_Name() { return dep_Name; }

};
fstream fd2;
department de;
bool check_dep_id(int x)
{
	int flag = 0;
	fd2.open("department.txt", ios::in);
	while (fd2.read((char*)&de, sizeof(department)))
	{
		if (de.depp_id() == x) {
			flag = 1;
		}
	}
	fd2.close();
	if (flag == 0) {
		return false;

	}
	else
		return true;
}
class employee {
private:
	int eid;
	string efName;
	string eLName;
	string phone;
	string  ssn;
	int age;
	string adderess;
	int dep_id;

public:
	employee(){
		eid = 0;
		efName = "";
		eLName;
		phone = "";
		ssn = "";
		age = 0;
		adderess = "";
		dep_id = 0;
	}
	void create_employee(int y) {
		eid = y;
		do{
			cout << "enter the employee  first name -> ";
			cin >> efName;
		} while (!tchek_sre(efName));
		do{
		cout << "enter the employee  last name -> ";
		cin >> eLName;
		} while (!tchek_sre(eLName));
		cout << "enter the employee phone->";
		cin >> phone;
			cout << "enter the employee National ID->";
			cin >> ssn;
		
		do
		{
			cout << "enter the employee age->";
			cin >> age;
		} while (age <= 0 || age >= 60);

		cout << "enter the employee adderess->";
		cin >> adderess;
		do
		{
			cout << "enter the employee department id ->";
			cin >> dep_id;
		} while (!check_dep_id(dep_id));
	}

	void show_info() {
		cout << "the employee id is=" << eid << "\n";
		cout << "the employee  first Name is=" << efName << "\n";
		cout << "the employee  last Name is=" << eLName << "\n";
		cout << "the employee phone is =" << phone << "\n";
		cout << "the product  National ID is =" << ssn << "\n";
		cout << "the product  age  is =" << age << "\n";
		cout << "the product  adderess  is =" << adderess << "\n";
		cout << "the product Supplier  is=" << dep_id;
	}
	int eeid(){ return eid; };
	string eefName(){ return efName; };
	string eeLName(){ return eLName; };
	string eephone(){ return phone; };
	string  eessn(){ return ssn; };
	int eeage(){ return age; };
	string eeadderess(){ return adderess; };
	int eedep_id(){ return dep_id; };
};

employee em;
fstream fe;
fstream fd;
void write_employee() {
	int x = 0;
	fe.open("employee.txt", ios::in);
	while (fe.read((char*)&em, sizeof(employee)))
	{
	}
	x = em.eeid() + 1;
	fe.close();
	fe.open("employee.txt", ios::out | ios::app);
	em.create_employee(x);
	fe.write((char*)&em, sizeof(employee));
	fe.close();
	cout << "\n\n the employee is created ";

}
void write_department() {
	int z = 0;
	fd.open("department.txt", ios::in);
	while (fd.read((char*)&de, sizeof(department)))
	{
	}
	z = de.depp_id() + 1;
	fd.close();
	fd.open("department.txt", ios::out | ios::app);
	de.add_department(z);
	fd.write((char*)&de, sizeof(department));
	fd.close();
	cout << "\n\n the department is adding ";

}
void Display_e(){
	cout << "all the employee Infromation : \n\n";
	fe.open("employee.txt", ios::in);
	while (fe.read((char*)&em, sizeof(employee)))
	{
		em.show_info();
		cout << "\n\n ============================================\n";
	}
	fe.close();


}
void Display_d() {
	cout << "all the department Infromation : \n\n";
	fd.open("department.txt", ios::in);
	while (fd.read((char*)&de, sizeof(department)))
	{
		de.show_info();
		cout << "\n\n ============================================\n";
	}
	fd.close();

}
void searsh_employee(int num) {
	int flag = 0;
	fe.open("employee.txt", ios::in);
	while (fe.read((char*)&em, sizeof(employee)))
	{
		if (em.eeid() == num) {
			em.show_info();
			flag = 1;
		}
	}
	fe.close();
	if (flag == 0) {
		cout << "\n employee not found \n";

	}
}
void searsh_department(int num) {
	int flag = 0;
	fd.open("department.txt", ios::in);
	while (fd.read((char*)&de, sizeof(department)))
	{
		if (de.depp_id() == num) {
			de.show_info();
			flag = 1;
		}
	}
	fd.close();
	if (flag == 0) {
		cout << "\n department not found \n";

	}
}
void delete_employee() {
	int num,t=0;
	cout << "\n\n please enter the employee want to deleted";
	cin >> num;
	fe.open("employee.txt", ios::in | ios::out);
	fstream fe2;
	fe2.open("replace.txt", ios::out);
	fe.seekg(0, ios::beg);
	while (fe.read((char*)&em, sizeof(employee)))
	{
		if (em.eeid() != num) {
			fe2.write((char*)&em, sizeof(employee));
		}
		if (em.eeid() == num)
			t = 1;
	}
	fe2.close();
	fe.close();
	remove("employee.txt");
	rename("replace.txt", "employee.txt");
	if (t==1)
		cout << "\n\n the employee deleted";
	else
	cout << "\n\n the employee  not found";

}
void delete_department() {
	int num,t=0;
	cout << "\n\n please enter the department want to deleted";
	cin >> num;
	fd.open("department.txt", ios::in | ios::out);
	fstream fdd2;
	fdd2.open("replace2.txt", ios::out);
	fd.seekg(0, ios::beg);
	while (fd.read((char*)&de, sizeof(department)))
	{
		if (de.depp_id() != num) {
			fdd2.write((char*)&de, sizeof(department));
		}
		if (de.depp_id() == num)
			t = 1;
	}
	fdd2.close();
	fd.close();
	remove("department.txt");
	rename("replace2.txt", "department.txt");
	if (t == 1)
		cout << "\n\n the department deleted";
	else
		cout << "\n\n the department  not found";

}
void update_department() {
	int num,t=0;
	cout << "\n\n please enter the department want to updalete";
	cin >> num;
	fd.open("department.txt", ios::in | ios::out);
	fstream fdd2;
	fdd2.open("replace2.txt", ios::out);
	fd.seekg(0, ios::beg);
	while (fd.read((char*)&de, sizeof(department)))
	{
		if (de.depp_id() == num)
		{
			de.add_department(de.depp_id());
			fdd2.write((char*)&de, sizeof(department));
			t =1;


		}
		else
		{
			fdd2.write((char*)&de, sizeof(department));
		}

	}
	fdd2.close();
	fd.close();
	remove("department.txt");
	rename("replace2.txt", "department.txt");
	if (t==1)
	cout << "\n\n the department update";
	else
		cout << "\n\n the department not found";


}
void update_employee() {
	int num,t=0;
	cout << "\n\n please enter the employee want to updalete";
	cin >> num;
	fe.open("employee.txt", ios::in | ios::out);
	fstream fe2;
	fe2.open("replace3.txt", ios::out);
	fe.seekg(0, ios::beg);
	while (fe.read((char*)&em, sizeof(employee)))
	{
		if (em.eeid() == num)
		{
			em.create_employee(em.eeid());
			fe2.write((char*)&em, sizeof(employee));
			t = 1;

		}
		else
		{
			fe2.write((char*)&em, sizeof(employee));
		}

	}
	fe2.close();
	fe.close();
	remove("employee.txt");
	rename("replace3.txt", "employee.txt");
	if (t == 1)
		cout << "\n\n the employee update";
	else
		cout << "\n\n the employee not found";


}
class Supplier{
private:
	int supp_id;
	string supp_Name;
public:
	Supplier(){
		supp_id = 0;
		supp_Name = "";
	}
	void add_suppler(int q) {
		
		supp_id = q;
		do{
			cout << "enter the Supplier name-> ";
			cin >> supp_Name;
		} while (!tchek_sre(supp_Name));
	  }
	void show_info() {
		cout << "the Supplier id is=" << supp_id << "\n";
		cout << "the Supplier Name is=" << supp_Name << "\n";
	}
	int sup_id() { return supp_id; }
	string sup_Name() { return supp_Name; }

};
fstream fs2;
Supplier sp;
bool check_supp_id(int x)
{
	int flag = 0;
	fs2.open("Supplier.txt", ios::in);
	while (fs2.read((char*)&sp, sizeof(Supplier)))
	{
		if (sp.sup_id() == x) {
			flag = 1;
		}
	}
	fs2.close();
	if (flag == 0) {
		return false;

	}
	else
		return true;
}
class products {
private:
	int pNo;
	string pName;
	float PPrice;
	double quantity;
	int supp_id;
	int dep_id;

public:
	products(){
		pNo = 0;
		pName = "";
		PPrice = 0;
		quantity = 0;
		supp_id = 0;
		dep_id = 0;

	}
	void create_products(int y) {
		pNo = y;
		do{
			cout << "enter the product name-> ";
			cin >> pName;
		} while (!tchek_sre(pName));
		do
		{
			cout << "enter the product Price->";
			cin >> PPrice;
		} while (PPrice <= 0);
		do
		{
			cout << "enter the product quantity->";
			cin >> quantity;
		} while (quantity <= 0);
		do
		{
			cout << "enter the product supp_id->";
			cin >> supp_id;
		} while (!check_supp_id(supp_id));
		do
		{
			cout << "enter the product department id->";
			cin >> dep_id;
		} while (!check_dep_id(dep_id));
		
	}


	void show_info() {
		cout << "the product Number is=" << pNo<<"\n";
		cout << "the product Name is=" << pName << "\n";
		cout << "the product price is =" << PPrice << "\n";
		cout << "the product quantity is =" << quantity << "\n";
		cout << "the product Supplier id  is=" << supp_id << "\n";
		cout << "the product department  id is=" << dep_id << "\n";
	}
	int pNum() { return pNo; }
	string pname() { return pName; }
	float Pprice() { return PPrice; }
	int pQuantity() { return quantity; }
	int sup_id() { return supp_id; }
	int depp_id() { return dep_id; }
};

products pro;
fstream fp;
fstream fs;
void write_product() {
	int x = 0;
	fp.open("shop.txt", ios::in);
	while (fp.read((char*)&pro, sizeof(products)))
	{
	}
	x = pro.pNum()+1;
	fp.close();
	fp.open("shop.txt", ios::out | ios::app);
	pro.create_products(x);
	fp.write((char*)&pro, sizeof(products));
	fp.close();
	cout << "\n\n the product is created ";

}
void write_Supplier() {
	int z = 0;
	fs.open("Supplier.txt", ios::in);
	while (fs.read((char*)&sp, sizeof(Supplier)))
	{
	}
	z = sp.sup_id() + 1;
	fs.close();
	fs.open("Supplier.txt", ios::out | ios::app);
	sp.add_suppler(z);
	fs.write((char*)&sp, sizeof(Supplier));
	fs.close();
	cout << "\n\n the Supplier is adding ";

}
void Display() {
	cout << "all the product Infromation : \n\n";
	fp.open("shop.txt", ios::in);
	while (fp.read((char*)&pro, sizeof(products)))
	{
		pro.show_info();
		cout << "\n\n ============================================\n";
	}
	fp.close();


}
void Display_s() {
	cout << "all the Supplier Infromation : \n\n";
	fs.open("Supplier.txt", ios::in);
	while (fs.read((char*)&sp, sizeof(Supplier)))
	{
		sp.show_info();
		cout << "\n\n ============================================\n";
	}
	fs.close();

}
void searsh_product(int num) {
	int flag = 0;
	fp.open("shop.txt", ios::in);
	while (fp.read((char*)&pro, sizeof(products)))
	{
		if (pro.pNum() == num) {
			pro.show_info();
			flag = 1;
		}
	}
	fp.close();
	if (flag == 0) {
		cout << "\n product not found \n";

	}
}
void searsh_Supplier(int num) {
	int flag = 0;
	fs.open("Supplier.txt", ios::in);
	while (fs.read((char*)&sp, sizeof(Supplier)))
	{
		if (sp.sup_id() == num) {
			sp.show_info();
			flag = 1;
		}
	}
	fs.close();
	if (flag == 0) {
		cout << "\n Supplier not found \n";

	}
}
void delete_product() {
	int num,t=0;
	cout << "\n\n please enter the product want to deleted";
	cin >> num;
	fp.open("shop.txt", ios::in | ios::out);
	fstream fp2;
	fp2.open("replace.txt", ios::out);
	fp.seekg(0, ios::beg);
	while (fp.read((char*)&pro, sizeof(products)))
	{
		if (pro.pNum()!= num) {
			fp2.write((char*)&pro, sizeof(products));
		}
		if (pro.pNum() == num)
			t = 1;
	}
	fp2.close();
	fp.close();
	remove("shop.txt");
	rename("replace.txt", "shop.txt");
	if (t==1)
	cout << "\n\n the product deleted";
	else
		cout << "\n\n the product not found";


}
void delete_Supplier() {
	int num,t=0;
	cout << "\n\n please enter the Supplier want to deleted";
	cin >> num;
	fs.open("Supplier.txt", ios::in | ios::out);
	fstream fs2;
	fs2.open("replace2.txt", ios::out);
	fs.seekg(0, ios::beg);
	while (fs.read((char*)&sp, sizeof(Supplier)))
	{
		if (sp.sup_id() != num) {
			fs2.write((char*)&sp, sizeof(Supplier));
		}
		if (sp.sup_id() == num)
			t = 1;
	}
	fs2.close();
	fs.close();
	remove("Supplier.txt");
	rename("replace2.txt", "Supplier.txt");
	if (t==1)
	cout << "\n\n the Supplier deleted";
	else
	cout << "\n\n the Supplier not found";

}
void update_Supplier() {
	int num,t=0;
	cout << "\n\n please enter the Supplier want to updalete";
	cin >> num;
	fs.open("Supplier.txt", ios::in | ios::out);
	fstream fs2;
	fs2.open("replace2.txt", ios::out);
	fs.seekg(0, ios::beg);
	while (fs.read((char*)&sp, sizeof(Supplier)))
	{
		if (sp.sup_id() == num)
		{
			sp.add_suppler(sp.sup_id());
			fs2.write((char*)&sp, sizeof(Supplier));
			t = 1;
		}
		else
		{
			fs2.write((char*)&sp, sizeof(Supplier));
		}

	}
	fs2.close();
	fs.close();
	remove("Supplier.txt");
	rename("replace2.txt", "Supplier.txt");
	if (t==1)
	cout << "\n\n the Supplier deleted";
	else
		cout << "\n\n the Supplier not found";


}
void update_produc() {
	int num,t=0;
	cout << "\n\n please enter the product want to updalete";
	cin >> num;
	fp.open("shop.txt", ios::in | ios::out);
	fstream fp2;
	fp2.open("replace3.txt", ios::out);
	fp.seekg(0, ios::beg);
	while (fp.read((char*)&pro, sizeof(products)))
	{
		if (pro.pNum()== num)
		{
			pro.create_products(pro.pNum());
			fp2.write((char*)&pro, sizeof(products));
			t = 1;
		}
		else
		{
			fp2.write((char*)&pro, sizeof(products));
		}

	}
	fp2.close();
	fp.close();
	remove("shop.txt");
	rename("replace3.txt","shop.txt");
	if (t == 1)
		cout << "\n\n the products update";
	else
		cout << "\n\n the products not found";

}

void intro() {
	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> the project of supermarket *kolo ray7*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	cout << "\n\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    made by rabea adel and ahmed mansour <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
	cout << "\n\n\t\t\t\t           **************Good lack************** ";
}
void main() {
	intro();
	int fl, fl1, fl2,fl3,fl4,fl5;
       fl5:
	string pasw;
	cout << "\n                                           --> enter your password\n";
	cout << "                                             -->";
	cin >> pasw;
	if (pasw == "671999")
	{
		
		
	   fl:	    
		cout << "\n\n\n                                        --> main Menu";
		cout << " choice 1-Supplier  2-product  3-department  4-employee   other-exit\n";
		int x;
		cout << "                                            ";
		cin >> x;
			switch (x)
			{
					
			  case 1:
			 {
					  char ch;
					  do {
						  fl1:
						  cout << "\n\n\t 1 create Supplier";
						  cout << "\n\n\t 2 display all Supplier";
						  cout << "\n\n\t 3 search ";
						  cout << "\n\n\t 4 deleted Supplier";
						  cout << "\n\n\t 5 update Supplier";
						  cout << "\n\n\t 6 main Menu";
						  cout << "\n\n\t 7 exit";
						  cout << "\n\n\t please enter your choice(1-6) ";
						  cin >> ch;
						  switch (ch)
						  {
						  case'1':write_Supplier();
							  break;
						  case'2':Display_s();
							  break;
						  case'3':
							  int num;
							  cout << "enter the number to search : \t ";
							  cin >> num;
							  searsh_Supplier(num);
							  break;
						  case'4':delete_Supplier();
							  break;
						  case'5':update_Supplier();
							  break;
						  case'6':
							  goto fl;
							  break;
						  case'7':exit(0);
							  break;
						  default:
							  cout << "error\n";
							  goto fl1;

							  break;
						  }
					  } while (ch != 5);
					  break;


			}


			case 2:
			{

					  char ch;
					  do {
						  fl2:
						  cout << "\n\n\n      main Menu";
						  cout << "\n\n\t 1 create product";
						  cout << "\n\n\t 2 display all product";
						  cout << "\n\n\t 3 search ";
						  cout << "\n\n\t 4 deleted product";
						  cout << "\n\n\t 5 update product";
						  cout << "\n\n\t 6 main Menu";
						  cout << "\n\n\t 7 exit";
						  cout << "\n\n\t please enter your choice(1-6) ";
						  cin >> ch;

						  switch (ch)
						  {
						  case'1':write_product();
							  break;
						  case'2':Display();
							  break;
						  case'3':
							  int num;
							  cout << "enter the number to search : \t ";
							  cin >> num;
							  searsh_product(num);
							  break;
						  case'4':delete_product();
							  break;
						  case'5':update_produc();
						  case'6':
							  goto fl;
							  break;
						  case'7':exit(0);
							  break;
						  default:
							  cout << "error\n";
							  goto fl2;
							  break;
						  }
					  } while (ch != 5);
					  break;
			}

			case 3:
			{
					  char ch;
					  do {
						  fl3:
						  cout << "\n\n\t 1 create department";
						  cout << "\n\n\t 2 display all department";
						  cout << "\n\n\t 3 search ";
						  cout << "\n\n\t 4 deleted department";
						  cout << "\n\n\t 5 update department";
						  cout << "\n\n\t 6 main Menu";
						  cout << "\n\n\t 7 exit";
						  cout << "\n\n\t please enter your choice(1-6) ";
						  cin >> ch;
						  switch (ch)
						  {
						  case'1':write_department();
							  break;
						  case'2':Display_d();
							  break;
						  case'3':
							  int num;
							  cout << "enter the number to search : \t ";
							  cin >> num;
							  searsh_department(num);
							  break;
						  case'4':delete_department();
							  break;
						  case'5':update_department();
							  break;
						  case'6':
							  goto fl;
							  break;
						  case'7':exit(0);
							  break;
						  default:
							  cout << "error\n";
							  goto fl3;
							  break;
						  }
					  } while (ch != 5);
					  break;


			}


			case 4:
			{

					  char ch;
					  do {
						  fl4:
						  cout << "\n\n\n      main Menu";
						  cout << "\n\n\t 1 create employee";
						  cout << "\n\n\t 2 display all employee";
						  cout << "\n\n\t 3 search ";
						  cout << "\n\n\t 4 deleted employee";
						  cout << "\n\n\t 5 update employee";
						  cout << "\n\n\t 6 main Menu";
						  cout << "\n\n\t 7 exit";
						  cout << "\n\n\t please enter your choice(1-6) ";
						  cin >> ch;

						  switch (ch)
						  {
						  case'1':write_employee();
							  break;
						  case'2':Display_e();
							  break;
						  case'3':
							  int num;
							  cout << "enter the number to search : \t ";
							  cin >> num;
							  searsh_employee(num);
							  break;
						  case'4':delete_employee();
							  break;
						  case'5':update_employee();
							  break;
						  case'6':
							  goto fl;
							  break;
						  case'7':exit(0);
							  break;
						  default:
							  cout << "error\n";
							  goto fl4;
							  break;
						  }
					  } while (ch != 5);
					  break;
			 }

			  case 5:
			  {
					  exit(0);
					  break;
			
			  }

			  default:
						 cout << "error\n";
						 exit(0);

				   break;

			}

		



	}
	else
		cout << "                                            Incorrect Password\n";
		 


}