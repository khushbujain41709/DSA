-- Leetcode 577
SELECT e.name , b.bonus FROM Employee e LEFT JOIN bonus b on e.empID = b.empID where b.bonus < 1000 OR b.bonus IS NULL;