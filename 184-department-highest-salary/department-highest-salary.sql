# Write your MySQL query statement below
select d.name as Department,e.name as Employee,salary AS Salary
from Employee as e
JOIN Department d
    ON e.departmentId = d.id
where (e.departmentId,e.salary) IN (
    select departmentId,max(salary)
    from Employee
    group by departmentId
);
