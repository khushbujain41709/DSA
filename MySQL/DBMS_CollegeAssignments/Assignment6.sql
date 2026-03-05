create database assignment6;

use assignment6;

create table Department(departmentID INT PRIMARY KEY, departmentName VARCHAR(20));

create table Employees(EmployeeID INT PRIMARY KEY, name varchar(20), departmentID INT, salary FLOAT, foreign key (departmentID) references Department(departmentID));

INSERT INTO Department VALUES(1, 'HR'),(2, 'Finance'),(3, 'Engineering'),(15, 'Research'),(20, 'Management');

INSERT INTO Employees (EmployeeID, Name, DepartmentID, Salary) VALUES(1, 'Khushbu', 3, 50000),(2, 'Lakshita', 15, 80000),(3, 'Manasvi', 2, 45000),(4, 'Simple', 1, 30000),(5, 'Kalash', 20, 100000);

DELIMITER //
CREATE PROCEDURE GetEmployeeDetails(IN emp_id INT)
BEGIN
    SELECT e.Name, d.DepartmentName, e.Salary FROM Employees e JOIN Department d ON e.DepartmentID = d.DepartmentID WHERE e.EmployeeID = emp_id;
END //
 
call GetEmployeeDetails(1);
//

DELIMITER //
CREATE PROCEDURE IncreaseSalaries(IN increasePercent FLOAT)
BEGIN
    UPDATE Employees SET Salary = Salary + (Salary * increasePercent / 100);
END //

call increasePercent(10);

DELIMITER //
CREATE PROCEDURE GetEmployeesByDepartment(IN dept_name VARCHAR(100))
BEGIN
    SELECT e.EmployeeID, e.Name, e.Salary FROM Employees e JOIN Departments d ON e.DepartmentID = d.DepartmentID WHERE d.DepartmentName = dept_name;
END //

call GetEmployeesByDepartment("Engineering");
//

delimiter //
create trigger preventNegativeSalary before update on employees for each row
begin
    if new.salary < 0 then signal sqlstate '45000' set message_text = 'Error: Salary cannot be negative';
    end if;
end //

delimiter //
create trigger ValidateEmployeeName before insert on Employees for each row
begin
    if new.name not regexp '^[A-Za-z]' then signal sqlstate '45000' set message_text = 'Error: Employee name must start with an alphabet.';
    end if;
end //







