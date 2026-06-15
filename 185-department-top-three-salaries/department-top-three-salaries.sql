# Write your MySQL query statement below
select Department,Employee,Salary
from (select d.name as Department, e.name as Employee,e.salary as Salary,DENSE_RANK() OVER (
    PARTITION BY e.departmentId
    ORDER BY e.salary DESC
) AS r
       from Employee as e
       join Department as d
       on e.departmentId=d.id
       )as t
 where r<4;