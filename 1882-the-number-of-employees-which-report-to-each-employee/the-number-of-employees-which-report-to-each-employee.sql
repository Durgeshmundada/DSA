select e.employee_id,e.name,count(*) as reports_count ,ROUND(AVG(m.age), 0) AS average_age
from employees e
join employees m
on e.employee_id=m.reports_to
GROUP BY e.employee_id, e.name
ORDER BY e.employee_id;