# Write your MySQL query statement below
select max(salary) as SecondHighestSalary
from (
select salary,
DENSE_RANK() OVER (ORDER BY salary DESC) as rnk
from Employee) t
where rnk=2;