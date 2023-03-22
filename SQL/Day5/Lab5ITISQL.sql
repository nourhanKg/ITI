--1.	Retrieve number of students who have a value in their age. 
Use ITI
select ST_ID , st_age
from Student
where st_age is not null

--2.	Get all instructors Names without repetition
select distinct Ins_name
from Instructor

--3.	Display student with the following Format (use isNull function)

select ST_Id as [Student ID], St_Fname +' ' + isNull(ST_Lname, '') as [Student Full Name], Dept_Name as [Department ID]
from student S, Department D
where S.Dept_ID = D.Dept_ID

--4.	Display instructor Name and Department Name 
--Note: display all the instructors if they are attached to a department or not

select Ins_name, Dept_Name
from Instructor I left outer join Department D
on I.Dept_Id = D.Dept_Id


--5.	Display student full name and the name of the course he is taking
--For only courses which have a grade  

select St_Fname +' ' + isNull(ST_Lname, '') as [Student Full Name], Crs_Name, Grade
from Student S, Stud_Course SC, Course C
where S.St_Id = SC.St_Id and SC.Crs_Id = C.Crs_Id and Grade is not null


--6.	Display number of courses for each topic name

select Count(Crs_Name) as [Course Numbers], Top_Name
from  Topic T, Course C
where C.Top_Id = T.Top_Id
group by Top_Name

--7.	Display max and min salary for instructors

select MAX(salary) as Maximum, Min(salary) as Minimum
from Instructor

---8.	Display instructors who have salaries less than the average salary of all instructors.
select Ins_Name, Salary
from Instructor
where salary < ( select Avg(Salary) from Instructor)

--9.	Display the Department name that contains the instructor who receives the minimum salary.
select D.Dept_Name, Ins_Name
from Department D, Instructor I
where I.Dept_Id = D.Dept_Id and Salary = (select Min(salary) from Instructor)


--10.	 Select max two salaries in instructor table. 
select Top(2) Salary
from Instructor
order by Salary desc

select Salary from (select Salary , DENSE_RANK() over(order by Salary desc) as DR
					from Instructor) as OrderedSal
where Dr <= 2


--*************
--11.	 Select instructor name and his salary but if there is no salary display instructor bonus keyword. “use coalesce Function”
select Ins_Name ,coalesce(Salary, '0')
from Instructor



--12.	Select Average Salary for instructors 
select AVG(Salary) as Average
from Instructor

select AVG(isnull(Salary, 0)) as Average
from Instructor

--13.	Select Student first name and the data of his supervisor 

select St.St_Fname, Sup.*
from Student St left outer join Student Sup
on St.St_super = Sup.St_Id

--14.	Write a query to select the highest two salaries in Each Department for instructors who have salaries. “using one of Ranking Functions”


select * from (select Salary , Dept_Id, DENSE_RANK() over(Partition by Dept_ID order by Salary desc) as DR
					from Instructor where salary is not null) as OrderedSal
where Dr <= 2

select * from (select Salary , Dept_Id, ROW_NUMBER() over(Partition by Dept_ID order by Salary desc) as RN
					from Instructor where salary is not null) as OrderedSal
where RN <= 2

--15.	 Write a query to select a random  student from each department.  “using one of Ranking Functions”
select * from (select *  , ROW_NUMBER() over(Partition by Dept_ID order by NEWID()) as RN
					from Student where Dept_Id is not null) as X
where RN = 1