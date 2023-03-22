use Company_SD


--1.	Display the Department id, name and id and the name of its manager.

select Dnum, Dname, MGRSSN, Fname
from Departments, Employee
where SSN = MGRSSN

--2.	Display the name of the departments and the name of the projects under its control.

select Dname , Pname
from Departments D, Project P
where D.Dnum = P.Dnum

--3.	Display the full data about all the dependence associated with the name of the employee they depend on him/her.

select Fname, D.*
from Employee E, Dependent D
where E.SSN = D.ESSN

--4.	Display the Id, name and location of the projects in Cairo or Alex city.

select Pnumber, Pname, Plocation
from Project
where City = 'Alex' or City = 'Cairo'

--5.	Display the Projects full data of the projects with a name starts with "a" letter.

select *
from Project
where Pname like 'a%'

--6. Display all the employees in department 30 whose salary from 1000 to 2000 LE monthly
select Fname 
from Employee
where Dno = 30 and Salary between 1000 and 2000


--7.	Retrieve the names of all employees in department 10 who works more than or equal10 hours per week on "AL Rabwah" project.
select Fname
from Employee E ,Works_for , Project
where SSN = ESSN and Pnumber = Pno and dno=10 and hours>=10 and pname= 'AL Rabwah'


--8.	Find the names of the employees who directly supervised with Kamel Mohamed.
select X.Fname as Employee, Y.Fname as Super
from Employee X, Employee Y
where Y.SSN = X.Superssn
and Y.Fname = 'Kamel'


--9.	Retrieve the names of all employees and the names of the projects they are working on, sorted by the project name.
select Fname, Pname
from Employee, Works_for, Project
where SSN = ESSN and Pnumber = Pno
order by Pname

--10.	For each project located in Cairo City , find the project number, the controlling department name ,the department manager last name ,address and birthdate.

select Pname, P.Dnum, Dname, Lname, Address, Bdate
from Project P, Departments D, Employee
where D.Dnum = P.Dnum and SSN = Mgrssn


--11.	Display All Data of the managers
select Employee.*
from Departments, Employee
where SSN = MGRSSN


--12.	Display All Employees data and the data of their dependents even if they have no dependents
select E.*, D.*
from Employee E left outer join Dependent D
on SSn = ESSN


13.	Insert your personal data to the employee table as a new employee in department number 30, SSN = 102672, Superssn = 112233, salary=3000.
14.	Insert another employee with personal data your friend as new employee in department number 30, SSN = 102660, but don’t enter any value for salary or supervisor number to him.
15.	Upgrade your salary by 20 % of its last value.
