-- Leetcode 181
select e1.name as Employee from employee e1 join employee e2 on e2.id = e1.managerID where e1.salary > e2.salary;