# Write your MySQL query statement below
select DISTINCT num as ConsecutiveNums
from (
    select id,num,res,
    LAG(res) over (order by id) as res1
    from (
        select id, num,
        LAG(num) over (order by id) as res
        from Logs
    )t
)f
where res1=num AND res=num;
