create database assignment4;

use assignment4;

create table Student(sid INT PRIMARY KEY, sname VARCHAR(30), GPA FLOAT, sizeHS INT);

create table College(cname VARCHAR(50) PRIMARY KEY, state VARCHAR(20), enrollment INT);

create table Apply(sid INT, cname VARCHAR(50), major VARCHAR(20), decision VARCHAR(5), FOREIGN KEY(sid) REFERENCES Student(sid), FOREIGN KEY(cname) REFERENCES College(cname));

insert into Student(sid, sname, GPA, sizeHS) values(123, 'Amy', 3.9, 1000),(234, 'Craig', 3.5, 500),(345, 'Doris', 3.9, 1000),(567, 'Edward', 2.9, 2000),(678, 'Fay', 3.8, 200),(789, 'Gary', 3.4, 800),(987, 'Helen', 3.7, 800),(876, 'Irene', 3.9, 400),(765, 'Jay', 2.9, 1500),(654, 'Amy', 3.9, 1000),(543, 'Craig', 3.5, 500),(432, 'Doris', 3.9, 1000),(321, 'Edward', 2.9, 2000),(210, 'Fay', 3.8, 200),(109, 'Gary', 3.4, 800);

insert into Apply(sid, cname, major, decision) values(123, 'Stanford', 'CS', 'Y'),(123, 'Berkeley', 'CS', 'Y'),(123, 'Cornell', 'EE', 'N'),(345, 'Cornell', 'EE', 'Y'),(678, 'Stanford', 'History', 'Y'),(987, 'Stanford', 'CS', 'Y'),(876, 'Stanford', 'History', 'N'),(765, 'Cornell', 'History', 'Y'),(543, 'Berkeley', 'Biology', 'Y');

insert into College(cname, state, enrollment) values('Stanford', 'CA', 15000),('Berkeley', 'CA', 36000),('MIT', 'MA', 10000), ('Cornell', 'NY', 21000),('Harvard', 'MA', 50000);

select* from student;

select* from apply;

select* from college;

SELECT* from student join apply;

select s.sid, s.sname, s.gpa , a.cname , a.major from student s join apply a on s.sid = a.sid;

select* from apply join college on apply.cname = college.cname where state = 'CA';

select s.sid, s.sname, s.GPA , a.cname from student s join apply a on s.sid = a.sid where s.GPA > 3.7 and a.cname = 'Stanford';

select* from student s join apply a on a.sid = s.sid where a.major = 'CS' and a.decision = 'N';

SELECT s.*, a.* from student s join apply a on s.sid = a.sid join college c on a.cname = c.cname where c.state = 'NY';

select s.* from student s left join apply a on a.sid = s.sid where a.sid is NULL;

select c.* from college c left join apply a on c.cname = a.cname where a.cname IS NULL;

select sid from apply group by sid having count(*) = 1;

select distinct s.sname, s.gpa from student s join apply a on s.sid = a.sid join college c on a.cname = c.cname where c.enrollment <= 25000 and a.cname IS NOT NULL;

select s11.sid as s1, s22.sid as s2, s11.GPA from student s11 join student s22 on s11.gpa = s22.gpa where s11.sid < s22.sid;

select distinct a.major from apply a join college c on a.cname = c.cname where c.state = 'MA';