# Write your MySQL query statement below
select 'Low Salary' as category, count(CASE WHEN income < 20000 THEN 1 END)as accounts_count
from accounts
union
select 'Average Salary' as category, count(CASE WHEN income <= 50000 and income>=20000 THEN 1 END)as accounts_count
from accounts
union 
select 'High Salary' as category, count(CASE WHEN income > 50000 THEN 1 END)as accounts_count
from accounts;
 