use Company_SD

/*1.	Display (Using Union Function)
a.	 The name and the gender of the dependence that's gender is Female and depending on Female Employee.
b.	 And the male dependence that depends on Male Employee.*/

select Fname, Dependent_name, D.Sex
from Employee E, Dependent D
where SSN = ESSN and E.Sex = 'F' and D.Sex = 'F'
union all
select Fname, Dependent_name, D.Sex
from Employee E, Dependent D
where SSN = ESSN and E.Sex = 'M' and D.Sex = 'M'

--2.	For each project, list the project name and the total hours per week (for all employees) spent on that project.

select Sum(Hours) as weeklyHours, Pname
from Employee, Works_for, Project
where SSN = ESSN and Pnumber = Pno
Group by Pname


--3.	Display the data of the department which has the smallest employee ID over all employees' ID.
select SSn, D.*
from Employee, Departments D
where D.Dnum = Employee.Dno and SSN = (select MIN(ssn) from Employee)



--4.	For each department, retrieve the department name and the maximum, minimum and average salary of its employees.
select Min(Salary), Max(Salary), Dname
from Departments, Employee
where Dnum = Dno
group by Dname

--5.	List the full name of all managers who have no dependents.

select distinct E.Fname + ' ' + E.Lname as [FullName]
from Employee E, Departments
where SSN = MGRSSn and SSN not In(select SSN 
									from Employee , Dependent
									where SSN = ESSN)

--6.	For each department-- if its average salary is less than the average salary of all employees-- display its number, name and number of its employees.


select Avg(Salary) as "AVG", Dname, Dnum, Count(SSN) as "Employees"
from Departments, Employee
where Dnum = Dno
group by Dnum, Dname
having Avg(Salary) < (select Avg(Salary)
						from Employee)



--7.	Retrieve a list of employees names and the projects names they are working on ordered by department number and within each department, ordered alphabetically by last name, first name.
select Fname, Lname, Pname, Dnum
from Employee, Works_for, Project
where SSN = ESSN and Pnumber = Pno
order by Dnum, Lname, Fname

--8.	Try to get the max 2 salaries using subquery

select MAX(Salary) from Employee
union all
select MAX(Salary) from Employee
where Salary Not In (select MAX(Salary) from Employee)

--9.	Get the full name of employees that is similar to any dependent name
select Fname + ' ' + E.Lname as [FullName]
from Employee E

intersect

select Dependent_name
from Dependent

--10.	Display the employee number and name if at least one of them have dependents (use exists keyword) self-study.

select Fname, SSN
from Employee
where exists ( select * from Dependent where SSN = ESSN)


--11.	In the department table insert new department called "DEPT IT" , with id 100, employee with SSN = 112233 as a manager for this department. The start date for this manager is '1-11-2006'

Insert into Departments
values('DEPT IT', '100', '112233', '1-11-2006')

/*12.	Do what is required if you know that : Mrs.Noha Mohamed(SSN=968574) 
moved to be the manager of the new department (id = 100), and they give you(your SSN =102672) her position (Dept. 20 manager) 

a.	First try to update her record in the department table
b.	Update your record to be department 20 manager.
c.	Update the data of employee number=102660 to be in your teamwork (he will be supervised by you) (your SSN =102672)
*/
update Departments
set MGRSSN = 968574
where Dnum = 100

update Departments
set MGRSSN = 102672
where Dnum = 20


update Employee
set Superssn = 102672
where SsN = 102660

--13.	Unfortunately the company ended the contract with Mr. Kamel Mohamed (SSN=223344) so try to delete his data from your database in case you know that you will be temporarily in his position.
--Hint: (Check if Mr. Kamel has dependents, works as a department manager, supervises any employees or works in any projects and handle these cases).


delete Dependent
where ESSN IN(select SSN from Employee where Fname= 'Kamel')

update Departments
set MGRSSN = '102672'
where MGRSSN = '223344'

update Employee
set Superssn = '102672'
where Superssn = '223344'

update Works_for
set ESSn = '102672'
from Employee, Works_for, Project
where SSn = ESSN and Pno = Pnumber and SSN= '223344'

delete Employee
where SSN = '223344'

--14.	Try to update all salaries of employees who work in Project ‘Al Rabwah’ by 30%
update Employee
set Salary = Salary + 0.3 * Salary
from Employee, Works_for, Project
where SSn = ESSN and Pno = Pnumber and Pname= 'Al Rabwah'