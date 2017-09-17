/**
  * Leonard Phillips
  * 15232331
  * Assignment 1 Part 2
  * This is a Marvel University. 
  * 
  */
  
#include <iostream>
#include <string>

using namespace std;

//=================================================================================
/**
 * A class representing an Employee
 */
class Employee {
	 protected:
		  string mFName;
		  string mGName;
	 private:
		  string mIRD;
	 public:
	 Employee(const string &_mFName, const string &_mGName, const string &_mIRD);
	 virtual ~Employee();
	 const string &getMFName() const;
	 const string &getMGName() const;
	 const string &getMIRD() const;
	 void setMFName(const string &_mFName);
	 void setMGName(const string &_mGName);
	 void setMIRD(const string &_mIRD);
	 virtual void print(ostream &_cout);
	 virtual int getNetMonthlyPay() = 0;
};


//---------------------------------------------------------------
Employee::Employee(const string &_mFName, const string &_mGName, const string &_mIRD)
	: mFName(_mFName), mGName(_mGName), mIRD(_mIRD) {}
//---------------------------------------------------------------
Employee::~Employee() {}
//---------------------------------------------------------------
const string &Employee::getMGName() const {
	 return mGName;
}
//---------------------------------------------------------------
const string &Employee::getMIRD() const {
	 return mIRD;
}
//---------------------------------------------------------------
const string &Employee::getMFName() const {
	 return mFName;
}
//---------------------------------------------------------------
void Employee::setMFName(const string &_mFName) {
	 Employee::mFName = _mFName;
}
//---------------------------------------------------------------
void Employee::setMGName(const string &_mGName) {
	 Employee::mGName = _mGName;
}
//---------------------------------------------------------------
void Employee::setMIRD(const string &_mIRD) {
	 Employee::mIRD = _mIRD;
}
//---------------------------------------------------------------
void Employee::print(ostream &_cout) {
	_cout << "Employee IRD number: " << getMIRD() << ". Last Name: " << 
	getMFName() << ". First Name: " << getMGName();
}
//---------------------------------------------------------------
//=================================================================================
/**
 * A class representing an employee with than annual salary. 
 */
class SalaryEmp : public Employee {
	 protected:
		  double mAPay; ///< The annual salary
	 
	 public:
		  SalaryEmp(const string &_nFName, const string &_mGName, const string &_mIRD, double _mAPay);
		  double getMAPay() const;
		  void setMAPay(double mAPay);
};
//---------------------------------------------------------------
SalaryEmp::SalaryEmp(const string &_nFName, const string &_mGName, const string &_mIRD, double _mAPay)
	: Employee(_nFName, _mGName, _mIRD), mAPay(_mAPay) {}
//---------------------------------------------------------------
double SalaryEmp::getMAPay() const {
	 return mAPay;
}
//---------------------------------------------------------------
void SalaryEmp::setMAPay(double _mAPay) {
	 SalaryEmp::mAPay = _mAPay;
}
//---------------------------------------------------------------
//=================================================================================
/**
 * A class representing a Professor
 */
class Prof : public SalaryEmp {
	 private:
		  int mDaysLeave; ///< Number of unpaid leave days.
		  const int mTax = 28; ///< Percent deductions from salary.

	 public:
		  Prof(const string &_nFName = "NO_PR", const string &_mGName = "NO_PR", 
		  const string &_mIRD = "PR00-0000-000", double _mAPay = 0.0, int _mDaysLeave = 0);
		  int getMDaysLeave() const;
		  void setMDaysLeave(int mDaysLeave);
		  virtual void print(ostream &) override;
		  virtual int getNetMonthlyPay() override;
};
//---------------------------------------------------------------
Prof::Prof(const string &_nFName = "NO_PR", const string &_mGName = "NO_PR", 
	const string &_mIRD = "PR00-0000-000", double _mAPay = 0.0, int _mDaysLeave = 0)
	: SalaryEmp(_nFName, _mGName, _mIRD, _mAPay), mDaysLeave(_mDaysLeave) {}
//---------------------------------------------------------------
int Prof::getMDaysLeave() const {
	 return mDaysLeave;
}
//---------------------------------------------------------------
void Prof::setMDaysLeave(int _mDaysLeave) {
	 Prof::mDaysLeave = _mDaysLeave;
}
//---------------------------------------------------------------
void Prof::print(ostream &_cout) {	
	_cout << "Employee IRD number: " << Employee::getMIRD() << ". Last Name: " << 
	Employee::getMFName() << ". First Name: " << Employee::getMGName() << " Monthly Net Pay: $" <<
	getNetMonthlyPay();
}
//---------------------------------------------------------------
///	Uncomplete ///
int Prof::getNetMonthlyPay(){
	double totalLeaveDeductions = ((SalaryEmp::getMAPay() / 365) * (double)getMDaysLeave());
	return (int)((SalaryEmp::getMAPay() - totalLeaveDeductions) / 12);	
}
//---------------------------------------------------------------
//=================================================================================
/**
 * A class representing an Administrator
 */
class Admin : public SalaryEmp{
    private:
        string mJob; ///< Job title.
        const int mTax = 25; ///< Percent deductions from salary.
public:
    Admin(const string &_nFName = = "NO_ADM", const string &_mGName = "NO_ADM", 
	 const string &_mIRD = "ADM00-0000-000", double _mAPay = 0, const string &_mJob = "NO_ADM");
    const string &getMJob() const;
    void setMJob(const string &_mJob);   
    virtual void print(ostream &_cout) override;    
    virtual int getNetMonthlyPay() override;

};
//---------------------------------------------------------------
Admin::Admin(const string &_nFName = "NO_ADM", const string &_mGName = "NO_ADM", 
	const string &_mIRD = "ADM00-0000-000", double _mAPay = 0, const string &_mJob = "NO_ADM")
	: SalaryEmp(_nFName, _mGName, _mIRD, _mAPay), mJob(_mJob) {}
//---------------------------------------------------------------
const string &Admin::getMJob() const {
    return mJob;
}
//---------------------------------------------------------------
void Admin::setMJob(const string &_mJob) {
    Admin::mJob = _mJob;
}
//---------------------------------------------------------------
void Admin::print(ostream &_cout) {
	_cout << "Employee IRD number: " << Employee::getMIRD() << ". Last Name: " << 
	Employee::getMFName() << ". First Name: " << Employee::getMGName() << " Monthly Net Pay: $" <<
	getNetMonthlyPay();
}
//---------------------------------------------------------------
int Admin::getNetMonthlyPay() {
	double deductableTaxAmount = SalaryEmp::getMAPay() * (mTax / 100);
	return (SalaryEmp::getMAPay() - deductableTaxAmount) / 12;
}
//---------------------------------------------------------------	
//=================================================================================
/**
 * A class representing an Administrator
 */
class TEmp : public Employee {
    private:
        string mID; ///< Student ID number.
        int mHWorked; ///< Number of hours worked per month.
        double mHPay; ///< Hourly rate the student is paid.
        const int mTax = 20; ///< Percent deductions from salary.
public:
    TEmp(const string &_nFName = "NO_TA", const string &_mGName = "NO_TA", 
	 const string &_mIRD = "NO_TA", const string &_mID = "NO_TA", int _mHWorked = 0, double _mHPay = 0);
    const string &getMID() const;
    int getMHWorked() const;
    double getMHPay() const;
    void setMID(const string &_mID);
    void setMHWorked(int _mHWorked);
    void setMHPay(double _mHPay);
    virtual void print(ostream &_cout) override;
    virtual int getNetMonthlyPay() override;
};
//---------------------------------------------------------------
TEmp::TEmp(const string &_nFName = "NO_TA", const string &_mGName = "NO_TA", 
	const string &_mIRD = "NO_TA", const string &_mID = "NO_TA", int _mHWorked = 0, double _mHPay = 0) 
	: Employee(_nFName, _mGName, _mIRD), mID(_mID), mHWorked(_mHWorked), mHPay(_mHPay), mTax(_mTax) {}
//---------------------------------------------------------------
void TEmp::setMID(const string &_mID) {
    TEmp::mID = _mID;
}
//---------------------------------------------------------------
void TEmp::setMHWorked(int _mHWorked) {
    TEmp::mHWorked = _mHWorked;
}
//---------------------------------------------------------------
void TEmp::setMHPay(double _mHPay) {
    TEmp::mHPay = _mHPay;
}
//---------------------------------------------------------------
const string &TEmp::getMID() const {
    return mID;
}
//---------------------------------------------------------------
int TEmp::getMHWorked() const {
    return mHWorked;
}
//---------------------------------------------------------------
double TEmp::getMHPay() const {
    return mHPay;
}
//---------------------------------------------------------------
void TEmp::print(ostream &_cout) {
	_cout << "Employee IRD number: " << Employee::getMIRD() << ". Last Name: " << 
	Employee::getMFName() << ". First Name: " << Employee::getMGName() << " Monthly Net Pay: $" <<
	getNetMonthlyPay();
}
//---------------------------------------------------------------
int TEmp::getNetMonthlyPay() {
	double totalWage = (double)getMHWorked() * getMHPay();
	double deductableTaxAmount = totalWage * (mTax / 100);
	return totalWage - deductableTaxAmount;
}
//---------------------------------------------------------------




int main() {
	const int SIZE = 10;
	
	Employee* emps[SIZE];
	emps[0] = new TEmp();
	emps[1] = new TEmp("Wuz", "Chris", "22-2678012", "12323405', 6, 5");
	emps[2] = new TEmp("Jackson", "Priscilla", "63-232-1456", "08001896", 2, 23.50);
	emps[3] = new Admin();
	emps[4] = new Admin("Bush", "GeorgeJr", "06-1342=0456", 59099.76, "Librarian");
	emps[5] = new Admin("Clever", "Bob", "22-267-812", 79345.00, "Bussines Manger");
	emps[6] = new Prof();
	emps[7] = new Prof("Steiger", "Ludwig", "65-102-456", 79345.00, 3);
	emps[8] = new Prof("Flop", "Boby", "11-178-120", 69009.00, 0);
	emps[9] = new Prof("Daisy", "Ana", "34-567-812", 67099.00, 3);
	double totalToPay=0.0;
	for (int i = 0; i < SIZE; ++i) {
		totalToPay += emps[i]->getNetMonthlyPay();
		emps[i]->print9cout);
		cout << endl;
	}
	cout << "\nTotal wages this month: $" << serprecision(10) << totalToPay;
	cout << "\nThank you for using out program! Bye!" << endl;
	
	return 0;
}
	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	