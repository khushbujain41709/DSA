create database assignment5;

use assignment5;

create table student(sid INT primary key, sname VARCHAR(20), gpa FLOAT, sizeHS INT);

create table college(cname VARCHAR(20) PRIMARY KEY, state VARCHAR(10), enrollment INT);

create table apply(sid INT, cname VARCHAR(20), major VARCHAR(5), decision VARCHAR(20), foreign key(sid) references student(sid), foreign key(cname) references college(cname));

INSERT INTO student VALUES(100, 'Kalash', 9.95, 3000),(101, 'Khushbu', 8.86, 2000),(102, 'Lakshita', 8.5, 1800),(103, 'Manasvi', 8.48, 2200),(104, NULL, 8.2, 2500),(105, 'Simple', 9.4, 2100);

INSERT INTO College VALUES('NIT Raipur', 'CG', 5000),('IIT Delhi', 'Delhi', 8000),('BITS Pilani', 'Rajasthan', 7000),('NIT Warangal', 'Telangana', 6000),('VIT', 'Tamil Nadu', 9000);

INSERT INTO Apply VALUES(101, 'NIT Raipur', 'CSE', 'Y'),(102, 'IIT Delhi', 'ECE', 'N'),(103, 'BITS Pilani', 'MECH', 'Y'),(104, 'NIT Warangal', 'CSE', 'Y'),(105, 'VIT', 'ECE', 'N'),  (100, 'NIT Warangal', 'MECH', 'Y');

select* from student where sname IS NULL;

select* from college1, apply, student limit 10;

select* from student where ROWNUM <= 10;
select* from apply where ROWNUM <= 10;
select* from college1 where ROWNUM <= 10;


CREATE TABLE Employee(ID INT PRIMARY KEY,Name VARCHAR(50),Email VARCHAR(50),Exp FLOAT ,Salary FLOAT,Phone VARCHAR(15) ,Address VARCHAR(100));

INSERT INTO Employee VALUES (1, 'Khushbu', 'khushbu@nitw.in', 3, 50000, '9999999999', 'Raipur'),(2, 'Lakshita', 'lakshita@nitw.in', 15, 80000, '8888888888', 'Delhi'),(3, 'Manasvi', 'manasvi@nitw.in', 2, 45000, '7777777777', 'Mumbai'),(4, 'Simple', 'simple@nitw.in', 1, 30000, '6666666666', 'Hyderabad'),(5, 'Kalash', 'kalash@nitw.in', 20, 100000, '5555555555', 'Raipur');

SELECT SID, sName, GPA, LEAST(GPA, sizeHS) AS LeastVal, GREATEST(GPA, sizeHS) AS GreatVal FROM Student;

SELECT cName, state, enrollment, LEAST(enrollment, LENGTH(state)) AS LeastVal, GREATEST(enrollment, LENGTH(state)) AS GreatVal FROM College;

SELECT SID, cName, major, LEAST(LENGTH(major), LENGTH(decision)) AS LeastVal, GREATEST(LENGTH(major), LENGTH(decision)) AS GreatVal FROM Apply;

SELECT SID, COALESCE(sName, 'No Name') AS sName FROM Student;

SELECT COALESCE(cName, 'No College') AS cName, COALESCE(state, 'Unknown') AS state FROM College;

SELECT COALESCE(SID, 0) AS SID, COALESCE(cName, 'No College') AS cName, coalesce(major, 'Undeclared') AS major, coalesce(decision, 'Not decided') as decision FROM Apply;

CREATE TABLE Employee(ID INT PRIMARY KEY,Name VARCHAR(50),Email VARCHAR(50),Exp FLOAT ,Salary FLOAT,Phone VARCHAR(15) ,Address VARCHAR(100));

INSERT INTO Employee VALUES (1, 'Khushbu', 'khushbu@nitw.in', 3, 50000, '9999999999', 'Raipur'),(2, 'Lakshita', 'lakshita@nitw.in', 15, 80000, '8888888888', 'Delhi'),(3, 'Manasvi', 'manasvi@nitw.in', 2, 45000, '7777777777', 'Mumbai'),(4, 'Simple', 'simple@nitw.in', 1, 30000, '6666666666', 'Hyderabad'),(5, 'Kalash', 'kalash@nitw.in', 20, 100000, '5555555555', 'Raipur');

DECLARE
    CURSOR emp_cur IS SELECT ID, Name, Salary FROM Employee WHERE Exp >= 2;
    v_id Employee.ID%TYPE;
    v_name Employee.Name%TYPE;
    v_salary Employee.Salary%TYPE;
    v_count NUMBER := 0;
BEGIN
    OPEN emp_cur;
    LOOP
        FETCH emp_cur INTO v_id, v_name, v_salary;
        EXIT WHEN emp_cur%NOTFOUND;
        UPDATE Employee SET Salary = Salary + 20000 WHERE ID = v_id;
        v_count := v_count + 1;
    END LOOP;
    CLOSE emp_cur;
    DBMS_OUTPUT.PUT_LINE(v_count || ' rows updated.');
END;
/

DECLARE
    CURSOR ins_cur IS SELECT * FROM Employee;
BEGIN
    INSERT INTO Employee VALUES (6, 'NewEmp', 'newemp@nitw.in', 5, 60000, '4444444444', 'Pune');
    DBMS_OUTPUT.PUT_LINE('1 row inserted using cursor.');
END;
/


DECLARE
    CURSOR exp_emp_cursor IS 
        SELECT * FROM Employee WHERE Exp > 14;
    v_emp_rec exp_emp_cursor%ROWTYPE;
    v_row_count NUMBER := 0;
BEGIN
    OPEN exp_emp_cursor;
    
    LOOP
        FETCH exp_emp_cursor INTO v_emp_rec;
        EXIT WHEN exp_emp_cursor%NOTFOUND;
        
        v_row_count := v_row_count + 1;
        DBMS_OUTPUT.PUT_LINE('Employee ' || v_row_count || ': ' || v_emp_rec.Name || 
                           ', Experience: ' || v_emp_rec.Exp || ' years');
    END LOOP;
    
    CLOSE exp_emp_cursor;
    DBMS_OUTPUT.PUT_LINE('Total rows fetched: ' || v_row_count);
END;
/