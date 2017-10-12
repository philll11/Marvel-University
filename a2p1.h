/**
  * Leonard Phillips
  * 15232331
  * Assignment 1 Part 2
  * This is a Marvel University. It uses classes and inheritance to simulate a University
  * with multiple staff roles.
  */
  
#include <iostream>
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
		  * Initializes an Employee object and sets all data members
		  * @param[in] _mFName 	Employee first name
		  * @param[in] _mGName	Employee second name
		  * @param[in] _mIRD		Employee IRD number
		  */
		Employee(const string &_mFName, const string &_mGName, const string &_mIRD);
		/**
		  * Destructor
		  * Deconstructs initialized Employee object
		  */
		virtual ~Employee();
		/**
		  * Returns mFName
		  * @return mFName
		  */
		const string &getMFName() const;
		/**
		  * Returns mGName 
		  * @return mGName
		  */
		const string &getMGName() const;
		/**
		  * Returns mIRD 
		  * @return mIRD
		  */
		const string &getMIRD() const;
		/**
		  * Mutates mFName 
		  * @param[in] _mFName Assigns mFName with the value _mFName
		  */
		void setMFName(const string &_mFName);
		/**
		  * Mutates mGName
		  * @param[in] _mGName Assigns mGName with the value _mGName
		  */
		void setMGName(const string &_mGName);
		/**
		  * Mutates mIRD
		  * @param[in] _mIRD Assigns mIRD with the value _mIRD
		  */
		void setMIRD(const string &_mIRD);
		/**
		  * Displays the mIRD, mFName and mGName data members for the Employee object
		  * @param[in] _cout	 The stream used to display the data members
		  */
		virtual void print(ostream &_cout);
		/**
		  * Calculates the monthly net wages for the Employee object
		  * @return total monthly net wages
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
	_cout << setw(20) << left << getMIRD();
	_cout << setw(15) << left << getMFName();
	_cout << setw(20) << left << getMGName();
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
		  * Initializes an SalaryEmp object and sets all data members
		  * @param[in] _mFName 	Employee first name
		  * @param[in] _mGName	Employee second name
		  * @param[in] _mIRD		Employee IRD number
		  * @param[in] _mAPay	SalaryEmp annual pay 
		  */
		SalaryEmp(const string &_nFName, const string &_mGName, const string &_mIRD, double _mAPay);
		/**
		  * Returns mAPay 
		  * @return mAPay
		  */
		double getMAPay() const;
		/**
		  * Mutates mAPay
		  * @param[in] _mAPay Assigns mAPay with the value _mAPay
		  */
		void setMAPay(double _mAPay);
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
class Prof final : public SalaryEmp {
	private:
		int mDaysLeave; ///< Number of unpaid leave days.
		const int mTax = 28; ///< Percent deductions from salary.
	public:
		/**
		  * Constructor
		  * Initializes an Prof object and sets data members
		  * @param[in] _mFName 		Employee first name
		  * @param[in] _mGName		Employee second name
		  * @param[in] _mIRD			Employee IRD number
		  * @param[in] _mAPay		SalaryEmp annual pay 
		  * @param[in] _mDaysLeave	Prof unpaid leave days
		  */
		Prof(const string &_nFName = "NO_PR", const string &_mGName = "NO_PR", 
		const string &_mIRD = "PR00-0000-000", double _mAPay = 0.0, int _mDaysLeave = 0);
		/**
		  * Returns mDaysLeave 
		  * @return mDaysLeave
		  */
		int getMDaysLeave() const;
		/**
		  * Mutates mDaysLeave
		  * @param[in] _mDaysLeave Assigns mDaysLeave with the value _mDaysLeave
		  */
		void setMDaysLeave(int _mDaysLeave);
		/**
		  * Displays the mIRD, mFName, mGName and monthly net pay for the Employee object
		  * @param[in] _cout	 The stream used to display the values
		  */
		void print(ostream &);
		/**
		  * Calculates the monthly net wages for the Prof object less leave days
		  * and tax deducted
		  * @return total monthly net wages
		  */
		double getNetMonthlyPay();
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
	_cout << setw(20) << left << getMIRD();
	_cout << setw(15) << left << getMFName();
	_cout << setw(20) << left << getMGName();
	_cout << "$" << setw(20) << left << getNetMonthlyPay();	
}
//---------------------------------------------------------------
///	Uncomplete ///
double Prof::getNetMonthlyPay(){
	double totalMonthlyLeaveDeductions = (SalaryEmp::getMAPay() / 365.0) * getMDaysLeave();	
	double monthlySalaryLessLeave = (SalaryEmp::getMAPay() / 12) - totalMonthlyLeaveDeductions;
	return monthlySalaryLessLeave - (monthlySalaryLessLeave * (mTax / 100.0));	
}
//---------------------------------------------------------------
//=================================================================================
/**
 * A class representing an Administrator
 */
class Admin final : public SalaryEmp{
	private:
		string mJob; ///< Job title.
		const int mTax = 25; ///< Percent deductions from salary.
	public:
		/**
		  * Constructor
		  * Initializes an Admin object and sets data members
		  * @param[in] _mFName 		Employee first name
		  * @param[in] _mGName		Employee second name
		  * @param[in] _mIRD			Employee IRD number
		  * @param[in] _mAPay		SalaryEmp annual pay 
		  * @param[in] _mJob			Admin job title
		  */
		Admin(const string &_nFName = "NO_ADM", const string &_mGName = "NO_ADM", 
		const string &_mIRD = "ADM00-0000-000", double _mAPay = 0, const string &_mJob = "NO_ADM");
		/**
		  * Returns mJob 
		  * @return mJob
		  */
		const string &getMJob() const;
		/**
		  * Mutates mJob
		  * @param[in] _mJob Assigns mJob with the value _mJob
		  */
		void setMJob(const string &_mJob);
		/**
		  * Displays the mIRD, mFName and mGName data members for the Admin object
		  * @param[in] _cout	 The stream used to display the values
		  */
		void print(ostream &_cout);
		/**
		  * Calculates the monthly net wages for the Admin object less tax rate deductions
		  * @return total monthly net wages
		  */
		double getNetMonthlyPay();

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
	_cout << setw(20) << left << getMIRD();
	_cout << setw(15) << left << getMFName();
	_cout << setw(20) << left << getMGName();
	_cout << "$" << setw(20) << left << getNetMonthlyPay();
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
class TEmp final : public Employee {
	private:
		string mID; ///< Student ID number.
		int mHWorked; ///< Number of hours worked per month.
		double mHPay; ///< Hourly rate the student is paid.
		const int mTax = 20; ///< Percent deductions from salary.
	public:
		/**
		  * Constructor
		  * Initializes an TEmp object and sets data members
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
		  * Returns mID 
		  * @return mID
		  */
		const string &getMID() const;
		/**
		  * Returns mHWorked 
		  * @return mHWorked
		  */
		int getMHWorked() const;
		/**
		  * Returns mHPay 
		  * @return mHPay
		  */
		double getMHPay() const;
		/**
		  * Mutates mID
		  * @param[in] _mID Assigns mID with the value _mID
		  */
		void setMID(const string &_mID);
		/**
		  * Mutates mHWorked
		  * @param[in] _mHWorked Assigns mHWorked with the value _mHWorked
		  */
		void setMHWorked(int _mHWorked);
		/**
		  * Mutates mHPay
		  * @param[in] _mHPay Assigns mHPay with the value _mHPay
		  */
		void setMHPay(double _mHPay);
		/**
		  * Displays the mIRD, mFName and mGName data members for the TEmp object
		  * @param[in] _cout	 The stream used to display the values
		  */
		void print(ostream &_cout);
		/**
		  * Calculates the monthly net wages by multiplying mHWorked by mHPay
		  * less tax detuctions.
		  * @return total monthly net wages
		  */
		double getNetMonthlyPay();
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
	_cout << setw(20) << left << getMIRD();
	_cout << setw(15) << left << getMFName();
	_cout << setw(20) << left << getMGName();
	_cout << "$" << setw(20) << left << getNetMonthlyPay();
}
//---------------------------------------------------------------
double TEmp::getNetMonthlyPay() {
	double totalWage = getMHWorked() * getMHPay();
	double deductableTaxAmount = totalWage * (mTax / 100.0);
	return totalWage - deductableTaxAmount;
}
//---------------------------------------------------------------

void info() {
	cout << "159.234 Assignment 2P1" << endl;
	cout << "Leonard Phillips   15232331" << endl;
	cout << endl;
}
	