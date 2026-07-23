-- Leetcode 1193
/*
Approach:
1) Extract Month and Year:
Use the LEFT function to get the YYYY-MM part from the trans_date. The LEFT() function extracts a number of characters from a string (starting from left).

2) Group By Month and Country:
Group the transactions by the extracted month and country.

3) Count Transactions:
Use COUNT(id) to count all transactions per group.

4) Count Approved Transactions:
Use SUM(state = 'approved') to count approved transactions, leveraging the fact that boolean expressions return 1 for true and 0 for false.

5) Sum Total Amounts:
Use SUM(amount) to sum the transaction amounts for all transactions per group.

6) Sum Approved Amounts:
Use SUM((state = 'approved') * amount) to sum the transaction amounts for approved transactions, ensuring only approved amounts are summed.
*/
select LEFT(trans_date,7) as month, country, count(id) as trans_count, sum(state = 'approved') as approved_count, sum(amount) as trans_total_amount, sum((state = 'approved') * amount) as approved_total_amount from Transactions group by month, country;