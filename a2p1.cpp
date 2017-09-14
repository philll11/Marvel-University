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
        string nFName;
        string mGName;
    private:
        string mIRD;
    public:
    Employee(const string &_nFName, const string &_mGName, const string &_mIRD);
    virtual ~Employee();
    const string &getNFName() const;
    const string &getMGName() const;
    const string &getMIRD() const;
    void setNFName(const string &nFName);
    void setMGName(const string &mGName);
    void setMIRD(const string &mIRD);
    virtual void print(ostream &empData);
    virtual int getNetMonthlyPay();
};


//---------------------------------------------------------------
Employee::Employee(const string &_nFName, const string &_mGName, const string &_mIRD)
	: nFName(_nFName), mGName(_mGName), mIRD(_mIRD) {}
//---------------------------------------------------------------
Employee::~Employee() {

}
//---------------------------------------------------------------
const string &Employee::getNFName() const {
    return nFName;
}
//---------------------------------------------------------------
void Employee::setNFName(const string &nFName) {
    Employee::nFName = nFName;
}
//---------------------------------------------------------------
void Employee::setMGName(const string &mGName) {
    Employee::mGName = mGName;
}
//---------------------------------------------------------------
void Employee::setMIRD(const string &mIRD) {
    Employee::mIRD = mIRD;
}
//---------------------------------------------------------------
const string &Employee::getMGName() const {
    return mGName;
}
//---------------------------------------------------------------
const string &Employee::getMIRD() const {
    return mIRD;
}
//---------------------------------------------------------------
virtual void print(ostream &empData) {
	
}
//---------------------------------------------------------------
virtual int getNetMonthlyPay() {
	
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
void SalaryEmp::setMAPay(double mAPay) {
    SalaryEmp::mAPay = mAPay;
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
        Prof(const std::string &nFName, const std::string &mGName, const std::string &mIRD);
        int getMDaysLeave() const;
        void setMDaysLeave(int mDaysLeave);
        virtual void print(ostream &empData) override;
        virtual int getNetMonthlyPay() override;
};
//---------------------------------------------------------------
Prof::Prof(const string &nFName, const string &mGName, const string &mIRD) 
	: SalaryEmp(nFName, mGName, mIRD) {}
//---------------------------------------------------------------
int Prof::getMDaysLeave() const {
    return mDaysLeave;
}
//---------------------------------------------------------------
void Prof::setMDaysLeave(int mDaysLeave) {
    Prof::mDaysLeave = mDaysLeave;
}
//---------------------------------------------------------------
virtual void print(ostream &empData) override {

}
//---------------------------------------------------------------
virtual int getNetMonthlyPay() override {

}
//---------------------------------------------------------------
//=================================================================================
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	