# Write your MySQL query statement below
select person_name
from (
    select person_name,turn
    from (
        select person_name,weight,sum(weight) OVER (ORDER BY turn) AS w,turn
        from Queue
        order by turn
    )f
    where w<=1000
)t
ORDER BY turn desc
LIMIT 1;