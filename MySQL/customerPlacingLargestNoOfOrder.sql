-- Leetcode 586
select customer_number from Orders group by customer_number order by count(*) desc limit 1;
-- This can also be written as 
select customer_number from Orders group by customer_number having count(*) = (select max(cnt) from (select count(*) as cnt from Orders group by customer_number) as orderNew);
-- orderNew is used because Every derived table (subquery in FROM) must have an alias