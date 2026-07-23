CREATE DATABASE Assignment3;

USE Assignment3;

CREATE TABLE Emp(empno INT AUTO_INCREMENT PRIMARY KEY, empname VARCHAR(50), hire_date DATE, mgr INT, job VARCHAR(50), salary DECIMAL(10, 2), commission DECIMAL(10, 2), deptno INT, grade INT);

CREATE TABLE Dept(deptno INT AUTO_INCREMENT PRIMARY KEY, deptname VARCHAR(30), locno INT);

CREATE TABLE Location(locno INT, city VARCHAR(30));

CREATE TABLE Salgrade(grade INT, lowsal DECIMAL(10, 2), hisal DECIMAL(10, 2));

INSERT INTO Emp(empname, hire_date, mgr, job, salary, commission, deptno, grade) VALUES ('Davies', '2008-01-19', 100, 'Technician', 10000.39, 800.78, 80, 3),('Kalash', '2009-08-20', 120, 'SDE', 1000048.89, 8050.78, 10, 1),('Manasvi', '2002-12-12', 110, 'SDE', 350000.39, 900.78, 60, 2),('Lakshita', '2005-12-06', 90, 'Technician', 510000.39, 800.78, 90, 3),('Khushbu', '2008-01-20', 103, 'SDE', 750000.39, 8090.78, 50, 1),('Niti', '2008-04-19', 160, 'Technician', 140000.39, 500.78, 80, 3),('Lisa', '2015-01-19', 170, 'Lawyer', 103000.39, 600.78, 76, 2),('Tanisha', '2007-01-19', 200, 'CA', 60000.39, 900.78, 80, 3),('Simple', '2008-01-19', 112, 'DA', 104000.39, 1800.78, 80, 1),('Mona', '2005-01-19', 130, 'Worker', 4000.39, 100.78, 99, 5);

INSERT INTO Dept(deptno, deptname, locno) VALUES (80, 'SDE', 490001), (112, 'DA', 490002),(90, 'Technician', 490003),(50, 'CA', 490004),(100, 'Cook', 490006),(76, 'Receptionist', 490005),(170, 'Lawyer', 490007),(99, 'Worker', 490008),(10, 'Analyst', 490009),(119, 'Plumber', 490010);

INSERT INTO Location(locno, city) VALUES(490001, 'Durg'),(490002, 'Bhilai'),(490003, 'Raipur'),(490004, 'Warangal'),(490005, 'Hyderabad'),(490006, 'Vizag'),(490007, 'Guntur'),(490008, 'Kazipet'),(490009, 'Chennai'),(490010, 'Tirupati');

INSERT INTO Salgrade(grade, lowsal, hisal) VALUES(1, 1000000.58, 6000000.70),(2, 1000000.58, 6000000.70),(3, 100000.58, 600000.70),(4, 100000.58, 600000.70),(5, 100000.58, 600000.70),(6, 100000.58, 600000.70),(7, 100000.58, 600000.70),(8, 100.58, 600.70),(9, 100.58, 600.70),(10, 10.58, 60.70);

SELECT e.empname, e.deptno, d.deptname FROM Emp e JOIN Dept d ON e.deptno = d.deptno;

SELECT DISTINCT e.job, l.city FROM Emp e JOIN Dept d ON e.deptno = d.deptno JOIN Location l ON d.locno = l.locno WHERE e.deptno = 80;

SELECT e.empname, d.deptname, d.locno, l.city FROM Emp e JOIN Dept d ON e.deptno = d.deptno JOIN Location l ON d.locno = l.locno WHERE e.commission IS NOT NULL;

SELECT e.empname, e.job, e.deptno, d.deptname FROM Emp e JOIN Dept d ON e.deptno = d.deptno JOIN Location l ON d.locno = l.locno WHERE l.city = 'Durg';

SELECT e.empname, e.deptno FROM Emp e WHERE e.deptno = (SELECT deptno FROM Emp WHERE empname = 'Khushbu');

SELECT e.empname, e.job, d.deptname, e.salary, s.grade FROM Emp e JOIN Dept d ON e.deptno = d.deptno JOIN Salgrade s ON e.grade = s.grade;

SELECT empname, hire_date FROM Emp WHERE hire_date > (SELECT hire_date FROM Emp WHERE empname = 'Davies');