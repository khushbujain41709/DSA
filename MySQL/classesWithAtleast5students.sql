-- Leetcode 596
select class from Courses group by class having count(*) >= 5;