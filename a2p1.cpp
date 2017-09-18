/**
  * Leonard Phillips
  * 15232331
  * Assignment 1 Part 2
  * This is a Marvel University. It uses classes and inheritance to simulate a University
  * with multiple staff roles.
  */
  
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void info();

//=================================================================================
/**
 * A class representing an Employee
 */
class Employee {
	protected:
		string mFName; ///< Employee first name
		string mGName; ///< Employee last name
	private:
		string mIRD; ///< Employee IRD number
	public:
		/**
		  * Constructor
		  * @param[in] _mFName 	Employee first name
		  * @param[in] _mGName	Employee second name
		  * @param[in] _mIRD		Employee IRD number
		  */
		Employee(const string &_mFName, const string &_mGName, const string &_mIRD);
		/**
		  * Destructor 
		  */
		virtual ~Employee();
		/**
		  * mFName Accessor
		  * Returns mFName
		  */
		const string &getMFName() const;
		/**
		  * mGName Accessor
		  * Returns mGName
		  */
		const string &getMGName() const;
		/**
		  * mIRD Accessor
		  * Returns mIRD
		  */
		const string &getMIRD() const;
		/**
		  * mFName Mutator
		  * Sets mFName
		  */
		void setMFName(const string &_mFName);
		/**
		  * mGName Mutator
		  * Sets mGName
		  */
		void setMGName(const string &_mGName);
		/**
		  * mIRD Mutator
		  * Sets mIRD
		  */
		void setMIRD(const string &_mIRD);
		/**
		  * Virtual Member Function: print
		  * @param[in] _cout	 The cout stream that, when returned, displays the IRD number, first and last 
		  * of the employee
		  */
		virtual void print(ostream &_cout);
		/**
		  * Virtual Member Function: getNetMonthlyPay
		  * Returns employee monthly income
		  */
		virtual double getNetMonthlyPay() = 0;
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
	_cout << setw(5) << getMIRD();
	_cout << setw(5) << getMFName();
	_cout << setw(5) << getMGName();
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
		/**
		  * Constructor
		  * @param[in] _mFName 	Employee first name
		  * @param[in] _mGName	Employee second name
		  * @param[in] _mIRD		Employee IRD number
		  * @param[in] _mAPay	SalaryEmp annual pay 
		  */
		SalaryEmp(const string &_nFName, const string &_mGName, const string &_mIRD, double _mAPay);
		/**
		  * mAPay Accessor
		  * Returns mAPay
		  */
		double getMAPay() const;
		/**
		  * mAPay Mutator
		  * Sets mAPay
		  */
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
		/**
		  * Constructor
		  * @param[in] _mFName 		Employee first name
		  * @param[in] _mGName		Employee second name
		  * @param[in] _mIRD			Employee IRD number
		  * @param[in] _mAPay		SalaryEmp annual pay 
		  * @param[in] _mDaysLeave	Prof unpaid leave days
		  */
		Prof(const string &_nFName = "NO_PR", const string &_mGName = "NO_PR", 
		const string &_mIRD = "PR00-0000-000", double _mAPay = 0.0, int _mDaysLeave = 0);
		/**
		  * mDaysLeave Accessor
		  * Returns mDaysLeave
		  */
		int getMDaysLeave() const;
		/**
		  * mDaysLeave Mutator
		  * Sets mDaysLeave
		  */
		void setMDaysLeave(int mDaysLeave);
		/**
		  * Overriden Member Function: print
		  * @param[in] _cout	 The cout stream that, when returned, displays the IRD number, first and last 
		  * of the employee
		  */
		virtual void print(ostream &) override;
		/**
		  * Overriden Member Function: getNetMonthlyPay
		  * Returns employee monthly income
		  */
		virtual double getNetMonthlyPay() override;
};
//---------------------------------------------------------------
Prof::Prof(const string &_nFName, const string &_mGName, 
	const string &_mIRD, double _mAPay, int _mDaysLeave)
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
	_cout << setw(10) << Employee::getMIRD();
	_cout << "\t" << Employee::getMFName();
	_cout << "\t\t" << Employee::getMGName();
	_cout << "\t\t$" << getNetMonthlyPay();
}
//---------------------------------------------------------------
///	Uncomplete ///
double Prof::getNetMonthlyPay(){
	double totalLeaveDeductions = (SalaryEmp::getMAPay() / 365.0) * getMDaysLeave();	
	double totalTaxDeductions = (SalaryEmp::getMAPay() - totalLeaveDeductions) * (mTax / 100.0);
	return (SalaryEmp::getMAPay() - totalTaxDeductions) / 12.0;
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
		/**
		  * Constructor
		  * @param[in] _mFName 		Employee first name
		  * @param[in] _mGName		Employee second name
		  * @param[in] _mIRD			Employee IRD number
		  * @param[in] _mAPay		SalaryEmp annual pay 
		  * @param[in] _mJob			Admin job title
		  */
		Admin(const string &_nFName = "NO_ADM", const string &_mGName = "NO_ADM", 
		const string &_mIRD = "ADM00-0000-000", double _mAPay = 0, const string &_mJob = "NO_ADM");
		/**
		  * mJob Accessor
		  * Returns mJob
		  */
		const string &getMJob() const;
		/**
		  * mJob Mutator
		  * Sets mJob
		  */
		void setMJob(const string &_mJob);
		/**
		  * Overriden Member Function: print
		  * @param[in] _cout	 The cout stream that, when returned, displays the IRD number, first and last 
		  * of the employee
		  */
		virtual void print(ostream &_cout) override;
		/**
		  * Overriden Member Function: getNetMonthlyPay
		  * Returns employee monthly income
		  */
		virtual double getNetMonthlyPay() override;

};
//---------------------------------------------------------------
Admin::Admin(const string &_nFName, const string &_mGName, const string &_mIRD,
	double _mAPay, const string &_mJob) : SalaryEmp(_nFName, _mGName, _mIRD, _mAPay), mJob(_mJob) {}
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
	_cout << setw(10) << Employee::getMIRD();
	_cout << "\t" << Employee::getMFName();
	_cout << "\t\t" << Employee::getMGName();
	_cout << "\t\t$" << getNetMonthlyPay();
}
//---------------------------------------------------------------
double Admin::getNetMonthlyPay() {
	double deductableTaxAmount = SalaryEmp::getMAPay() * (mTax / 100.0);
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
		/**
		  * Constructor
		  * @param[in] _mFName 		Employee first name
		  * @param[in] _mGName		Employee second name
		  * @param[in] _mIRD			Employee IRD number
		  * @param[in] _mID			Student ID number
		  * @param[in] _mHWorked	The amount of hours the student has worked
		  * @param[in] _mHPay		The pay rate the studnet earns
		  */
		TEmp(const string &_nFName = "NO_TA", const string &_mGName = "NO_TA", 
		const string &_mIRD = "TA00-0000-000", const string &_mID = "NO_TA", int _mHWorked = 0, double _mHPay = 0);
		/**
		  * mID Accessor
		  * Returns mID
		  */
		const string &getMID() const;
		/**
		  * mHWorked Accessor
		  * Returns mHWorked
		  */
		int getMHWorked() const;
		/**
		  * mHPay Accessor
		  * Returns mHPay
		  */
		double getMHPay() const;
		/**
		  * mID Mutator
		  * Sets mID
		  */
		void setMID(const string &_mID);
		/**
		  * mHWorked Mutator
		  * Sets mHWorked
		  */
		void setMHWorked(int _mHWorked);
		/**
		  * mHPay Mutator
		  * Sets mHPay
		  */
		void setMHPay(double _mHPay);
		/**
		  * Overriden Member Function: print
		  * @param[in] _cout	 The cout stream that, when returned, displays the IRD number, first and last 
		  * of the employee
		  */
		virtual void print(ostream &_cout) override;
		/**
		  * Overriden Member Function: getNetMonthlyPay
		  * Returns employee monthly income
		  */
		virtual double getNetMonthlyPay() override;
};
//---------------------------------------------------------------
TEmp::TEmp(const string &_nFName, const string &_mGName,
	const string &_mIRD, const string &_mID, int _mHWorked, double _mHPay) 
	: Employee(_nFName, _mGName, _mIRD), mID(_mID), mHWorked(_mHWorked), mHPay(_mHPay) {}
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
	_cout << setw(10) << Employee::getMIRD();
	_cout << "\t" << Employee::getMFName();
	_cout << "\t\t" << Employee::getMGName();
	_cout << "\t\t$" << getNetMonthlyPay();
}
//---------------------------------------------------------------
double TEmp::getNetMonthlyPay() {
	double totalWage = getMHWorked() * getMHPay();
	double deductableTaxAmount = totalWage * (mTax / 100.0);
	return totalWage - deductableTaxAmount;
}
//---------------------------------------------------------------




int main() {
	const int SIZE = 10;
	info();
	Employee* emps[SIZE];
	emps[0] = new TEmp();
	emps[1] = new TEmp("Wuz", "Chris", "22-267-8012", "12323405", 6, 25);
	emps[2] = new TEmp("Jackson", "Priscilla", "63-232-1456", "08001896", 12, 23.50);
	emps[3] = new Admin();
	emps[4] = new Admin("Bush", "GeorgeJr", "06-1342-0456", 59099.76, "Librarian");
	emps[5] = new Admin("Clever", "Bob", "22-267-812", 79345.00, "Bussines Manger");
	emps[6] = new Prof();
	emps[7] = new Prof("Steiger", "Ludwig", "65-102-456", 79345.00, 3);
	emps[8] = new Prof("Flop", "Boby", "11-178-120", 69009.00, 0);
	emps[9] = new Prof("Daisy", "Ana", "34-567-812", 67099.00, 3);
	double totalToPay=0.0;
	for (int i = 0; i < SIZE; ++i) {
		totalToPay += emps[i]->getNetMonthlyPay();
		emps[i]->print(cout);
		cout << endl;
	}
	cout << "\nTotal wages this month: $" << setprecision(10) << totalToPay;
	cout << "\nThank you for using out program! Bye!" << endl;
	return 0;
}
	
void info() {
	cout << "159.234 Assignment 2P1" << endl;
	cout << "Leonard Phillips   15232331" << endl;
	cout << endl;
}
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	